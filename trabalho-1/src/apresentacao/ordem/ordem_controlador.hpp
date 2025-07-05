#ifndef ORDEM_CONTROLADOR_HPP_INCLUDED
#define ORDEM_CONTROLADOR_HPP_INCLUDED

/**
 * @file ordem_controlador.hpp
 * @brief Implementação do controlador de apresentação de Ordem para console.
 * 
 * @details Este arquivo define a classe `CntrlIAOrdem`, que implementa a interface
 * `IAOrdem` para fornecer uma interação com o usuário baseada em linha de comando.
 * 
 * @author Gabriel Castro
 * @date 04/07/2025
 */

#include <ios>
#include <limits>
#include <iomanip>
#include <cstdlib>
#include <iostream>
#include <stdexcept>

#include "../../../libs/dominios/dominios.hpp"
#include "../../../libs/entidades/entidades.hpp"
#include "../../../libs/sessao_usuario/sessao_usuario.hpp"
#include "../../../libs/apresentacao_utils/apresentacao_utils.hpp"

#include "interface_apresentacao_ordem.hpp"

/**
 * @class CntrlIAOrdem
 * @brief Controlador de Apresentação de Ordem para Interface de Console.
 * 
 * @details Implementa a interface `IAOrdem` para gerenciar ordens através de um menu de texto.
 */
class CntrlIAOrdem : public IAOrdem {
private:
    const static int VOLTAR = 0;
    const static int CRIAR_ORDEM = 1;
    const static int EXCLUIR_ORDEM = 2;
    const static int LISTAR_ORDENS = 3;

    ISOrdem* servicoOrdem;
    Codigo codigoCarteira;

    void mostrarOpcoes() override;
    bool escolherOpcao(int) override;

    void criarOrdem() override;
    void excluirOrdem() override;
    void listarOrdens() override;
    void solicitarCodigoCarteira();

public:
    /**
     * @brief Solicita a exclusão de todas as ordens do usuário quando da exclusão de conta.
     */
    void excluirOrdensUsuario() override;
    
    /**
     * @brief Inicia o loop de interação do menu de carteiras no console.
     */
    void executar() override;

    /**
     * @brief Define a dependência da camada de serviço.
     * 
     * @param servicoOrdem Ponteiro para o serviço de ordem.
     */
    void setCntrlISOrdem(ISOrdem* servicoOrdem) override {
        this->servicoOrdem = servicoOrdem;
    };
};

#endif  // ORDEM_CONTROLADOR_HPP_INCLUDED