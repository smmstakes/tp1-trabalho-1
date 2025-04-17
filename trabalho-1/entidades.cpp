#include <string>
#include "entidades.hpp"

Carteira::Carteira (const std::string& codigo, const std::string& nome, 
    const std::string& perfil) : codigo{}, nome{}, perfil {} {
        this->codigo.set(codigo);
        this->nome.set(nome);
        this->perfil.set(perfil);
    }
