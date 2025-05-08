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
         * @brief Constrói uma nova instância de Ordem.
         * 
         * @param cod Código identificador da ordem (5 dígitos).
         * @param codNeg Código de negociação (até 12 caracteres alfanuméricos).
         * @param data Data de compra da ordem (AAAAMMDD).
         * @param preco Valor da negociação (entre 0.01 e 1.000.000,00).
         * @param qtd Quantidade negociada (entre 1 e 1.000.000).
         * 
         * @throw std::invalid_argument Exceção caso algum valor informado 
         * não esteja de acordo com as especificações.
         */
        Ordem(const std::string& cod, const std::string& codNeg, const std::string& data,
              double preco, int qtd);
    
        /**
         * @brief Retorna o código identificador da ordem.
         * 
         * @return Código da ordem como string.
         */
        std::string getCodigo() const {return codigo.get();}
    
        /**
         * @brief Retorna o código de negociação associado à ordem.
         * 
         * @return Código de negociação como string.
         */
        std::string getCodNegociacao() const {return codNegociacao.get();}
    
        /**
         * @brief Retorna a data de compra da ordem.
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
