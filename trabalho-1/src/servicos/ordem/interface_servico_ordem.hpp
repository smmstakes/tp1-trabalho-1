#ifndef INTERFACE_SERVICO_ORDEM_HPP_INCLUDED
#define INTERFACE_SERVICO_ORDEM_HPP_INCLUDED

/**
 * @file interface_servico_ordem.hpp
 * @brief Define a interface para a camada de serviço de Ordem.
 * 
 * @details Este arquivo declara a classe abstrata `ISOrdem`, que serve como
 * um contrato para as classes que implementam as regras de negócio relacionadas
 * à entidade `Ordem`.
 * 
 * @author Gabriel Castro
 * @date 04/07/2025
 */

#include <string>

#include "../../../libs/tipos/estruturas.hpp"
#include "../../../libs/dominios/dominios.hpp"
#include "../../../libs/entidades/entidades.hpp"
#include "../../../libs/sessao_usuario/sessao_usuario.hpp"


/**
 * @class ISOrdem
 * @brief Interface Abstrata para o Serviço de Negócio de Ordem.
 * 
 * @details Define todas as operações de negócio que podem ser realizadas com ordens.
 * As implementações desta interface conterão a lógica de validação e coordenação das operações.
 */
class ISOrdem {
public:
    /**
     * @brief Destrutor virtual padrão.
     */
    virtual ~ISOrdem() = default;

     /**
     * @brief Cria uma nova ordem, calculando seu preço com base em dados históricos.
     * 
     * @param codNegociacao Código do ativo a ser negociado.
     * @param quantidade Quantidade de papéis.
     * @param data Data da transação.
     * @param codigoCarteira Código da carteira onde a ordem será criada.
     * 
     * @throw std::runtime_error ou std::invalid_argument em caso de erro.
     */
    virtual void criarOrdem(const CodigoNegociacao& codNeg, const Quantidade& quantidade, const Data& data, const Codigo& codCarteira) = 0;

    /**
     * @brief Exclui uma ordem de uma carteira.
     * 
     * @param codigoOrdem Código da ordem a ser excluída.
     * 
     * @param codigoCarteira Código da carteira para validação.
     */
    virtual void excluirOrdem(const Codigo& codigoOrdem, const Codigo& codigoCarteira) = 0;

    /**
     * @brief Lista todas as ordens de uma carteira específica.
     * 
     * @param codigoCarteira Código da carteira a ser consultada.
     * 
     * @return Vetor de objetos Ordem.
     */
    virtual std::vector<Ordem> listarOrdens(const Codigo& codigoCarteira) = 0;
};

#endif // INTERFACE_SERVICO_ORDEM_HPP_INCLUDED
