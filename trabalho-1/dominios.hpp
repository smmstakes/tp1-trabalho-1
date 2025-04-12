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
        static const int TAMANHO_MAX = 6;
        static const std::regex PADRAO_SENHA;
        void validar(std::string senha);

    public:
        void set(std::string senha);
        std::string get() const {return senha;}
};

#endif // DOMINIOS_HPP_INCLUDED
