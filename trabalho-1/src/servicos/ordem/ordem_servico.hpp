#ifndef ORDEM_SERVICO_HPP_INCLUDED
#define ORDEM_SERVICO_HPP_INCLUDED

/**
 * @file ordem_servico.hpp
 * @brief Implementação da camada de serviço para a entidade Ordem.
 * 
 * @details Este arquivo define a classe `ServicoIOrdem`, que implementa a
 * interface `ISOrdem` e contém a lógica de negócio principal para o gerenciamento de ordens.
 * 
 * @author Gabriel Castro
 * @date 04/07/2025
 */

#include <sstream>
#include <iomanip>
#include <vector>
#include <string>

#include "../../servicos/dados_historicos/interface_servico_dados_historicos.hpp"
#include "../../persistencia/carteira/interface_repositorio_carteira.hpp"
#include "../../persistencia/ordem/interface_repositorio_ordem.hpp"
#include "../../../libs/sessao_usuario/sessao_usuario.hpp"

#include "interface_servico_ordem.hpp"

/**
 * @class ServicoIOrdem
 * @brief Implementação concreta do serviço de negócio de Ordem.
 * 
 * @details Esta classe implementa as regras de negócio para ordens, como cálculo de preço
 * e validação de posse, coordenando as operações com a camada de persistência.
 */
class ServicoIOrdem : public ISOrdem { 
private:
    IPOrdem* persistenciaOrdem;
    IPCarteira* persistenciaCarteira;
    IServicoDadosHistoricos* servicoDados;

    void verificarSessao(SessaoUsuario& sessao);
    std::string getCPFSessao();

public:
    /**
     * @brief Construtor que recebe as dependências das camadas inferiores.
     * 
     * @param persistenciaOrdem Ponteiro para o repositório de Ordem.
     * @param persistenciaCarteira Ponteiro para o repositório de Carteira.
     * @param servicoDados Ponteiro para o serviço de dados históricos.
     */
    ServicoIOrdem(IPOrdem* persistenciaOrdem, IPCarteira* persistenciaCarteira, IServicoDadosHistoricos* servicoDados);    

    // Documentação já apresentada na interface
    void criarOrdem(const CodigoNegociacao& codNegociacao, const Quantidade& quantidade, const Data& data, const Codigo& codigoCarteira) override;
    void excluirOrdem(const Codigo& codigoOrdem, const Codigo& codigoCarteira) override;
    void excluirOrdensUsuario() override;
    std::vector<Ordem> listarOrdens(const Codigo& codigoCarteira) override;
};

#endif  // ORDEM_SERVICO_HPP_INCLUDED