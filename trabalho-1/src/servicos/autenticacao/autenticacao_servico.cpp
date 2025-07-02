#include "autenticacao_servico.hpp"

ServicoIAutenticacao::ServicoIAutenticacao(IPAutenticacao* persistencia) : persistencia(persistencia) {}

void ServicoIAutenticacao::acessarConta(const CPF& cpf, const Senha& senha) {
    if (!persistencia->getCPF(cpf.get())) {
        throw std::runtime_error("CPF não registrado. Pressione 0 para retornar ao menu inicial.");
    }

    if (!persistencia->getSenha(cpf.get(), senha.get())) {
        throw std::runtime_error("Senha incorreta.");
    }

    Conta conta(cpf.get(), senha.get());
    SessaoUsuario& sessao = SessaoUsuario::getInstance();
    sessao.login(conta);
    return;

};

void ServicoIAutenticacao::registrarConta(const CPF& cpf, const Nome& nome, const Senha& senha) {
    if (persistencia->getCPF(cpf.get())) {
        throw std::runtime_error("CPF já registrado. Entre 0 para retornar ao menu inicial.");
    }
    else{
        persistencia->registrarContaUsuario(cpf.get(), nome.get(), senha.get());
    }
};