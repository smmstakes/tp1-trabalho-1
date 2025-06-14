#ifndef CARTEIRA_TEST_HPP_INCLUDED
#define CARTEIRA_TEST_HPP_INCLUDED

#include "entidades_test.hpp"
#include "../../libs/entidades/entidades.hpp"

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

// Criado por Pedro Vale - 231038733
};

#endif //CARTEIRA_TEST_HPP
