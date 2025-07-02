#ifndef INTERFACE_REPOSITORIO_AUTENTICACAO_HPP_INCLUDED
#define INTERFACE_REPOSITORIO_AUTENTICACAO_HPP_INCLUDED

#include <string>

#include "../../../libs/tipos/estruturas.hpp"
#include "../../../libs/dominios/dominios.hpp"
#include "../../../libs/entidades/entidades.hpp"

class IPAutenticacao {
public:
    virtual ~IPAutenticacao() = default;

    virtual void acessarConta(const std::string& cpf, const std::string& senha) = 0;
    virtual bool registrarConta(const std::string& cpf, const std::string& nome, const std::string& senha) = 0;
    virtual bool getCPF(const CPF& cpf) = 0;
    virtual bool getSenha(const CPF& cpf, const Senha& senha) = 0;

    virtual std::vector<CarteiraComValor> getCarteiras(const std::string& cpf) = 0;
    //ver do que se trata

};

#endif  // INTERFACE_REPOSITORIO_CARTEIRA_HPP_INCLUDED
