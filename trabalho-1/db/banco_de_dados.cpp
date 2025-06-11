#include "banco_de_dados.hpp"
#include <iostream>

BancoDeDados::BancoDeDados() : db(nullptr), conectado(false) {}

BancoDeDados::~BancoDeDados() {
    desconectar();
}

bool BancoDeDados::conectar(const std::string& nome_arquivo) {
    int rc = sqlite3_open(nome_arquivo.c_str(), &db);
    if (rc) {
        std::cerr << "Erro ao abrir o banco de dados: " << sqlite3_errmsg(db) << std::endl;
        return false;
    }
    conectado = true;
    return true;
}

void BancoDeDados::desconectar() {
    if (conectado) {
        sqlite3_close(db);
        conectado = false;
    }
}

bool BancoDeDados::criarTabelas() {
    if (!conectado) return false;

    const char* sqls[] = {
        "CREATE TABLE IF NOT EXISTS Conta (cpf TEXT PRIMARY KEY, nome TEXT NOT NULL, senha TEXT NOT NULL);",
        "CREATE TABLE IF NOT EXISTS Carteira (codigo TEXT PRIMARY KEY, nome TEXT NOT NULL, perfil TEXT NOT NULL);",
        "CREATE TABLE IF NOT EXISTS Ordem (codigo TEXT PRIMARY KEY, codNegociacao TEXT, data TEXT, preco REAL, quantidade INTEGER);"
    };

    char* errMsg = nullptr;
    for (auto sql : sqls) {
        int rc = sqlite3_exec(db, sql, 0, 0, &errMsg);
        if (rc != SQLITE_OK) {
            std::cerr << "Erro SQL: " << errMsg << std::endl;
            sqlite3_free(errMsg);
            return false;
        }
    }

    return true;
}
