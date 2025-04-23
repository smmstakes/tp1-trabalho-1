#include <iostream>
#include <stdexcept>

#include "data_test.hpp"

const std::string TUData::VALOR_VALIDO = "20240229";
const std::string TUData::DIA_INVALIDO = "20240230";
const std::string TUData::MES_INVALIDO = "20251322";
const std::string TUData::ANO_INVALIDO = "00000101";
const std::string TUData::FORMATO_INVALIDO = "2024210";

void TUData::testarCenarioValido() {
    data->set(VALOR_VALIDO);
    if (data->get() != VALOR_VALIDO){
        estado = FALHA;
        std::cout << "TUData: testarCenarioValido -> FALHA \n";
        return;
    }
    std::cout << "TUData: testarCenarioValido -> SUCESSO \n";
}

void TUData::testarDiaInvalido() {
    try {
        data->set(DIA_INVALIDO);
        std::cout << "TUData: testarDiaInvalido -> FALHA\n";
        estado = FALHA;
    } catch(std::invalid_argument &excecao) {
        std::cout << "TUData: testarDiaInvalido -> SUCESSO\n";
    }
}

void TUData::testarMesInvalido() {
    try {
        data->set(MES_INVALIDO);
        std::cout << "TUData: testarMesInvalido -> FALHA\n";
        estado = FALHA;
    } catch(std::invalid_argument &excecao) {
        std::cout << "TUData: testarMesInvalido -> SUCESSO\n";
    }
}

void TUData::testarAnoInvalido() {
    try {
        data->set(ANO_INVALIDO);
        std::cout << "TUData: testarAnoInvalido -> FALHA\n";
        estado = FALHA;
    } catch(std::invalid_argument &excecao) {
        std::cout << "TUData: testarAnoInvalido -> SUCESSO\n";
    }
}

void TUData::testarFormatoInvalido() {
    try {
        data->set(FORMATO_INVALIDO);
        std::cout << "TUData: testarFormatoInvalido -> FALHA\n";
        estado = FALHA;
    } catch(std::invalid_argument &excecao) {
        std::cout << "TUData: testarFormatoInvalido -> SUCESSO\n";
    }
}

int TUData::run() {
    setUp();

    testarCenarioValido();
    testarDiaInvalido();
    testarMesInvalido();
    testarAnoInvalido();
    testarFormatoInvalido();

    tearDown();
    return estado;
}