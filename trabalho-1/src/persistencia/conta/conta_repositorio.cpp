#include <memory>
#include <iostream>
#include <stdexcept>

#include "conta_repositorio.hpp"
#include "../../../libs/sqlite/sqlite3.h"
#include "../../../libs/comandoSQL/comandoSQL.hpp"

RepositorioIPConta::RepositorioIPConta() : gerenciadorBD(GerenciadorBD::getInstance()) {}

RepositorioIPConta& RepositorioIPConta::getInstancia() {
    static RepositorioIPConta instancia;
    return instancia;
}

void RepositorioIPConta::criarConta(const std::string& cpf, const std::string& nome, const std::string& senha) {
    sqlite3* db = gerenciadorBD.getDB();
    
    // SQL com placeholders (?) para segurança
    std::string sql = "INSERT INTO Carteira (cpf, nome, senha) VALUES (?, ?, ?);";
    
    // Cria, usa e destrói o comando preparado
    ComandoSQL comando(db, sql);
    
    // Vincula os parâmetros de forma segura
    comando.bind(1, cpf);
    comando.bind(2, nome);
    comando.bind(3, senha);
    
    // Executa o comando
    comando.execute(); 
}

std::string RepositorioIPConta::obterUltimoCPFContaInserido() {
    sqlite3* db = gerenciadorBD.getDB();
    std::string sql = "SELECT cpf FROM Conta ORDER BY cpf DESC LIMIT 1;";
    
    ComandoSQL comando(db, sql);
    
    // Se houver um resultado (step() retorna true)
    if (comando.step()) {
        return comando.getColumnString(0); // Pega o resultado da coluna 0
    }
    
    // Se não, retorna vazio. A limpeza é automática.
    return "";
}
