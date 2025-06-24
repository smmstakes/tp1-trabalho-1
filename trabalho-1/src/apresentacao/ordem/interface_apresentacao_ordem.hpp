#ifndef INTERFACE_APRESENTACAO_ORDEM_HPP_INCLUDED
#define INTERFACE_APRESENTACAO_ORDEM_HPP_INCLUDED

#include <cstdlib>
#include "../../libs/entidades/entidades.hpp"
#include "../../libs/apresentacao_utils/apresentacao_utils.hpp"
#include "../../src/servicos/ordem/interface_servico_ordem.hpp" // nao existe serviço de ordem ainda

class IAOrdem{
    protected:
    virtual void mostrarOpcoes() = 0;
    virtual bool escolherOpcao(int) = 0;

    virtual bool criarOrdem() = 0;
    virtual bool lerOrdem() = 0;
    virtual bool excluirOrdem() = 0;
    virtual bool listarOrdem() = 0;

public:
    virtual void executar() = 0;

    virtual void setCntrlISOrdem(ISOrdem*) = 0;

    virtual ~IAOrdem() {};

};

#endif // INTERFACE_APRESENTACAO_ORDEM_HPP_INCLUDED