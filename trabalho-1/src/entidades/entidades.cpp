#include <string>
#include "entidades.hpp"

Carteira::Carteira (const std::string& codigo, const std::string& nome, 
    const std::string& perfil) : codigo{}, nome{}, perfil {} {
        this->codigo.set(codigo);
        this->nome.set(nome);
        this->perfil.set(perfil);
    }

Ordem::Ordem(const std::string& cod, const std::string& codNeg, const std::string& data,
    double preco, int qtd) : codigo {}, codNegociacao {}, data {}, preco {}, quantidade {} {
    codigo.set(cod);
    codNegociacao.set(codNeg);
    this->data.set(data);
    this->preco.set(preco);
    quantidade.set(qtd);
}

Conta::Conta(const std::string& cpf, const std::string& nome, const std::string& senha)
    : cpf{}, nome{}, senha{} {
    this->cpf.set(cpf);
    this->nome.set(nome);
    this->senha.set(senha);
}
