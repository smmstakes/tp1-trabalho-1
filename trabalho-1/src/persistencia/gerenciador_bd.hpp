#ifndef GERENCIADOR_BD_HPP_INCLUDED
#define GERENCIADOR_BD_HPP_INCLUDED

#include <string>

#include "../../libs/sqlite/sqlite3.h"

class GerenciadorBD {
private:
    sqlite3* db;
    bool conectado;

    GerenciadorBD();
    ~GerenciadorBD();

public:
    GerenciadorBD(const GerenciadorBD&) = delete;
    GerenciadorBD& operator=(const GerenciadorBD&) = delete;

    static GerenciadorBD& getInstance();

    bool conectar(const std::string& nome_arquivo);
    void desconectar();
    bool criarTabelas();
    sqlite3* getDB() const { return db; }
};

#endif  // GERENCIADOR_BD_HPP_INCLUDED
