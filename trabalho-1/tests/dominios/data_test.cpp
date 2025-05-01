#include <iostream>
#include <stdexcept>

#include "data_test.hpp"
#include "../tests.hpp"

const std::string TUData::VALOR_VALIDO = "20240229";
const std::string TUData::DIA_INVALIDO = "20240230";
const std::string TUData::MES_INVALIDO = "20251322";
const std::string TUData::ANO_INVALIDO = "00000101";
const std::string TUData::FORMATO_INVALIDO = "2024210";

void TUData::testarCenarioValido() {
    valor->set(VALOR_VALIDO);
    TUUtils::assertIgual(valor->get(), VALOR_VALIDO, "testarCenarioValido", "TUData", estado);
}

void TUData::testarDiaInvalido() {
    TUUtils::assertExcecao([this]() { valor->set(DIA_INVALIDO); }, "testarDiaInvalido", "TUData", estado);
}

void TUData::testarMesInvalido() {
   TUUtils::assertExcecao([this]() { valor->set(MES_INVALIDO); }, "testarMesInvalido", "TUData", estado);
}

void TUData::testarAnoInvalido() {
    TUUtils::assertExcecao([this]() { valor->set(ANO_INVALIDO); }, "testarAnoInvalido", "TUData", estado);
}

void TUData::testarFormatoInvalido() {
    TUUtils::assertExcecao([this]() { valor->set(FORMATO_INVALIDO); }, "testarFormatoInvalido", "TUData", estado);
}

int TUData::run() {
    setUp();

    testarCenarioValido();
    testarDiaInvalido();
    testarMesInvalido();
    testarAnoInvalido();
    testarFormatoInvalido();

    tearDown();
    return estado;
}