#ifndef INTERFACE_APRESENTACAO_ORDEM_HPP_INCLUDED
#define INTERFACE_APRESENTACAO_ORDEM_HPP_INCLUDED

#include "../../servicos/ordem/interface_servico_ordem.hpp"

class IAOrdem {
protected:
    virtual void mostrarOpcoes() = 0;
    virtual bool escolherOpcao(int) = 0;

    virtual void criarOrdem() = 0;
    virtual void excluirOrdem() = 0;
    virtual void listarOrdens() = 0;

public:
    virtual void executar(const Codigo& codigoCarteira) = 0;

    virtual void setCntrlISOrdem(ISOrdem*) = 0;
    
    virtual ~IAOrdem() {};
};

#endif // INTERFACE_APRESENTACAO_ORDEM_HPP_INCLUDED
