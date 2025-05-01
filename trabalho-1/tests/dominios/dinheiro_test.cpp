#include <iostream>
#include <stdexcept>

#include "../utils/tu_utils.hpp"
#include "dinheiro_test.hpp"

const double TUDinheiro::VALOR_VALIDO = 999999.99;
const double TUDinheiro::TAMANHO_INVALIDO = 10000000.00;
const double TUDinheiro::VALOR_INVALIDO = 1000001.00;

void TUDinheiro::testarCenarioValido() {
    valor->set(VALOR_VALIDO);
    TUUtils::assertIgual(valor->get(), VALOR_VALIDO, "testarCenarioValido", "TUDinheiro", estado);
}

void TUDinheiro::testarTamanhoInvalido() {
    TUUtils::assertExcecao([this]() { valor->set(TAMANHO_INVALIDO); }, "testarTamanhoInvalido", "TUDinheiro", estado);
}

void TUDinheiro::testarValorInvalido() {
    TUUtils::assertExcecao([this]() { valor->set(VALOR_INVALIDO); }, "testarValorInvalido", "TUDinheiro", estado);
}

int TUDinheiro::run(){
    setUp();

    testarCenarioValido();
    testarTamanhoInvalido();
    testarValorInvalido();

    tearDown();
    return estado;
}