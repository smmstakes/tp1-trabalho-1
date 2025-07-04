#ifndef INTERFACE_SERVICO_ORDEM_HPP_INCLUDED
#define INTERFACE_SERVICO_ORDEM_HPP_INCLUDED

#include <string>

#include "../../../libs/tipos/estruturas.hpp"
#include "../../../libs/dominios/dominios.hpp"
#include "../../../libs/entidades/entidades.hpp"
#include "../../../libs/sessao_usuario/sessao_usuario.hpp"

/**
 * @file interface_servico_ordem.hpp
 * @brief Especificação dos serviços de lógica de negócio para a entidade Ordem.
 * @author Gabriel Castro
 */

/**
 * @class ISOrdem
 * @brief Interface para os serviços que gerenciam a lógica de negócio de Ordens.
 */
class ISOrdem {
public:
    virtual ~ISOrdem() = default;

     /**
     * @brief Cria uma nova ordem, calculando seu preço com base em dados históricos.
     * @param codNegociacao Código do ativo a ser negociado.
     * @param quantidade Quantidade de papéis.
     * @param data Data da transação.
     * @param codigoCarteira Código da carteira onde a ordem será criada.
     * @throw std::runtime_error ou std::invalid_argument em caso de erro.
     */
    virtual void criarOrdem(const CodigoNegociacao& codNeg, const Quantidade& quantidade, const Data& data, const Codigo& codCarteira) = 0;

    /**
     * @brief Exclui uma ordem de uma carteira.
     * @param codigoOrdem Código da ordem a ser excluída.
     * @param codigoCarteira Código da carteira para validação.
     */
    virtual void excluirOrdem(const Codigo& codigoOrdem, const Codigo& codigoCarteira) = 0;

    /**
     * @brief Lista todas as ordens de uma carteira específica.
     * @param codigoCarteira Código da carteira a ser consultada.
     * @return Vetor de objetos Ordem.
     */
    virtual std::vector<Ordem> listarOrdens(const Codigo& codigoCarteira) = 0;
};

#endif // INTERFACE_SERVICO_ORDEM_HPP_INCLUDED
