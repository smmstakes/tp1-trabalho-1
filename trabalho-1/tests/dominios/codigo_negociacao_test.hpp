#ifndef CODIGO_NEGOCIACAO_TEST_HPP_INCLUDED
#define CODIGO_NEGOCIACAO_TEST_HPP_INCLUDED

#include <string>

#include "../../src/dominios/dominios.hpp"

class TUCodigoNegociacao {
    private:
        const static std::string CODIGO_VALIDO;
        const static std::string CODIGO_DIGITO_INVALIDO;
        const static std::string CODIGO_TAMANHO_INVALIDO;
        
        CodigoNegociacao *codNegociacao;
        int estado;

        void setUp() {
            codNegociacao = new CodigoNegociacao();
            estado = SUCESSO;
        };

        void tearDown() {
            delete codNegociacao;
        };

        void testarCenarioValido();
        void testarDigitoInvalido();
        void testarTamanhoInvalido();

    public:
        const static int SUCESSO = 1;
        const static int FALHA = -1;

        int run();
};

#endif // CODIGO_NEGOCIACAO_TEST_HPP_INCLUDED
