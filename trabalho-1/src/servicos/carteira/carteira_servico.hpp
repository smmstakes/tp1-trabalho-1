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

public:
    ServicoICarteira(const ServicoICarteira&) = delete;
    ServicoICarteira& operator=(const ServicoICarteira&) = delete;

    static ServicoICarteira& getInstancia();
    void verificarSessao(SessaoUsuario& sessao) override;

    void criarCarteira(const Nome& nome, const Perfil& perfil) override;
    void excluirCarteira(const std::string& codigo) override;
    std::vector<Carteira> listarCarteiras() override;
};

#endif  // CARTEIRA_SERVICO_HPP_INCLUDED
