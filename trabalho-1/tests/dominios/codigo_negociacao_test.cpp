#include <iostream>
#include <stdexcept>

#include "codigo_negociacao_test.hpp"

const std::string TUCodigoNegociacao::CODIGO_VALIDO = "ABC123def   ";
const std::string TUCodigoNegociacao::CODIGO_DIGITO_INVALIDO = "ABC123def ! ";
const std::string TUCodigoNegociacao::CODIGO_TAMANHO_INVALIDO = "ABC123defG4   ";


void TUCodigoNegociacao::setUp() {
    codNegociacao = new CodigoNegociacao();
    estado = SUCESSO;
}

void TUCodigoNegociacao::tearDown() {
    delete codNegociacao;
}

void TUCodigoNegociacao::testarCenarioValido() {
    try {
        codNegociacao->set(CODIGO_VALIDO);
        if (codNegociacao->get() != CODIGO_VALIDO){
            std::cerr << "Valor válido não aceito.\n";
            estado = FALHA;
        }
    } catch(std::invalid_argument &excecao) {
        std::cerr << "Ocorreu uma exceção: " << excecao.what() << "\n";
        estado = FALHA;
    }
}

void TUCodigoNegociacao::testarDigitoInvalido() {
    try {
        codNegociacao->set(CODIGO_DIGITO_INVALIDO);
        std::cerr << "Código com digito inválido aceito.\n";
        estado = FALHA;
    } catch(std::invalid_argument &excecao) {
        std::cerr << excecao.what() << "Digito inválido.\n";
    }
}

void TUCodigoNegociacao::testarTamanhoInvalido() {
    try {
        codNegociacao->set(CODIGO_TAMANHO_INVALIDO);
        std::cerr << "Código com tamanho inválido aceito.\n";
        estado = FALHA;
    } catch(std::invalid_argument &excecao) {
        std::cerr << excecao.what() << "Tamanho inválido.\n";
    }
}

int TUCodigoNegociacao::run() {
    setUp();
    testarCenarioValido();
    testarDigitoInvalido();
    testarTamanhoInvalido();
    tearDown();
    return estado;
}