#ifndef ENTIDADES_HPP_INCLUDED
#define ENTIDADES_HPP_INCLUDED

#include <string>

#include "dominios.hpp"

class Ordem {
    private:
        Codigo codigo;
        CodigoNegociacao codNegociacao;
        Data data;
        Dinheiro preco;
        Quantidade quantidade;

    public:
        Ordem(const std::string& cod, const std::string& codNeg, const std::string& data,
        double preco, int qtd);
        std::string getCodigo() const {return codigo.get();}
        std::string getCodNegociacao() const {return codNegociacao.get();}
        std::string getData() const {return data.get();}
        double getDinheiro() const {return preco.get();}
        int getQuantidade() const {return quantidade.get();}
};

#endif // ENTIDADES_HPP_INCLUDED
