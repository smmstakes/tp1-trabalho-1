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

#include "interface_repositorio_Autenticacao.hpp"

class RepositorioIPAutenticacao : public IPAutenticacao {
private:
    GerenciadorBD& gerenciadorBD;
      
public:
    RepositorioIPAutenticacao();  

    void registrarContaUsuario(const CPF& cpf, const Nome& nome, const Senha& senha);
    bool getCPF(const CPF& cpf);
    bool getSenha(const CPF& cpf, const Senha& senha);

};

#endif  // AUTENTICACAO_REPOSITORIO_HPP_INCLUDED
