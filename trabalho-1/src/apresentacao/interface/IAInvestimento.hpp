#ifndef IAINVESTIMENTO_HPP_INCLUDED
#define IAINVESTIMENTO_HPP_INCLUDED

#ifdef _WIN32
    // Se o sistema for Windows
    #define CLR_SCR() system("cls")
#else
    // Para Linux, macOS e outros sistemas POSIX
    #define CLR_SCR() system("clear")
#endif

#include <cstdlib>
#include "../entidades/entidades.hpp"

class ISInvestimento;

class IAInvestimento {
    private:
        virtual void mostrarOpcoes() = 0;
        virtual bool escolherOpcao(int, const CPF&) = 0;

    public:
        // Método por meio do qual é solicitado o serviço
        virtual void executar(const CPF&) = 0;

        // Método para estabelecer ligação (link) com a controladora
        virtual void setCntrlISInvestimento(ISInvestimento*) = 0;

        // Método destrutor virtual
        virtual ~IAInvestimento() {};
};

#endif // IAINVESTIMENTO_HPP_INCLUDED
