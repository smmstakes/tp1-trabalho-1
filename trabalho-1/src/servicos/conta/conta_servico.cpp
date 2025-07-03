#include "conta_servico.hpp"

ServicoIConta::ServicoIConta(IPConta* persistencia) : persistencia(persistencia) {}

void ServicoIConta::verificarSessao(SessaoUsuario& sessao) {
    if (!sessao.estaLogado()) {
        throw std::runtime_error("Usuário não está logado.");
    }
}

std::string ServicoIConta::getCPFSessao() {
    SessaoUsuario& sessao = SessaoUsuario::getInstance();
    verificarSessao(sessao);

    return sessao.getContaLogada().getCpf();
}

void ServicoIConta::editarNomeConta(Nome& novoNome) {
    std::string cpfUsuario= getCPFSessao();

    bool sucesso = persistencia->editarNomeConta(cpfUsuario, novoNome.get());

    if (!sucesso) {
        throw std::runtime_error("Não foi possível realizar a ação.");
    }
}

void ServicoIConta::editarSenhaConta(Senha& novaSenha){
    std::string cpfUsuario = getCPFSessao();

    bool sucesso = persistencia->editarSenhaConta(cpfUsuario, novaSenha.get());

    if (!sucesso) {
        throw std::runtime_error("Não foi possível realizar a ação.");
    }
}

void ServicoIConta::excluirContaLogada() {
    std::string cpfUsuario= getCPFSessao();

    if(!persistencia->excluirConta(cpfUsuario))
        throw std::invalid_argument("Não foi possível realizar a ação");
}

Conta ServicoIConta::lerConta() {
    std::string cpfUsuario = getCPFSessao();
    auto contaOpt = persistencia->getConta(cpfUsuario);

    if (!contaOpt.has_value()) {
        throw std::runtime_error("Conta não encontrada no banco.");
    }

    return contaOpt.value();
}
