#ifndef INTERFACE_REPOSITORIO_INVESTIMENTO_HPP_INCLUDED
#define INTERFACE_REPOSITORIO_INVESTIMENTO_HPP_INCLUDED

#include <string>

class IPInvestimento {
public:
    virtual void conectar() = 0;
    virtual void desconectar() = 0;
    virtual bool criarTabelas() = 0;
    virtual ~IPInvestimento() = default;

    virtual void salvarCarteira(const std::string& codigo, const std::string& nome, const std::string& perfil) = 0;
    virtual std::string obterUltimoCodigoCarteiraInserido() = 0;

};

#endif  // INTERFACE_REPOSITORIO_INVESTIMENTO_HPP_INCLUDED
