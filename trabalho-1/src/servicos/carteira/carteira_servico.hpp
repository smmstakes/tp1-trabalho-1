#ifndef CARTEIRA_SERVICO_HPP_INCLUDED
#define CARTEIRA_SERVICO_HPP_INCLUDED

#include <sstream>
#include <iomanip>

#include "../../persistencia/carteira/interface_repositorio_carteira.hpp"

#include "interface_servico_carteira.hpp"

class ServicoICarteira : public ISCarteira { 
private:
    IPCarteira* persistencia;

    void verificarSessao(SessaoUsuario& sessao);
    std::string getCPFSessao();
    std::vector<Ordem> getOrdensCarteira(const std::string codCarteira);

public:
    ServicoICarteira(IPCarteira* persistencia);
    
    void criarCarteira(const Nome& nome, const Perfil& perfil) override;
    void editarNomeCarteira(const std::string& codigo, const Nome& novoNome) override;
    void editarPerfilCarteira(const std::string& codigo, const Perfil& novoPerfil) override;
    void excluirCarteira(const std::string& codigo) override;
    std::vector<CarteiraComValor> getCarteiras() override;
};

#endif  // CARTEIRA_SERVICO_HPP_INCLUDED
