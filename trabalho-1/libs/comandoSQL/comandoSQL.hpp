#ifndef COMANDOSQL_HPP_INCLUDED
#define COMANDOSQL_HPP_INCLUDED

/**
 * @file comandoSQL.hpp
 * @brief Classe que realiza todas as operações relacionadas a SQL
 * 
 * @details Nesse arquivo foi implementado a classe que servirá de ponte
 * para realizar os comandos SQL no banco de dados, sua principal função é 
 * facilitar o desenvolvimento da camada de persistência com a abastração das funções,
 * fornecendo códigos reutilizáveis, além de uma classe de erro.
 *
 * @author Matheus Duarte
 * @date 03/07/2025
 */

#include <list>
#include <string>
#include <memory>
#include <stdio.h>
#include <iostream>

extern "C" {
    #include "../../libs/sqlite/sqlite3.h"
}


/**
 * @class EErroPersistencia
 * @brief Classe auxiliar para erros
 * 
 * @details Tem como objetivo fornecer um erro específico afim de diferenciar os erros 
 * da camada de persistência dos outros erros do restante do projeto.
 */
class EErroPersistencia : public std::exception {
private:
    std::string mensagem;

public:
    /**
     * @brief Constrói uma nova instância do erro com a mensagem fornecida.
     * 
     * @param mensagem Mensagem que explicita o erro ocorrido durante a execução.
     */

    explicit EErroPersistencia(const std::string& mensagem) : mensagem(mensagem) {}

    /**
     * @brief Retorna a mensagem do erro em forma de string.
     */
    const char* what() const noexcept override { return mensagem.c_str(); }
};


/**
 * @class ComandoSQL
 * 
 * @brief Gerencia o ciclo de vida de um único comando SQL preparado (`sqlite3_stmt`).
 * 
 * @details Esta classe encapsula a preparação, execução e finalização de um comando SQL.
 * Ela abstrai a complexidade da API C do SQLite, oferecendo métodos para vincular parâmetros
 * de forma segura, executar o comando passo a passo (para SELECTs) ou de uma só vez
 * (para INSERTs, UPDATEs, etc.), e obter os resultados.
 */
class ComandoSQL {
private:
    std::unique_ptr<sqlite3_stmt, decltype(&sqlite3_finalize)> stmt_ptr;

public:
    /**
     * @brief Prepara um comando SQL para execução.
     * 
     * @details O construtor chama `sqlite3_prepare_v2` e armazena o statement
     * preparado no ponteiro único para o banco.
     * 
     * @param db Ponteiro para a conexão com o banco de dados SQLite.
     * @param sql A string do comando SQL a ser preparada.
     * 
     * @throw EErroPersistencia Se a preparação do comando falhar.
     */
    ComandoSQL(sqlite3* db, const std::string& sql);

    /**
     * @brief Vincula um valor a um placeholder no comando SQL.
     * 
     * @details Substitui um placeholder ('?') no comando SQL pelo valor fornecido.
     * 
     * @param index O índice do placeholder (começando em 1).
     * @param value O valor (int, double ou string) a ser vinculado.
     */
    void bind(int index, int value);
    void bind(int index, double value);
    void bind(int index, const std::string& value);

    /**
     * @brief Executa um passo do comando preparado.
     * 
     * @details Essencial para comandos SELECT, pois posiciona o cursor na próxima
     * linha do conjunto de resultados. Para comandos INSERT, UPDATE ou DELETE,
     * executa a operação.
     * 
     * @return `true` se uma nova linha de resultado está disponível para leitura.
     * 
     * @return `false` se o comando concluiu a execução e não há mais linhas.
     * 
     * @throw EErroPersistencia Se ocorrer um erro durante a execução do passo.
     */
    bool step();
    
    /**
     * @brief Executa um comando que não retorna linhas de resultado (ex: INSERT, UPDATE, DELETE).
     * 
     * @details É um método de conveniência que chama `step()` e ignora o resultado.
     * Ideal para operações de modificação de dados.
     * 
     * @throw EErroPersistencia Se ocorrer um erro durante a execução.
     */
    void execute();

    /**
     * @brief Obtém o valor de uma coluna da linha de resultado atual.
     * 
     * @pre Deve ser chamado somente após uma chamada a `step()` que retornou `true`.
     * 
     * @param index O índice da coluna (começando em 0).
     * 
     * @return O valor da coluna no tipo especificado.
     */
    int getColumnInt(int index);
    double getColumnDouble(int index);
    std::string getColumnString(int index);

    // Impedir cópias para evitar dupla liberação do recurso
    ComandoSQL(const ComandoSQL&) = delete;
    ComandoSQL& operator=(const ComandoSQL&) = delete;
};

#endif  // COMANDOSQL_HPP_INCLUDED
