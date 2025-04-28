#include <iostream>
#include <stdexcept>

#include "perfil_test.hpp"

const std::string TUPerfil::PERFIL_VALIDO = "Moderado"; // Pode ser Conservador, Moderado ou Agressivo
const std::string TUPerfil::PERFIL_INVALIDO = "Radical"; //Qualquer coisa que não seja nenhum dos três

void TUPerfil::testarCenarioValido(){
    try{
        valor->set(PERFIL_VALIDO);
        if (valor->get() != PERFIL_VALIDO){
            std::cout << "TUPerfil: testarCenarioValido -> FALHA\n";
            estado = FALHA;
            return;
        }
        std::cout << "TUPerfil: testarCenarioValido -> SUCESSO\n";
    } catch(const std::exception& execao){
        std::cout << "TUPerfil: testarCenarioValido -> FALHA\n";
        estado = FALHA;
    }
}

void TUPerfil::testarCenarioInvalido(){
    try{
        valor->set(PERFIL_INVALIDO);
        std::cout << "TUPerfil: testarTamanhoInvalido -> FALHA\n";
        estado = FALHA;

    } catch(const std::invalid_argument& execao){
        std::cout << "TUPerfil: testarTamanhoInvalido -> SUCESSO\n";
    }    
}

int TUPerfil::run(){
    setUp();

    testarCenarioValido();
    testarCenarioInvalido();

    tearDown();
    return estado;
}