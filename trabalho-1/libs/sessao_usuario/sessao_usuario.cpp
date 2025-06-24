#include "sessao_usuario.hpp"

SessaoUsuario& SessaoUsuario::getInstance() {
    static SessaoUsuario instancia;
    return instancia;
}

void SessaoUsuario::login(const Conta& conta) {
    this->contaLogada = conta;
}

void SessaoUsuario::logout() {
    // limpa o conteúdo do std::optional
    this->contaLogada.reset();
}

bool SessaoUsuario::estaLogado() const {
    // retorna true se o optional contém um objeto
    return this->contaLogada.has_value();
}

const Conta& SessaoUsuario::getContaLogada() const {
    if (!estaLogado()) {
        throw std::runtime_error("Nenhum usuário está logado para obter a conta.");
    }

    // retorna o objeto contido ou lança exceção se vazio
    return this->contaLogada.value();
}
