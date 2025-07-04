#ifndef INTERFACE_SERVICO_DADOS_HISTORICOS_HPP_INCLUDED
#define INTERFACE_SERVICO_DADOS_HISTORICOS_HPP_INCLUDED

#include <string>
#include "../../../libs/dominios/dominios.hpp"

/**
 * @file interface_servico_dados_historicos.hpp
 * @brief Especificação para o serviço que acessa dados históricos de ativos.
 * @author Gabriel Castro
 */

/**
 * @class IServicoDadosHistoricos
 * @brief Interface que define a operação de busca de preços em dados históricos.
 */
class IServicoDadosHistoricos {
public:
    virtual ~IServicoDadosHistoricos() = default;

    /**
     * @brief Busca o preço médio de um ativo em uma data específica.
     * @param codNegociacao Código do ativo a ser pesquisado.
     * @param data Data do pregão (período em que a bolsa de valores está aberta para negocaições de ativo) a ser pesquisada.
     * @return O preço médio do ativo como um double.
     */
    virtual double getPrecoMedioNaData(const CodigoNegociacao& codNegociacao, const Data& data) = 0;
};

#endif // INTERFACE_SERVICO_DADOS_HISTORICOS_HPP_INCLUDED