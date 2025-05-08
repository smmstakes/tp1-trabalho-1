#ifndef EXECUTOR_DE_TESTES_HPP_INCLUDED
#define EXECUTOR_DE_TESTES_HPP_INCLUDED

/**
 * @file executor_de_testes.hpp
 * @brief Classe auxiliar para execução de testes.
 * 
 * @details Esse arquivo define a classe que servirá como principal
 * meio de executar os testes definidos no projeto de forma automática
 * e organizada.
 * 
 * @author Suyanne Miranda
 * @date 05/05/2025
 */

/**
 * @class ExecutorDeTestes
 * @brief Classe responsável por executar todos os testes do projeto. 
 */
class ExecutorDeTestes {
    private:
        static constexpr const char* COR_SUCESSO = "\033[32m";
        static constexpr const char* COR_FALHA   = "\033[31m";
        static constexpr const char* COR_RESET   = "\033[0m";

        template<typename Teste>
        static void executarTU(Teste* teste, const std::string& nomeTipo);

    public:

        /**
         * @brief Executa todos os testes definidos no sistema.
         * 
         * @details Esta função instância e executa os testes de 
         * todas as entidades e domínios do projeto.
         */
        static void executarTodos();

// Criado por Suyanne Miranda - 222006445
};
#endif // EXECUTOR_DE_TESTES_HPP_INCLUDED