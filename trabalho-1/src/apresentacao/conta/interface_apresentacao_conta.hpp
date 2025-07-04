#ifndef INTERFACE_APRESENTACAO_CONTA_INCLUDED
#define INTERFACE_APRESENTACAO_CONTA_INCLUDED
/**
 * @file interface_apresentacao_conta.hpp
 * @brief Define a interface para a camada de apresentação de Conta.
 *
 * @details Este arquivo declara a classe abstrata `IAConta`, que serve como
 * um contrato para qualquer controlador de apresentação que gerencie a
 * interação do usuário com suas contas de investimento. 
 *
 * @author Pedro Vale
 * @date 03/07/2025
 */
#include "../../servicos/conta/interface_servico_conta.hpp"

/**
 * @class IAConta
 * @brief Interface Abstrata para o Controlador de Apresentação de Conta.
 *
 * @details Define o conjunto de operações que uma interface de usuário para
 * conta deve ser capaz de realizar. 
 * As classes que herdam de `IAConta` são responsáveis por implementar 
 * a lógica de interação com o usuário.
 */

class IAConta {
protected:
    virtual void mostrarOpcoes() = 0;
    virtual bool escolherOpcao(int) = 0;

    virtual void lerConta() = 0;
    virtual void editarConta() = 0;
    virtual void excluirConta() = 0;

public:

    /**
     * @brief Iniciar a execução do módulo de apresentação.
     * 
     * @details Este método deve conter o loop principal de interação com o usuário
     */

    virtual void executar() = 0;

    /**
     * @brief Injeta a dependência da camada de serviço no controlador.
     * 
     * @details Essencial para o padrão de Injeção de Dependência, este método
     * conecta a camada de apresentação com a camada de regras de negócio.
     * 
     * @param servicoConta Ponteiro para uma implementação da interface `ISConta`.
     */

    virtual void setCntrlISConta(ISConta*) = 0;

    /**
     * @brief Destrutor virtual.
     * 
     * @details Garante que o destrutor da classe derivada seja chamado corretamente
     * quando um objeto é deletado através de um ponteiro para a classe base.
     */
    
    virtual ~IAConta() {};
};


#endif // INTERFACE_APRESENTACAO_CONTA_INCLUDED