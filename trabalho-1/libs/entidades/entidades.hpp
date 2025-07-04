#ifndef ENTIDADES_HPP_INCLUDED
#define ENTIDADES_HPP_INCLUDED

/**
 * @file entidades.hpp
 * @brief Declaração das classes de entidades.
 * 
 * @details Este arquivo contém as definições das entidades presentes no sistema.
 * 
 * @author Gabriel Castro
 * @author José Artur
 * @author Matheus Duarte
 * @author Pedro Vale
 * @author Suyanne Miranda
 * @date 01/05/2025
 */

#include <string>

#include "../dominios/dominios.hpp"

/**
 * @class Conta
 * @brief Representa os dados de acesso de um usuário ao sistema.
 * 
 * @details A conta é composta por CPF, nome completo e senha.
 *
 * Essa entidade pode ser modificada após sua criação, excluída ou visualizada.
 */
class Conta {
    private:
        CPF cpf; 
        Nome nome;
        Senha senha;

    public:
        /**
         * @brief Constrói uma nova instância de Conta setando os atributos de CPF, Nome e Senha.
         * 
         * @param cpf CPF do usuário (formato XXX.XXX.XXX-XX).
         * @param nome Nome completo do usuário (até 20 caracteres).
         * @param senha Senha de acesso (6 caracteres alfauméricos e especiais).
         * 
        /**
         * @throw std::invalid_argument Se o CPF, o nome ou a senha não estiverem de acordo com as especificações.
         */

        Conta(const std::string& cpf, const std::string& nome, const std::string& senha);
        Conta(const std::string& cpf, const std::string& senha);

        /**
         * @brief Provêm CPF associado à conta.
         * 
         * @return CPF como string.
         */
        std::string getCpf() const { return cpf.get(); }

        /**
         * @brief Provêm nome do titular da conta.
         * 
         * @return Nome como string.
         */
        std::string getNome() const { return nome.get(); }

        /**
         * @brief Provêm a senha da conta.
         * 
         * @return Senha como string.
         */
        std::string getSenha() const { return senha.get(); }

// Criado por Gabriel Castro - 202066571             
};

/**
 * @class Carteira
 * @brief Identificação de Ativos Financeiros pertencentes à uma Pessoa Física.
 * 
 * @details Possui elementos de Código, Nome e Perfil, para identificar a pessoa dona da Carteira.
 * 
 */

class Carteira {
    private:
        Codigo codigo;
        Nome nome;
        Perfil perfil;

    public:
    /**
     * @brief Constroi uma instância Carteira com atributos de codigo, nome e perfil.
     * @param codigo Código identificador da ordem (5 dígitos).
     * @param Nome Nome completo do usuário (até 20 caracteres).
     * @param Perfil Caracteristica financeira do usuário (Conservador/Moderado/Agressivo).
     * 
     * @throw std::invalid_argument Para caso os atributos código,nome e perfil, não estejam de acordo com as especificações.
     * 
     */
        Carteira (const std::string& codigo,const std::string& nome, const std::string& perfil);

        /**
         * @brief Provem o Código de Identificação da Carteira.
         * @return Código da Carteira como string.
         */
        std::string getCodigo() const{return codigo.get();}
        
        /**
         * @brief Provem o Nome do Usuário da Carteira.
         * @return Nome da Carteira como string.
         */
        std::string getNome() const {return nome.get();}

        /**
         * @brief Provem o Perfil Financeiro do Usuário da Carteira.
         * @return Perfil da Carteira como string.
         */
        std::string getPerfil() const {return perfil.get();}

        /**
         * @brief Define ou Edita o Nome de Usuário.
         * 
         * @throw std::invalid_argument Caso o Nome não esteja de acordo com as especificações.
         */
        void setNome(std::string nome);

        /**
         * @brief Define ou Edita o Perfil Financeiro do Usuário.
         * 
         * @throw std::invalid_argument Caso o Perfil não esteja de acordo com as especificações.
         */
        void setPerfil(std::string perfil);
        
// Criado por Pedro Vale - 231038733
};

/**
 * @class Ordem
 * @brief Documento comercial que tem o papel de oficializar a compra da ação.
 * 
 * @details A ordem contém informações como código identificador, código de negociação,
 * data da operação, preço e quantidade negociada.
 * 
 * Essa entidade não pode ser modificada após sua criação, mas pode ser excluída ou visualizada.
 */
class Ordem {
    private:
        Codigo codigo;
        CodigoNegociacao codNegociacao;
        Data data;
        Dinheiro preco;                 
        Quantidade quantidade;
    
    public:
        /**
         * @brief Constrói uma nova instância de Ordem setando o código, código de negociação, data, preço e quantidade.
         * 
         * @param cod Código identificador da ordem (5 dígitos).
         * @param codNeg Código de negociação (até 12 caracteres alfanuméricos).
         * @param data Data de compra da ordem (AAAAMMDD).
         * @param preco Valor da negociação (entre 0.01 e 1.000.000,00).
         * @param qtd Quantidade negociada (entre 1 e 1.000.000).
         * 
         * @throw std::invalid_argument Se o código, código de negociação, data, preço e quantidade não estiverem de acordo com as especificações.
         */
        Ordem(const std::string& cod, const std::string& codNeg, const std::string& data,
              double preco, int qtd);
    
        /**
         * @brief Provêm o código identificador da ordem.
         * 
         * @return Código da ordem como string.
         */
        std::string getCodigo() const {return codigo.get();}
    
        /**
         * @brief Provêm o código de negociação associado à ordem.
         * 
         * @return Código de negociação como string.
         */
        std::string getCodNegociacao() const {return codNegociacao.get();}
    
        /**
         * @brief Provêm a data de compra da ordem.
         * 
         * @return Data da compra como string.
         */
        std::string getData() const {return data.get();}
    
        /**
         * @brief Retorna o valor monetário da ordem.
         * 
         * @return Preço da ordem como número de precisão dupla.
         */
        double getDinheiro() const {return preco.get();}
    
        /**
         * @brief Retorna a quantidade de unidades negociadas.
         * 
         * @return Quantidade como número inteiro.
         */
        int getQuantidade() const {return quantidade.get();}
        
// Criado por Matheus Duarte - 211062277
};

#endif  // ENTIDADES_HPP_INCLUDED
