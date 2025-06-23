#ifndef INTERFACE_APRESENTACAO_CARTEIRA_HPP_INCLUDED
#define INTERFACE_APRESENTACAO_CARTEIRA_HPP_INCLUDED

#include "../../servicos/carteira/interface_servico_carteira.hpp"

class IACarteira {
protected:
    virtual void mostrarOpcoes() = 0;
    virtual bool escolherOpcao(int) = 0;

    virtual void criarCarteira() = 0;
    virtual void lerCarteira() = 0;
    virtual void editarCarteira() = 0;
    virtual void excluirCarteira() = 0;
    virtual void listarCarteiras() = 0;

public:
    virtual void executar() = 0;

    virtual void setCntrlISCarteira(ISCarteira*) = 0;

    virtual ~IACarteira() {};
};

#endif // INTERFACE_APRESENTACAO_CARTEIRA_HPP_INCLUDED
