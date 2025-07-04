#ifndef INTERFACE_SERVICO_CONTA_HPP_INCLUDED
#define INTERFACE_SERVICO_CONTA_HPP_INCLUDED

/**
 * @file interface_servico_conta.hpp
 * @brief Define a interface (contrato) para a camada de serviço de Conta.
 *
 * @details Este arquivo declara a classe abstrata `ISConta`, que serve como
 * um contrato para as classes que implementam as regras de negócio relacionadas
 * à entidade `Conta`. 
 * 
 * Ele desacopla a camada de apresentação da lógica de
 * negócio, definindo os casos de uso de alto nível.
 *
 * @author Pedro Vale
 * @date 03/07/2025
 */

#include <string>

#include "../../../libs/tipos/estruturas.hpp"
#include "../../../libs/dominios/dominios.hpp"
#include "../../../libs/entidades/entidades.hpp"
#include "../../../libs/sessao_usuario/sessao_usuario.hpp"

/**
 * @class ISConta
 * @brief Interface Abstrata para o Serviço de Negócio de Conta.
 *
 * @details Define todas as operações de negócio que podem ser realizadas na
 * conta de investimento. 
 * As implementações desta interface conterão a lógica de validação e coordenação das operações.
 */

class ISConta {
public:
    /**
     * @brief Destrutor virtual padrão.
     */
    virtual ~ISConta() = default;
    
    /**
     * @brief Edita o nome referente a conta.
     * 
     * @param novoNome O novo nome encapsulado em um objeto do domínio.
     * @throw runtime_error Se a regra de negócio for violada na camada
     * de persistência.
     */

    virtual void editarNomeConta(Nome& novoNome) = 0;
    
    /**
     * @brief Edita a senha referente a conta.
     * 
     * @param novaSenha A nova senha encapsulado em um objeto do domínio.
     * @throw runtime_error Se a regra de negócio for violada na camada
     * de persistência.
     */

    virtual void editarSenhaConta(Senha& novaSenha) = 0;
    
    /**
     * @brief Exclui a conta logada.
     * 
     * @throw invalid_argument Se a regra de negócio for violada na camada
     * de persistência.
     */

    virtual void excluirContaLogada() = 0;
    /**
     * @brief Leitura dos dados da conta.
     * 
     * @return Atributos do domínio Conta.
     * @throw runtime_error Se a regra de negócio for violada na camada
     * de persistência.
     */
    virtual Conta lerConta()= 0;

};

#endif // INTERFACE_SERVICO_CONTA_HPP_INCLUDED