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

class Dinheiro
{
    private :
        float dinheiro;
        static const float Dinheiro_Min = 0.01;
        static const float Dinheiro_Max = 1000000.00;
        void validarDinheiro (float dinheiro);
    public:
        float getDinheiro(float dinheiro) const {return dinheiro};
        void setDinheiro (float dinheiro);
};

class Quantidade
{
    private:
        int quantidade;
        static const int Valor_Min= 1;
        static const int Valor_Max=1000000;
        void validarQuantidade (int quantidade);
    public:
        int getQuantidade (int quantidade) const {return quantidade};
        void setQuantidade (int quantidade);

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
