#include <iostream>
#include <stdexcept>

#include "codigo_negociacao_test.hpp"

const std::string TUCodigoNegociacao::CODIGO_VALIDO = "ABC123def   ";
const std::string TUCodigoNegociacao::CODIGO_DIGITO_INVALIDO = "ABC123def ! ";
const std::string TUCodigoNegociacao::CODIGO_TAMANHO_INVALIDO = "ABC123defG4   ";

void TUCodigoNegociacao::testarCenarioValido() {
    try {
        valor->set(CODIGO_VALIDO);
        if (valor->get() != CODIGO_VALIDO){
            std::cout << "TUCodigoNegociacao: testarCenarioValido -> FALHA\n";
            estado = FALHA;
            return;
        }
        std::cout << "TUCodigoNegociacao: testarCenarioValido -> SUCESSO\n";

    } catch(std::invalid_argument &excecao) {
        std::cout << "TUCodigoNegociacao: testarCenarioValido -> FALHA\n";
        estado = FALHA;
    }
}

void TUCodigoNegociacao::testarDigitoInvalido() {
    try {
        valor->set(CODIGO_DIGITO_INVALIDO);
        std::cout << "TUCodigoNegociacao: testarDigitoInvalido -> FALHA\n";
        estado = FALHA;

    } catch(std::invalid_argument &excecao) {
        std::cout << "TUCodigoNegociacao: testarDigitoInvalido -> SUCESSO\n";
    }
}

void TUCodigoNegociacao::testarTamanhoInvalido() {
    try {
        valor->set(CODIGO_TAMANHO_INVALIDO);
        std::cout << "TUCodigoNegociacao: testarTamanhoInvalido -> FALHA\n";
        estado = FALHA;

    } catch(std::invalid_argument &excecao) {
        std::cout << "TUCodigoNegociacao: testarTamanhoInvalido -> SUCESSO\n";
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