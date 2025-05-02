#ifndef ENTIDADES_HPP_INCLUDED
#define ENTIDADES_HPP_INCLUDED

/**
 * @file entidades.hpp
 * @brief Declaração das classes de entidades.
 * 
 * @details Este arquivo contém as definições das classes 
 * que representam as entidades do sistema.
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

class Conta{
    private:
        CPF cpf; 
        Nome nome;
        Senha senha;

    public:
        Conta(const std::string& cpf, const std::string& nome, const std::string& senha);
        std::string getCpf() const {return cpf.get();}
        std::string getNome() const {return nome.get();}
        std::string getSenha() const {return senha.get();}                
};

class Carteira {
    private:
        Codigo codigo;
        Nome nome;
        Perfil perfil;

    public:
        Carteira (const std::string& codigo,const std::string& nome, const std::string& perfil);
        std::string getCodigo() const{return codigo.get();}
        std::string getNome() const {return nome.get();}
        std::string getPerfil() const {return perfil.get();}
        void setNome(std::string nome);
        void setPerfil(std::string perfil);
    };

/**
 * @class Ordem
 * @brief Representa uma ordem de negociação no sistema.
 * 
 * @details A ordem contém informações como código identificador, código de negociação,
 * data da operação, preço e quantidade negociada.
 * 
 * Esta é uma entidade imutável após a criação, ou seja, suas operações
 * são limitadas a visualização e exclusão.
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
         * @brief Constrói uma nova instância de Ordem.
         * 
         * @param cod Código identificador da ordem (5 dígitos).
         * @param codNeg Código de negociação (até 12 caracteres alfanuméricos).
         * @param data Data da ordem no formato AAAAMMDD.
         * @param preco Valor da negociação (entre 0.01 e 1.000.000,00).
         * @param qtd Quantidade negociada (entre 1 e 1.000.000).
         * 
         * @throw std::invalid_argument Se algum dos parâmetros não for válido.
         */
        Ordem(const std::string& cod, const std::string& codNeg, const std::string& data,
              double preco, int qtd);
    
        /**
         * @brief Retorna o código identificador da ordem.
         * 
         * @return Código da ordem como string.
         */
        std::string getCodigo() const;
    
        /**
         * @brief Retorna o código de negociação associado à ordem.
         * 
         * @return Código de negociação como string.
         */
        std::string getCodNegociacao() const;
    
        /**
         * @brief Retorna a data da ordem.
         * 
         * @return Data no formato AAAAMMDD.
         */
        std::string getData() const;
    
        /**
         * @brief Retorna o valor monetário da ordem.
         * 
         * @return Preço da ordem como número real.
         */
        double getDinheiro() const;
    
        /**
         * @brief Retorna a quantidade de unidades negociadas.
         * 
         * @return Quantidade como número inteiro.
         */
        int getQuantidade() const;
    };

#endif  // ENTIDADES_HPP_INCLUDED
