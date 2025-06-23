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

    int contarCarteirasUsuario(const std::string& cpfUsuario) override;
    std::string obterUltimoCodigoCarteiraInserido() override;
    std::vector<Ordem> getOrdensCarteira(const std::string codCarteira) override;
    
    void criarCarteira(const std::string& codigo, const std::string& nome, const std::string& perfil, const std::string& cpfUsuario) override;
    bool editarNomeCarteira(const std::string& codigo, const std::string& cpfUsuario, const std::string& novoNome) override;
    bool editarPerfilCarteira(const std::string& codigo, const std::string& cpfUsuario, const std::string& novoPerfil) override;
    bool excluirCarteira(const std::string& codigo, const std::string& cpfUsuario) override;
    std::vector<CarteiraComValor> getCarteiras(const std::string& cpf) override;
};

#endif  // CARTEIRA_REPOSITORIO_HPP_INCLUDED
