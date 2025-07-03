#ifndef INTERFACE_APRESENTACAO_AUTENTICACAO_HPP_INCLUDED
#define INTERFACE_APRESENTACAO_AUTENTICACAO_HPP_INCLUDED

#include "../../servicos/autenticacao/interface_servico_autenticacao.hpp"

class IAAutenticacao {
protected:

    virtual void mostrarOpcoes() = 0;
    virtual bool escolherOpcao(int) = 0;

    virtual bool acessarConta() = 0;
    virtual void registrarConta() = 0;

public:
    virtual void executar() = 0;

    virtual void setCntrlISAutenticacao(ISAutenticacao*) = 0;

    virtual ~IAAutenticacao() {};
};

#endif // INTERFACE_APRESENTACAO_AUTENTICACAO_HPP_INCLUDED
