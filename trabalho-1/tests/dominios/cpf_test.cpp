#include <iostream>
#include <stdexcept>

#include "../utils/tu_utils.hpp"
#include "cpf_test.hpp"

const std::string TUCPF::VALOR_VALIDO = "123.456.789-01";
const std::string TUCPF::DIGITO_INVALIDO = "12E.4S6.789-O1";
const std::string TUCPF::TAMANHO_INVALIDO = "123.456.789-012";
const std::string TUCPF::FORMATACAO_INVALIDA = "12345678901";

void TUCPF::testarCenarioValido() {
    valor->set(VALOR_VALIDO);
    TUUtils::assertIgual(valor->get(), VALOR_VALIDO, "testarCenarioValido", "TUCPF", estado);
}

void TUCPF::testarDigitoInvalido() {
    TUUtils::assertExcecao([this]() { valor->set(DIGITO_INVALIDO); }, "testarDigitoInvalido", "TUCPF", estado);
}

void TUCPF::testarTamanhoInvalido() {
    TUUtils::assertExcecao([this]() { valor->set(TAMANHO_INVALIDO); }, "testarTamanhoInvalido", "TUCPF", estado);
}

void TUCPF::testarFormatacaoInvalida() {
    TUUtils::assertExcecao([this]() { valor->set(FORMATACAO_INVALIDA); }, "testarFormatacaoInvalida", "TUCPF", estado);
}


int TUCPF::run() {
    setUp();

    testarCenarioValido();
    testarDigitoInvalido();
    testarTamanhoInvalido();
    testarFormatacaoInvalida();

    tearDown();
    return estado;
}