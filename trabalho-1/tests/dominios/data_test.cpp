#include <iostream>
#include <stdexcept>

#include "data_test.hpp"

const static std::string DATA_VALIDA = "19640120";
const static std::string DATA_FORMATO_INVALIDO = "2024210";
const static std::string DATA_MES_INVALIDO = "20251322";
const static std::string DATA_DIA_INVALIDO = "20000229";


void TUData::testarCenarioValido() {
    try {
        data->set(DATA_VALIDA);
        if (data->get() != DATA_VALIDA){
            std::cerr << "Valor válido não aceito.\n";
            estado = FALHA;
        }
    } catch(std::invalid_argument &excecao) {
        std::cerr << "Ocorreu uma exceção: " << excecao.what() << "\n";
        estado = FALHA;
    }
}

void TUData::testarFormatoInvalido() {
    try {
        data->set(DATA_FORMATO_INVALIDO);
        std::cerr << "Código com digito inválido aceito.\n";
        estado = FALHA;
    } catch(std::invalid_argument &excecao) {
        std::cerr << excecao.what() << "Digito inválido.\n";
    }
}

// void TUData::testarTamanhoInvalido() {
//     try {
//         codigo->set(CODIGO_TAMANHO_INVALIDO);
//         std::cerr << "Código com tamanho inválido aceito.\n";
//         estado = FALHA;
//     } catch(std::invalid_argument &excecao) {
//         std::cerr << excecao.what() << "Tamanho inválido.\n";
//     }
// }

// int TUData::run() {
//     setUp();
//     testarCenarioValido();
//     testarDigitoInvalido();
//     testarTamanhoInvalido();
//     tearDown();
//     return estado;
// }