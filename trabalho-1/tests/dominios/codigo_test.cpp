#include <iostream>
#include <stdexcept>

#include "../utils/tu_utils.hpp"
#include "codigo_test.hpp"

const std::string TUCodigo::VALOR_VALIDO = "04562";
const std::string TUCodigo::DIGITO_INVALIDO = "678A5";
const std::string TUCodigo::TAMANHO_INVALIDO = "032785";

void TUCodigo::testarCenarioValido() {
    valor->set(VALOR_VALIDO);
    TUUtils::assertIgual(valor->get(), VALOR_VALIDO, "testarCenarioValido", "TUCodigo", estado);
}

void TUCodigo::testarDigitoInvalido() {
    TUUtils::assertExcecao([this]() { valor->set(DIGITO_INVALIDO); }, "testarDigitoInvalido", "TUCodigo", estado);
}

void TUCodigo::testarTamanhoInvalido() {
    TUUtils::assertExcecao([this]() { valor->set(DIGITO_INVALIDO); }, "testarTamanhoInvalido", "TUCodigo", estado);
}

int TUCodigo::run() {
    setUp();

    testarCenarioValido();
    testarDigitoInvalido();
    testarTamanhoInvalido();

    tearDown();
    return estado;
}
