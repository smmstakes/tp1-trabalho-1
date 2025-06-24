#ifndef AUTENTICACAO_SERVICO_HPP_INCLUDED
#define AUTENTICACAO_SERVICO_HPP_INCLUDED

#include "interface_servico_autenticacao.hpp"
#include "../../persistencia/autenticacao/interface_repositorio_autenticacao.hpp" // ainda nao existe persistencia de autenticacao

class ServicoIAutenticar : public ISAutenticacao { 
private:
    IPAutenticacao* persistencia;
    ServicoIAutenticar();

public:
    void autenticar (const CPF& cpf, const Senha& senha) override;
    
};

#endif  // AUTENTICACAO_SERVICO_HPP_INCLUDED