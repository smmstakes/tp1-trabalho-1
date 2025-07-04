#ifndef CONTA_SERVICO_HPP_INCLUDED
#define CONTA_SERVICO_HPP_INCLUDED

/**
 * @file conta_servico.hpp
 * @brief Implementação da camada de serviço para a entidade Conta.
 *
 * @details Este arquivo define a classe `ServicoIConta`, que implementa a
 * interface `ISConta` e contém a lógica de negócio principal para
 * o gerenciamento de contas. 
 * Ela coordena as operações, aplica regras de negócio e interage com a camada de persistência.
 *
 * @author Pedro Vale
 * @date 03/07/2025
 */

#include <sstream>
#include <iomanip>

#include "../../persistencia/conta/interface_repositorio_conta.hpp"

#include "interface_servico_conta.hpp"

/**
 * @class ServicoIConta
 * @brief Implementação concreta do serviço de negócio de Conta.
 *
 * @details Esta classe implementa os métodos definidos em `ISConta`,
 * atuando como um intermediário entre a camada de apresentação e a de persistência,
 * garantindo que todas as regras de negócio sejam cumpridas.
 */

class ServicoIConta : public ISConta { 
private:
    IPConta* persistencia;

    void verificarSessao(SessaoUsuario& sessao);
    std::string getCPFSessao();

public:
    
    /**
     * @brief Construtor que recebe a dependência da camada de persistência.
     * 
     * @param persistencia Ponteiro para uma implementação de `IPConta`.
     */

    ServicoIConta(IPConta* persistencia);
    //Metodos já documentados na Interface
    void editarNomeConta(Nome& novoNome) override;
    void editarSenhaConta(Senha& novaSenha) override;
    void excluirContaLogada() override;
    Conta lerConta() override;
};

#endif  // CONTA_SERVICO_HPP_INCLUDED
