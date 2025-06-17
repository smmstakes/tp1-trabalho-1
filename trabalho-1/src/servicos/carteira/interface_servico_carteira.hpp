#ifndef INTERFACE_SERVICO_CARTEIRA_HPP_INCLUDED
#define INTERFACE_SERVICO_CARTEIRA_HPP_INCLUDED

#include "../../../libs/dominios/dominios.hpp"
#include "../../../libs/entidades/entidades.hpp"

class ISCarteira {
public:
    virtual void criarCarteira(const Nome& nome, const Perfil& perfil) = 0;
    virtual std::vector<Carteira> listarCarteiras() = 0;
};

#endif // INTERFACE_SERVICO_CARTEIRA_HPP_INCLUDED
