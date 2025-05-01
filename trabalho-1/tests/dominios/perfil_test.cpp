#include <iostream>
#include <stdexcept>

#include "../tests.hpp"
#include "perfil_test.hpp"

const std::string TUPerfil::VALOR_VALIDO = "Moderado"; // Pode ser Conservador, Moderado ou Agressivo
const std::string TUPerfil::VALOR_INVALIDO = "Radical";

void TUPerfil::testarCenarioValido() {
    valor->set(VALOR_VALIDO);
    TUUtils::assertIgual(valor->get(), VALOR_VALIDO, "testarCenarioValido", "TUPerfil", estado);
}

void TUPerfil::testarCenarioInvalido() {
    TUUtils::assertExcecao([this]() { valor->set(VALOR_INVALIDO); }, "testarCenarioInvalido", "TUPerfil", estado);
}

int TUPerfil::run(){
    setUp();

    testarCenarioValido();
    testarCenarioInvalido();

    tearDown();
    return estado;
}