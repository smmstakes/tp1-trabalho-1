#ifndef INTERFACE_SERVICO_AUTENTICACAO_HPP_INCLUDED
#define INTERFACE_SERVICO_AUTENTICACAO_HPP_INCLUDED

#include <string>

#include "../../../libs/tipos/estruturas.hpp"
#include "../../../libs/dominios/dominios.hpp"
#include "../../../libs/entidades/entidades.hpp"
#include "../../../libs/sessao_usuario/sessao_usuario.hpp"

class ISAutenticacao {
public:
    virtual ~ISAutenticacao() = default;
    
    virtual void acessarConta(const CPF& cpf, const Senha& senha) = 0;
    virtual void registrarConta(const CPF& cpf, const Nome& nome, const Senha& senha) = 0;
};

#endif // INTERFACE_SERVICO_CARTEIRA_HPP_INCLUDED
