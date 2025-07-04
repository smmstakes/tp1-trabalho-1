#ifndef CONTA_REPOSITORIO_HPP_INCLUDED
#define CONTA_REPOSITORIO_HPP_INCLUDED

/**
 * @file conta_repositorio.hpp
 * @brief Implementação do repositório de Conta para o banco de dados SQLite.
 *
 * @details Este arquivo define a classe `RepositorioIPConta`, que implementa
 * a interface `IPConta` e é responsável por gerenciar a persistência dos dados da
 * entidade `Conta`.
 *
 * @author Pedro Vale
 * @date 03/07/2025
 */

#include <string>
#include <vector>
#include <memory>
#include <iostream>
#include <stdexcept>
#include <optional>

#include "../../../libs/sqlite/sqlite3.h"
#include "../../../libs/comandoSQL/comandoSQL.hpp"
#include "../../../libs/sessao_usuario/sessao_usuario.hpp"

#include "../gerenciador_bd.hpp"

#include "interface_repositorio_conta.hpp"

/**
 * @class RepositorioIPConta
 * @brief Implementação concreta do repositório de Conta para SQLite.
 *
 * @details Esta classe implementa os métodos definidos na interface `IPConta`,
 * utilizando a classe `ComandoSQL` para interagir com o banco de dados SQLite.
 */

class RepositorioIPConta : public IPConta {
private:
    GerenciadorBD& gerenciadorBD;
      
public:
    /**
     * @brief Construtor padrão. Obtém a instância do gerenciador de banco de dados.
     */

    RepositorioIPConta();  
    
    // Implementação dos métodos já documentados na Interface
    bool editarNomeConta(const std::string& cpf, const std::string& nomeNome) override;
    bool editarSenhaConta(const std::string& cpf ,const std::string& novaSenha) override;
    bool excluirConta(const std::string& cpf ) override;
    std::optional<Conta> getConta(const std::string& cpfUsuario) override;

};

#endif  // CONTA_REPOSITORIO_HPP_INCLUDED
