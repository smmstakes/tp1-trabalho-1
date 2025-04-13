#ifndef DOMINIOS_HPP_INCLUDED
#define DOMINIOS_HPP_INCLUDED

#include <regex>
#include <string>


class Codigo {
    private:
        std::string codigo;
        static const std::regex PADRAO_CODIGO;
        void validaCodigo(std::string cod);

    public:
        void setCod(std::string codigo);
        std::string getValor() const {return codigo;}
};


class CodigoNegociacao {
    private:
        std::string codNegociacao;
        static const std::regex PADRAO_CODIGO_NEGOCIACAO;
        void validaCodNegociacao(std::string cod);

    public:
        void setCodNegociacao(std::string codNegociacao);
        std::string getCodNegociacao() const {return codNegociacao;}
};


class CPF {
    private:
        std::string cpf;
        static const std::regex PADRAO_CPF;
        void validaCPF(std::string cpf);

    public:
        void setCPF(std::string cpf);
        std::string getCPF() const {return cpf;}
};

class Dinheiro {
    private :
        double dinheiro;
        static const double DINHEIRO_MIN = 0.01;
        static const double DINHEIRO_MAX = 1000000.00;
        void validar(double dinheiro);
    public:
        double get() {return dinheiro};
        void set(double dinheiro);
// Criado por Pedro Vale - 231038733
};

class Quantidade {
    private:
        int quantidade;
        static const int VALOR_MIN= 1;
        static const int VALOR_MAX=1000000;
        void validar(int quantidade);
    public:
        int get() {return quantidade};
        void set(int quantidade);
// Criada por Pedro Vale - 231038733
};

class Data {
    private:
        static const std::regex FORMATO;
        std::string data;
        bool ehAnoBissexto(int ano) const{
            // Combinamos metodos de retorno direto na classe? inline?
            return (ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0);
        };
        void validar(const std::string& data);

    public:
        void set(std::string ano);
        std::string get() const {return data;}
};

#endif // DOMINIOS_HPP_INCLUDED
