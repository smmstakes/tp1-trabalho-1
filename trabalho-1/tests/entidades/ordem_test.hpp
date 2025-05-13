#ifndef ORDEM_TEST_HPP_INCLUDED
#define ORDEM_TEST_HPP_INCLUDED

#include <string>

#include "entidades_test.hpp"
#include "../../src/entidades/entidades.hpp"

class TUOrdem : public TUEntidade<Ordem> {
    private:
        const static int QUANTIDADE_VALIDA;
        const static double DINHEIRO_VALIDO;
        const static std::string DATA_VALIDA;
        const static std::string CODIGO_VALIDO;
        const static std::string CODIGO_NEGOCIACAO_VALIDO;

        void setUp() override;
        void testarCenarioValido() override;

    public:
        int run() override;
};


#endif // ORDEM_TEST_HPP_INCLUDED
