#ifndef APRESENTACAO_UTILS_HPP_INCLUDED
#define APRESENTACAO_UTILS_HPP_INCLUDED

/**
 * @file apresentacao_utils.hpp
 * @brief Macros para utilização na camada de apresentação
 * 
 * @details Este arquivo contém macros para limpar o terminal dependendo
 * do Sistema Operacional.
 * 
 * @author Matheus Duarte
 * @date 03/07/2025
 */

#ifdef _WIN32
    // Se o sistema for Windows
    #define CLR_SCR() system("cls")
#else
    // Para Linux, macOS e outros sistemas POSIX
    #define CLR_SCR() system("clear")
#endif

#endif  // APRESENTACAO_UTILS_HPP_INCLUDED
