#ifndef SESSAO_USUARIO_HPP_INCLUDED
#define SESSAO_USUARIO_HPP_INCLUDED

#include <optional>
#include <stdexcept>
#include "../entidades/entidades.hpp"

class SessaoUsuario {
private:
    std::optional<Conta> contaLogada;

    SessaoUsuario();

public:
    SessaoUsuario(const SessaoUsuario&) = delete;
    SessaoUsuario& operator=(const SessaoUsuario&) = delete;

    static SessaoUsuario& getInstance();

    void login(const Conta& conta);
    void logout();
    bool estaLogado() const;

    const Conta& getContaLogada() const;
};

#endif // SESSAO_USUARIO_HPP_INCLUDED
