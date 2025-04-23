#ifndef DATA_TEST_HPP_INCLUDED
#define DATA_TEST_HPP_INCLUDED

#include <string>

#include "../../src/dominios/dominios.hpp"

class TUData {
    private:
        const static std::string VALOR_VALIDO;
        const static std::string DIA_INVALIDO;
        const static std::string MES_INVALIDO;
        const static std::string ANO_INVALIDO;
        const static std::string FORMATO_INVALIDO;

        Data *data;
        int estado;

        void setUp() {
            data = new Data();
            estado = SUCESSO;
        };

        void tearDown(){
            delete data;
        };

        void testarCenarioValido();
        void testarDiaInvalido();
        void testarMesInvalido();
        void testarAnoInvalido();
        void testarFormatoInvalido();

    public:
        const static int SUCESSO = 1;
        const static int FALHA = -1;
        
        int run();
};

#endif // DATA_TEST_HPP_INCLUDED
