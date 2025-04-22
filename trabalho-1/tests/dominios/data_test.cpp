#include <iostream>
#include <stdexcept>

#include "data_test.hpp"

const static std::string VALOR_VALIDO = "20240229";
const static std::string FORMATO_INVALIDO = "2024210";
const static std::string MES_INVALIDO = "20251322";
const static std::string DIA_INVALIDO = "20240230";

void TUData::testarCenarioValido() {
    data->set(VALOR_VALIDO);
    if (data->get() != VALOR_VALIDO){
        estado = FALHA;
        return;
    }
    std::cout << "TUData: testarCenarioValido -> SUCESSO \n";
}

void TUData::testarFormatoInvalido() {
    try {
        data->set(FORMATO_INVALIDO);
        std::cerr << "TUData: testarFormatoInvalido -> FALHA\n";
        estado = FALHA;
    } catch(std::invalid_argument &excecao) {
        std::cerr << "TUData: testarFormatoInvalido -> SUCESSO\n";
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

void TUData::testarDiaInvalido() {
    try {
        data->set(DIA_INVALIDO);
        std::cout << "TUData: testarDiaInvalido -> FALHA\n";
        estado = FALHA;
    } catch(std::invalid_argument &excecao) {
        std::cout << "TUData: testarDiaInvalido -> SUCESSO\n";
    }
}

int TUData::run() {
    setUp();
    testarCenarioValido();
    testarFormatoInvalido();
    testarMesInvalido();
    testarDiaInvalido();
    tearDown();
    return estado;
}