#ifndef TU_UTILS_HPP_INCLUDED
#define TU_UTILS_HPP_INCLUDED

#include <functional>
#include <iostream>
#include <string>

class TUUtils {
    private:
        const static int FALHA = -1;
    public:
        template<typename Tipo>
        static void assertIgual(const Tipo& valorObtido, const Tipo& valorEsperado, const std::string& nomeMetodo, const std::string& nomeClasse, int& estado) {
            if (valorObtido == valorEsperado) {
                std::cout << nomeClasse << ": " << nomeMetodo << " -> SUCESSO\n";
                return;
            }
            std::cout << nomeClasse << ": " << nomeMetodo << " -> FALHA\n";
            estado = FALHA;
        }

        static void assertExcecao(std::function<void()> lambda, const std::string& nomeMetodo, const std::string& nomeClasse, int& estado);
};

#endif // TU_UTILS_HPP_INCLUDED
