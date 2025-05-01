#ifndef TESTS_HPP_INCLUDED
#define TESTS_HPP_INCLUDED

#include <iostream>
#include "./dominios/dominios_test.hpp"

class ExecutorDeTestes {
    private:
        static constexpr const char* COR_SUCESSO = "\033[32m";
        static constexpr const char* COR_FALHA   = "\033[31m";
        static constexpr const char* COR_RESET   = "\033[0m";

    public:
        template<typename Teste>
        static void executar(Teste* teste, const std::string& nomeTipo) {
            bool sucesso = teste->run() == Teste::SUCESSO;
            std::cout << "---------- " << nomeTipo << " -> "
                    << (sucesso ? COR_SUCESSO : COR_FALHA)
                    << (sucesso ? "SUCESSO" : "FALHA") 
                    << COR_RESET << std::endl;
            if (!sucesso) throw nomeTipo;
        }
};

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

        template<typename Metodo>
        static void assertExcecao(Metodo metodo, const std::string& nomeMetodo, const std::string& nomeClasse, int& estado) {
            try {
                metodo();
                std::cout << nomeClasse << ": " << nomeMetodo << " -> FALHA\n";
                estado = FALHA;
            } catch (std::invalid_argument&) {
                std::cout << nomeClasse << ": " << nomeMetodo << " -> SUCESSO\n";
            }
        }
};

#endif // TESTS_HPP_INCLUDED
