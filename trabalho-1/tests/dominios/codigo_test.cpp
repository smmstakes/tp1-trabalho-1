#include <iostream>
#include <stdexcept>

#include "codigo_test.hpp"

const std::string TUCodigo::CODIGO_VALIDO = "04562";
const std::string TUCodigo::CODIGO_DIGITO_INVALIDO = "678A5";
const std::string TUCodigo::CODIGO_TAMANHO_INVALIDO = "032785";


void TUCodigo::setUp() {
    codigo = new Codigo();
    estado = SUCESSO;
}

void TUCodigo::tearDown() {
    delete codigo;
}

void TUCodigo::testarCenarioValido() {
    try {
        codigo->set(CODIGO_VALIDO);
        if (codigo->get() != CODIGO_VALIDO){
            std::cerr << "Valor válido não aceito.\n";
            estado = FALHA;
        }
    } catch(std::invalid_argument &excecao) {
        std::cerr << "Ocorreu uma exceção: " << excecao.what() << "\n";
        estado = FALHA;
    }
}

void TUCodigo::testarDigitoInvalido() {
    try {
        codigo->set(CODIGO_DIGITO_INVALIDO);
        std::cerr << "Código com digito inválido aceito.\n";
        estado = FALHA;
    } catch(std::invalid_argument &excecao) {
        std::cerr << excecao.what() << "Digito inválido.\n";
    }
}

void TUCodigo::testarTamanhoInvalido() {
    try {
        codigo->set(CODIGO_TAMANHO_INVALIDO);
        std::cerr << "Código com tamanho inválido aceito.\n";
        estado = FALHA;
    } catch(std::invalid_argument &excecao) {
        std::cerr << excecao.what() << "Tamanho inválido.\n";
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