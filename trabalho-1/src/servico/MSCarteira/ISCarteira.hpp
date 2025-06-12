#ifndef ISCARTEIRA_HPP_INCLUDED
#define ISCARTEIRA_HPP_INCLUDED
#include "../../dominios/dominios.hpp"

#include <string>

class ISCarteira {
    public:
        virtual void criarCarteira(std::string& nome, const std::string& perfil) = 0;
};

#endif // ISCARTEIRA_HPP_INCLUDED