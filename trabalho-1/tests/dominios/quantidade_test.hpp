#ifndef QUANTIDADE_TEST_HPP_INCLUDED
#define QUANTIDADE_TEST_HPP_INCLUDED

#include "dominios_test.hpp"
#include "../../src/dominios/dominios.hpp"

class TUQuantidade: public TUDominio<Quantidade> {
    private:
        const static int QUANTIDADE_VALIDA;
        const static int QUANTIDADE_TAMANHO_INVALIDO;
        const static int QUANTIDADE_VALOR_INVALIDO;
        
        void testarCenarioValido() override;
        void testarTamanhoInvalido();
        void testarValorInvalido();

    public:
        int run() override;
};

#endif // QUANTIDADE_TEST_HPP_INCLUDED