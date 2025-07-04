#ifndef ESTRUTURAS_HPP_INCLUDED
#define ESTRUTURAS_HPP_INCLUDED

/**
 * @file estruturas.hpp
 * 
 * @brief Define estruturas de dados auxiliares e DTOs (Data Transfer Objects).
 * 
 * @details Este arquivo centraliza a definição de estruturas de dados que não são
 * entidades de negócio puras, mas que servem para agrupar e transportar dados
 * entre as camadas da aplicação.
 *
 * @author Matheus Duarte, Suyanne Miranda
 * @date 03/07/2025
 */

#include "../entidades/entidades.hpp"


/**
 * @struct CarteiraComValor
 * 
 * @brief Agrupa uma entidade `Carteira` com o seu valor total de ativos calculado.
 *
 * @details Esta estrutura é usada como um DTO para transportar
 * informações sobre uma carteira. Ela encapsula a entidade e o resultado de um
 * cálculo (soma do valor das ordens), simplificando a lógica na interface do usuário.
 */
struct CarteiraComValor {
    /**
     * @var Carteira carteira
     * @brief A instância da entidade `Carteira` com seus dados básicos (código, nome, perfil).
     */
    Carteira carteira;

    /**
     * @var double valorTotal
     * @brief O valor monetário total calculado de todos os ativos contidos na carteira.
     */
    double valorTotal;
    
// Criado por Matheus Duarte - 211062277
};

/**
 * @struct ExcecaoSolicitacaoExclusaoConta
 * @brief Exceção personalizada para sinalizar quando uma solicitação de exclusão de conta é feita.
 *
 * @details Utilizada para sinalizar a controladora da aplicação que o protocolo de exclusão de
 * conta deve ser iniciado, a saber: exclusão de ordens, de carteira e por fim dos dados de conta.
 */
struct ExcecaoSolicitacaoExclusaoConta : public std::exception {
    const char* what() const noexcept override {
        return "Solicitação de exclusão de conta confirmada.";
    }

// Criado por Suyanne Miranda - 222006445
};





#endif // ESTRUTURAS_HPP_INCLUDED
