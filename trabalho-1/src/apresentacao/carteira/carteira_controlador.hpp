#ifndef CARTEIRA_CONTROLADOR_HPP_INCLUDED
#define CARTEIRA_CONTROLADOR_HPP_INCLUDED

#include <ios>
#include <limits>
#include <iostream>
#include <stdexcept>

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
    
    bool criarCarteira() override;
    bool lerCarteira() override;
    bool editarCarteira() override;
    bool excluirCarteira() override;
    bool listarCarteira() override;

public:
    void executar() override;
    void setCntrlISCarteira(ISCarteira* servicoCarteira) override {
        this->servicoCarteira = servicoCarteira;
    };
};

#endif  // CARTEIRA_CONTROLADOR_HPP_INCLUDED
