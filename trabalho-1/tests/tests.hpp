#ifndef TESTS_HPP_INCLUDED
#define TESTS_HPP_INCLUDED

#include <iostream>
#include "./dominios/dominios_test.hpp"

class GerenciadorDeTestes {
    private:
        static constexpr const char* COR_SUCESSO = "\033[32m";
        static constexpr const char* COR_FALHA   = "\033[31m";
        static constexpr const char* COR_RESET   = "\033[0m";

        static void exibirMensagem(const std::string& nomeTipo, const std::string& resultado, const char* cor) {
            std::cout << "---------- " << nomeTipo << " -> " << cor << resultado << COR_RESET << std::endl;
        }

    public:
        template<typename Tipo>
        static void executar(TUDominio<Tipo>* teste, const std::string& nomeTipo) {
            int estado = teste->run();
            if (estado == TUDominio<Tipo>::SUCESSO) {
                exibirMensagem(nomeTipo, "SUCESSO", COR_SUCESSO);
            }
            else {
                exibirMensagem(nomeTipo, "FALHA", COR_FALHA);
                throw nomeTipo;
            }
        }
};

#endif // TESTS_HPP_INCLUDED
