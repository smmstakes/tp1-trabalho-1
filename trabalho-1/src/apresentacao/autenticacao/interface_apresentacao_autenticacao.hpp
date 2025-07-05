#ifndef INTERFACE_APRESENTACAO_AUTENTICACAO_HPP_INCLUDED
#define INTERFACE_APRESENTACAO_AUTENTICACAO_HPP_INCLUDED

/**
 * @file interface_apresentacao_autenticacao.hpp
 * @brief Define a interface para a camada de apresentação da Autenticação de Conta.
 * 
 * @details Esse arquivo declara a classe abstrata `IAAutenticacao`, que serve como
 * um contrato para qualquer controlador de apresentação que gerencie a
 * interação do usuário com suas contas de investimento. 
 * 
 * @author Jose Artur Nordestino
 * @date 04/07/2025
 */

#include "../../servicos/autenticacao/interface_servico_autenticacao.hpp"

/**
 * @class IAAutenticacao
 * @brief Interface Abstrata para o Controlador de Apresentação da Autenticação de Conta
 * 
 * @details Define o conjunto de operações que uma interface de usuário para
 * autenticação de conta deve ser capaz de realizar.
 * As classes que herdam de `IAAutenticacao` sao responsáveis por implementar 
 * a lógica de integração com o usuário. 
 */

class IAAutenticacao {
protected:

    virtual void mostrarOpcoes() = 0;
    virtual bool escolherOpcao(int) = 0;

    virtual bool acessarConta() = 0;
    virtual bool registrarConta() = 0;

public:
/**
 * @brief Iniciar a execução do módulo de apresentação.
 * 
 * @details Este método deve conter o loop principal de interação com o usuário
 */
    virtual bool executar() = 0;

/**
 * @brief Injeta a dependência da camada de serviço no controlador.
 * 
 * @details essencial para o padrão de Injeção de Dependência, este método
 * conecta a camada de apresentação com a camada de regras de negócio.
 * 
 * @param servicoAutenticacao Ponteiro para uma implementação de interface `ISAutenticacao`
 */

    virtual void setCntrlISAutenticacao(ISAutenticacao*) = 0;

/**
 * @brief Destrutor virtual.
 * 
 * @details Garante que o destrutor da classe derivada seja chamado corretamente
 * quando um objeto é deletado através de um ponteiro para a classe base.
 */    

    virtual ~IAAutenticacao() {};
};

#endif // INTERFACE_APRESENTACAO_AUTENTICACAO_HPP_INCLUDED
