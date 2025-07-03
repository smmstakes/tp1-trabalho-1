#ifndef CONTA_SERVICO_HPP_INCLUDED
#define CONTA_SERVICO_HPP_INCLUDED

#include <sstream>
#include <iomanip>

#include "../../persistencia/conta/interface_repositorio_conta.hpp"

#include "interface_servico_conta.hpp"

class ServicoIConta : public ISConta { 
private:
    IPConta* persistencia;

    void verificarSessao(SessaoUsuario& sessao);
    std::string getCPFSessao();

public:
    ServicoIConta(IPConta* persistencia);
    void editarNomeConta(Nome& novoNome) override;
    void editarSenhaConta(Senha& novaSenha) override;
    void excluirContaLogada() override;
    Conta lerConta() override;
};

#endif  // CONTA_SERVICO_HPP_INCLUDED
