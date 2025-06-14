#ifndef SENHA_TEST_HPP_INCLUDED
#define SENHA_TEST_HPP_INCLUDED

#include <string>

#include "dominios_test.hpp"
#include "../../libs/dominios/dominios.hpp"

class TUSenha:public TUDominio<Senha> {
    private:
        const static std::string VALOR_VALIDO;
        const static std::string DIGITO_INVALIDO;
        const static std::string TAMANHO_INVALIDO;
        const static std::string CRITERIO_MINIMO_INVALIDO;
        const static std::string CARACTER_DUPLICADO_INVALIDO;

        void testarCenarioValido() override;
        void testarDigitoInvalido();
        void testarTamanhoInvalido();
        void testarCriterioMinimoInvalido();
        void testarCaracterDuplicadoInvalido();

    public:
        int run() override;

// Criado por Matheus Duarte - 211062277
};

#endif // SENHA_TEST_HPP_INCLUDED
