#ifndef APRESENTACAO_UTILS_HPP_INCLUDED
#define APRESENTACAO_UTILS_HPP_INCLUDED

#ifdef _WIN32
    // Se o sistema for Windows
    #define CLR_SCR() system("cls")
#else
    // Para Linux, macOS e outros sistemas POSIX
    #define CLR_SCR() system("clear")
#endif

#endif  // APRESENTACAO_UTILS_HPP_INCLUDED