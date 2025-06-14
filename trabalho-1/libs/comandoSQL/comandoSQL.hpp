#ifndef COMANDOSQL_HPP_INCLUDED
#define COMANDOSQL_HPP_INCLUDED

#include <list>
#include <string>
#include <memory>
#include <stdio.h>
#include <iostream>

extern "C" {
    #include "../../libs/sqlite/sqlite3.h"
}

class EErroPersistencia : public std::exception {
private:
    std::string mensagem;

public:
    explicit EErroPersistencia(const std::string& mensagem) : mensagem(mensagem) {}
    const char* what() const noexcept override { return mensagem.c_str(); }
};

class ComandoSQL {
private:
    std::unique_ptr<sqlite3_stmt, decltype(&sqlite3_finalize)> stmt_ptr;

public:
    void inicializarBanco();

    // O construtor prepara o comando. Ele assume a responsabilidade.
    ComandoSQL(sqlite3* db, const std::string& sql);

    // Métodos para vincular ("bind") parâmetros de forma segura
    void bind(int index, int value);
    void bind(int index, double value);
    void bind(int index, const std::string& value);

    // Executa um passo (para SELECTs) ou o comando inteiro (para INSERT/UPDATE)
    // Retorna true se houver uma linha de resultado, false se a execução terminou.
    bool step();
    
    // Executa um comando que não retorna resultados (INSERT, UPDATE, DELETE)
    void execute();

    // Métodos para obter os valores das colunas do resultado
    int getColumnInt(int index);
    double getColumnDouble(int index);
    std::string getColumnString(int index);

    // Impedir cópias para evitar dupla liberação do recurso
    ComandoSQL(const ComandoSQL&) = delete;
    ComandoSQL& operator=(const ComandoSQL&) = delete;
};

#endif  // COMANDOSQL_HPP_INCLUDED
