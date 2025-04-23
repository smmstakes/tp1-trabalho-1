#ifndef DOMINIO_TEST_HPP_INCLUDED
#define DOMINIO_TEST_HPP_INCLUDED

#include <string>

#include "../../src/dominios/dominios.hpp"

template<typename Tipo>
class TUDominio {
    private:
        Tipo *valor;
        int estado;

        void setUp() {
            valor = new Tipo();
            estado = SUCESSO;
        };
        void tearDown() { delete valor };
        void testarCenarioValido();
        // void testarDigitoInvalido();
        // void testarTamanhoInvalido();
        // void testarFormatacaoInvalida();

    public:
        const static int SUCESSO = 1;
        const static int FALHA = -1;

        virtual int run() = 0;
};

#endif // DOMINIO_TEST_HPP_INCLUDED