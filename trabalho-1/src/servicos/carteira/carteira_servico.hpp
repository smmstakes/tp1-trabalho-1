#ifndef CARTEIRA_SERVICO_HPP_INCLUDED
#define CARTEIRA_SERVICO_HPP_INCLUDED

#include <sstream>
#include <iomanip>

#include "../../persistencia/carteira/carteira_repositorio.hpp"

#include "interface_servico_carteira.hpp"

class ServicoICarteira : public ISCarteira { 
private:
    IPCarteira* persistencia;
    ServicoICarteira();

    void verificarSessao(SessaoUsuario& sessao);
    std::string getCPFSessao();
    std::vector<Ordem> getOrdensCarteira(const std::string codCarteira);

public:
    ServicoICarteira(const ServicoICarteira&) = delete;
    ServicoICarteira& operator=(const ServicoICarteira&) = delete;
    static ServicoICarteira& getInstancia();

    void criarCarteira(const Nome& nome, const Perfil& perfil) override;
    void editarNomeCarteira(const std::string& codigo, const Nome& novoNome) override;
    void editarPerfilCarteira(const std::string& codigo, const Perfil& novoPerfil) override;
    void excluirCarteira(const std::string& codigo) override;
    std::vector<CarteiraComValor> getCarteiras() override;
};

#endif  // CARTEIRA_SERVICO_HPP_INCLUDED
