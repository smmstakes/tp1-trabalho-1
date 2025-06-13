#ifndef CARTEIRA_REPOSITORIO_HPP_INCLUDED
#define CARTEIRA_REPOSITORIO_HPP_INCLUDED

#include <string>

#include "../gerenciador_bd.hpp"
#include "interface_repositorio_carteira.hpp"


class RepositorioIPCarteira : public IPCarteira {
private:
    GerenciadorBD& gerenciadorBD;
    RepositorioIPCarteira();    

public:
    RepositorioIPCarteira(const RepositorioIPCarteira&) = delete;
    RepositorioIPCarteira& operator=(const RepositorioIPCarteira&) = delete;

    static RepositorioIPCarteira& getInstancia();
    void criarCarteira(const std::string& codigo, const std::string& nome, const std::string& perfil) override;
    std::string obterUltimoCodigoCarteiraInserido() override;
};

#endif  // CARTEIRA_REPOSITORIO_HPP_INCLUDED
