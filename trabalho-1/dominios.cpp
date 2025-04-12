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


void Dinheiro::validarDinheiro(float dinheiro)
{
    if (dinheiro > Dinheiro_Max && dinheiro < Dinheiro_Min){
        throw std:: invalid_argument ("Quantia de Dinheiro Inválida, por favor digite um valor entre 0.01 a 1000000.00 .");
    }
}
void Dinheiro::setDinheiro (float dinheiro)
{
    validarDinheiro(dinheiro);
    this-> dinheiro = dinheiro;

}

void Quantidade::validarQuantidade(int Quantidade)
{
    if (quantidade<Valor_Min || quantidade > Valor_Max)
    {
        throw std :: invalid_argument("Quantidade Inválida, por favor digite um valor entre 1 a 1000000 .");
    }
}

void Quantidade::setQuantidade (int quantidade)
{
    validarQuantidade(quantidade);
    this-> quantidade = quantidade;
}


