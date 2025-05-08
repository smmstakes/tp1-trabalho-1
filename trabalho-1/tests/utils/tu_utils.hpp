#ifndef TU_UTILS_HPP_INCLUDED
#define TU_UTILS_HPP_INCLUDED

/**
 * @file tu_utils.hpp
 * @brief Classe utilitária para verificação dos testes
 * 
 * @details Esse arquivo fornece funções auxiliares para verificação de
 * valores esperados e obtidos, além da verificação dos lançamentos de 
 * exceções.
 * 
 * @author Suyanne Miranda
 * @date 05/05/2025
 * 
 */

#include <functional>
#include <iostream>
#include <string>


/**
 * @class TUUtils
 * @brief Classe utilitária para facilitar a validação dos testes unitários.
 */
class TUUtils {
    private:
        const static int FALHA = -1;
    public:

        /**
         * @brief Verifica se dois valores são iguais.
         * 
         * @tparam Tipo Tipo dos valores comparados.
         * 
         * @param valorObtido Valor retornado pela função testada.
         * @param valorEsperado Valor que era esperado.
         * @param nomeMetodo Nome do método testado.
         * @param nomeClasse Nome da classe do teste.
         * @param estado Estado geral do teste.
         */
        template<typename Tipo>
        static void assertIgual(const Tipo& valorObtido, const Tipo& valorEsperado, const std::string& nomeMetodo, const std::string& nomeClasse, int& estado) {
            if (valorObtido == valorEsperado) {
                std::cout << nomeClasse << ": " << nomeMetodo << " -> SUCESSO\n";
                return;
            }
            std::cout << nomeClasse << ": " << nomeMetodo << " -> FALHA\n";
            estado = FALHA;
        }

        /**
         * @brief Verifica se uma exceção é corretamente lançada por uma função.
         * 
         * @param lambda Função que deve lançar uma exceção.
         * @param nomeMetodo Nome do método testado.
         * @param nomeClasse Nome da classe do teste.
         * @param estado Estado geral do teste.
         */
        static void assertExcecao(std::function<void()> lambda, const std::string& nomeMetodo, const std::string& nomeClasse, int& estado);

// Criado por Suyanne Miranda - 222006445
};

#endif // TU_UTILS_HPP_INCLUDED
