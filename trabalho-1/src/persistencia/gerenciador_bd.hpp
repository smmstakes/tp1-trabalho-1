#ifndef GERENCIADOR_BD_HPP_INCLUDED
#define GERENCIADOR_BD_HPP_INCLUDED

/**
 * @file gerenciador_bd.hpp
 * @brief Declaração do gerenciador de conexão com o banco de dados SQLite.
 *
 * @details Este arquivo define a classe `GerenciadorBD`, um Singleton responsável por
 * todo o ciclo de vida da conexão com o banco de dados. 
 * Ele centraliza as operações de conectar, desconectar, criar as tabelas e fornecer o
 * handle da conexão para outras partes do sistema.
 *
 * @author Matheus Duarte
 * @date 03/07/2025
 */

#include <string>
#include <iostream>

extern "C" {
    #include "../../libs/sqlite/sqlite3.h"
}

/**
 * @class GerenciadorBD
 * 
 * @brief Gerencia a conexão e o estado do banco de dados SQLite.
 *
 * @details Implementado como um Singleton, esta classe garante que existe apenas
 * um ponto de controle para o banco de dados em toda a aplicação. 
 * Ela abstrai os detalhes de baixo nível da abertura e fechamento da conexão.
 */
class GerenciadorBD {
private:
    sqlite3* db;
    bool conectado;

    GerenciadorBD();
    ~GerenciadorBD();

public:
    /**
     * @brief Desabilita o construtor de cópia para garantir uma única instância.
     */
    GerenciadorBD(const GerenciadorBD&) = delete;

    /**
     * @brief Desabilita o operador de atribuição de cópia.
     */
    GerenciadorBD& operator=(const GerenciadorBD&) = delete;

    /**
     * @brief Fornece acesso à instância única (Singleton) do gerenciador.
     * 
     * @return GerenciadorBD& Uma referência para a instância global.
     */
    static GerenciadorBD& getInstance();

    /**
     * @brief Método para inicializar o banco de dados.
     * 
     * @details Realiza a sequência de conexão com o arquivo padrão e criação das tabelas.
     * 
     * @return `true` se a conexão e a criação das tabelas foram bem-sucedidas.
     * @return `false` se ocorreu algum erro durante o processo.
     */
    bool inicializarBanco();

    /**
     * @brief Abre a conexão com um arquivo de banco de dados SQLite.
     * 
     * @param nome_arquivo O caminho para o arquivo do banco de dados.
     * 
     * @return `true` em caso de sucesso na conexão.
     * @return `false` se a conexão falhar.
     */
    bool conectar(const std::string& nome_arquivo);

    /**
     * @brief Fecha a conexão com o banco de dados, se estiver aberta.
     */
    void desconectar();

    /**
     * @brief Executa os comandos SQL para criar as tabelas do sistema, caso não existam.
     * 
     * @return `true` se todas as tabelas foram criadas com sucesso.
     * @return `false` se ocorreu algum erro de SQL.
     */
    bool criarTabelas();

    /**
     * @brief Fornece o ponteiro bruto para a conexão com o banco de dados.
     * 
     * @details Este método é usado por outras classes (como `ComandoSQL`) que precisam
     * interagir diretamente com a API do SQLite.
     * 
     * @return sqlite3* O ponteiro para o handle do banco de dados, ou `nullptr` se não conectado.
     */
    sqlite3* getDB() const { return db; }
};

#endif  // GERENCIADOR_BD_HPP_INCLUDED
