#include "dominios.hpp"

#include <stdexcept>
#include <string>
#include <regex>


void Codigo::validaCodigo(std::string cod) {
    std::regex regExp("[0-9]{5}");
    if (!std::regex_match(cod, regExp)) {
        throw std::invalid_argument("Código inválido.");
    }
}

void Codigo::setCod(std::string codigo) {
    validaCodigo(codigo);
    this->codigo = codigo;
}


void CodigoNegociacao::validaCodNegociacao(std::string cod) {
    std::regex regExp("\\w[a-zA-Z0-9 ]{0,11}");
    if (!std::regex_match(cod, regExp)) {
        throw std::invalid_argument("Codigo de Negociação inválido.");
    }
}

void CodigoNegociacao::setCodNegociacao(std::string codNegociacao) {
    validaCodNegociacao(codNegociacao);
    this->codNegociacao = codNegociacao;
}


void CPF::validaCPF(std::string cpf) {
    std::regex regExp("[0-9]{3}.[0-9]{3}.[0-9]{3}-[0-9]{2}");
    if (!std::regex_match(cpf, regExp)) {
        throw std::invalid_argument("CPF inválido.");
    }
}

void CPF::setCPF(std::string cpf) {
    validaCPF(cpf);
    this->cpf = cpf;
}



