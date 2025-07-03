#ifndef INTERFACE_APRESENTACAO_CONTA_INCLUDED
#define INTERFACE_APRESENTACAO_CONTA_INCLUDED

#include "../../servicos/conta/interface_servico_conta.hpp"

class IAConta {
protected:
    virtual void mostrarOpcoes() = 0;
    virtual bool escolherOpcao(int) = 0;

    virtual void lerConta() = 0;
    virtual void editarConta() = 0;
    virtual void excluirConta() = 0;

public:
    virtual void executar() = 0;

    virtual void setCntrlISConta(ISConta*) = 0;

    virtual ~IAConta() {};
};


#endif // INTERFACE_APRESENTACAO_CONTA_INCLUDED