#ifndef INTERFACE_APRESENTACAO_ORDEM_HPP_INCLUDED
#define INTERFACE_APRESENTACAO_ORDEM_HPP_INCLUDED

/**
 * @file interface_apresentacao_ordem.hpp
 * @brief Define a interface para a camada de apresentação de Ordem.
 * 
 * @details Este arquivo declara a classe abstrata `IAOrdem`, que serve como
 * um contrato para qualquer controlador de apresentação que gerencie a
 * interação do usuário com as ordens de uma carteira.
 * 
 * @author Gabriel Castro
 * @date 04/07/2025
 */

#include "../../servicos/ordem/interface_servico_ordem.hpp"

/**
 * @class IAOrdem
 * @brief Interface Abstrata para o Controlador de Apresentação de Ordem.
 * 
 * @details Define as operações que uma interface de usuário para ordens deve realizar.
 */
class IAOrdem {
protected:
    virtual void mostrarOpcoes() = 0;
    virtual bool escolherOpcao(int) = 0;

    virtual void criarOrdem() = 0;
    virtual void excluirOrdem() = 0;
    virtual void listarOrdens() = 0;

public:
    /**
     * @brief Ponto de entrada para iniciar a execução do módulo de apresentação de ordens.
     * 
     * @param codigoCarteira O código da carteira específica cujas ordens serão gerenciadas.
     */
    virtual void executar() = 0;

    /**
     * @brief Injeta a dependência da camada de serviço no controlador.
     * 
     * @param servicoOrdem Ponteiro para uma implementação da interface `ISOrdem`.
     */
    virtual void setCntrlISOrdem(ISOrdem*) = 0;
    
    /**
     * @brief Destrutor virtual.
     * 
     * @details Garante que o destrutor da classe derivada seja chamado corretamente
     * quando um objeto é deletado através de um ponteiro para a classe base.
     */
    virtual ~IAOrdem() {};
};

#endif // INTERFACE_APRESENTACAO_ORDEM_HPP_INCLUDED
