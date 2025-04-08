#include <set>
#include <regex>
#include <string>
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


const std::regex Senha::PADRAO_SENHA("[a-zA-Z0-9#$%&]{6}");

void Senha::validaSenha(std::string senha) {
    if (!std::regex_match(senha, PADRAO_SENHA)) {
        throw std::invalid_argument("Senha inválida deve ter exatamente 6 caracteres válidos.");
    }

    std::set<char> caracteresSenha;
    bool temDigito = false;
    bool temEspecial = false;
    bool temMaiuscula = false;
    bool temMinuscula = false;

    for (auto c : senha) {
        caracteresSenha.insert(c);

        if (std::isdigit(c)) {
            temDigito = true;
        } else if (std::isupper(c)) {
            temMaiuscula = true;
        } else if (std::islower(c)) {
            temMinuscula = true;
        } else if (c == '#' || c == '$' || c == '%' || c == '&') {
            temEspecial = true;
        }
    }

    if (!temDigito || !temEspecial || !temMaiuscula || !temMinuscula) {
        throw std::invalid_argument("Senha não contém todos os caracteres necessários.");
    }
}

void Senha::setSenha(std::string senha) {
    validaSenha(senha);
    this->senha = senha;
}