#ifndef CONTA_CONTROLADOR_HPP_INCLUDED
#define CONTA_CONTROLADOR_HPP_INCLUDED

/**
 * @file conta_controlador.hpp
 * @brief Implementação do controlador de apresentação de Conta para uso de interface com usuário.
 *
 * @details Este arquivo define a classe `CntrlIAConta`, que implementa a interface
 * `IAConta` para fornecer uma interação com o usuário baseada em linha de comando (CLI).
 * É responsável por exibir o menu da conta onde por meio dela o usuário poderá ter uma interação com suas informações da conta e orquestrar as chamadas
 * para a camada de serviço.
 *
 * @author Pedro Vale
 * @date 03/07/2025
 */

#include <ios>
#include <limits>
#include <cstdlib>
#include <iostream>
#include <stdexcept>

#include "../../../libs/dominios/dominios.hpp"
#include "../../../libs/entidades/entidades.hpp"
#include "../../../libs/sessao_usuario/sessao_usuario.hpp"
#include "../../../libs/apresentacao_utils/apresentacao_utils.hpp"

#include "../../servicos/conta/conta_servico.hpp"

#include "interface_apresentacao_conta.hpp"

/**
 * @class CntrlIAConta
 * @brief Controlador de Apresentação de Conta para Interface de Console.
 *
 * @details Implementa a interface `IAConta` para fazer a interação
 * entre o usuário e a camada de serviço (`ISConta`).
 */

class CntrlIAConta : public IAConta {
private:
    // Códigos de serviços
    const static int VOLTAR = 0;
    const static int LER_CONTA = 1;
    const static int EDITAR_CONTA = 2;
    const static int EXCLUIR_CONTA = 3;

    ISConta *servicoConta;

    void mostrarOpcoes() override;
    bool escolherOpcao(int) override;

    void lerConta() override;
    void editarConta() override;
    void solicitarExclusaoConta() override;

public:
    /**
     * @brief Exclui a conta do usuário logado.
     */
    void excluirConta() override;

    /**
     * @brief Iniciar a execução do menu de conta 
     * pelo módulo de apresentação.
     */

    void executar() override;

    /**
     * @brief Define a dependência da camada de serviço.
     * 
     * @param servicoConta Ponteiro para o serviço de conta.
     */

    void setCntrlISConta(ISConta* servicoConta) override {
        this->servicoConta = servicoConta;
    };
};



#endif  // CONTA_CONTROLADOR_HPP_INCLUDED
