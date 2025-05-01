#include <string>
#include <iostream>
#include <stdexcept>

#include "ordem_test.hpp"
#include "../tests.hpp"

const int TUOrdem::QUANTIDADE_VALIDA = 5000;
const double TUOrdem::DINHEIRO_VALIDO = 123456.78;
const std::string TUOrdem::DATA_VALIDA = "20250429";
const std::string TUOrdem::CODIGO_VALIDO = "01385";
const std::string TUOrdem::CODIGO_NEGOCIACAO_VALIDO = "CodNeg123   ";

void TUOrdem::setUp() {
    entidade = new Ordem(CODIGO_VALIDO, CODIGO_NEGOCIACAO_VALIDO, DATA_VALIDA, DINHEIRO_VALIDO, QUANTIDADE_VALIDA);
    estado = SUCESSO;
}

void TUOrdem::testarCenarioValido() {
    TUUtils::assertIgual(entidade->getCodigo(), CODIGO_VALIDO, "Codigo", "TUOrdem", estado);
    TUUtils::assertIgual(entidade->getCodNegociacao(), CODIGO_NEGOCIACAO_VALIDO, "CodigoNegociacao", "TUOrdem", estado);
    TUUtils::assertIgual(entidade->getData(), DATA_VALIDA, "Data", "TUOrdem", estado);
    TUUtils::assertIgual(entidade->getDinheiro(), DINHEIRO_VALIDO, "Dinheiro", "TUOrdem", estado);
    TUUtils::assertIgual(entidade->getQuantidade(), QUANTIDADE_VALIDA, "Quantidade", "TUOrdem", estado);
}

int TUOrdem::run() {
    setUp();

    testarCenarioValido();

    tearDown();
    return estado;
}

