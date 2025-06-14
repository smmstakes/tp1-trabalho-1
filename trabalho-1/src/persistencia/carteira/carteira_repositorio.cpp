#include <memory>
#include <iostream>
#include <stdexcept>

#include "carteira_repositorio.hpp"
#include "../../../libs/sqlite/sqlite3.h"
#include "../../../libs/comandoSQL/comandoSQL.hpp"

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
    
    // Se houver um resultado (step() retorna true)
    if (comando.step()) {
        return comando.getColumnString(0); // Pega o resultado da coluna 0
    }
    
    // Se não, retorna vazio. A limpeza é automática.
    return "";
}
