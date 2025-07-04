#include "autenticacao_servico.hpp"

ServicoIAutenticacao::ServicoIAutenticacao(IPAutenticacao* persistencia) : persistencia(persistencia) {}

void ServicoIAutenticacao::acessarConta(const CPF& cpf, const Senha& senha) {
    if (!persistencia->getCPF(cpf.get())) {
        throw std::runtime_error("CPF não registrado.");
    }

    if (!persistencia->getSenha(cpf.get(), senha.get())) {
        throw std::runtime_error("Senha incorreta.");
    }

    std::string nome = persistencia->getNome(cpf.get());

    Conta conta(cpf.get(), nome, senha.get());
    SessaoUsuario& sessao = SessaoUsuario::getInstance();
    sessao.login(conta);
    return;

};

void ServicoIAutenticacao::registrarConta(const CPF& cpf, const Nome& nome, const Senha& senha) {
    if (persistencia->getCPF(cpf.get())) {
        throw std::runtime_error("CPF já utilizado em outra conta.");
    }
    else{
        persistencia->registrarContaUsuario(cpf.get(), nome.get(), senha.get());
    }
};