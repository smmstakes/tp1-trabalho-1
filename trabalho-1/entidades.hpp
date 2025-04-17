#ifndef ENTIDADES_HPP_INCLUDED
#define ENTIDADES_HPP_INCLUDED

#include "dominios.hpp"
class Carteira {
    private:
        Codigo codigo;
        Nome nome;
        Perfil perfil;
    public:
        Carteira (const std::string& codigo,const std::string& nome, const std::string& perfil);
        std::string getCodigo() const{return codigo.get();}
        std::string getNome() const {return nome.get();}
        std::string getPerfil() const {return perfil.get();}
};


#endif // ENTIDADES_HPP_INCLUDED
