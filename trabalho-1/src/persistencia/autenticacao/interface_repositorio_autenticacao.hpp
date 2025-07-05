#ifndef INTERFACE_REPOSITORIO_AUTENTICACAO_HPP_INCLUDED
#define INTERFACE_REPOSITORIO_AUTENTICACAO_HPP_INCLUDED

/**
 * @file interface_repositorio_autenticacao.hpp
 * @brief Define a interface (contrato) para a camada de persistência de Autenticação.
 *
 * @details Este arquivo declara a classe abstrata `IPAutenticacao`, que serve como
 * um contrato para qualquer classe de repositório que gerencie o armazenamento
 * e a recuperação de dados da entidade `Conta`. 
 * Ele desacopla a camada de serviço dos detalhes de implementação do banco de dados.
 *
 * @author Jose Artur Nordestino
 * @date 04/07/2025
 */

#include <string>

#include "../../../libs/tipos/estruturas.hpp"
#include "../../../libs/dominios/dominios.hpp"
#include "../../../libs/entidades/entidades.hpp"

/**
 * @class IPAutenticacao
 * @brief Interface Abstrata para o Repositório da entidade Autenticação.
 *
 * @details Define o conjunto de operações de persistência de dados
 * que podem ser realizadas com as contas.
 */
class IPAutenticacao {
public:
    /**
     * @brief Destrutor virtual padrão.
     */
    virtual ~IPAutenticacao() = default;

    /**
     * @brief Insere uma nova conta no banco de dados.
     * 
     * @param cpf O CPF do usuário.
     * @param nome O nome do usuário.
     * @param senha A senha do usuário.
     */
    virtual void registrarContaUsuario(const std::string& cpf, const std::string& nome, const std::string& senha) = 0;

    /**
     * @brief Verifica se já existe alguma entrada do CPF inserido no banco de dados.
     * 
     * @param cpf O CPF do usuário.
     * 
     * @return `true` se encontrar uma entrada com esses parâmetros.
     * @return `false` se não encontrar nada.
     */
    virtual bool getCPF(const std::string& cpf) = 0;

    /**
     * @brief Verifica se já existe no banco de dados alguma entrada que possua simultaneamente
     * o CPF inserido e a senha inserida.
     * 
     * @param cpf O CPF do usuário.
     * @param senha A senha do usuário.
     * @return `true` se encontrar uma entrada com esses parâmetros.
     * @return `false` se não encontrar nada.
     * @return Retorna um falso booleano caso não tenha a entrada no banco de dados ou um verdadeiro caso tenha.
     */
    virtual bool getSenha(const std::string& cpf, const std::string& senha) = 0;

    /**
     * @brief Recupera do banco de dados o nome associado ao CPF inserido.
     * 
     * @param cpf O CPF do usuário.
     * @return Retorna uma string com o nome encontrado.
     */
    virtual std::string getNome(const std::string& cpf) = 0;

};

#endif  // INTERFACE_REPOSITORIO_CARTEIRA_HPP_INCLUDED
