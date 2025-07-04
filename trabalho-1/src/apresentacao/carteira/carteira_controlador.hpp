#ifndef CARTEIRA_CONTROLADOR_HPP_INCLUDED
#define CARTEIRA_CONTROLADOR_HPP_INCLUDED

/**
 * @file carteira_controlador.hpp
 * @brief Implementação do controlador de apresentação de Carteira para interface de console.
 *
 * @details Este arquivo define a classe `CntrlIACarteira`, que implementa a interface
 * `IACarteira` para fornecer uma interação com o usuário baseada em linha de comando (CLI).
 * É responsável por exibir menus, ler entradas do teclado e orquestrar as chamadas
 * para a camada de serviço.
 *
 * @author Matheus Duarte
 * @date 03/07/2025
 */

#include <ios>
#include <limits>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <stdexcept>

#include "../../../libs/dominios/dominios.hpp"
#include "../../../libs/entidades/entidades.hpp"
#include "../../../libs/sessao_usuario/sessao_usuario.hpp"
#include "../../../libs/apresentacao_utils/apresentacao_utils.hpp"

#include "../../servicos/carteira/interface_servico_carteira.hpp"

#include "interface_apresentacao_carteira.hpp"

/**
 * @class CntrlIACarteira
 * @brief Controlador de Apresentação de Carteira para Interface de Console.
 *
 * @details Implementa a interface `IACarteira` para gerenciar carteiras através
 * de um menu de texto. Atua como um elo entre o usuário e a camada de serviço (`ISCarteira`).
 */
class CntrlIACarteira : public IACarteira {
private:
    // Códigos de serviços
    const static int VOLTAR = 0;
    const static int CRIAR_CARTEIRA = 1;
    const static int LER_CARTEIRA = 2;
    const static int EDITAR_CARTEIRA = 3;
    const static int EXCLUIR_CARTEIRA = 4;
    const static int LISTAR_CARTEIRAS = 5;

    ISCarteira *servicoCarteira;

    void mostrarOpcoes() override;
    bool escolherOpcao(int) override;

    void criarCarteira() override;
    void lerCarteira() override;
    void editarCarteira() override;
    void excluirCarteira() override;
    void listarCarteiras() override;

public:
    /**
     * @brief Inicia o loop de interação do menu de carteiras no console.
     */
    void executar() override;

    /**
     * @brief Define a dependência da camada de serviço.
     * 
     * @param servicoCarteira Ponteiro para o serviço de carteira.
     */
    void setCntrlISCarteira(ISCarteira* servicoCarteira) override {
        this->servicoCarteira = servicoCarteira;
    };
};

#endif  // CARTEIRA_CONTROLADOR_HPP_INCLUDED
