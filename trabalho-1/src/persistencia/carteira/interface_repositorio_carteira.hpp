#ifndef INTERFACE_REPOSITORIO_CARTEIRA_HPP_INCLUDED
#define INTERFACE_REPOSITORIO_CARTEIRA_HPP_INCLUDED

#include <string>

#include "../../../libs/dominios/dominios.hpp"
#include "../../../libs/entidades/entidades.hpp"

class IPCarteira {
    public:
        virtual ~IPCarteira() = default;

        virtual int contarCarteirasUsuario(const std::string& cpfUsuario) = 0;
        virtual std::string obterUltimoCodigoCarteiraInserido() = 0;
        virtual std::vector<Ordem> getOrdensCarteira(const std::string codCarteira) = 0;

        virtual void criarCarteira(const std::string& codigo, const std::string& nome, const std::string& perfil, const std::string& cpfUsuario) = 0;
        virtual bool excluirCarteira(const std::string& codigo, const std::string& cpfUsuario) = 0;
        virtual std::vector<Carteira> listarCarteiras(const std::string& cpf) = 0;
};

#endif  // INTERFACE_REPOSITORIO_CARTEIRA_HPP_INCLUDED
