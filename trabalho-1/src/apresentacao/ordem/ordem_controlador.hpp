#ifndef ORDEM_CONTROLADOR_HPP_INCLUDED
#define ORDEM_CONTROLADOR_HPP_INCLUDED

#include <ios>
#include <limits>
#include <iostream>
#include <stdexcept>

#include "interface_apresentacao_ordem.hpp"

class CntrlIAOrdem : public IAOrdem {
private:
    // Códigos de serviços
    const static int VOLTAR = 0;
    const static int CRIAR_ORDEM = 1;
    const static int LER_ORDEM = 2;
    const static int EXCLUIR_ORDEM = 3;
    const static int LISTAR_ORDEM = 4;

    ISOrdem *servicoOrdem;

    void mostrarOpcoes() override;
    bool escolherOpcao(int) override;

    bool criarOrdem() override;
    bool lerOrdem() override;
    bool excluirOrdem() override;
    bool listarOrdem() override;

public:
    void executar() override;
    void setCntrlISOrdem (ISOrdem* servicoOrdem) override {
        this->servicoOrdem = servicoOrdem;
    };
};

#endif // ORDEM_CONTROLADOR_HPP_INCLUDED