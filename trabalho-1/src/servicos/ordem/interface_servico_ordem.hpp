#ifndef INTERFACE_SERVICO_ORDEM_HPP_INCLUDED
#define INTERFACE_SERVICO_ORDEM_HPP_INCLUDED

#include <string>

#include "../../../libs/tipos/estruturas.hpp"
#include "../../../libs/dominios/dominios.hpp"
#include "../../../libs/entidades/entidades.hpp"
#include "../../../libs/sessao_usuario/sessao_usuario.hpp"

class ISOrdem {
public:
    virtual ~ISOrdem() = default;

    virtual void criarOrdem(const CodigoNegociacao& codNeg, const Quantidade& quantidade, const Data& data, const Codigo& codCarteira) = 0;
    virtual void excluirOrdem(const Codigo& codigoOrdem, const Codigo& codigoCarteira) = 0;
    virtual std::vector<Ordem> listarOrdens(const Codigo& codigoCarteira) = 0;
};

#endif // INTERFACE_SERVICO_ORDEM_HPP_INCLUDED
