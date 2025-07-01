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

void ServicoIConta::editarNomeConta(const Nome& novoNome) {
    std::string cpfUsuario= getCPFSessao();

    bool sucesso = persistencia->editarNomeConta(cpfUsuario, novoNome.get());

    if (!sucesso) {
        throw std::runtime_error("Não foi possível realizar a ação.");
    }
}

void ServicoIConta::editarSenhaConta(const Senha& novaSenha){
    std::string cpfUsuario = getCPFSessao();

    bool sucesso = persistencia->editarSenhaConta(cpfUsuario, novaSenha.get());

    if (!sucesso) {
        throw std::runtime_error("Não foi possível realizar a ação.");
    }
}

void ServicoIConta::excluirConta(const CPF& cpfUsuario) {

    if(!persistencia->excluirConta(cpfUsuario))
        throw std::invalid_argument("Não foi possível realizar a ação");
}

void ServicoIConta::getConta() {
    std::string cpfUsuario = getCPFSessao();

    return persistencia->getConta(cpfUsuario);
}