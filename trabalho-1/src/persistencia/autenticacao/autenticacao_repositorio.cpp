#include "autenticacao_repositorio.hpp"

RepositorioIPAutenticacao::RepositorioIPAutenticacao() : gerenciadorBD(GerenciadorBD::getInstance()) {}

void RepositorioIPAutenticacao::registrarContaUsuario(const std::string& cpf, const std::string& nome, const std::string& senha) {
    sqlite3* db = gerenciadorBD.getDB();
    
    // SQL com placeholders (?) para segurança
    std::string sql = "INSERT INTO Conta (cpf, nome, senha) VALUES (?, ?, ?);";
    
    // Cria, usa e destrói o comando preparado
    ComandoSQL comando(db, sql);
    
    // Vincula os parâmetros de forma segura
    comando.bind(1, cpf);
    comando.bind(2, nome);
    comando.bind(3, senha);
    //ver o que eh esse cpfusuario
    
    // Executa o comando
    comando.execute(); 
}

bool RepositorioIPAutenticacao::getCPF(const std::string& cpf) {
    sqlite3* db = gerenciadorBD.getDB();

    // SQL para obter as carteiras do usuário
    std::string sql = "SELECT * FROM Conta WHERE cpf = ?;";
    
    ComandoSQL comando(db, sql);
    comando.bind(1, cpf);
    
    if (comando.step()) {
        return true;
    }

    return false;
}

bool RepositorioIPAutenticacao::getSenha(const std::string& cpf, const std::string& senha) {
    sqlite3* db = gerenciadorBD.getDB();

    // SQL para obter as carteiras do usuário
    std::string sql = "SELECT * FROM Conta WHERE cpf = ? AND senha = ?;";
    
    ComandoSQL comando(db, sql);
    comando.bind(1, cpf);
    comando.bind(2, senha);
    
    if (comando.step()) {
        return true;
    }

    return false;
}