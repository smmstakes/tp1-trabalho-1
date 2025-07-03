#ifndef INTERFACE_REPOSITORIO_ORDEM_HPP_INCLUDED
#define INTERFACE_REPOSITORIO_ORDEM_HPP_INCLUDED

#include <string>

#include "../../../libs/tipos/estruturas.hpp"
#include "../../../libs/dominios/dominios.hpp"
#include "../../../libs/entidades/entidades.hpp"

/**
 * @file interface_repositorio_ordem.hpp
 * @brief Especificação para a camada de persistência da entidade Ordem.
 * @author Gabriel Castro
 */

/**
 * @class IPOrdem
 * @brief Interface que define as operações de banco de dados para a entidade Ordem.
 */
class IPOrdem {
public:
    virtual ~IPOrdem() = default;

    /**
     * @brief Conta o número total de ordens de todas as carteiras de um usuário.
     * @param cpfUsuario CPF do usuário a ser consultado.
     * @return O número total de ordens como um inteiro.
     */
    virtual int contarOrdensUsuario(const std::string& cpfUsuario) = 0;

    /**
     * @brief Busca o último código de ordem inserido no sistema.
     * @return String contendo o último código.
     */
    virtual std::string obterUltimoCodigoOrdemInserido() = 0;

    /**
     * @brief Busca todas as ordens de uma carteira específica.
     * @param codCarteira Código da carteira.
     * @return Vetor de objetos Ordem.
     */
    virtual std::vector<Ordem> getOrdensPorCarteira(const std::string& codCarteira) = 0;

    /**
     * @brief Salva uma nova ordem no sistema de persistência.
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
     * @param codigoOrdem Código da ordem a ser excluída.
     * @param codigoCarteira Código da carteira para validação de posse.
     * @return true se a exclusão foi bem-sucedida.
     */
    virtual bool excluirOrdem(const std::string& codOrdem, const std::string& codCarteira) = 0;

};

#endif  // INTERFACE_REPOSITORIO_ORDEM_HPP_INCLUDED
