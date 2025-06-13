#ifndef INTERFACE_SERVICO_CARTEIRA_HPP_INCLUDED
#define INTERFACE_SERVICO_CARTEIRA_HPP_INCLUDED

#include <string>

#include "../../../libs/dominios/dominios.hpp"

class ISCarteira {
public:
    virtual void criarCarteira(const Nome& nome, const Perfil& perfil) = 0;
};

#endif // INTERFACE_SERVICO_CARTEIRA_HPP_INCLUDED
