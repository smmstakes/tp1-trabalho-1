#include <regex>
#include <string>
#include <iostream>
#include <stdexcept>
#include <unordered_set>

#include "dominios.hpp"

const std::regex Codigo::PADRAO_CODIGO("[0-9]{5}");

void Codigo::validar(const std::string& cod) {
    if (!std::regex_match(cod, PADRAO_CODIGO)) {
        throw std::invalid_argument("Código inválido: ");
    }
}

const std::regex CodigoNegociacao::PADRAO_CODIGO_NEGOCIACAO("\\w[a-zA-Z0-9 ]{0,11}");

void CodigoNegociacao::validar(const std::string& cod) {
    if (!std::regex_match(cod, PADRAO_CODIGO_NEGOCIACAO)) {
        throw std::invalid_argument("Codigo de Negociação inválido: ");
    }
}

const std::regex CPF::PADRAO_CPF("[0-9]{3}.[0-9]{3}.[0-9]{3}-[0-9]{2}");

void CPF::validar(const std::string& cpf) {
    if (!std::regex_match(cpf, PADRAO_CPF)) {
        throw std::invalid_argument("CPF não segue o padrão pedido.");
    }
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

    if (ano == 0) {
        throw std::invalid_argument("Ano inválido: não é permitido o ano 0000.");
    }

    if (mes < 1 || mes > 12)
        throw std::invalid_argument("Mês inválido: deve estar entre 01 e 12.");

    int diasNoMes[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };

    if (mes == 2 && ehAnoBissexto(ano)) {
        diasNoMes[2] = 29;
    }

    if (dia < 1 || dia > diasNoMes[mes])
        throw std::invalid_argument("Dia inválido para o mês informado.");
}

const std::regex Nome::FORMATO("^[A-Za-z0-9 ]+$");

void Nome::validar(const std::string& nome){

    if (nome.size() > LIMITE_CARACTERES_NOME){
        throw std::invalid_argument("O nome não pode ser maior do que 20 caracteres");
    }

    if(!std::regex_match(nome, FORMATO)){
        throw std::invalid_argument("O nome não pode ter caracteres especiais");
    }

    for (size_t i = 1; i < nome.length(); i++){
        if (nome[i] == ' ' && nome[i] == nome[i-1]){
            throw std::invalid_argument("O nome não pode ter dois espaços em branco seguidos");
        }
    }
};

const int Nome::LIMITE_CARACTERES_NOME = 20;

const std::regex Perfil::PADRAO_PERFIL("(Conservador|Moderado|Agressivo)");

void Perfil::validar(const std::string& perfil){
    if (!std::regex_match(perfil, PADRAO_PERFIL)){
        throw std::invalid_argument("Perfil inválido.");
    }
}

const double Dinheiro::DINHEIRO_MIN = 0.01;
const double Dinheiro::DINHEIRO_MAX = 1000000.00;
  
void Dinheiro::validar(const double& dinheiro){
    if (dinheiro > DINHEIRO_MAX || dinheiro < DINHEIRO_MIN){
        throw std:: invalid_argument ("Quantia de Dinheiro Inválida, por favor digite um valor entre 0.01 a 1000000.00.");
    }
}

void Quantidade::validar(const int& Quantidade){
    if (quantidade < VALOR_MIN || quantidade > VALOR_MAX){
        throw std::invalid_argument("Quantidade Inválida, por favor digite um valor entre 1 a 1000000.");
    }
}

const std::regex Senha::PADRAO_SENHA("[a-zA-Z0-9#$%&]{6}");

void Senha::validar(const std::string& senha) {
    if (!std::regex_match(senha, PADRAO_SENHA)) {
        throw std::invalid_argument("Senha inválida deve ter exatamente 6 caracteres válidos.");
    }

    std::unordered_set<char> caracteres;

    bool temDigito = false;
    bool temEspecial = false;
    bool temMaiuscula = false;
    bool temMinuscula = false;

    for (auto c : senha) {
        caracteres.insert(c);

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

    if (caracteres.size() != TAMANHO_SENHA) {
        throw std::invalid_argument("Senha contém caracteres duplicados.");
    }

    if (!temDigito || !temEspecial || !temMaiuscula || !temMinuscula) {
        throw std::invalid_argument("Senha não contém todos os caracteres necessários.");
    }
}
