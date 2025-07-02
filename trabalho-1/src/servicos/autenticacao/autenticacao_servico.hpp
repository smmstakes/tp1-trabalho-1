#ifndef AUTENTICACAO_SERVICO_HPP_INCLUDED
#define AUTENTICACAO_SERVICO_HPP_INCLUDED

#include <sstream>
#include <iomanip>

#include "../../persistencia/autenticacao/interface_repositorio_autenticacao.hpp"

#include "interface_servico_autenticacao.hpp"

class ServicoIAutenticacao : public ISAutenticacao { 
private:
    IPAutenticacao* persistencia;

    void verificarSessao(SessaoUsuario& sessao);
    std::string getCPFSessao();
    //como vou criar o retorno de estar logado?

public:
    ServicoIAutenticacao(IPAutenticacao* persistencia);

    void acessarConta(const CPF& cpf, const Senha& senha) override;
    void registrarConta(const CPF& cpf, const Nome& nome, const Senha& senha) override;
};

#endif  // AUTENTICACAO_SERVICO_HPP_INCLUDED
