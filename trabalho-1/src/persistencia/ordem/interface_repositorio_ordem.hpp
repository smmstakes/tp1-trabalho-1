#ifndef INTERFACE_REPOSITORIO_ORDEM_HPP_INCLUDED
#define INTERFACE_REPOSITORIO_ORDEM_HPP_INCLUDED

/**
 * @file interface_repositorio_ordem.hpp
 * @brief Define a interface para a camada de persistência de Ordem.
 * 
 * @details Este arquivo declara a classe abstrata `IPOrdem`, que serve como
 * um contrato para qualquer classe de repositório que gerencie o armazenamento
 * e a recuperação de dados da entidade `Ordem`.
 * 
 * @author Gabriel Castro, Suyanne Miranda
 * @date 04/07/2025
 */

#include <string>

#include "../../../libs/tipos/estruturas.hpp"
#include "../../../libs/dominios/dominios.hpp"
#include "../../../libs/entidades/entidades.hpp"

/**
 * @class IPOrdem
 * @brief Interface Abstrata para o Repositório da entidade Ordem.
 * @details Define o conjunto de operações de persistência de dados (CRUD)
 * que podem ser realizadas com as ordens.
 */
class IPOrdem {
public:
    /**
     * @brief Destrutor virtual padrão.
     */
    virtual ~IPOrdem() = default;

    /**
     * @brief Conta o número total de ordens de todas as carteiras de um usuário.
     * 
     * @param cpfUsuario CPF do usuário a ser consultado.
     * 
     * @return O número total de ordens como um inteiro.
     */
    virtual int contarOrdensUsuario(const std::string& cpfUsuario) = 0;

    /**
     * @brief Busca o último código de ordem inserido no sistema.
     * 
     * @return String contendo o último código.
     */
    virtual std::string obterUltimoCodigoOrdemInserido() = 0;

    /**
     * @brief Busca todas as ordens de uma carteira específica.
     * 
     * @param codCarteira Código da carteira.
     * 
     * @return Vetor de objetos Ordem.
     */
    virtual std::vector<Ordem> getOrdensPorCarteira(const std::string& codCarteira) = 0;

    /**
     * @brief Salva uma nova ordem no sistema.
     * 
     * @param cod Código da ordem.
     * @param codNeg Código de negociação do ativo.
     * @param data Data da operação.
     * @param preco Preço total da ordem.
     * @param qtd Quantidade de papéis.
     * @param codigoCarteira Código da carteira à qual a ordem pertence.
     */
    virtual void criarOrdem(const std::string& cod, const std::string& codNeg, const std::string& data, double preco, 
    int qtd, const std::string& codigoCarteira) = 0;

    /**
     * @brief Exclui uma ordem do banco de dados.
     * 
     * @param codigoOrdem Código da ordem a ser excluída.
     * @param codigoCarteira Código da carteira para validação de posse.
     * 
     * @return true se a exclusão foi bem-sucedida.
     */
    virtual bool excluirOrdem(const std::string& codOrdem, const std::string& codCarteira) = 0;

    /**
     * @brief Exclui todas as ordens de cada carteira de um usuário.
     * 
     * @param cpf CPF do usuário cujas ordens serão excluídas.
     */
    virtual void excluirOrdensUsuario(const std::string& cpf) = 0;

};

#endif  // INTERFACE_REPOSITORIO_ORDEM_HPP_INCLUDED
