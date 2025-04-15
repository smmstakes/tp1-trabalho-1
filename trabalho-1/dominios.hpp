#ifndef DOMINIOS_HPP_INCLUDED
#define DOMINIOS_HPP_INCLUDED

#include <regex>
#include <string>

class Dominio {
    private:
        std::string valor;
        virtual void validar(std::string valor) = 0;

    public:
        void set(std::string codigo);
        std::string get() const { return valor; };
};

class Codigo:public Dominio {
    private:
        static const std::regex PADRAO_CODIGO;
        void validar(std::string cod);
};

class Nome {
    private:
        static const int LIMITE_CARACTERES_NOME;
        static const std::regex FORMATO;
        void validar(std::string nome);
};


class CodigoNegociacao {
    private:
        static const std::regex PADRAO_CODIGO_NEGOCIACAO;
        void validar(std::string cod);
};


class CPF {
    private:
        static const std::regex PADRAO_CPF;
        void validar(std::string cpf);
};

class Dinheiro {
    private :
        double dinheiro;
        static const double DINHEIRO_MIN;
        static const double DINHEIRO_MAX;
        void validar(double dinheiro);
    public:
        double get() const {return dinheiro;};
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
        int get() const {return quantidade;};
        void set(int quantidade);
// Criada por Pedro Vale - 231038733
};

class Data {
    private:
        static const std::regex FORMATO;
        bool ehAnoBissexto(int ano) const {
            return (ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0);
        };
        void validar(const std::string& data);
};


class Perfil {
    private:
        static const std::regex PADRAO_PERFIL;
        void validar(std::string perfil);
};

class Senha {
    private:
        static const std::regex PADRAO_SENHA;
        void validar(std::string senha);
};

#endif // DOMINIOS_HPP_INCLUDED
