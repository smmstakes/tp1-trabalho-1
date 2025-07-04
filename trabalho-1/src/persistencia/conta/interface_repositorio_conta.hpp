#ifndef INTERFACE_REPOSITORIO_CONTA_HPP_INCLUDED
#define INTERFACE_REPOSITORIO_CONTA_HPP_INCLUDED

/**
 * @file interface_repositorio_conta.hpp
 * @brief Define a interface integradora para a camada de persistência de Conta.
 *
 * @details Este arquivo declara a classe abstrata `IPConta`, que serve como
 * gerenciador de armazenamento e para a recuperação de dados da entidade `Conta`. 
 * Ele desacopla a camada de serviço dos detalhes de implementação do banco de dados.
 *
 * @author Pedro Vale
 * @date 03/07/2025
 */

#include <string>
#include <optional>


#include "../../../libs/tipos/estruturas.hpp"
#include "../../../libs/dominios/dominios.hpp"
#include "../../../libs/entidades/entidades.hpp"

/**
 * @class IPConta
 * @brief Interface Abstrata para o Repositório da entidade Conta.
 *
 * @details Define o conjunto de operações de persistência de dados (CRUD)
 * que podem ser realizadas com as contas. Por meio dessa interface o 
 * usuário é capaz de editar nome e senha, ler dados da conta e exclui-la
 */

class IPConta {
public:

    /**
     * @brief Destrutor virtual padrão.
     */

    virtual ~IPConta() = default;

    /**
     * @brief Edita o nome referente a conta.
     * 
     * @param cpf O CPF do usuário.
     * @param novoNome O novo Nome do usuário.
     * @return `true` se o nome da conta foi atualizado com sucesso.
     * @return `false` se o nome da conta nao foi atualizada.
     */

    virtual bool editarNomeConta(const std::string& cpf ,const std::string& novoNome) = 0;
    
    /**
     * @brief Edita a senha referente a conta.
     * 
     * @param cpf O CPF do usuário.
     * @param novaSenha A nova senha de usuário.
     * @return `true` se a nova senha da conta foi atualizada com sucesso.
     * @return `false` se a nova senha da conta nao foi atualizada.
     */

    virtual bool editarSenhaConta(const std::string& cpf,const std::string& novaSenha) = 0;

    /**
     * @brief Exclui a conta do usuário.
     * 
     * @param cpf O CPF do usuário
     * @return `true` se a conta foi excluída com sucesso.
     * @return `false` se a conta não foi excluída.
     */

    virtual bool excluirConta(const std::string& cpf) = 0;

    /**
     * @brief Recupera a leitura do CPF referentea à conta.
     * 
     * @param cpf O CPF do usuário
     * @return Retorna o CPF do usuário.
     */

    virtual std::optional<Conta> getConta(const std::string& cpfUsuario) = 0;
};

#endif  // INTERFACE_REPOSITORIO_CONTA_HPP_INCLUDED
