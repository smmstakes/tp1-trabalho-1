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
 * @details Essa classe serve como modelo a ser seguido pelas outras classes
 * domínios, evitando repetição de código e padronizando o projeto.
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
         * @param valor Valor a ser atribuído ao domínio.
         * 
         * @throw std::invalid_argument Exceção caso o valor informado não esteja 
         * de acordo com as especificações.
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
 * @brief Sequência de caracteres para identificar de entidades.
 * 
 * @details Deve conter uma sequência de 5 caracteres numéricos.
 */
class Codigo:public Dominio<std::string> {
    private:
        static const std::regex PADRAO_CODIGO;

        void validar(const std::string& cod) override;

// Criado por Matheus Duarte - 211062277
};

/**
 * @class CodigoNegociacao
 * @brief Identificador das ações negociadas no sistema financeiro.
 * 
 * @details Deve conter um conjunto de 12 caracteres alfanuméricos, incluindo espaços.
 */
class CodigoNegociacao:public Dominio<std::string> {
    private:
        static const std::regex PADRAO_CODIGO_NEGOCIACAO;

        void validar(const std::string& cod) override;

// Criado por Matheus Duarte - 211062277
};

/**
 * @class CPF
 * @brief Documento de identificação, ou o número do Cadastro de Pessoa Física.
 * 
 * @details Deve conter 11 caracteres numéricos, formatados da seguinte forma:
 * XXX.XXX.XXX-XX.
 */
class CPF:public Dominio<std::string> {
    private:
        static const std::regex PADRAO_CPF;

        void validar(const std::string& cpf) override;

// Criado por Matheus Duarte - 211062277
};

/**
 * @class Data
 * @brief Ano, mês e dia para datação de ordens financeiras.
 * 
 * @details Deve conter 8 números representados como string no formato AAAAMMDD, considerando anos bissextos.
 */

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
/**
 * @class Perfil
 * @brief Classificação que define o quanto um investidor tolera riscos em busca de retorno financeiro na compra de ações, as categorias são:
 * - Conservador (evita riscos);
 * - Moderado (equilibra risco e retorno);
 * - Agressivo (assume altos riscos em busca de maiores ganhos).
 * 
 * @details O perfil do investidor deve obrigatoriamente se enquadrar em umas das três categorias: Conservador, Moderado ou Agressivo.
 * 
*/

class Perfil:public Dominio<std::string>{
    private:
        static const std::regex PADRAO_PERFIL;

        void validar(const std::string& perfil) override;
// Criado por Gabriel Castro - 202066571
};

/**
 * @class Dinheiro
 * @brief Quantia Númerica Econômica referente à identificação de precificação de uma ação financeira. 
 * 
 * @details A Quantia Numérica deve conter um número decimal entre 0,01 a 1000000,00.
 * 
*/

class Dinheiro:public Dominio<double> {
    private :
        double dinheiro;
        static const double DINHEIRO_MIN;
        static const double DINHEIRO_MAX;

        void validar(const double& dinheiro) override;
// Criado por Pedro Vale - 231038733
};

/**
 * @class Quantidade
 * @brief Valor Numérico medido para realizar uma contagem de números de ações financeiras desejada.
 * 
 * @details A Quantia Númerica deve conter apenas números inteiros positivos entre 1 a 1000000.
 * 
 */
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
 * @brief Conjunto de caracteres que fornece acesso à conta.
 * 
 * @details Método de autenticação para permitir acesso ao sistema.
 * 
 * Deve conter os seguintes requisitos:
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
