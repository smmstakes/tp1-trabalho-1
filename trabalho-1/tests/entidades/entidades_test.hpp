#ifndef ENTIDADES_TEST_HPP_INCLUDED
#define ENTIDADES_TEST_HPP_INCLUDED

/**
 * @file entidades_test.hpp
 * @brief Declaração da classe base para testes de entidades.
 * 
 * @details Este arquivo define a classe genérica TUEntidade, utilizada como base
 * para a criação de testes unitários dos tipos de entidades do sistema.
 * Define métodos de configuração, execução e liberação
 * de recursos, além do cenário de teste com dados válidos.
 * 
 * @author Matheus Duarte
 * @date 01/05/2025
 */

 /**
 * @class TUEntidade
 * @brief Classe base genérica para testes de entidades.
 * 
 * @details Fornece uma estrutura para configurar, executar e deletar 
 * testes unitários das entidades.
 
 * @tparam Entidade Entidade a ser testada.
 */
template<typename Entidade>
class TUEntidade {
    protected:
        Entidade *entidade;
        int estado;

         /**
         * @brief Prepara a classe para realizar os testes.
         */
        virtual void setUp() = 0;

        /**
         * @brief Deleta a instância da entidade. 
         */
        void tearDown() {delete entidade;}

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
        virtual ~TUEntidade() = default;

// Criado por Matheus Duarte - 211062277
};

#endif // ENTIDADES_TEST_HPP_INCLUDED
