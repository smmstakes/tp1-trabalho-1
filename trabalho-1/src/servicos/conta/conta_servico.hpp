#ifndef CONTA_SERVICO_HPP_INCLUDED
#define CONTA_SERVICO_HPP_INCLUDED

#include <sstream>
#include <iomanip>

#include "../../persistencia/carteira/interface_repositorio_carteira.hpp"

#include "interface_servico_conta.hpp"

class ServicoIConta : public ISConta { 
private:
    IPConta* persistencia;

    void verificarSessao(SessaoUsuario& sessao);
    std::string getCPFSessao();

public:
    ServicoIConta(IPConta* persistencia);
    void editarNomeConta(const Nome& novoNome) override;
    void editarSenhaConta(const Senha& novaSenha) override;
    void excluirConta(const CPF& cpf) override;
    void getConta() override;
};

#endif  // CONTA_SERVICO_HPP_INCLUDED
