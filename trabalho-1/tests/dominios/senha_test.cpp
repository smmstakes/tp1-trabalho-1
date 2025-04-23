#include <iostream>
#include <stdexcept>

#include "senha_test.hpp"

const std::string VALOR_VALIDO = "3aG#k8";
const std::string DIGITO_INVALIDO = "jD2!&l";
const std::string TAMANHO_INVALIDO = "Mn09#%W";
const std::string CRITERIO_MINIMO_INVALIDO = "sd23#$";
const std::string CARACTER_DUPLICADO_INVALIDO = "4rX4#y";

void TUSenha::setUp() {
    senha = new Senha();
    estado = SUCESSO;
}

void TUSenha::tearDown() {
    delete senha;
}

void TUSenha::testarCenarioValido() {
    try {
        senha->set(VALOR_VALIDO);
        if (senha->get() != VALOR_VALIDO){
            std::cout << "TUSenha: testarCenarioValido -> FALHA!\n";
            estado = FALHA;
            return;
        }
        std::cout << "TUSenha: testarCenarioValido -> SUCESSO!\n";

    } catch(std::invalid_argument &excecao) {
        std::cout << "TUSenha: testarCenarioValido -> FALHA!\n";
        estado = FALHA;
    }
}

void TUSenha::testarDigitoInvalido() {
    try {
        senha->set(DIGITO_INVALIDO);
        std::cout << "TUSenha: testarDigitoInvalido -> FALHA!\n";
        estado = FALHA;

    } catch(std::invalid_argument &excecao) {
        std::cout << "TUSenha: testarDigitoInvalido -> SUCESSO!\n";
    }
}

void TUSenha::testarTamanhoInvalido() {
    try {
        senha->set(TAMANHO_INVALIDO);
        std::cout << "TUSenha: testarTamanhoInvalido -> FALHA!\n";
        estado = FALHA;
        
    } catch(std::invalid_argument &excecao) {
        std::cout << "TUSenha: testarTamanhoInvalido -> SUCESSO!\n";
    }
}

void TUSenha::testarCriterioMinimoInvalido() {
    try {
        senha->set(CRITERIO_MINIMO_INVALIDO);
        std::cout << "TUSenha: testarCriterioMinimoInvalido -> FALHA!\n";
        estado = FALHA;
    } catch(std::invalid_argument &excecao) {
        std::cout << "TUSenha: testarCriterioMinimoInvalido -> SUCESSO!\n";
    }
}

void TUSenha::testarCaracterDuplicadoInvalido() {
    try {
        senha->set(CARACTER_DUPLICADO_INVALIDO);
        std::cout << "TUSenha: testarCaracterDuplicadoInvalido -> FALHA!\n";
        estado = FALHA;
    } catch(std::invalid_argument &excecao) {
        std::cout << "TUSenha: testarCaracterDuplicadoInvalido -> SUCESSO!\n";
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
