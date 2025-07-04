#ifndef CARTEIRA_CONTROLADOR_HPP_INCLUDED
#define CARTEIRA_CONTROLADOR_HPP_INCLUDED

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

#include "../../servicos/carteira/carteira_servico.hpp"

#include "interface_apresentacao_carteira.hpp"

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
    void executar() override;
    void setCntrlISCarteira(ISCarteira* servicoCarteira) override {
        this->servicoCarteira = servicoCarteira;
    };
};

#endif  // CARTEIRA_CONTROLADOR_HPP_INCLUDED
