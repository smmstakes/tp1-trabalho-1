#include <string>
#include <iostream>
#include <stdexcept>

#include "../utils/tu_utils.hpp"
#include "conta_test.hpp"

const std::string TUConta::CPF_VALIDO = "123-456-789-10";
const std::string TUConta::NOME_VALIDO = "FuLAN0 da SILV4";
const std::string TUConta::SENHA_VALIDA = "01ABc%";

void TUConta::setUp(){
    entidade = new Conta(CPF_VALIDO, NOME_VALIDO, SENHA_VALIDA);
    estado = SUCESSO;
}

void TUConta::testarCenarioValido() {
    TUUtils::assertIgual(entidade->getCpf(), CPF_VALIDO, "testarCenarioValido -> CPF", "TUConta", estado);
    TUUtils::assertIgual(entidade->getNome(), NOME_VALIDO, "testarCenarioValido -> Nome", "TUConta", estado);
    TUUtils::assertIgual(entidade->getSenha(), SENHA_VALIDA, "testarCenarioValido -> Senha", "TUConta", estado);
}

int TUConta::run(){
    setUp();

    testarCenarioValido();

    tearDown();
    return estado;
}