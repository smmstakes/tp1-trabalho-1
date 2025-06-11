#ifndef IPERSISTENCIA_HPP
#define IPERSISTENCIA_HPP

#include <string>

class ISPersistencia {
public:
    virtual void conectar() = 0;
    virtual void desconectar() = 0;
    virtual bool criarTabelas() = 0;
    virtual ~ISPersistencia() = default;

    virtual void salvarCarteira(const std::string& codigo, const std::string& nome, const std::string& perfil) = 0;
    virtual std::string obterUltimoCodigoCarteiraInserido() = 0;

};

#endif
