#ifndef INTERFACE_REPOSITORIO_CARTEIRA_HPP_INCLUDED
#define INTERFACE_REPOSITORIO_CARTEIRA_HPP_INCLUDED

/**
 * @file interface_repositorio_carteira.hpp
 * @brief Define a interface (contrato) para a camada de persistência de Carteira.
 *
 * @details Este arquivo declara a classe abstrata `IPCarteira`, que serve como
 * um contrato para qualquer classe de repositório que gerencie o armazenamento
 * e a recuperação de dados da entidade `Carteira`. 
 * Ele desacopla a camada de serviço dos detalhes de implementação do banco de dados.
 *
 * @author Matheus Duarte
 * @date 03/07/2025
 */

#include <string>

#include "../../../libs/tipos/estruturas.hpp"
#include "../../../libs/dominios/dominios.hpp"
#include "../../../libs/entidades/entidades.hpp"

/**
 * @class IPCarteira
 * @brief Interface Abstrata para o Repositório da entidade Carteira.
 *
 * @details Define o conjunto de operações de persistência de dados (CRUD)
 * que podem ser realizadas com as carteiras.
 */
class IPCarteira {
public:
    /**
     * @brief Destrutor virtual padrão.
     */
    virtual ~IPCarteira() = default;

    /**
     * @brief Conta o número de carteiras associadas a um CPF.
     * 
     * @param cpfUsuario O CPF do usuário.
     * 
     * @return int O número total de carteiras que o usuário possui.
     */
    virtual int contarCarteirasUsuario(const std::string& cpfUsuario) = 0;

    /**
     * @brief Obtém o código da última carteira inserida no banco de dados.
     * 
     * @return string O código da última carteira, ou uma string vazia se não houver nenhuma.
     */
    virtual std::string obterUltimoCodigoCarteiraInserido() = 0;

    /**
     * @brief Recupera todas as ordens de uma carteira específica.
     * 
     * @param codCarteira O código da carteira.
     * 
     * @return vector<Ordem> Um vetor contendo todas as ordens da carteira.
     */
    virtual std::vector<Ordem> getOrdensCarteira(const std::string codCarteira) = 0;

    /**
     * @brief Insere uma nova carteira no banco de dados.
     * 
     * @param codigo O código único da nova carteira.
     * @param nome O nome da carteira.
     * @param perfil O perfil de investidor da carteira.
     * @param cpfUsuario O CPF do proprietário da carteira.
     */
    virtual void criarCarteira(const std::string& codigo, const std::string& nome, const std::string& perfil, const std::string& cpfUsuario) = 0;

    /**
     * @brief Atualiza o nome de uma carteira existente.
     * 
     * @param codigo O código da carteira a ser editada.
     * @param cpfUsuario O CPF do proprietário, para verificação de permissão.
     * @param novoNome O novo nome a ser atribuído à carteira.
     * 
     * @return `true` se a atualização foi bem-sucedida (uma linha afetada).
     * @return `false` se a carteira não foi encontrada ou não pertence ao usuário.
     */
    virtual bool editarNomeCarteira(const std::string& codigo, const std::string& cpfUsuario, const std::string& novoNome) = 0;

    /**
     * @brief Atualiza o perfil de uma carteira existente.
     * 
     * @param codigo O código da carteira a ser editada.
     * @param cpfUsuario O CPF do proprietário, para verificação de permissão.
     * @param novoPerfil O novo perfil a ser atribuído à carteira.
     * 
     * @return `true` se a atualização foi bem-sucedida.
     * @return `false` se a carteira não foi encontrada ou não pertence ao usuário.
     */
    virtual bool editarPerfilCarteira(const std::string& codigo, const std::string& cpfUsuario, const std::string& novoPerfil) = 0;

    /**
     * @brief Remove uma carteira do banco de dados.
     * 
     * @param codigo O código da carteira a ser excluída.
     * @param cpfUsuario O CPF do proprietário, para verificação de permissão.
     * 
     * @return `true` se a exclusão foi bem-sucedida.
     * @return `false` se a carteira não foi encontrada ou não pertence ao usuário.
     */
    virtual bool excluirCarteira(const std::string& codigo, const std::string& cpfUsuario) = 0;

    /**
     * @brief Recupera todas as carteiras de um usuário, incluindo o valor total de cada uma.
     * 
     * @param cpf O CPF do usuário.
     * 
     * @return vector<CarteiraComValor> Um vetor com as carteiras e seus valores totais.
     */
    virtual std::vector<CarteiraComValor> getCarteiras(const std::string& cpf) = 0;

};

#endif  // INTERFACE_REPOSITORIO_CARTEIRA_HPP_INCLUDED
