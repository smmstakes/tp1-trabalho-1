#ifndef DATA_TEST_HPP_INCLUDED
#define DATA_TEST_HPP_INCLUDED

#include <string>

#include "../../src/dominios/dominios.hpp"
#include "dominios_test.hpp"

class TUData:public TUDominio<Data>{
    private:
        const static std::string VALOR_VALIDO;
        const static std::string DIA_INVALIDO;
        const static std::string MES_INVALIDO;
        const static std::string ANO_INVALIDO;
        const static std::string FORMATO_INVALIDO;

        void testarCenarioValido() override;
        void testarDiaInvalido();
        void testarMesInvalido();
        void testarAnoInvalido();
        void testarFormatoInvalido();

    public:
        int run() override;
};

#endif // DATA_TEST_HPP_INCLUDED
