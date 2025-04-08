#ifndef DOMINIOS_HPP_INCLUDED
#define DOMINIOS_HPP_INCLUDED

#include <string>


class Codigo {
    private:
        std::string codigo;
        void validaCodigo(std::string cod);

    public:
        void setCod(std::string codigo);
        std::string getValor() const {return codigo;}
};


class CodigoNegociacao {
    private:
        std::string codNegociacao;
        void validaCodNegociacao(std::string cod);

    public:
        void setCodNegociacao(std::string codNegociacao);
        std::string getCodNegociacao() const {return codNegociacao;}
};


class CPF {
    private:
        std::string cpf;
        void validaCPF(std::string cpf);

    public:
        void setCPF(std::string cpf);
        std::string getCPF() const {return cpf;}
};

class Data {
    private:
        std::string data;
        bool ehAnoBissexto(int ano){
            // Combinamos metodos de retorno direto na classe? inline?
            return (ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0);
        };
        void validar(const std::string& data);
        
    public:
        void set(std::string ano);
        std::string get(){return data;}
};

#endif // DOMINIOS_HPP_INCLUDED
