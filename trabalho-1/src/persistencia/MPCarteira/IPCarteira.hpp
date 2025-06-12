#ifndef IPCARTEIRA_HPP
#define IPCARTEIRA_HPP

#include <string>
class IPCarteira {
    public:
        virtual ~IPCarteira() = default;

        virtual void criarCarteira(const std::string& codigo, const std::string& nome, const std::string& perfil) = 0;
        virtual std::string obterUltimoCodigoCarteiraInserido() = 0;
};

#endif // IPCARTEIRA_HPP
