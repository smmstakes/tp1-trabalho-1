#ifndef DINHEIRO_TEST_HPP_INCLUDED
#define DINHEIRO_TEST_HPP_INCLUDED

#include "dominios_test.hpp"
#include "../../src/dominios/dominios.hpp"

class TUDinheiro: public TUDominio<Dinheiro>{
    private:
        const static double DINHEIRO_VALIDO;
        const static double DINHEIRO_TAMANHO_INVALIDO;
        const static double DINHEIRO_VALOR_INVALIDO;

        void testarCenarioValido() override;
        void testarTamanhoInvalido();
        void testarValorInvalido();
    public:
        int run() override;
};

#endif //DINHEIRO_TEST_HPP_INCLUDED