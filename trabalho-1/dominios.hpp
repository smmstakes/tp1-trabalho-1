#ifndef DOMINIOS_HPP_INCLUDED
#define DOMINIOS_HPP_INCLUDED

#include <regex>
#include <string>


class Codigo {
    private:
        std::string codigo;
        static const std::regex PADRAO_CODIGO;
        void validar(std::string cod);

    public:
        void set(std::string codigo);
        std::string get() const {return codigo;}
};


class CodigoNegociacao {
    private:
        std::string codNegociacao;
        static const std::regex PADRAO_CODIGO_NEGOCIACAO;
        void validar(std::string cod);

    public:
        void set(std::string codNegociacao);
        std::string get() const {return codNegociacao;}
};


class CPF {
    private:
        std::string cpf;
        static const std::regex PADRAO_CPF;
        void validar(std::string cpf);

    public:
        void set(std::string cpf);
        std::string get() const {return cpf;}
};


class Senha {
    private:
        std::string senha;
        static const std::regex PADRAO_SENHA;
        void validar(std::string senha);

    public:
        void set(std::string senha);
        std::string get() const {return senha;}
};

class Dinheiro {
    private :
        double dinheiro;
        static const double DINHEIRO_MIN;
        static const double DINHEIRO_MAX;
        void validar(double dinheiro);
    public:
        double get() const {return dinheiro};
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
        int get() const {return quantidade};
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

class Perfil {
    private:
    std::string perfil;
    static const std::regex PADRAO_PERFIL;
    void valida(std::string perfil);

    public:
    void set(std::string perfil);
    std::string get() const{return perfil;}
};

#endif // DOMINIOS_HPP_INCLUDED
