#ifndef CARTEIRA_REPOSITORIO_HPP_INCLUDED
#define CARTEIRA_REPOSITORIO_HPP_INCLUDED

/**
 * @file carteira_repositorio.hpp
 * @brief Implementação do repositório de Carteira para o banco de dados SQLite.
 *
 * @details Este arquivo define a classe `RepositorioIPCarteira`, que implementa
 * a interface `IPCarteira` e é responsável por traduzir as operações de negócio
 * em comandos SQL para o SQLite, gerenciando a persistência dos dados da
 * entidade `Carteira`.
 *
 * @author Matheus Duarte
 * @date 03/07/2025
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

#include "interface_repositorio_carteira.hpp"

/**
 * @class RepositorioIPCarteira
 * @brief Implementação concreta do repositório de Carteira para SQLite.
 *
 * @details Esta classe implementa os métodos definidos na interface `IPCarteira`,
 * utilizando a classe `ComandoSQL` para interagir com o banco de dados SQLite.
 */
class RepositorioIPCarteira : public IPCarteira {
private:
    GerenciadorBD& gerenciadorBD;
      
public:
    /**
     * @brief Construtor padrão. Obtém a instância do gerenciador de banco de dados.
     */
    RepositorioIPCarteira();  

    // Apenas implementação dos métodos já documentados na Interface
    int contarCarteirasUsuario(const std::string& cpfUsuario) override;
    std::string obterUltimoCodigoCarteiraInserido() override;
    std::vector<Ordem> getOrdensCarteira(const std::string codCarteira) override;
    
    void criarCarteira(const std::string& codigo, const std::string& nome, const std::string& perfil, const std::string& cpfUsuario) override;
    bool editarNomeCarteira(const std::string& codigo, const std::string& cpfUsuario, const std::string& novoNome) override;
    bool editarPerfilCarteira(const std::string& codigo, const std::string& cpfUsuario, const std::string& novoPerfil) override;
    bool excluirCarteira(const std::string& codigo, const std::string& cpfUsuario) override;
    void excluirCarteirasPorCPF(const std::string& cpfUsuario);
    std::vector<CarteiraComValor> getCarteiras(const std::string& cpf) override;
};

#endif  // CARTEIRA_REPOSITORIO_HPP_INCLUDED
