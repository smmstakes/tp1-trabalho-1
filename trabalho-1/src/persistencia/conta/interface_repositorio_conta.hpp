#ifndef INTERFACE_REPOSITORIO_CONTA_HPP_INCLUDED
#define INTERFACE_REPOSITORIO_CONTA_HPP_INCLUDED

#include <string>

class IPConta {
    public:
        virtual ~IPConta() = default;
        virtual void criarConta(const std::string& cpf, const std::string& nome, const std::string& senha) = 0;
        virtual std::string obterUltimoCPFContaInserido() = 0;
};

#endif  // INTERFACE_REPOSITORIO_CONTA_HPP_INCLUDED