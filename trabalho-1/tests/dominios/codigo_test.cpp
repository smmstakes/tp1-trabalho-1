#include <iostream>
#include <stdexcept>

#include "codigo_test.hpp"

const std::string TUCodigo::CODIGO_VALIDO = "04562";
const std::string TUCodigo::CODIGO_DIGITO_INVALIDO = "678A5";
const std::string TUCodigo::CODIGO_TAMANHO_INVALIDO = "032785";

void TUCodigo::testarCenarioValido() {
    try {
        valor->set(CODIGO_VALIDO);
        if (valor->get() != CODIGO_VALIDO){
            std::cout << "TUCodigo: testarCenarioValido -> FALHA\n";
            estado = FALHA;
            return;
        }
        std::cout << "TUCodigo: testarCenarioValido -> SUCESSO\n";

    } catch(std::invalid_argument &excecao) {
        std::cout << "TUCodigo: testarCenarioValido -> FALHA\n";
        estado = FALHA;
    }
}

void TUCodigo::testarDigitoInvalido() {
    try {
        valor->set(CODIGO_DIGITO_INVALIDO);
        std::cout << "TUCodigo: testarDigitoInvalido -> FALHA\n";
        estado = FALHA;

    } catch(std::invalid_argument &excecao) {
        std::cout << "TUCodigo: testarDigitoInvalido -> SUCESSO\n";
    }
}

void TUCodigo::testarTamanhoInvalido() {
    try {
        valor->set(CODIGO_TAMANHO_INVALIDO);
        std::cout << "TUCodigo: testarTamanhoInvalido -> FALHA\n";
        estado = FALHA;

    } catch(std::invalid_argument &excecao) {
        std::cout << "TUCodigo: testarTamanhoInvalido -> SUCESSO\n";
    }
}

int TUCodigo::run() {
    setUp();

    testarCenarioValido();
    testarDigitoInvalido();
    testarTamanhoInvalido();

    tearDown();
    return estado;
}