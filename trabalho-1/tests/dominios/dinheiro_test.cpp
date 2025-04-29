#include <iostream>
#include <stdexcept>

#include "dinheiro_test.hpp"

const double TUDinheiro::VALOR_VALIDO = 999999.99;
const double TUDinheiro::TAMANHO_INVALIDO = 10000000.00;
const double TUDinheiro::VALOR_INVALIDO = 1000001.00;

void TUDinheiro::testarCenarioValido(){
    valor->set(VALOR_VALIDO);
    if (valor->get()!= VALOR_VALIDO){
        std::cout<< "TUDinheiro: testarCenarioValido -> FALHA"<<std::endl;
        estado=FALHA;
        return;
    }
    std::cout<< "TUDinheiro: testarCenarioValido -> SUCESSO"<<std::endl;
}

void TUDinheiro::testarTamanhoInvalido(){
    try{
        valor->set(TAMANHO_INVALIDO);
        std::cout<< "TUDinheiro: testarTamanhoInvalido -> FALHA"<<std::endl;
        estado=FALHA;
   } catch(std::invalid_argument &except){
        std::cout<< "TUDinheiro: testarTamanhoInvalido -> SUCESSO"<<std::endl;
   }
}

void TUDinheiro::testarValorInvalido(){
    try{
        valor->set(VALOR_INVALIDO);
        std::cout<< "TUDinheiro: testarValorInvalido -> FALHA"<<std::endl;
    } catch(std::invalid_argument &except){
        std::cout<< "TUDinheiro: testarValorInvalido -> SUCESSO"<<std::endl;
    }
}

int TUDinheiro::run(){
    setUp();

    testarCenarioValido();
    testarTamanhoInvalido();
    testarValorInvalido();

    tearDown();
    return estado;
}