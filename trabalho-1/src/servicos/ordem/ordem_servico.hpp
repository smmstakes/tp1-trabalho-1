#ifndef ORDEM_SERVICO_HPP_INCLUDED
#define ORDEM_SERVICO_HPP_INCLUDED

#include <sstream>
#include <iomanip>
#include <vector>
#include <string>

#include "../../servicos/dados_historicos/interface_servico_dados_historicos.hpp"
#include "../../persistencia/carteira/interface_repositorio_carteira.hpp"
#include "../../persistencia/ordem/interface_repositorio_ordem.hpp"
#include "../../../libs/sessao_usuario/sessao_usuario.hpp"

#include "interface_servico_ordem.hpp"

class ServicoIOrdem : public ISOrdem { 
private:
    IPOrdem* persistenciaOrdem;
    IPCarteira* persistenciaCarteira;
    IServicoDadosHistoricos* servicoDados;

    void verificarSessao(SessaoUsuario& sessao);
    std::string getCPFSessao();

public:
    ServicoIOrdem(IPOrdem* persistenciaOrdem, IPCarteira* persistenciaCarteira, IServicoDadosHistoricos* servicoDados);    

    void criarOrdem(const CodigoNegociacao& codNegociacao, const Quantidade& quantidade, const Data& data, const Codigo& codigoCarteira) override;
    void excluirOrdem(const Codigo& codigoOrdem, const Codigo& codigoCarteira) override;
    std::vector<Ordem> listarOrdens(const Codigo& codigoCarteira) override;
};

#endif  // ORDEM_SERVICO_HPP_INCLUDED