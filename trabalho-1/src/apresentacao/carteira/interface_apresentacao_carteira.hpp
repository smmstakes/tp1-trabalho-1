#ifndef INTERFACE_APRESENTACAO_CARTEIRA_HPP_INCLUDED
#define INTERFACE_APRESENTACAO_CARTEIRA_HPP_INCLUDED

/**
 * @file interface_apresentacao_carteira.hpp
 * @brief Define a interface (contrato) para a camada de apresentação de Carteira.
 *
 * @details Este arquivo declara a classe abstrata `IACarteira`, que serve como
 * um contrato para qualquer controlador de apresentação que gerencie a
 * interação do usuário com as carteiras de investimento. 
 *
 * @author Matheus Duarte
 * @date 03/07/2025
 */

#include "../../servicos/carteira/interface_servico_carteira.hpp"


/**
 * @class IACarteira
 * @brief Interface Abstrata para o Controlador de Apresentação de Carteira.
 *
 * @details Define o conjunto de operações que uma interface de usuário para
 * carteiras deve ser capaz de realizar. 
 * As classes que herdam de `IACarteira` são responsáveis por implementar 
 * a lógica de interação com o usuário.
 */
class IACarteira {
protected:
    virtual void mostrarOpcoes() = 0;
    virtual bool escolherOpcao(int) = 0;

    virtual void criarCarteira() = 0;
    virtual void lerCarteira() = 0;
    virtual void editarCarteira() = 0;
    virtual void excluirCarteira() = 0;
    virtual void listarCarteiras() = 0;

public:
    /**
     * @brief Ponto de entrada principal para iniciar a execução do módulo de apresentação.
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
     * @param servicoCarteira Ponteiro para uma implementação da interface `ISCarteira`.
     */
    virtual void setCntrlISCarteira(ISCarteira*) = 0;

    /**
     * @brief Destrutor virtual.
     * 
     * @details Garante que o destrutor da classe derivada seja chamado corretamente
     * quando um objeto é deletado através de um ponteiro para a classe base.
     */
    virtual ~IACarteira() {};
};

#endif // INTERFACE_APRESENTACAO_CARTEIRA_HPP_INCLUDED
