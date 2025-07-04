#ifndef DADOS_HISTORICOS_SERVICO_HPP_INCLUDED
#define DADOS_HISTORICOS_SERVICO_HPP_INCLUDED

#include <map>
#include <string>
#include "interface_servico_dados_historicos.hpp"

class ServicoDadosHistoricos : public IServicoDadosHistoricos {
private:
    std::map<std::string, std::map<std::string, double>> cacheDePrecos;
    void carregarDados();

public:
    ServicoDadosHistoricos();
    double getPrecoMedioNaData(const CodigoNegociacao& codNegociacao, const Data& data) override;
};

#endif // DADOS_HISTORICOS_SERVICO_HPP_INCLUDED