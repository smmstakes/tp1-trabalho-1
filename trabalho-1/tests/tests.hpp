#ifndef TESTS_HPP_INCLUDED
#define TESTS_HPP_INCLUDED

#include <iostream>

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

#endif // TESTS_HPP_INCLUDED
