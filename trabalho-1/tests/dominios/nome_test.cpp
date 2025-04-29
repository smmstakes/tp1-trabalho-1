#include <iostream>
#include <stdexcept>

#include "nome_test.hpp"

const std::string TUNome::VALOR_VALIDO = "Maria de Alencar";
const std::string TUNome::DIGITO_INVALIDO = "Mar!ia de Alencar";
const std::string TUNome::TAMANHO_INVALIDO = "Maria Alencar de Jesus";
const std::string TUNome::ESPAÇOS_INVALIDOS = "Maria  de Alencar";

void TUNome::testarCenarioValido() {
    try {
        valor->set(VALOR_VALIDO);
        if (valor->get() != VALOR_VALIDO){
            std::cout << "TUNome: testarCenarioValido -> FALHA\n";
            estado = FALHA;
            return;
        }
        std::cout << "TUNome: testarCenarioValido -> SUCESSO\n";

    } catch(std::invalid_argument &excecao) {
        std::cout << "TUNome: testarCenarioValido -> FALHA\n";
        estado = FALHA;
    }
}

void TUNome::testarDigitoInvalido() {
    try {
        valor->set(DIGITO_INVALIDO);
        std::cout << "TUNome: testarDigitoInvalido -> FALHA\n";
        estado = FALHA;

    } catch(std::invalid_argument &excecao) {
        std::cout << "TUNome: testarDigitoInvalido -> SUCESSO\n";
    }
}

void TUNome::testarTamanhoInvalido() {
    try {
        valor->set(TAMANHO_INVALIDO);
        std::cout << "TUNome: testarTamanhoInvalido -> FALHA\n";
        estado = FALHA;
        
    } catch(std::invalid_argument &excecao) {
        std::cout << "TUNome: testarTamanhoInvalido -> SUCESSO\n";
    }
}

void TUNome::testarFormatacaoInvalida() {
    try {
        valor->set(ESPAÇOS_INVALIDOS);
        std::cout << "TUNome: testarFormatacaoInvalida -> FALHA\n";
        estado = FALHA;
    } catch(std::invalid_argument &excecao) {
        std::cout << "TUNome: testarFormatacaoInvalida -> SUCESSO\n";
    }
}

int TUNome::run() {
    setUp();

    testarCenarioValido();
    testarDigitoInvalido();
    testarTamanhoInvalido();
    testarFormatacaoInvalida();

    tearDown();
    return estado;
}