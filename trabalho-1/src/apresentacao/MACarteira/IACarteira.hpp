#ifndef IACARTEIRA_HPP_INCLUDED
#define IACARTEIRA_HPP_INCLUDED

#ifdef _WIN32
    // Se o sistema for Windows
    #define CLR_SCR() system("cls")
#else
    // Para Linux, macOS e outros sistemas POSIX
    #define CLR_SCR() system("clear")
#endif

#include <cstdlib>
#include "../../entidades/entidades.hpp"
#include "../../servico/MSCarteira/ISCarteira.hpp"

class IACarteira {
    // TODO: isso se torna protected, porque as filhas precisam ter acesso
    protected:
        virtual void mostrarOpcoes() = 0;
        virtual bool escolherOpcao(int) = 0;

    public:
        // Método por meio do qual é solicitado o serviço
        virtual void executar() = 0;

        // Método para estabelecer ligação (link) com a controladora
        virtual void setCntrlISCarteira(ISCarteira*) = 0;

        // Método destrutor virtual
        virtual ~IACarteira() {};
};

#endif // IACARTEIRA_HPP_INCLUDED
