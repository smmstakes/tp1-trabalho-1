#ifndef BANCO_DE_DADOS_HPP
#define BANCO_DE_DADOS_HPP

#include <sqlite3.h>
#include <string>

class BancoDeDados {
private:
    sqlite3* db;
    bool conectado;

public:
    BancoDeDados();
    ~BancoDeDados();

    bool conectar(const std::string& nome_arquivo);
    void desconectar();
    bool criarTabelas();
};

#endif
