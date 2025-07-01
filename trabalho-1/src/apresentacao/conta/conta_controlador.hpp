#ifndef CONTA_CONTROLADOR_HPP_INCLUDED
#define CONTA_CONTROLADOR_HPP_INCLUDED

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

#include "interface_apresentacao_carteira.hpp"

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
    void excluirConta() override;

public:
    void executar() override;
    void setCntrlISConta(ISConta* servicoConta) override {
        this->servicoConta = servicoConta;
    };
};

#endif  // CONTA_CONTROLADOR_HPP_INCLUDED
