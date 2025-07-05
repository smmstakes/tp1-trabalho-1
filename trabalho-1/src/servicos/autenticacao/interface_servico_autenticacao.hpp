#ifndef INTERFACE_SERVICO_AUTENTICACAO_HPP_INCLUDED
#define INTERFACE_SERVICO_AUTENTICACAO_HPP_INCLUDED

/**
 * @file interface_servico_autenticacao.hpp
 * @brief define a interface (contrato) para a camada de serviço de Autenticação de Conta.
 * 
 * @details Este arquivo declara a classe abstrata `ISAutenticacao`, que serve como
 * um contrato para as classes que implementam as regras de autenticação relacionadas
 * à entidade `Autenticação`. 
 * Ele desacopla a camada de apresentação da lógica de
 * negócio, definindo os casos de uso de alto nível.
 * 
 * @author Jose Artur Nordestino
 * @date 04/07/2025
 */

#include <string>

#include "../../../libs/tipos/estruturas.hpp"
#include "../../../libs/dominios/dominios.hpp"
#include "../../../libs/entidades/entidades.hpp"
#include "../../../libs/sessao_usuario/sessao_usuario.hpp"

/**
 * @class ISAutenticacao
 * @brief Interface Abstrata para o Serviço de Autenticação de Conta.
 *
 * @details Define todas as operações de autenticação que podem ser realizadas na primeira interação
 * com o programa. 
 * As implementações desta interface conterão a lógica de validação e coordenação das operações.
 */

class ISAutenticacao {
public:

    /**
     * @brief Destrutor virtual padrão.
     */

    virtual ~ISAutenticacao() = default;

    /**
     * @brief Permite inserir os dados para acessar a conta e os serviços do programa.
     * 
     * @details A implementação deve verificar regras de autenticação, como verificar se
     * o CPF inserido existe no banco de dados e se a senha inserida é igual a senha associada
     * ao CPF inserido.
     * 
     * @param cpf O cpf do usuário, encapsulado em um objeto de domínio.
     * @param senha A senha do usuário, encapsulado em um objeto de domínio.
     * 
     * @throw runtime_error Se o CPF não for encontrado no banco de dados ou se a senha não corresponder
     * à senha associada ao CPF inserido.
     */
    virtual void acessarConta(const CPF& cpf, const Senha& senha) = 0;

    /**
     * @brief Permite inserir os dados para registrar uma conta no banco de dados.
     * 
     * @details A implementação deve verificar regras de autenticação, como verificar se
     * o CPF inserido já existe no banco de dados antes de solicitar a criação na camada
     * de persistência.
     * 
     * @param cpf O cpf do usuário, encapsulado em um objeto de domínio.
     * @param nome O nome do usuário, encapsulado em um objeto de domínio.
     * @param senha A senha do usuário, encapsulado em um objeto de domínio.
     * 
     * @throw runtime_error Se o CPF inserido já existir no banco de dados.
     */
    virtual void registrarConta(const CPF& cpf, const Nome& nome, const Senha& senha) = 0;
};

#endif // INTERFACE_SERVICO_CARTEIRA_HPP_INCLUDED
