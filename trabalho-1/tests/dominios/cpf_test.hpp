#ifndef CPF_TEST_HPP_INCLUDED
#define CPF_TEST_HPP_INCLUDED

#include <string>

#include "dominios_test.hpp"
#include "../../src/dominios/dominios.hpp"

class TUCPF:public TUDominio<CPF> {
    private:
        const static std::string VALOR_VALIDO;
        const static std::string DIGITO_INVALIDO;
        const static std::string TAMANHO_INVALIDO;
        const static std::string FORMATACAO_INVALIDA;

        void testarCenarioValido();
        void testarDigitoInvalido();
        void testarTamanhoInvalido();
        void testarFormatacaoInvalida();

    public:
        int run();
};

#endif // CPF_TEST_HPP_INCLUDED