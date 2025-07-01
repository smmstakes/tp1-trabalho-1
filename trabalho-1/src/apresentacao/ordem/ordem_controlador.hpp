#ifndef ORDEM_CONTROLADOR_HPP_INCLUDED
#define ORDEM_CONTROLADOR_HPP_INCLUDED

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

public:
    void executar(const Codigo& codigoCarteira) override;
    void setCntrlISOrdem(ISOrdem* servicoOrdem) override {
        this->servicoOrdem = servicoOrdem;
    };
};

#endif  // ORDEM_CONTROLADOR_HPP_INCLUDED