#include <string>
#include <iostream>
#include <stdexcept>

#include "conta_test.hpp"

const std::string TUConta::CPF_VALIDO = "123-456-789-10";
const std::string TUConta::NOME_VALIDO = "FuLAN0 da SILV4";
const std::string TUConta::SENHA_VALIDA = "01ABc%";

void TUConta::setUp(){
    entidade = new Conta(CPF_VALIDO, NOME_VALIDO, SENHA_VALIDA);
    estado = SUCESSO;
}

void TUConta::testarCenarioValido(){
    try {
        if (entidade->getCpf() != CPF_VALIDO) {
            std::cout << "TUConta: testarCenarioValido -> CPF -> FALHA\n";
            estado = FALHA;
            return;
        }
        std::cout << "TUConta: testarCenarioValido -> CPF -> SUCESSO\n";

        if (entidade->getNome() != NOME_VALIDO) {
            std::cout << "TUConta: testarCenarioValido -> Nome -> FALHA\n";
            estado = FALHA;
            return;
        }
        std::cout << "TUConta: testarCenarioValido -> Nome -> SUCESSO\n";

        if (entidade->getSenha() != SENHA_VALIDA) {
            std::cout << "TUConta: testarCenarioValido -> Senha -> FALHA\n";
            estado = FALHA;
            return;
        }
        std::cout << "TUConta: testarCenarioValido -> Senha -> SUCESSO\n";

    } catch(std::invalid_argument &excecao) {
        std::cout << "TUConta: testarCenarioValido -> FALHA\n";
        estado = FALHA;
    }
}

int TUConta::run(){
    setUp();

    testarCenarioValido();

    tearDown();
    return estado;
}