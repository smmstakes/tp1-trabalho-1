#ifndef BANCO_DE_DADOS_HPP
#define BANCO_DE_DADOS_HPP

#include <sqlite3.h>
#include <string>

class BancoDeDados {
private:
    sqlite3* db;
    bool conectado;

    BancoDeDados();  // Construtor privado
    ~BancoDeDados();

public:
    BancoDeDados(const BancoDeDados&) = delete;
    BancoDeDados& operator=(const BancoDeDados&) = delete;

    static BancoDeDados& getInstance();

    bool conectar(const std::string& nome_arquivo);
    void desconectar();
    bool criarTabelas();
    sqlite3* getDB() const { return db; };
};


#endif
