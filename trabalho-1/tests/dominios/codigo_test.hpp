#ifndef CODIGO_TEST_HPP_INCLUDED
#define CODIGO_TEST_HPP_INCLUDED

#include <string>

#include "../../src/dominios/dominios.hpp"

class TUCodigo {
    private:
        const static std::string CODIGO_VALIDO;
        const static std::string CODIGO_DIGITO_INVALIDO;
        const static std::string CODIGO_TAMANHO_INVALIDO;
        Codigo *codigo;
        int estado;
        void setUp();
        void tearDown();
        void testarCenarioValido();
        void testarDigitoInvalido();
        void testarTamanhoInvalido();

    public:
        const static int SUCESSO = 1;
        const static int FALHA = -1;
        int run();
};

#endif // CODIGO_TEST_HPP_INCLUDED
