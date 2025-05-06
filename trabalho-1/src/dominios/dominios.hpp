#ifndef DOMINIOS_HPP_INCLUDED
#define DOMINIOS_HPP_INCLUDED

/**
 * @file dominios.hpp
 * @brief Declaração das classes de domínio.
 * 
 * @details Este arquivo contém as definições da classe base e derivadas desta, 
 * que representam os domínios presentes no sistema.
 * 
 * @author Gabriel Castro
 * @author José Artur
 * @author Matheus Duarte
 * @author Pedro Vale
 * @author Suyanne Miranda
 * @date 01/05/2025
 */

#include <regex>
#include <string>

/**
 * @class Dominio
 * @brief Classe base genérica para domínios.
 * 
 * @details Essa classe define a classe genérica Dominio, utilizada como base
 * para a criação dos outros domínios, garantindo um padrão.
 * 
 * @tparam Tipo Tipo do domínio.
 */
template<typename Tipo>
class Dominio {
    private:
        Tipo valor;
        virtual void validar(const Tipo& valor) = 0;

    public:
        /**
         * @brief Define o valor do domínio após validação.
         * 
         * @param valor Valor a ser atribuído.
         * 
         * @throw std::invalid_argument Se o valor for inválido.
         */
        void set(const Tipo& valor) {
            validar(valor);
            this->valor = valor;
        };

        /**
         * @brief Retorna o valor armazenado no domínio.
         * 
         * @return Tipo Tipo do domínio.
         */
        Tipo get() const { return valor; };

        virtual ~Dominio() = default;
};

/**
 * @class Codigo
 * @brief Representa um código de 5 dígitos numéricos.
 */
class Codigo:public Dominio<std::string> {
    private:
        static const std::regex PADRAO_CODIGO;

        void validar(const std::string& cod) override;

// Criado por Matheus Duarte - 211062277
};

/**
 * @class CodigoNegociacao
 * @brief Representa um código de negociação para ordens de compra.
 * 
 * @details Código alfanumérico com até 12 caracteres, incluindo espaços.
 */
class CodigoNegociacao:public Dominio<std::string> {
    private:
        static const std::regex PADRAO_CODIGO_NEGOCIACAO;

        void validar(const std::string& cod) override;

// Criado por Matheus Duarte - 211062277
};

/**
 * @class CPF
 * @brief Representa um CPF no formato XXX.XXX.XXX-XX.
 * 
 * @details Utilizado para identificar o titular da conta.
 */
class CPF:public Dominio<std::string> {
    private:
        static const std::regex PADRAO_CPF;

        void validar(const std::string& cpf) override;

// Criado por Matheus Duarte - 211062277
};

class Data:public Dominio<std::string> {
    private:
        static const std::regex PADRAO_DATA;

        bool ehAnoBissexto(int ano) const {
            return (ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0);
        };
        void validar(const std::string& data) override;
// Criada por Suyanne Miranda - 222006445
};

class Nome:public Dominio<std::string> {
    private:
        static const int TAMANHO_NOME = 20;
        static const std::regex PADRAO_NOME;

        void validar(const std::string& nome) override;
};

class Perfil:public Dominio<std::string>{
    private:
        static const std::regex PADRAO_PERFIL;

        void validar(const std::string& perfil) override;
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
        static const int VALOR_MIN = 1;
        static const int VALOR_MAX = 1000000;

        void validar(const int& quantidade) override;
// Criada por Pedro Vale - 231038733
};

/**
 * @class Senha
 * @brief Representa a senha de uma Conta.
 * 
 * @details A senha do usuário deve conter os seguintes requisitos:
 * - Seis caracteres;
 * - Digitos alfanuméricos e os símbolos: #, $, % e &;
 * - Nenhum caractere duplicado;
 * - Pelo menos um dígito;
 * - Pelo menos uma letra maiúscula e uma minúscula;
 * - Pelo menos um caractere especial (#, $, % ou &).
 */
class Senha:public Dominio<std::string> {
    private:
        static const int TAMANHO_SENHA = 6;
        static const std::regex PADRAO_SENHA;

        void validar(const std::string& senha) override;

// Criado por Matheus Duarte - 211062277
};

#endif // DOMINIOS_HPP_INCLUDED
