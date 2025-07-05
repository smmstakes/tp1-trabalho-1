#ifndef AUTENTICACAO_SERVICO_HPP_INCLUDED
#define AUTENTICACAO_SERVICO_HPP_INCLUDED

/**
 * @file autenticacao_servico.hpp
 * @brief Implementação da camada de serviço para a entidade Carteira.
 * 
 * @details Este arquivo define a classe `ServicoIAutenticacao`, que implementa a
 * interface `ISAutenticacao` e contém a lógica de negócio principal para o acesso e 
 * registro de contas.
 * Ela coordena as operações, aplica regras de autenticação e interage com a camada de persistência
 * 
 * @author Jose Artur Nordestino
 * @date 04/07/2025
 */


#include <sstream>
#include <iomanip>

#include "../../persistencia/autenticacao/interface_repositorio_autenticacao.hpp"
#include "../../../libs/sessao_usuario/sessao_usuario.hpp"

#include "interface_servico_autenticacao.hpp"

/**
 * @class ServicoIAutenticacao
 * @brief Implementação concreta do serviço de Autenticação de Conta.
 * 
 * @details Esta classe implementa os métodos definidos em `ISAutenticacao`, 
 * atuando como um intermediário entre a camada de apresentação e a de persistênica,
 * garantindo que todas as regras de autenticação sejam cumpridas.
 */

class ServicoIAutenticacao : public ISAutenticacao { 
private:
    IPAutenticacao* persistencia;

    void verificarSessao(SessaoUsuario& sessao);
    std::string getCPFSessao();

public:
/**
 * @brief Construtor que recebe a dependência da camada de persistência.
 * 
 * @param persistencia Ponteiro para uma implementação de `IPAutenticacao`
 */
    ServicoIAutenticacao(IPAutenticacao* persistencia);

    void acessarConta(const CPF& cpf, const Senha& senha) override;
    void registrarConta(const CPF& cpf, const Nome& nome, const Senha& senha) override;
};

#endif  // AUTENTICACAO_SERVICO_HPP_INCLUDED
