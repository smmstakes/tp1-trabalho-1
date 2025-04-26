#include <iostream>
#include <stdexcept>

#include "quantidade_test.hpp"

const int TUQuantidade::QUANTIDADE_VALIDA = 999999;
const int TUQuantidade::QUANTIDADE_TAMANHO_INVALIDO = 10000000;
const int TUQuantidade::QUANTIDADE_VALOR_INVALIDO = 1000001;

void TUQuantidade::testarCenarioValido(){
    try {
        valor->set(QUANTIDADE_VALIDA);
        if (valor->get() != QUANTIDADE_VALIDA){
            std::cout<< "TUQuantidade: testarCenarioValido -> FALHA"<<std::endl;
            estado=FALHA;
            return;
        }
        std::cout<<"TUQuantidade: testarCenarioValido -> SUCESSO"<<std::endl;

    } catch (const std::invalid_argument& e){
        std::cout<< "TUQuantidade: testarCenarioValido -> FALHA" << ".Excessão: " << e.what() << std::endl;
        estado=FALHA;
    }
    
}

void TUQuantidade::testarTamanhoInvalido(){
    try{
        valor->set(QUANTIDADE_TAMANHO_INVALIDO);
        std::cout<< "TUQuantidade: testarTamanhoInvalido -> FALHA"<<std::endl;
        estado= FALHA;
    } catch(std::invalid_argument &excecao){
        std::cout<< "TUQuantidade: testarTamanhoInvalido -> SUCESSO"<<std::endl;
    }
}
void TUQuantidade::testarValorInvalido(){
    try{
        valor->set(QUANTIDADE_VALOR_INVALIDO);
        std::cout<< "TUQuantidade: testarValorInvalido -> FALHA"<<std::endl;
        estado= FALHA;
    } catch(std::invalid_argument &excecao){
        std::cout<< "TUQuantidade: testarValorInvalido -> SUCESSO"<<std::endl;
    }
}

int TUQuantidade::run(){
    setUp();

    testarCenarioValido();
    testarTamanhoInvalido();
    testarValorInvalido();

    tearDown();
    return estado;
}