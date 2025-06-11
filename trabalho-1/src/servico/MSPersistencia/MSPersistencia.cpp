#include "MSPersistencia.hpp"
#include <iostream>
#include <stdexcept>

const char* MSPersistencia::NOME_DB = "investimentos.db";

MSPersistencia& MSPersistencia::getInstancia() {
    static MSPersistencia instancia;
    return instancia;
}

MSPersistencia::MSPersistencia() {
    conectar();
    if (conectado) {
        std::cout << "[INFO] Conexão com banco de dados estabelecida com sucesso\n";
        criarTabelas();
    }
}

MSPersistencia::~MSPersistencia() {
    desconectar();
}

void MSPersistencia::conectar() {
    if (sqlite3_open(NOME_DB, &db) == SQLITE_OK) {
        conectado = true;
    } else {
        conectado = false;
        throw std::runtime_error("Erro ao abrir o banco de dados: " + std::string(sqlite3_errmsg(db)));
    }
}

void MSPersistencia::desconectar() {
    if (conectado) {
        sqlite3_close(db);
        std::cout << "[INFO] Conexão com o banco encerrada\n";
    }
}

bool MSPersistencia::criarTabelas() {
    if (!conectado)
        throw std::runtime_error("Tentativa de criar tabelas sem conexão com banco.");

    const char* sqls[] = {
        "CREATE TABLE IF NOT EXISTS Conta (cpf TEXT PRIMARY KEY, nome TEXT NOT NULL, senha TEXT NOT NULL);",
        "CREATE TABLE IF NOT EXISTS Carteira (codigo TEXT PRIMARY KEY, nome TEXT NOT NULL, perfil TEXT NOT NULL);",
        "CREATE TABLE IF NOT EXISTS Ordem (codigo TEXT PRIMARY KEY, codNegociacao TEXT, data TEXT, preco REAL, quantidade INTEGER);"
    };

    char* errMsg = nullptr;
    for (auto sql : sqls) {
        int rc = sqlite3_exec(db, sql, 0, 0, &errMsg);
        if (rc != SQLITE_OK) {
            std::string erro = errMsg ? errMsg : "Erro desconhecido ao criar tabelas.";
            sqlite3_free(errMsg);
            throw std::runtime_error("Erro SQL: " + erro);
        }
    }

    std::cout << "[INFO] Tabelas criadas com sucesso (ou já existiam)\n";
    return true;
}

void MSPersistencia::salvarCarteira(const std::string& codigo, const std::string& nome, const std::string& perfil) {
    if (!conectado) {
        throw std::runtime_error("Banco de dados não está conectado.");
    }

    std::string sql = "INSERT INTO Carteira (codigo, nome, perfil) VALUES ('" +
                      codigo + "', '" + nome + "', '" + perfil + "');";

    char* errMsg = nullptr;
    int rc = sqlite3_exec(db, sql.c_str(), 0, 0, &errMsg);
    if (rc != SQLITE_OK) {
        std::string erro = errMsg ? errMsg : "Erro desconhecido.";
        sqlite3_free(errMsg);
        throw std::runtime_error("Erro ao salvar carteira: " + erro);
    }

    std::cout << "[INFO] Carteira salva com sucesso: " << codigo << "\n";
}


std::string MSPersistencia::obterUltimoCodigoCarteiraInserido() {
    if (!conectado) {
        throw std::runtime_error("Banco de dados não está conectado.");
    }

    const char* sql = "SELECT MAX(codigo) FROM Carteira;";
    sqlite3_stmt* stmt = nullptr;

    std::string maiorCodigo;

    int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);
    if (rc != SQLITE_OK) {
        throw std::runtime_error("Erro ao preparar consulta SQL: " + std::string(sqlite3_errmsg(db)));
    }

    rc = sqlite3_step(stmt);
    if (rc == SQLITE_ROW) {
        const unsigned char* text = sqlite3_column_text(stmt, 0);
        if (text) {
            maiorCodigo = reinterpret_cast<const char*>(text);
        }
    } else if (rc != SQLITE_DONE) {
        sqlite3_finalize(stmt);
        throw std::runtime_error("Erro ao executar consulta SQL: " + std::string(sqlite3_errmsg(db)));
    }

    sqlite3_finalize(stmt);
    return maiorCodigo;
}

