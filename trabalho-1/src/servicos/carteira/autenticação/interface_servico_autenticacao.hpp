#ifndef INTERFACE_SERVICO_AUTENTICACAO_HPP_INCLUDED
#define INTERFACE_SERVICO_AUTENTICACAO_HPP_INCLUDED

#include <string>

#include "../../../libs/dominios/dominios.hpp"

class ISAutenticacao {
public:
    virtual void autenticar(const CPF& cpf, const Senha& senha) = 0;
};

#endif // INTERFACE_SERVICO_AUTENTICACAO_HPP_INCLUDED