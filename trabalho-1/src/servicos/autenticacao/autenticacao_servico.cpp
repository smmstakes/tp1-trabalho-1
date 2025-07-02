#include "autenticacao_servico.hpp"
#include "../../../libs/sessao_usuario/sessao_usuario.hpp"
#include "../../../libs/sessao_usuario/sessao_usuario.cpp"

ServicoIAutenticacao::ServicoIAutenticacao(IPAutenticacao* persistencia) : persistencia(persistencia) {}

void ServicoIAutenticacao::acessarConta(const CPF& cpf, const Senha& senha) {
    if (!persistencia->getCPF(cpf)) {
        throw std::runtime_error("CPF não registrado. Entre 0 para retornar ao menu inicial.");
    }
    else if (!persistencia->getSenha(cpf, senha)) {
        throw std::runtime_error("Senha incorreta.");
    }
    else{
        sessaoUsuario.login(conta);
        return;
    }
}

void ServicoIAutenticacao::registrarConta(const CPF& cpf, const Nome& nome, const Senha& senha) {
    if (persistencia->getCPF(cpf.get())) {
        throw std::runtime_error("CPF já registrado. Entre 0 para retornar ao menu inicial.");
    }
    else{
        persistencia->registrarContaUsuario(cpf.get(), nome.get(), senha.get());
        //nao entendi os tipos
    }
}