#include <set>
#include <regex>
#include <string>
#include <iostream>
#include <stdexcept>

#include "dominios.hpp"

const std::regex Codigo::PADRAO_CODIGO("[0-9]{5}");

void Codigo::validaCodigo(std::string cod) {
    if (!std::regex_match(cod, PADRAO_CODIGO)) {
        throw std::invalid_argument("Código inválido.");
    }
}

void Codigo::setCod(std::string codigo) {
    validaCodigo(codigo);
    this->codigo = codigo;
    // TODO: Precisa retornar um erro tratado caso o código a ser setado já exista no bd
}

const std::regex CodigoNegociacao::PADRAO_CODIGO_NEGOCIACAO("\\w[a-zA-Z0-9 ]{0,11}");

void CodigoNegociacao::validaCodNegociacao(std::string cod) {
    if (!std::regex_match(cod, PADRAO_CODIGO_NEGOCIACAO)) {
        throw std::invalid_argument("Codigo de Negociação inválido.");
    }
}

void CodigoNegociacao::setCodNegociacao(std::string codNegociacao) {
    validaCodNegociacao(codNegociacao);
    this->codNegociacao = codNegociacao;
}

const std::regex CPF::PADRAO_CPF("[0-9]{3}.[0-9]{3}.[0-9]{3}-[0-9]{2}");

void CPF::validaCPF(std::string cpf) {
    if (!std::regex_match(cpf, PADRAO_CPF)) {
        throw std::invalid_argument("CPF inválido.");
    }
}

void CPF::setCPF(std::string cpf) {
    validaCPF(cpf);
    this->cpf = cpf;
}

const std::regex Data::FORMATO("^\\d{8}$");

void Data::validar(const std::string& data) {
    if (!std::regex_match(data, FORMATO)) {
        throw std::invalid_argument("Formato inválido: a data deve ter 8 dígitos numéricos (AAAAMMDD).");
    }

    int ano, mes, dia;

    ano = std::stoi(data.substr(0, 4));
    mes = std::stoi(data.substr(4, 2));
    dia = std::stoi(data.substr(6, 2));
    
    if (mes < 1 || mes > 12)
        throw std::invalid_argument("Mês inválido: deve estar entre 01 e 12.");

    int diasNoMes[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };

    if (mes == 2 && ehAnoBissexto(ano)) {
        diasNoMes[2] = 29;
    }

    if (dia < 1 || dia > diasNoMes[mes])
        throw std::invalid_argument("Dia inválido para o mês informado.");
}

void Data::set(std::string data){
    validar(data);
    this->data = data;
}

void Nome::validar(std::string nome){
    int vrfs = 0;
    int vrfb = 1;

    cout << "type a name ";
    getline(cin, nome);

    if (nome.size() > 20){
        cout << "The name is bigger than 20 characters, try again." << endl;
        validar();
        return;
    }
    else{
        vrfs = 1;
        cout << "The name has the correct size" << endl;
    }

    for (int i = 0; i < nome.size(); i++){
        if (nome[i] == ' ' && nome[i+1] == ' '){
            cout << "The name has two blank spaces, try again" << endl;
            vrfb = 0;
            validar();
            return;
        }
    }

    if(vrfb == 1){
        cout << "The name has no two blank spaces" << endl;
        }

    if (vrfs == 1 && vrfb == 1){
        cout << "The name is correct" << endl;
    }
}

void Nome::set(std::string nome){
    validar(nome);
    this->nome = nome;
}