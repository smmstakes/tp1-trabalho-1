#ifndef ORDEM_REPOSITORIO_HPP_INCLUDED
#define ORDEM_REPOSITORIO_HPP_INCLUDED

/**
 * @file ordem_repositorio.hpp
 * @brief Implementação do repositório de Ordem para o banco de dados SQLite.
 * 
 * @details Este arquivo define a classe `RepositorioIPOrdem`, que implementa
 * a interface `IPOrdem` para gerenciar a persistência dos dados da entidade `Ordem`.
 * 
 * @author Gabriel Castro
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

#include "interface_repositorio_ordem.hpp"

/**
 * @class RepositorioIPOrdem
 * @brief Implementação concreta do repositório de Ordem para SQLite.
 * 
 * @details Esta classe implementa os métodos definidos na interface `IPOrdem`,
 * utilizando a classe `ComandoSQL` para interagir com o banco de dados.
 */
class RepositorioIPOrdem : public IPOrdem {
private:
    GerenciadorBD& gerenciadorBD;

public:
    /**
     * @brief Construtor padrão. Obtém a instância do gerenciador de banco de dados.
     */
    RepositorioIPOrdem();

     // A documentação detalhada dos métodos está na classe de interface (IPOrdem)
    int contarOrdensUsuario(const std::string& cpfUsuario) override;
    std::string obterUltimoCodigoOrdemInserido() override;
    std::vector<Ordem> getOrdensPorCarteira(const std::string& codCarteira) override;

    void criarOrdem(const std::string& cod, const std::string& codNeg, const std::string& data, double preco, 
    int qtd, const std::string& codigoCarteira) override;
    bool excluirOrdem(const std::string& codOrdem, const std::string& codCarteira) override;
    void excluirOrdensUsuario(const std::string& cpf) override;

};

#endif  // ORDEM_REPOSITORIO_HPP_INCLUDED