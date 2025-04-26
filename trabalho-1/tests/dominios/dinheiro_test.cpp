#include <iostream>
#include <stdexcept>

#include "dinheiro_test.hpp"

const double TUDinheiro::DINHEIRO_VALIDO = 999999.99;
const double TUDinheiro::DINHEIRO_TAMANHO_INVALIDO = 10000000.00;
const double TUDinheiro::DINHEIRO_VALOR_INVALIDO = 1000001.00;

void TUDinheiro::testarCenarioValido(){
    valor->set(DINHEIRO_VALIDO);
    if (valor->get()!= DINHEIRO_VALIDO){
        std::cout<< "TUDinheiro: testarCenarioValido -> FALHA"<<std::endl;
        estado=FALHA;
        return;
    }
    std::cout<< "TUDinheiro: testarCenarioValido -> SUCESSO"<<std::endl;
}

void TUDinheiro::testarTamanhoInvalido(){
    try{
        valor->set(DINHEIRO_TAMANHO_INVALIDO);
        std::cout<< "TUDinheiro: testarTamanhoInvalido -> FALHA"<<std::endl;
        estado=FALHA;
   } catch(std::invalid_argument &except){
        std::cout<< "TUDinheiro: testarTamanhoInvalido -> SUCESSO"<<std::endl;
   }
}

void TUDinheiro::testarValorInvalido(){
    try{
        valor->set(DINHEIRO_VALOR_INVALIDO);
        std::cout<< "TUDinheiro: testarValorInvalido -> FALHA"<<std::endl;
    } catch(std::invalid_argument &except){
        std::cout<< "TUDinheiro: testarValorInvalido -> SUCESSO"<<std::endl;
    }
}