#ifndef CONTA_TESTE_HPP_INCLUDED
#define CONTA_TESTE_HPP_INCLUDED

#include <string>

#include "entidades_test.hpp"
#include "../../src/entidades/entidades.hpp"

class TUConta : public TUEntidade<Conta>{
    private:
    const static std::string CPF_VALIDO;
    const static std::string NOME_VALIDO;
    const static std::string SENHA_VALIDA;

    void setUp() override;
    void testarCenarioValido() override;

    public:
        int run() override;
};

#endif //CONTA_TESTE_HPP_INCLUDED
