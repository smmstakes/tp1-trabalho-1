#include <iostream>
#include <stdexcept>

#include "senha_test.hpp"

const std::string TUSenha::VALOR_VALIDO = "3aG#k8";
const std::string TUSenha::DIGITO_INVALIDO = "jD2!&l";
const std::string TUSenha::TAMANHO_INVALIDO = "Mn09#%W";
const std::string TUSenha::CRITERIO_MINIMO_INVALIDO = "sd23#$";
const std::string TUSenha::CARACTER_DUPLICADO_INVALIDO = "4rX4#y";

void TUSenha::testarCenarioValido() {
    try {
        valor->set(VALOR_VALIDO);
        if (valor->get() != VALOR_VALIDO){
            std::cout << "TUSenha: testarCenarioValido -> FALHA\n";
            estado = FALHA;
            return;
        }
        std::cout << "TUSenha: testarCenarioValido -> SUCESSO\n";

    } catch(std::invalid_argument &excecao) {
        std::cout << "TUSenha: testarCenarioValido -> FALHA\n";
        estado = FALHA;
    }
}

void TUSenha::testarDigitoInvalido() {
    try {
        valor->set(DIGITO_INVALIDO);
        std::cout << "TUSenha: testarDigitoInvalido -> FALHA\n";
        estado = FALHA;

    } catch(std::invalid_argument &excecao) {
        std::cout << "TUSenha: testarDigitoInvalido -> SUCESSO\n";
    }
}

void TUSenha::testarTamanhoInvalido() {
    try {
        valor->set(TAMANHO_INVALIDO);
        std::cout << "TUSenha: testarTamanhoInvalido -> FALHA\n";
        estado = FALHA;
        
    } catch(std::invalid_argument &excecao) {
        std::cout << "TUSenha: testarTamanhoInvalido -> SUCESSO\n";
    }
}

void TUSenha::testarCriterioMinimoInvalido() {
    try {
        valor->set(CRITERIO_MINIMO_INVALIDO);
        std::cout << "TUSenha: testarCriterioMinimoInvalido -> FALHA\n";
        estado = FALHA;
    } catch(std::invalid_argument &excecao) {
        std::cout << "TUSenha: testarCriterioMinimoInvalido -> SUCESSO\n";
    }
}

void TUSenha::testarCaracterDuplicadoInvalido() {
    try {
        valor->set(CARACTER_DUPLICADO_INVALIDO);
        std::cout << "TUSenha: testarCaracterDuplicadoInvalido -> FALHA\n";
        estado = FALHA;
    } catch(std::invalid_argument &excecao) {
        std::cout << "TUSenha: testarCaracterDuplicadoInvalido -> SUCESSO\n";
    }
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
