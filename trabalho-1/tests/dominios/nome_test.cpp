#include <iostream>
#include <stdexcept>

#include "../utils/tu_utils.hpp"
#include "nome_test.hpp"

const std::string TUNome::VALOR_VALIDO = "Maria de Alencar";
const std::string TUNome::DIGITO_INVALIDO = "Mar!ia de Alencar";
const std::string TUNome::TAMANHO_INVALIDO = "Maria Alencar de Jesus";
const std::string TUNome::ESPAÇOS_INVALIDOS = "Maria  de Alencar";

void TUNome::testarCenarioValido() {
    valor->set(VALOR_VALIDO);
    TUUtils::assertIgual(valor->get(), VALOR_VALIDO, "testarCenarioValido", "TUNome", estado);
}

void TUNome::testarDigitoInvalido() {
    TUUtils::assertExcecao([this]() { valor->set(DIGITO_INVALIDO); }, "testarDigitoInvalido", "TUNome", estado);
}

void TUNome::testarTamanhoInvalido() {
    TUUtils::assertExcecao([this]() { valor->set(TAMANHO_INVALIDO); }, "testarTamanhoInvalido", "TUNome", estado);
}

void TUNome::testarFormatacaoInvalida() {
    TUUtils::assertExcecao([this]() { valor->set(ESPAÇOS_INVALIDOS); }, "testarFormatacaoInvalida", "TUNome", estado);
}

int TUNome::run() {
    setUp();

    testarCenarioValido();
    testarDigitoInvalido();
    testarTamanhoInvalido();
    testarFormatacaoInvalida();

    tearDown();
    return estado;
}