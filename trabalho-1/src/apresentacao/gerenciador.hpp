#ifndef GERENCIADOR_SISTEMA_HPP_INCLUDED
#define GERENCIADOR_SISTEMA_HPP_INCLUDED

#include <memory>
#include <iostream>

#include "../persistencia/gerenciador_bd.hpp"
#include "../servicos/carteira/carteira_servico.hpp"
#include "../apresentacao/carteira/carteira_controlador.hpp"
#include "../persistencia/carteira/carteira_repositorio.hpp"

// Importações de carteira
#include "../persistencia/carteira/carteira_repositorio.hpp"
#include "../servicos/carteira/carteira_servico.hpp"
#include "./carteira/carteira_controlador.hpp"


class GerenciadorSistema {
    private:
        void simularLogin();

        void inicializarCarteira();
        void inicializarConta();

        std::unique_ptr<RepositorioIPCarteira> repoCarteira;
        std::unique_ptr<ServicoICarteira> servicoCarteira;
        std::unique_ptr<CntrlIACarteira> ctrlCarteira;

    public:
        void inicializar();
        void executar();

};


#endif // GERENCIADOR_SISTEMA_HPP_INCLUDED
