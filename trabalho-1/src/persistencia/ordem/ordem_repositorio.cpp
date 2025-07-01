#include "ordem_repositorio.hpp"

RepositorioIPOrdem::RepositorioIPOrdem() : gerenciadorBD(GerenciadorBD::getInstance()) {}

std::string RepositorioIPOrdem::obterUltimoCodigoOrdemInserido() {
    sqlite3* db = gerenciadorBD.getDB();
    std::string sql = "SELECT codigo FROM Ordem ORDER BY codigo DESC LIMIT 1;";

    ComandoSQL comando(db, sql);
    
    if (comando.step()) {
        return comando.getColumnString(0);
    }

    return ""; 
}

std::vector<Ordem> RepositorioIPOrdem::getOrdensPorCarteira(const std::string& codCarteira) {
    sqlite3* db = gerenciadorBD.getDB();
    std::string sql = "SELECT codigo, codNegociacao, data, preco, quantidade FROM Ordem WHERE cod_carteira = ?;";
    
    ComandoSQL comando(db, sql);
    comando.bind(1, codCarteira);

    std::vector<Ordem> ordens;

    while (comando.step()) {
        std::string codigo = comando.getColumnString(0);
        std::string codNegociacao = comando.getColumnString(1);
        std::string data = comando.getColumnString(2);
        double preco = comando.getColumnDouble(3);
        int qtd = comando.getColumnInt(4);

        Ordem ordem(codigo, codNegociacao, data, preco, qtd);

        ordens.push_back(ordem);
    }

    return ordens;
}

int RepositorioIPOrdem::contarOrdensUsuario(const std::string& cpfUsuario) {
    sqlite3* db = gerenciadorBD.getDB();
    std::string sql = "SELECT COUNT(*) AS qtd_ordens FROM Ordem WHERE cpf_conta= ?;";

    ComandoSQL comando(db, sql);
    comando.bind(1, cpfUsuario);

    comando.execute();
    return comando.getColumnInt(0);
}

void RepositorioIPOrdem::criarOrdem(const std::string& codigo, const std::string& codigo_negociacao, const std::string& data, double preco, int quantidade, const std::string& codigoCarteira) {
    sqlite3* db = gerenciadorBD.getDB();
    
    std::string sql = "INSERT INTO Ordem (codigo, codNegociacao, data, preco, quantidade, cod_carteira) VALUES (?, ?, ?, ?, ?, ?);";
    
    ComandoSQL comando(db, sql);
    
    comando.bind(1, codigo);
    comando.bind(2, codigo_negociacao);
    comando.bind(3, data);
    comando.bind(4, preco);
    comando.bind(5, quantidade);
    comando.bind(6, codigoCarteira);
    
    comando.execute(); 
}

bool RepositorioIPOrdem::excluirOrdem(const std::string& codOrdem, const std::string& codCarteira) {
    sqlite3* db = gerenciadorBD.getDB();
    
    std::string sql = "DELETE FROM Ordem WHERE codigo = ?;";

    ComandoSQL comando(db, sql);
    comando.bind(1, codOrdem);
    comando.bind(2, codCarteira);

    
    comando.execute();

    return sqlite3_changes(db) > 0;
}