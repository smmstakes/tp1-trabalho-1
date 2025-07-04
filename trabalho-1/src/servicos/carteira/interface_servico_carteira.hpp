#ifndef INTERFACE_SERVICO_CARTEIRA_HPP_INCLUDED
#define INTERFACE_SERVICO_CARTEIRA_HPP_INCLUDED

/**
 * @file interface_servico_carteira.hpp
 * @brief Define a interface (contrato) para a camada de serviço de Carteira.
 *
 * @details Este arquivo declara a classe abstrata `ISCarteira`, que serve como
 * um contrato para as classes que implementam as regras de negócio relacionadas
 * à entidade `Carteira`. 
 * Ele desacopla a camada de apresentação da lógica de
 * negócio, definindo os casos de uso de alto nível.
 *
 * @author Matheus Duarte, Suyanne Miranda
 * @date 03/07/2025
 */

#include <string>

#include "../../../libs/tipos/estruturas.hpp"
#include "../../../libs/dominios/dominios.hpp"
#include "../../../libs/entidades/entidades.hpp"
#include "../../../libs/sessao_usuario/sessao_usuario.hpp"

/**
 * @class ISCarteira
 * @brief Interface Abstrata para o Serviço de Negócio de Carteira.
 *
 * @details Define todas as operações de negócio que podem ser realizadas em
 * carteiras de investimento. 
 * As implementações desta interface conterão a lógica de validação e coordenação das operações.
 */
class ISCarteira {
public:
    /**
     * @brief Destrutor virtual padrão.
     */
    virtual ~ISCarteira() = default;
    
    /**
     * @brief Cria uma nova carteira de investimentos para o usuário logado.
     * 
     * @details A implementação deve verificar regras de negócio, como o limite
     * de carteiras por usuário, antes de solicitar a criação na camada de persistência.
     * 
     * @param nome O nome da nova carteira, encapsulado em um objeto de domínio.
     * @param perfil O perfil de investidor da carteira, encapsulado em um objeto de domínio.
     * 
     * @throw runtime_error Se uma regra de negócio for violada .
     */
    virtual void criarCarteira(const Nome& nome, const Perfil& perfil) = 0;

     /**
     * @brief Edita o nome de uma carteira pertencente ao usuário logado.
     * 
     * @param codigo O código da carteira a ser modificada.
     * @param novoNome O novo nome para a carteira.
     * 
     * @throw runtime_error Se a carteira não for encontrada ou não pertencer ao usuário.
     */
    virtual void editarNomeCarteira(const std::string& codigo, const Nome& novoNome) = 0;

    /**
     * @brief Edita o perfil de uma carteira pertencente ao usuário logado.
     * 
     * @param codigo O código da carteira a ser modificada.
     * @param novoPerfil O novo perfil de investidor para a carteira.
     * 
     * @throw runtime_error Se a carteira não for encontrada ou não pertencer ao usuário.
     */
    virtual void editarPerfilCarteira(const std::string& codigo, const Perfil& novoPerfil) = 0;

    /**
     * @brief Exclui uma carteira pertencente ao usuário logado.
     * 
     * @param codigo O código da carteira a ser excluída.
     * 
     * @throw runtime_error Se a carteira não for encontrada ou não pertencer ao usuário.
     */
    virtual void excluirCarteira(const std::string& codigo) = 0;

    /**
     * @brief Exclui todas as carteiras do usuário logado.
     * 
     * @details Remove da base de dados todas as carteiras associadas ao CPF da conta
     * atualmente em sessão.
     */
    virtual void excluirCarteirasUsuario() = 0;
    // Criado por Suyanne Miranda - 222006445

    /**
     * @brief Recupera todas as carteiras do usuário logado.
     * 
     * @details Solicita à camada de persistência todas as carteiras associadas ao
     * CPF do usuário na sessão atual, já com o valor total calculado.
     * 
     * @return vector<CarteiraComValor> Um vetor com as carteiras do usuário.
     * 
     * @throw runtime_error Se não houver um usuário logado.
     */
    virtual std::vector<CarteiraComValor> getCarteiras() = 0;
};

#endif // INTERFACE_SERVICO_CARTEIRA_HPP_INCLUDED
