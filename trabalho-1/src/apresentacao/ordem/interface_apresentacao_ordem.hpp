#ifndef INTERFACE_APRESENTACAO_ORDEM_HPP_INCLUDED
#define INTERFACE_APRESENTACAO_ORDEM_HPP_INCLUDED

#include "../../servicos/ordem/interface_servico_ordem.hpp"

/**
 * @file interface_apresentacao_ordem.hpp
 * @brief Especificação para a controladora de apresentação da entidade Ordem.
 * @author Gabriel Castro
 */

/**
 * @class IAOrdem
 * @brief Interface que define o fluxo de interação do usuário para gerenciar ordens.
 */
class IAOrdem {
protected:
    /**
     * @brief Mostra as opções do menu de ordens para o usuário.
     */
    virtual void mostrarOpcoes() = 0;

    /**
     * @brief Processa a opção escolhida pelo usuário.
     * @param opcao Número da opção digitada pelo usuário.
     * @return false se o usuário escolher a opção de voltar, true caso contrário.
     */
    virtual bool escolherOpcao(int) = 0;

    /**
     * @brief Conduz o fluxo para a criação de uma nova ordem.
     */
    virtual void criarOrdem() = 0;

    /**
     * @brief Conduz o fluxo para a exclusão de uma ordem existente.
     */
    virtual void excluirOrdem() = 0;

    /**
     * @brief Apresenta a lista de todas as ordens da carteira selecionada.
     */
    virtual void listarOrdens() = 0;

public:
    /**
     * @brief Inicia e controla o loop do menu de gerenciamento de ordens.
     */
    virtual void executar() = 0;

    /**
     * @brief Injeta a dependência do serviço de negócio de Ordem.
     */
    virtual void setCntrlISOrdem(ISOrdem*) = 0;
    
    virtual ~IAOrdem() {};
};

#endif // INTERFACE_APRESENTACAO_ORDEM_HPP_INCLUDED
