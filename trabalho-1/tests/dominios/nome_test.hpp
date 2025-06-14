#ifndef NOME_TEST_HPP_INCLUDED
#define NOME_TEST_HPP_INCLUDED

#include <string>

#include "dominios_test.hpp"
#include "../../libs/dominios/dominios.hpp"

class TUNome:public TUDominio<Nome> {
    private:
        const static std::string VALOR_VALIDO;
        const static std::string DIGITO_INVALIDO;
        const static std::string TAMANHO_INVALIDO;
        const static std::string ESPAÇOS_INVALIDOS;

        void testarCenarioValido() override;
        void testarDigitoInvalido();
        void testarTamanhoInvalido();
        void testarFormatacaoInvalida();

    public:
        int run() override;

// Criado por Jose Artur Nordestino - 180020439
};

#endif // NOME_TEST_HPP_INCLUDED
