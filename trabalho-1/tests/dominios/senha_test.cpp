#include <iostream>
#include <stdexcept>

#include "../utils/tu_utils.hpp"
#include "senha_test.hpp"

const std::string TUSenha::VALOR_VALIDO = "3aG#k8";
const std::string TUSenha::DIGITO_INVALIDO = "jD2!&l";
const std::string TUSenha::TAMANHO_INVALIDO = "Mn09#%W";
const std::string TUSenha::CRITERIO_MINIMO_INVALIDO = "sd23#$";
const std::string TUSenha::CARACTER_DUPLICADO_INVALIDO = "4rX4#y";

void TUSenha::testarCenarioValido() {
    valor->set(VALOR_VALIDO);
    TUUtils::assertIgual(valor->get(), VALOR_VALIDO, "testarCenarioValido", "TUSenha", estado);
}

void TUSenha::testarDigitoInvalido() {
    TUUtils::assertExcecao([this]() { valor->set(DIGITO_INVALIDO); }, "testarDigitoInvalido", "TUSenha", estado);
}

void TUSenha::testarTamanhoInvalido() {
    TUUtils::assertExcecao([this]() { valor->set(TAMANHO_INVALIDO); }, "testarTamanhoInvalido", "TUSenha", estado);
}

void TUSenha::testarCriterioMinimoInvalido() {
    TUUtils::assertExcecao([this]() { valor->set(CRITERIO_MINIMO_INVALIDO); }, "testarCriterioMinimoInvalido", "TUSenha", estado);
}

void TUSenha::testarCaracterDuplicadoInvalido() {
    TUUtils::assertExcecao([this]() { valor->set(CARACTER_DUPLICADO_INVALIDO); }, "testarCaracterDuplicadoInvalido", "TUSenha", estado);
}

int TUSenha::run() {
    setUp();

    testarCenarioValido();
    testarDigitoInvalido();
    testarTamanhoInvalido();
    testarCriterioMinimoInvalido();
    testarCaracterDuplicadoInvalido();

    tearDown();
    return estado;
}
