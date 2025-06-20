#include "gerenciador_bd.hpp"

GerenciadorBD::GerenciadorBD() : db(nullptr), conectado(false) {}

GerenciadorBD::~GerenciadorBD() {
    desconectar();
}

GerenciadorBD& GerenciadorBD::getInstance() {
    static GerenciadorBD instancia;
    return instancia;
}

bool GerenciadorBD::conectar(const std::string& nome_arquivo) {
    int rc = sqlite3_open(nome_arquivo.c_str(), &db);
    if(rc) {
        std::cerr << "Erro ao abrir o banco de dados: " << sqlite3_errmsg(db) << std::endl;
        return conectado;
    }
    conectado = true;
    return conectado;
}

void GerenciadorBD::desconectar() {
    if(conectado) {
        sqlite3_close(db);
        conectado = false;
    }
}

bool GerenciadorBD::criarTabelas() {
    if(!conectado) return false;

    const char* sqls[] = {
        "CREATE TABLE IF NOT EXISTS Conta (cpf TEXT PRIMARY KEY, nome TEXT NOT NULL, senha TEXT NOT NULL);",
        "CREATE TABLE IF NOT EXISTS Carteira (codigo TEXT PRIMARY KEY, nome TEXT NOT NULL, perfil TEXT NOT NULL, cpf_conta TEXT, FOREIGN KEY (cpf_conta) REFERENCES Conta (cpf));",
        "CREATE TABLE IF NOT EXISTS Ordem (codigo TEXT PRIMARY KEY, codNegociacao TEXT, data TEXT, preco REAL, quantidade INTEGER, cod_carteira TEXT, FOREIGN KEY (cod_carteira) REFERENCES Carteira (codigo));"
    };

    char* errMsg = nullptr;
    for(auto sql : sqls) {
        int rc = sqlite3_exec(db, sql, 0, 0, &errMsg);
        if(rc != SQLITE_OK) {
            std::cerr << "Erro SQL: " << errMsg << std::endl;
            sqlite3_free(errMsg);
            return false;
        }
    }

    return true;
}

bool GerenciadorBD::inicializarBanco() {
    try {
        GerenciadorBD& gerenciadorBD = GerenciadorBD::getInstance();

        if (!gerenciadorBD.conectar("sistema_de_investimentos.db")) {
            std::cerr << "Falha ao conectar ao banco de dados.\n";
            return false;
        }

        if (!gerenciadorBD.criarTabelas()) {
            std::cerr << "Não foi possível criar as tabelas do banco de dados.\n";
            return false;
        }

        return true;

    } catch (const std::exception& excp) {
        std::cerr << "Ocorreu um erro durante a inicialização: " << excp.what() << "\n";
        return false;
    }
}
