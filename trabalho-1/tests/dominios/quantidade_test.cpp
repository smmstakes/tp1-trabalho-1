#include <iostream>
#include <stdexcept>

#include "../utils/tu_utils.hpp"
#include "quantidade_test.hpp"

const int TUQuantidade::VALOR_VALIDO = 999999;
const int TUQuantidade::TAMANHO_INVALIDO = 10000000;
const int TUQuantidade::VALOR_INVALIDO = 1000001;

void TUQuantidade::testarCenarioValido() {
    valor->set(VALOR_VALIDO);
    TUUtils::assertIgual(valor->get(), VALOR_VALIDO, "testarCenarioValido", "TUQuantidade", estado);
}

void TUQuantidade::testarTamanhoInvalido() {
    TUUtils::assertExcecao([this]() { valor->set(TAMANHO_INVALIDO); }, "testarTamanhoInvalido", "TUQuantidade", estado);
}

void TUQuantidade::testarValorInvalido() {
    TUUtils::assertExcecao([this]() { valor->set(VALOR_INVALIDO); }, "testarValorInvalido", "TUQuantidade", estado);
}

int TUQuantidade::run(){
    setUp();

    testarCenarioValido();
    testarTamanhoInvalido();
    testarValorInvalido();

    tearDown();
    return estado;
}
