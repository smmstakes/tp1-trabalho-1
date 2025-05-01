#include <iostream>
#include <stdexcept>

#include "../tests.hpp"
#include "codigo_negociacao_test.hpp"

const std::string TUCodigoNegociacao::VALOR_VALIDO = "ABC123def   ";
const std::string TUCodigoNegociacao::DIGITO_INVALIDO = "ABC123def ! ";
const std::string TUCodigoNegociacao::TAMANHO_INVALIDO = "ABC123defG4   ";


void TUCodigoNegociacao::testarCenarioValido() {
    valor->set(VALOR_VALIDO);
    TUUtils::assertIgual(valor->get(), VALOR_VALIDO, "testarCenarioValido", "TUCodigoNegociacao", estado);
}

void TUCodigoNegociacao::testarDigitoInvalido() {
    TUUtils::assertExcecao([this]() { valor->set(DIGITO_INVALIDO); }, "testarDigitoInvalido", "TUCodigoNegociacao", estado);
}

void TUCodigoNegociacao::testarTamanhoInvalido() {
   TUUtils::assertExcecao([this]() { valor->set(TAMANHO_INVALIDO); }, "testarTamanhoInvalido", "TUCodigoNegociacao", estado);
}

int TUCodigoNegociacao::run() {
    setUp();

    testarCenarioValido();
    testarDigitoInvalido();
    testarTamanhoInvalido();
    
    tearDown();
    return estado;
}