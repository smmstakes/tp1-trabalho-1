#ifndef CPF_TEST_HPP_INCLUDED
#define CPF_TEST_HPP_INCLUDED

#include <string>

#include "../../src/dominios/dominios.hpp"

class TUCPF {
    private:
        const static std::string VALOR_VALIDO;
        const static std::string DIGITO_INVALIDO;
        const static std::string TAMANHO_INVALIDO;
        const static std::string FORMATACAO_INVALIDA;

        CPF *cpf;
        int estado;

        void setUp() {
            cpf = new CPF();
            estado = SUCESSO;
        };

        void tearDown() {
            delete cpf;
        };

        void testarCenarioValido();
        void testarDigitoInvalido();
        void testarTamanhoInvalido();
        void testarFormatacaoInvalida();

    public:
        const static int SUCESSO = 1;
        const static int FALHA = -1;

        int run();
};

#endif // CPF_TEST_HPP_INCLUDED