#ifndef ENTIDADES_HPP_INCLUDED
#define ENTIDADES_HPP_INCLUDED
#include <string>
#include "dominios.hpp"

class Carteira {
    private:
        Codigo codigo;
        Nome nome;
        Perfil perfil;
    public:
        Carteira (const std::string& codigo,const std::string& nome, const std::string& perfil);
        std::string getCodigo() const{return codigo.get();}
        std::string getNome() const {return nome.get();}
        std::string getPerfil() const {return perfil.get();}
        void setNome(std::string nome);
        void setPerfil(std::string perfil);
    };

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

class Conta{
    private:
        CPF cpf; 
        Nome nome;
        Senha senha;

    public:
        Conta(const std::string& cpf, const std::string& nome, const std::string& senha);
        std::string getCpf() const {return cpf.get();}
        std::string getNome() const {return nome.get();}
        std::string getSenha() const {return senha.get();}           
        void setNome(std::string nome);
        void setSenha(std::string senha);     
};
#endif // ENTIDADES_HPP_INCLUDED
