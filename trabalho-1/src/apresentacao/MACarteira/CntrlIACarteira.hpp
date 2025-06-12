#ifndef CNTRLIACARTEIRA_HPP_INCLUDED
#define CNTRLIACARTEIRA_HPP_INCLUDED

#include <ios>
#include <limits>
#include <iostream>
#include <stdexcept>

#include "IACarteira.hpp"

class CntrlIACarteira:public IACarteira {
    private:
        // Códigos de serviços
        const static int VOLTAR = 0;

        const static int CRIAR_CARTEIRA = 1;
        const static int LER_CARTEIRA = 2;
        const static int EDITAR_CARTEIRA = 3;
        const static int EXCLUIR_CARTEIRA = 4;
        const static int LISTAR_CARTEIRA = 5;

        const static int CRIAR_ORDEM = 6;
        const static int LER_ORDEM = 7;
        const static int EXCLUIR_ORDEM = 8;
        const static int LISTAR_ORDEM = 9;

        ISCarteira *servicoCarteira;

        void mostrarOpcoes() override;
        bool escolherOpcao(int) override;

    public:
        void executar() override;
        void setCntrlISCarteira(ISCarteira* servicoCarteira) override {
            this->servicoCarteira = servicoCarteira;
        };
};

#endif  // CNTRLIACARTEIRA_HPP_INCLUDED
