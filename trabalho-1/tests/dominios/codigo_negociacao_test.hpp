#ifndef CODIGO_NEGOCIACAO_TEST_HPP_INCLUDED
#define CODIGO_NEGOCIACAO_TEST_HPP_INCLUDED

#include <string>

#include "dominios_test.hpp"
#include "../../libs/dominios/dominios.hpp"

class TUCodigoNegociacao:public TUDominio<CodigoNegociacao>{
    private:
        const static std::string VALOR_VALIDO;
        const static std::string DIGITO_INVALIDO;
        const static std::string TAMANHO_INVALIDO;

        void testarCenarioValido() override;
        void testarDigitoInvalido();
        void testarTamanhoInvalido();

    public:
        int run() override;

// Criado por Matheus Duarte - 211062277
};

#endif // CODIGO_NEGOCIACAO_TEST_HPP_INCLUDED
