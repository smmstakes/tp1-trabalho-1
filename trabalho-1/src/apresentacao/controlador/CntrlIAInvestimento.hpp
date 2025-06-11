#ifndef CNTRLIAINVESTIMENTO_HPP_INCLUDED
#define CNTRLIAINVESTIMENTO_HPP_INCLUDED

#include <ios>
#include <limits>
#include <iostream>
#include <stdexcept>

#include "../interface/IAInvestimento.hpp"

class CntrlIAInvestimento:public IAInvestimento {
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

        ISInvestimento *cntrlISInvestimento;

        void mostrarOpcoes();
        bool escolherOpcao(int, const CPF&);

    public:
        void executar(const CPF&);
        void setCntrlISInvestimento(ISInvestimento* cntrlISInvestimento) {
            this->cntrlISInvestimento = cntrlISInvestimento;
        };
};

#endif  // CNTRLIAINVESTIMENTO_HPP_INCLUDED
