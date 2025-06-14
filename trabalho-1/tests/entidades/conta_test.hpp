#ifndef CONTA_TESTE_HPP_INCLUDED
#define CONTA_TESTE_HPP_INCLUDED

#include <string>

#include "entidades_test.hpp"
#include "../../libs/entidades/entidades.hpp"

class TUConta : public TUEntidade<Conta>{
    private:
    const static std::string CPF_VALIDO;
    const static std::string NOME_VALIDO;
    const static std::string SENHA_VALIDA;

    void setUp() override;
    void testarCenarioValido() override;

    public:
        int run() override;

// Criado por Gabriel Castro - 202066571
};

#endif //CONTA_TESTE_HPP_INCLUDED
