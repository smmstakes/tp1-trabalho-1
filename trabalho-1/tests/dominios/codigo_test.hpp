#ifndef CODIGO_TEST_HPP_INCLUDED
#define CODIGO_TEST_HPP_INCLUDED

#include <string>

#include "dominios_test.hpp"
#include "../../src/dominios/dominios.hpp"

class TUCodigo:public TUDominio<Codigo> {
    private:
        const static std::string CODIGO_VALIDO;
        const static std::string CODIGO_DIGITO_INVALIDO;
        const static std::string CODIGO_TAMANHO_INVALIDO;

        void testarCenarioValido() override;
        void testarDigitoInvalido();
        void testarTamanhoInvalido();

    public:
        int run() override;
};

#endif // CODIGO_TEST_HPP_INCLUDED
