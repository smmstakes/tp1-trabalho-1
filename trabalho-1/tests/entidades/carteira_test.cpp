#include "carteira_test.hpp"

#include <iostream>
#include <string>
#include <stdexcept>

const std::string TUCarteira::CODIGO_VALIDO = "24680";
const std::string TUCarteira::NOME_VALIDO = "Felipe Santos 10";
const std::string TUCarteira::PERFIL_VALIDO = "Conservador";

void TUCarteira::setUp() {
    entidade = new Carteira(CODIGO_VALIDO, NOME_VALIDO, PERFIL_VALIDO);
    estado = SUCESSO;
}

void TUCarteira::testarCenarioValido(){
    try{
        if(entidade->getCodigo() != CODIGO_VALIDO){
            std::cout << "TUCarteira: testarCenarioValido -> Codigo -> FALHA" <<std::endl;
            estado = FALHA;
        }
        std::cout<< "TUCarteira: testarCenarioValido -> Codigo -> SUCESSO"<<std::endl;
        
        if(entidade->getNome() != NOME_VALIDO){
            std::cout<<"TUCarteira: testarCenarioValido -> Nome -> FALHA"<<std::endl;
            estado = FALHA;
        }
        std::cout<<"TUCarteira: testarCenarioValido -> Nome -> SUCESSO"<<std::endl;

        if (entidade->getPerfil()!= PERFIL_VALIDO){
            std::cout<< "TUCarteira: testarCenarioValido -> Perfil -> FALHA"<<std::endl;
            estado = FALHA;
        }
        std::cout<<"TUCarteira: testarCenarioValido -> Perfil -> SUCESSO"<<std::endl;
    } catch (std::invalid_argument &excecao){
        std::cout<< "TUCarteira: testarCenarioValido -> FALHA"<<std::endl;
        estado = FALHA;
    }
}

int TUCarteira::run (){
    setUp();
    testarCenarioValido();
    tearDown();
    return estado;
}