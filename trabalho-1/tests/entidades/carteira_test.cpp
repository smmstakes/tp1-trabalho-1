#include <iostream>
#include <string>
#include <stdexcept>

#include "../utils/tu_utils.hpp"
#include "carteira_test.hpp"

const std::string TUCarteira::CODIGO_VALIDO = "24680";
const std::string TUCarteira::NOME_VALIDO = "Felipe Santos 10";
const std::string TUCarteira::PERFIL_VALIDO = "Conservador";

void TUCarteira::setUp() {
    entidade = new Carteira(CODIGO_VALIDO, NOME_VALIDO, PERFIL_VALIDO);
    estado = SUCESSO;
}

void TUCarteira::testarCenarioValido() {
    TUUtils::assertIgual(entidade->getCodigo(), CODIGO_VALIDO, "testarCenarioValido -> Codigo", "TUCarteira", estado);
    TUUtils::assertIgual(entidade->getNome(), NOME_VALIDO, "testarCenarioValido -> Nome", "TUCarteira", estado);
    TUUtils::assertIgual(entidade->getPerfil(), PERFIL_VALIDO, "testarCenarioValido -> Perfil", "TUCarteira", estado);
}

int TUCarteira::run (){
    setUp();
    testarCenarioValido();
    tearDown();
    return estado;
}