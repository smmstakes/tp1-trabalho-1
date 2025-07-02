#ifndef AUTENTICACAO_REPOSITORIO_HPP_INCLUDED
#define AUTENTICACAO_REPOSITORIO_HPP_INCLUDED

#include <string>
#include <vector>
#include <memory>
#include <iostream>
#include <stdexcept>

#include "../../../libs/sqlite/sqlite3.h"
#include "../../../libs/comandoSQL/comandoSQL.hpp"
#include "../../../libs/sessao_usuario/sessao_usuario.hpp"

#include "../gerenciador_bd.hpp"

#include "interface_repositorio_autenticacao.hpp"

class RepositorioIPAutenticacao : public IPAutenticacao {
    private:
        GerenciadorBD& gerenciadorBD;
        
    public:
        RepositorioIPAutenticacao();  

        void registrarContaUsuario(const std::string& cpf, const std::string& nome, const std::string& senha) override;
        bool getCPF(const std::string& cpf) override;
        bool getSenha(const std::string& cpf, const std::string& senha) override;

};

#endif  // AUTENTICACAO_REPOSITORIO_HPP_INCLUDED
