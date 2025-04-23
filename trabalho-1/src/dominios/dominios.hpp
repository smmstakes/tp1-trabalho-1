#ifndef DOMINIOS_HPP_INCLUDED
#define DOMINIOS_HPP_INCLUDED

#include <regex>
#include <string>

template<typename Tipo>
class Dominio {
    private:
        Tipo valor;
        virtual void validar(const Tipo& valor) = 0;

    public:
        void set(const Tipo& valor) {
            validar(valor);
            this->valor = valor;
        };
        Tipo get() const { return valor; };

        virtual ~Dominio() = default;
};

class Codigo:public Dominio<std::string> {
    private:
        static const std::regex PADRAO_CODIGO;
        void validar(const std::string& cod) override;
};

class Nome:public Dominio<std::string> {
    private:
        static const int LIMITE_CARACTERES_NOME;
        static const std::regex FORMATO;
        void validar(const std::string& nome) override;
};

class CodigoNegociacao:public Dominio<std::string> {
    private:
        static const std::regex PADRAO_CODIGO_NEGOCIACAO;
        void validar(const std::string& cod) override;
};

class CPF:public Dominio<std::string> {
    private:
        static const std::regex PADRAO_CPF;
        void validar(const std::string& cpf) override;
};

class Dinheiro:public Dominio<double> {
    private :
        double dinheiro;
        static const double DINHEIRO_MIN;
        static const double DINHEIRO_MAX;
        void validar(const double& dinheiro) override;
// Criado por Pedro Vale - 231038733
};

class Quantidade:public Dominio<int> {
    private:
        int quantidade;
        static const int VALOR_MIN= 1;
        static const int VALOR_MAX=1000000;
        void validar(const int& quantidade) override;
// Criada por Pedro Vale - 231038733
};

class Data:public Dominio<std::string> {
    private:
        static const std::regex FORMATO;
        bool ehAnoBissexto(int ano) const {
            return (ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0);
        };
        void validar(const std::string& data) override;
// Criada por Suyanne Miranda - 222006445
};

class Perfil:public Dominio<std::string>{
    private:
        static const std::regex PADRAO_PERFIL;
        void validar(const std::string& perfil) override;
};

class Senha:public Dominio<std::string> {
    private:
        static const int TAMANHO_SENHA = 6;
        static const std::regex PADRAO_SENHA;
        void validar(const std::string& senha) override;
};

#endif // DOMINIOS_HPP_INCLUDED
