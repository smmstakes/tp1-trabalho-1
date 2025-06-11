#ifndef IS_INVESTIMENTOS_HPP_INCLUDED
#define IS_INVESTIMENTOS_HPP_INCLUDED
#include "../../dominios/dominios.hpp"

#include <string>

class ISInvestimentos {
    public:
        virtual void criarCarteira(const Nome& nome, const Perfil& perfil) = 0;
};

#endif // IS_INVESTIMENTOS_HPP_INCLUDED