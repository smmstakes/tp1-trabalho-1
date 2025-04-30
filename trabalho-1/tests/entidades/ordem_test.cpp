#include <string>
#include <iostream>
#include <stdexcept>

#include "ordem_test.hpp"

const double TUOrdem::DINHEIRO_VALIDO = 123456.78;
const std::string TUOrdem::DATA_VALIDA = "20250429";
const std::string TUOrdem::CODIGO_VALIDO = "01385";
const std::string TUOrdem::CODIGO_NEGOCIACAO_VALIDO = "CodNeg123   ";

void TUOrdem::setUp() {
    entidade = new Ordem(CODIGO_VALIDO, CODIGO_NEGOCIACAO_VALIDO, DATA_VALIDA, DINHEIRO_VALIDO, QUANTIDADE_VALIDA);
    estado = SUCESSO;
}

void TUOrdem::testarCenarioValido() {
    try {
        if (entidade->getCodigo() != CODIGO_VALIDO) {
            std::cout << "TUOrdem: testarCenarioValido -> Codigo -> FALHA\n";
            estado = FALHA;
            return;
        }
        std::cout << "TUOrdem: testarCenarioValido -> Codigo -> SUCESSO\n";

        if (entidade->getCodNegociacao() != CODIGO_NEGOCIACAO_VALIDO) {
            std::cout << "TUOrdem: testarCenarioValido -> CodigoNegociacao -> FALHA\n";
            estado = FALHA;
            return;
        }
        std::cout << "TUOrdem: testarCenarioValido -> CodigoNegociacao -> SUCESSO\n";

        if (entidade->getData() != DATA_VALIDA) {
            std::cout << "TUOrdem: testarCenarioValido -> Data -> FALHA\n";
            estado = FALHA;
            return;
        }
        std::cout << "TUOrdem: testarCenarioValido -> Data -> SUCESSO\n";

        if (entidade->getDinheiro() != DINHEIRO_VALIDO) {
            std::cout << "TUOrdem: testarCenarioValido -> Dinheiro -> FALHA\n";
            estado = FALHA;
            return;
        }
        std::cout << "TUOrdem: testarCenarioValido -> Dinheiro -> SUCESSO\n";

        if (entidade->getQuantidade() != QUANTIDADE_VALIDA) {
            std::cout << "TUOrdem: testarCenarioValido -> Quantidade -> FALHA\n";
            estado = FALHA;
            return;
        }
        std::cout << "TUOrdem: testarCenarioValido -> Quantidade -> SUCESSO\n";
        
    } catch(std::invalid_argument &excecao) {
        std::cout << "TUOrdem: testarCenarioValido -> FALHA\n";
        estado = FALHA;
    }
}

int TUOrdem::run() {
    setUp();

    testarCenarioValido();

    tearDown();
    return estado;
}

