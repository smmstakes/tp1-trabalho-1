#ifndef INTERFACE_REPOSITORIO_ORDEM_HPP_INCLUDED
#define INTERFACE_REPOSITORIO_ORDEM_HPP_INCLUDED

#include <string>

#include "../../../libs/tipos/estruturas.hpp"
#include "../../../libs/dominios/dominios.hpp"
#include "../../../libs/entidades/entidades.hpp"

class IPOrdem {
public:
    virtual ~IPOrdem() = default;

    virtual int contarOrdensUsuario(const std::string& cpfUsuario) = 0;
    virtual std::string obterUltimoCodigoOrdemInserido() = 0;
    virtual std::vector<Ordem> getOrdensPorCarteira(const std::string& codCarteira) = 0;

    virtual void criarOrdem(const std::string& cod, const std::string& codNeg, const std::string& data, double preco, 
    int qtd, const std::string& codigoCarteira) = 0;
    virtual bool excluirOrdem(const std::string& codOrdem, const std::string& codCarteira) = 0;

};

#endif  // INTERFACE_REPOSITORIO_ORDEM_HPP_INCLUDED
