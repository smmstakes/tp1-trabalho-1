#ifndef CODIGO_TESTE_HPP_INCLUDED
#define CODIGO_TESTE_HPP_INCLUDED

#include <string>

#include "dominios_test.hpp"
#include "../../src/dominios/dominios.hpp"

class TUPerfil:public TUDominio<Perfil>{
    private:
        const static std::string VALOR_VALIDO;
        const static std::string VALOR_INVALIDO;

        void testarCenarioValido() override;
        void testarCenarioInvalido();
    
    public:
        int run() override;

};

#endif //CODIGO_TESTE_HPP_INCLUDED