#ifndef APLICACAO_CONTROLADOR_HPP_INCLUDED
#define APLICACAO_CONTROLADOR_HPP_INCLUDED

#include <memory>
#include <iostream>

#include "../persistencia/gerenciador_bd.hpp"
#include "../../libs/tipos/estruturas.hpp"

// Importações de carteira
#include "../persistencia/carteira/carteira_repositorio.hpp"
#include "../servicos/carteira/carteira_servico.hpp"
#include "./carteira/carteira_controlador.hpp"

// Importações de ordem
#include "../persistencia/ordem/ordem_repositorio.hpp"
#include "../servicos/ordem/ordem_servico.hpp"
#include "./ordem/ordem_controlador.hpp"

// Importações de autenticacao
#include "../persistencia/autenticacao/autenticacao_repositorio.hpp"
#include "../servicos/autenticacao/autenticacao_servico.hpp"
#include "./autenticacao/autenticacao_controlador.hpp"

// Importações de conta
#include "../persistencia/conta/conta_repositorio.hpp"
#include "../servicos/conta/conta_servico.hpp"
#include "./conta/conta_controlador.hpp"

// Importações de dados históricos
#include "../servicos/dados_historicos/dados_historicos_servico.hpp"

/**
 * @file gerenciador.hpp
 * @brief Declaração do gerenciador principal do sistema.
 * 
 * @details Define a classe responsável por iniciar e coordenar os módulos do sistema.
 * 
 * @author Suyanne Miranda
 * @date 04/07/2025
 */

/**
 * @class CntrlIAAplicacao
 * @brief Coordena a inicialização e execução dos módulos da aplicação.
 * 
 * @details Responsável por instanciar repositórios, serviços e controladores,
 * e por gerenciar o fluxo principal entre autenticação, carteiras, ordens, contas e dados históricos.
 */
class CntrlIAAplicacao {
    private:
        void inicializarAutenticacao();
        void inicializarCarteira();
        void inicializarOrdem();
        void inicializarConta();
        void inicializarDadosHistoricos();

        std::unique_ptr<RepositorioIPAutenticacao> repoAutenticacao;
        std::unique_ptr<ServicoIAutenticacao> servicoAutenticacao;
        std::unique_ptr<CntrlIAAutenticacao> ctrlAutenticacao;

        std::unique_ptr<RepositorioIPCarteira> repoCarteira;
        std::unique_ptr<ServicoICarteira> servicoCarteira;
        std::unique_ptr<CntrlIACarteira> ctrlCarteira;

        std::unique_ptr<RepositorioIPOrdem> repoOrdem;
        std::unique_ptr<ServicoIOrdem> servicoOrdem;
        std::unique_ptr<CntrlIAOrdem> ctrlOrdem;

        std::unique_ptr<RepositorioIPConta> repoConta;
        std::unique_ptr<ServicoIConta> servicoConta;
        std::unique_ptr<CntrlIAConta> ctrlConta;

        std::unique_ptr<ServicoDadosHistoricos> servicoDadosHistoricos;
    public:
        /**
         * @brief Inicializa todos os módulos do sistema.
         * 
         * @details Cria as instâncias de repositórios, serviços e controladores.
         */
        void inicializar();

        /**
         * @brief Executa o fluxo principal do sistema.
         * 
         * @details Inicia pelo menu de autenticação e segue para os menus das funcionalidades.
         */
        void executar();
};


#endif // APLICACAO_CONTROLADOR_HPP_INCLUDED
