#ifndef SESSAO_USUARIO_HPP_INCLUDED
#define SESSAO_USUARIO_HPP_INCLUDED

/**
 * @file sessao_usuario.hpp
 * @brief Define a classe de gerenciamento da sessão do usuário global.
 *
 * @details Este arquivo contém a declaração da classe `SessaoUsuario`, que utiliza
 * o padrão de projeto Singleton para garantir uma única instância de sessão em
 * toda a aplicação. Ela é responsável por manter o estado de autenticação,
 * ou seja, qual usuário está logado no sistema em um dado momento.
 * O uso de `std::optional` torna o gerenciamento do estado de login mais seguro
 * e explícito.
 *
 * @author Matheus Duarte
 * @date 03/07/2025
 */

#include <optional>
#include <stdexcept>
#include "../entidades/entidades.hpp"

/**
 * @class SessaoUsuario
 * @brief Gerencia a sessão do usuário atualmente autenticado na aplicação.
 *
 * @details Implementada como um Singleton, esta classe garante que haja apenas uma
 * sessão de usuário ativa por vez. Ela armazena os dados da conta logada e
 * fornece métodos para realizar login, logout, verificar o estado da sessão e
 * obter os dados do usuário logado.
 */
class SessaoUsuario {
private:
    std::optional<Conta> contaLogada;

    SessaoUsuario() = default;

public:
    /**
     * @brief Desabilita o construtor de cópia para garantir uma única instância.
     */
    SessaoUsuario(const SessaoUsuario&) = delete;

    /**
     * @brief Desabilita o operador de atribuição de cópia.
     */
    SessaoUsuario& operator=(const SessaoUsuario&) = delete;

    /**
     * @brief Fornece acesso à instância única (Singleton) da sessão.
     * 
     * @return SessaoUsuario& Uma referência para a instância global de `SessaoUsuario`.
     */
    static SessaoUsuario& getInstance();

     /**
     * @brief Inicia uma sessão para o usuário, armazenando seus dados de conta.
     * 
     * @param conta O objeto `Conta` do usuário que está realizando o login.
     */
    void login(const Conta& conta);

     /**
     * @brief Encerra a sessão do usuário atual, limpando os dados da conta logada.
     */
    void logout();

    /**
     * @brief Verifica se há um usuário atualmente logado no sistema.
     * 
     * @return `true` se existe uma sessão ativa (usuário logado).
     * @return `false` se não há nenhum usuário logado.
     */
    bool estaLogado() const;

    /**
     * @brief Obtém o objeto `Conta` do usuário que está logado.
     * 
     * @return const Conta& Uma referência constante para a conta do usuário logado.
     * 
     * @throw std::runtime_error Se o método for chamado quando nenhum usuário está logado.
     */
    const Conta& getContaLogada() const;
};

#endif // SESSAO_USUARIO_HPP_INCLUDED
