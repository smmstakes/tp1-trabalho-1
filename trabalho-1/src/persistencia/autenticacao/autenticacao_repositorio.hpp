#ifndef AUTENTICACAO_REPOSITORIO_HPP_INCLUDED
#define AUTENTICACAO_REPOSITORIO_HPP_INCLUDED

/**
 * @file autenticacao_repositorio.hpp
 * @brief Implementação do repositório de Autenticação para o banco de dados SQLite.
 *
 * @details Este arquivo define a classe `RepositorioIPAutenticacao`, que implementa
 * a interface `IPAutenticacao` e é responsável por traduzir as operações de autenticação
 * em comandos SQL para o SQLite, gerenciando a persistência dos dados da
 * entidade `Conta`.
 *
 * @author Jose Artur Nordestino
 * @date 04/07/2025
 */


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

/**
 * @class RepositorioIPAutenticacao
 * @brief Implementação concreta do repositório de Autenticação para SQLite.
 *
 * @details Esta classe implementa os métodos definidos na interface `IPAutenticacao`,
 * utilizando a classe `ComandoSQL` para interagir com o banco de dados SQLite.
 */

class RepositorioIPAutenticacao : public IPAutenticacao {
    private:
        GerenciadorBD& gerenciadorBD;
        
    public:
        /**
         * @brief Construtor padrão. Obtém a instância do gerenciador de banco de dados.
         */
        RepositorioIPAutenticacao();  

        void registrarContaUsuario(const std::string& cpf, const std::string& nome, const std::string& senha) override;
        bool getCPF(const std::string& cpf) override;
        bool getSenha(const std::string& cpf, const std::string& senha) override;
        std::string getNome(const std::string& cpf) override;

};

#endif  // AUTENTICACAO_REPOSITORIO_HPP_INCLUDED
