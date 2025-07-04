#ifndef DADOS_HISTORICOS_SERVICO_HPP_INCLUDED
#define DADOS_HISTORICOS_SERVICO_HPP_INCLUDED

/**
 * @file dados_historicos_servico.hpp
 * @brief Implementação do serviço de acesso aos dados históricos.
 * 
 * @details Este arquivo define a classe `ServicoDadosHistoricos`, que implementa
 * a interface `IServicoDadosHistoricos`, sendo responsável por carregar e consultar
 * os dados do arquivo de cotações.
 * 
 * @author Gabriel Castro
 * @date 04/07/2025
 */

#include <map>
#include <string>
#include "interface_servico_dados_historicos.hpp"
/**
 * @class ServicoDadosHistoricos
 * @brief Implementação concreta do serviço de dados históricos.
 * 
 * @details Esta classe carrega os dados de um arquivo de texto para um cache em
 * memória na sua inicialização, permitindo consultas rápidas de preços.
 */
class ServicoDadosHistoricos : public IServicoDadosHistoricos {
private:
    std::map<std::string, std::map<std::string, double>> cacheDePrecos;
    void carregarDados();

public:
    /**
     * @brief Construtor que aciona o carregamento dos dados históricos.
     */
    ServicoDadosHistoricos();

    // A documentação detalhada do método está na classe de interface
    double getPrecoMedioNaData(const CodigoNegociacao& codNegociacao, const Data& data) override;
};

#endif // DADOS_HISTORICOS_SERVICO_HPP_INCLUDED