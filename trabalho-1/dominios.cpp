#include "dominios.hpp"

#include <stdexcept>
#include <string>
#include <iostream>
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
    // TODO: Precisa retornar um erro tratado caso o código a ser setado já exista no bd
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

void Data::validar(const std::string& data) {
    std::regex formato("^\\d{8}$");

    if (!std::regex_match(data, formato)) {
        throw std::invalid_argument("Formato inválido: a data deve ter 8 dígitos numéricos (YYYYMMDD).");
    }

    int ano, mes, dia;

    ano = std::stoi(data.substr(0, 4));
    mes = std::stoi(data.substr(4, 2));
    dia = std::stoi(data.substr(6, 2));
    
    if (mes < 1 || mes > 12)
        throw std::invalid_argument("Mês inválido: deve estar entre 01 e 12.");

    int diasNoMes[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };

    if (mes == 2 && this->ehAnoBissexto(ano)) {
        diasNoMes[2] = 29;
    }

    if (dia < 1 || dia > diasNoMes[mes])
        throw std::invalid_argument("Dia inválido para o mês informado.");
}

void Data::set(std::string data){
    this->validar(data);
    this->data = data;
}
