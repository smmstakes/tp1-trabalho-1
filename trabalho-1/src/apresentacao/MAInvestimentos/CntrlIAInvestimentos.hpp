#ifndef CNTRLIAINVESTIMENTOS_HPP_INCLUDED
#define CNTRLIAINVESTIMENTOS_HPP_INCLUDED

#include <ios>
#include <limits>
#include <iostream>
#include <stdexcept>

#include "IAInvestimentos.hpp"

class CntrlIAInvestimentos:public IAInvestimentos {
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

        ISInvestimentos *servicoInvestimentos;

        void mostrarOpcoes() override;
        bool escolherOpcao(int) override;

    public:
        void executar() override;
        void setCntrlISInvestimentos(ISInvestimentos* servicoInvestimentos) override {
            this->servicoInvestimentos = servicoInvestimentos;
        };
};

#endif  // CNTRLIAINVESTIMENTOS_HPP_INCLUDED
