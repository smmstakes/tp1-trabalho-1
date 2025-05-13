#ifndef QUANTIDADE_TEST_HPP_INCLUDED
#define QUANTIDADE_TEST_HPP_INCLUDED

#include "dominios_test.hpp"
#include "../../src/dominios/dominios.hpp"

class TUQuantidade: public TUDominio<Quantidade> {
    private:
        const static int VALOR_VALIDO;
        const static int TAMANHO_INVALIDO;
        const static int VALOR_INVALIDO;
        
        void testarCenarioValido() override;
        void testarTamanhoInvalido();
        void testarValorInvalido();

    public:
        int run() override;
};

#endif // QUANTIDADE_TEST_HPP_INCLUDED
