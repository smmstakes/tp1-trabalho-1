#include <iostream>
#include <stdexcept>

#include "cpf_test.hpp"

const std::string TUCPF::VALOR_VALIDO = "123.456.789-01";
const std::string TUCPF::DIGITO_INVALIDO = "12E.4S6.789-O1";
const std::string TUCPF::TAMANHO_INVALIDO = "123.456.789-012";
const std::string TUCPF::FORMATACAO_INVALIDA = "12345678901";

void TUCPF::testarCenarioValido() {
    try {
        cpf->set(VALOR_VALIDO);
        if (cpf->get() != VALOR_VALIDO){
            std::cout << "TUCPF: testarCenarioValido -> FALHA!\n";
            estado = FALHA;
            return;
        }
        std::cout << "TUCPF: testarCenarioValido -> SUCESSO!\n";

    } catch(std::invalid_argument &excecao) {
        std::cout << "TUCPF: testarCenarioValido -> FALHA!\n";
        estado = FALHA;
    }
}

void TUCPF::testarDigitoInvalido() {
    try {
        cpf->set(DIGITO_INVALIDO);
        std::cout << "TUCPF: testarDigitoInvalido -> FALHA!\n";
        estado = FALHA;

    } catch(std::invalid_argument &excecao) {
        std::cout << "TUCPF: testarDigitoInvalido -> SUCESSO!\n";
    }
}

void TUCPF::testarTamanhoInvalido() {
    try {
        cpf->set(TAMANHO_INVALIDO);
        std::cout << "TUCPF: testarTamanhoInvalido -> FALHA!\n";
        estado = FALHA;
        
    } catch(std::invalid_argument &excecao) {
        std::cout << "TUCPF: testarTamanhoInvalido -> SUCESSO!\n";
    }
}

void TUCPF::testarFormatacaoInvalida() {
    try {
        cpf->set(FORMATACAO_INVALIDA);
        std::cout << "TUCPF: testarFormatacaoInvalida -> FALHA!\n";
        estado = FALHA;
    } catch(std::invalid_argument &excecao) {
        std::cout << "TUCPF: testarFormatacaoInvalida -> SUCESSO!\n";
    }
}

int TUCPF::run() {
    setUp();

    testarCenarioValido();
    testarDigitoInvalido();
    testarTamanhoInvalido();
    testarFormatacaoInvalida();

    tearDown();
    return estado;
}