#ifndef AUTENTICACAO_CONTROLADOR_HPP_INCLUDED
#define AUTENTICACAO_CONTROLADOR_HPP_INCLUDED


/**
 * @file autenticacao_controlador.hpp
 * @brief Implementação do controlador de apresentação da autenticação de conta para uso de interface com usuário.
 *
 * @details Este arquivo define a classe `CntrlIAAutenticacao`, que implementa a interface
 * `IAAutenticacao` para fornecer uma interação com o usuário baseada em linha de comando (CLI).
 * É responsável por exibir o menu inicial onde o usuário opta por acessar sua conta ou registrar uma conta chamando os respectivos métodos
 * da camada de serviço.
 *
 * @author Jose Artur Nordestino
 * @date 04/07/2025
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

#include "../../servicos/autenticacao/autenticacao_servico.hpp"

#include "interface_apresentacao_autenticacao.hpp"

/** 
 * @class CntrlIAAutenticacao
 * @brief Controlador de Apresentação da Autenticação de Conta para Interface de Console
 * 
 * @details Implementa a interface `IAAutenticacao` para fazer a interação
 * entre o usuário e a camada de serviço (`ISAutenticacao`).
 */

class CntrlIAAutenticacao : public IAAutenticacao {
private:
    // Códigos de serviços
    const static int SAIR = 0;
    const static int ACESSAR_CONTA = 1;
    const static int REGISTRAR_CONTA = 2;
    
    ISAutenticacao *servicoAutenticacao;

    void mostrarOpcoes() override;
    bool escolherOpcao(int) override;

    bool acessarConta() override;
    bool registrarConta() override;

public:
    /**
     * @brief iniciar a execução do menu inicial pelo módulo de apresentação.
     */
    void executar() override;

    /**
     * @brief Define a dependência da camada de serviço.
     * 
     * @param servicoAutenticacao Ponteiro para o serviço de autenticação.
     */
    void setCntrlISAutenticacao(ISAutenticacao* servicoAutenticacao) override {
        this->servicoAutenticacao = servicoAutenticacao;
    };
};

#endif  // AUTENTICACAO_CONTROLADOR_HPP_INCLUDED
