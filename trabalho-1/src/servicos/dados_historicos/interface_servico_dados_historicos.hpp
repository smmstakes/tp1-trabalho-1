#ifndef INTERFACE_SERVICO_DADOS_HISTORICOS_HPP_INCLUDED
#define INTERFACE_SERVICO_DADOS_HISTORICOS_HPP_INCLUDED

#include <string>
#include "../../../libs/dominios/dominios.hpp"

class IServicoDadosHistoricos {
public:
    virtual ~IServicoDadosHistoricos() = default;
    virtual double getPrecoMedioNaData(const CodigoNegociacao& codNegociacao, const Data& data) = 0;
};

#endif // INTERFACE_SERVICO_DADOS_HISTORICOS_HPP_INCLUDED