#ifndef SENHA_TEST_HPP_INCLUDED
#define SENHA_TEST_HPP_INCLUDED

#include <string>

#include "../../src/dominios/dominios.hpp"

class TUSenha {
    private:
        const static std::string VALOR_VALIDO;
        const static std::string DIGITO_INVALIDO;
        const static std::string TAMANHO_INVALIDO;
        const static std::string CRITERIO_MINIMO_INVALIDO;
        const static std::string CARACTER_DUPLICADO_INVALIDO;

        Senha *senha;
        int estado;

        void setUp() {
            senha = new Senha();
            estado = SUCESSO;
        }
        
        void tearDown() {
            delete senha;
        }
        
        void testarCenarioValido();
        void testarDigitoInvalido();
        void testarTamanhoInvalido();
        void testarCriterioMinimoInvalido();
        void testarCaracterDuplicadoInvalido();

    public:
        const static int SUCESSO = 1;
        const static int FALHA = -1;

        int run();
};

#endif // SENHA_TEST_HPP_INCLUDED
