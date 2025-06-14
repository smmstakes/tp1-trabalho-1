#ifndef INTERFACE_REPOSITORIO_CARTEIRA_HPP_INCLUDED
#define INTERFACE_REPOSITORIO_CARTEIRA_HPP_INCLUDED

#include <string>

class IPCarteira {
    public:
        virtual ~IPCarteira() = default;

        virtual void criarCarteira(const std::string& codigo, const std::string& nome, const std::string& perfil) = 0;
        virtual std::string obterUltimoCodigoCarteiraInserido() = 0;
};

#endif  // INTERFACE_REPOSITORIO_CARTEIRA_HPP_INCLUDED
