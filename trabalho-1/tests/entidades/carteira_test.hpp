#ifndef CARTEIRA_TEST_HPP_INCLUDED
#define CARTEIRA_TEST_HPP_INCLUDED

#include "entidades_test.hpp"
#include "../../src/entidades/entidades.hpp"

#include <string>

class TUCarteira: public TUEntidade <Carteira>{
    private:
        const static std::string CODIGO_VALIDO;
        const static std::string NOME_VALIDO;
        const static std::string PERFIL_VALIDO;

        void setUp() override;
        void testarCenarioValido() override;
    public:
        int run() override;
};

#endif //CARTEIRA_TEST_HPP