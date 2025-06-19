#ifndef CARTEIRA_REPOSITORIO_HPP_INCLUDED
#define CARTEIRA_REPOSITORIO_HPP_INCLUDED

#include <string>
#include <vector>
#include <memory>
#include <iostream>
#include <stdexcept>

#include "../../../libs/sqlite/sqlite3.h"
#include "../../../libs/comandoSQL/comandoSQL.hpp"
#include "../../../libs/sessao_usuario/sessao_usuario.hpp"

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

    bool excluirCarteira(const std::string& codigo, const std::string& cpfUsuario) override;

    std::vector<Carteira> listarCarteiras(const std::string& cpf) override;
};

#endif  // CARTEIRA_REPOSITORIO_HPP_INCLUDED
