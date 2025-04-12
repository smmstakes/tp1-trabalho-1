#include <set>
#include <regex>
#include <string>
#include <stdexcept>

#include "dominios.hpp"


const std::regex Codigo::PADRAO_CODIGO("[0-9]{5}");

void Codigo::validar(std::string cod) {
    if (!std::regex_match(cod, PADRAO_CODIGO)) {
        throw std::invalid_argument("Código inválido.");
    }
}

void Codigo::set(std::string codigo) {
    validar(codigo);
    this->codigo = codigo;
}


const std::regex CodigoNegociacao::PADRAO_CODIGO_NEGOCIACAO("\\w[a-zA-Z0-9 ]{0,11}");

void CodigoNegociacao::validar(std::string cod) {
    if (!std::regex_match(cod, PADRAO_CODIGO_NEGOCIACAO)) {
        throw std::invalid_argument("Codigo de Negociação inválido.");
    }
}

void CodigoNegociacao::set(std::string codNegociacao) {
    validar(codNegociacao);
    this->codNegociacao = codNegociacao;
}


const std::regex CPF::PADRAO_CPF("[0-9]{3}.[0-9]{3}.[0-9]{3}-[0-9]{2}");

void CPF::validar(std::string cpf) {
    if (!std::regex_match(cpf, PADRAO_CPF)) {
        throw std::invalid_argument("CPF não segue o padrão pedido.");
    }
}

void CPF::set(std::string cpf) {
    validar(cpf);
    this->cpf = cpf;
}


const std::regex Senha::PADRAO_SENHA("[a-zA-Z0-9#$%&]{6}");

void Senha::validar(std::string senha) {
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

void Senha::set(std::string senha) {
    validar(senha);
    this->senha = senha;
}