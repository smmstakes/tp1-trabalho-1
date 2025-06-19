#include "carteira_repositorio.hpp"

RepositorioIPCarteira::RepositorioIPCarteira() : gerenciadorBD(GerenciadorBD::getInstance()) {}

RepositorioIPCarteira& RepositorioIPCarteira::getInstancia() {
    static RepositorioIPCarteira instancia;
    return instancia;
}

void RepositorioIPCarteira::criarCarteira(const std::string& codigo, const std::string& nome, const std::string& perfil) {
    sqlite3* db = gerenciadorBD.getDB();
    
    // SQL com placeholders (?) para segurança
    std::string sql = "INSERT INTO Carteira (codigo, nome, perfil) VALUES (?, ?, ?);";
    
    // Cria, usa e destrói o comando preparado
    ComandoSQL comando(db, sql);
    
    // Vincula os parâmetros de forma segura
    comando.bind(1, codigo);
    comando.bind(2, nome);
    comando.bind(3, perfil);
    
    // Executa o comando
    comando.execute(); 
}

std::string RepositorioIPCarteira::obterUltimoCodigoCarteiraInserido() {
    sqlite3* db = gerenciadorBD.getDB();
    std::string sql = "SELECT codigo FROM Carteira ORDER BY codigo DESC LIMIT 1;";
    
    ComandoSQL comando(db, sql);
    
    if (comando.step()) {
        return comando.getColumnString(0); // Pega o resultado da coluna 0
    }

    return "";
}

bool RepositorioIPCarteira::excluirCarteira(const std::string& codigo, const std::string& cpfUsuario) {
    sqlite3* db = gerenciadorBD.getDB();
    std::string sql = "DELETE FROM Carteira WHERE codigo = ? AND cpf_conta = ?;";

    ComandoSQL comando(db, sql);
    comando.bind(1, codigo);
    comando.bind(2, cpfUsuario);
    
    comando.execute();

    return sqlite3_changes(db) > 0;
}

std::vector<Carteira> RepositorioIPCarteira::listarCarteiras(const std::string& cpf) {
    sqlite3* db = gerenciadorBD.getDB();
    std::string sql = "SELECT codigo, nome, perfil FROM Carteira WHERE cpf_conta = ?;";

    ComandoSQL comando(db, sql);
    comando.bind(1, cpf);

    std::vector<Carteira> carteiras;

    while (comando.step()) {
        std::string codigo = comando.getColumnString(0);
        std::string nome = comando.getColumnString(1);
        std::string perfil = comando.getColumnString(2);

        Carteira carteira(codigo, nome, perfil);

        carteiras.push_back(carteira);
    }

    return carteiras;
}
