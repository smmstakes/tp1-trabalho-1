#ifndef DOMINIO_TEST_HPP_INCLUDED
#define DOMINIO_TEST_HPP_INCLUDED

/**
 * @file dominios_test.hpp
 * @brief Declaração da classe base para testes de domínios.
 * 
 * @details Este arquivo define a classe genérica TUDominio, utilizada como base
 * para a criação de testes unitários dos tipos de domínio do sistema.
 * Define métodos de configuração, execução e liberação
 * de recursos, além do cenário de teste com dados válidos.
 * 
 * @author Suyanne Miranda
 * @date 01/05/2025
 */

#include <string>


/**
 * @class TUDominio
 * @brief Classe base genérica para testes de domínios.
 * 
 * @details Fornece uma estrutura para configurar, executar e deletar 
 * testes unitários de classes de domínio.
 * 
 * @tparam Dominio Dominio que será testado.
 */
template<typename Dominio>
class TUDominio {
    protected:
        Dominio *valor;
        int estado;

        /**
         * @brief Inicializa o domínio e define o estado inicial do teste. 
         */
        void setUp() {
            valor = new Dominio();
            estado = SUCESSO;
        };

        /**
         * @brief Deleta a instância do domínio. 
         */
        void tearDown() { delete valor ;};

        /**
         * @brief Executa o cenário de teste com valor válido.
         */
        virtual void testarCenarioValido() = 0;

    public:
        const static int SUCESSO = 1;
        const static int FALHA = -1;

         /**
         * @brief Executa os testes definidos na subclasse.
         * 
         * @return int Estado do teste (SUCESSO ou FALHA).
         */
        virtual int run() = 0;
        virtual ~TUDominio() = default;
};

#endif // DOMINIO_TEST_HPP_INCLUDED