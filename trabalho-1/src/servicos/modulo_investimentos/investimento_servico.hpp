#ifndef INVESTIMENTO_SERVICO_HPP_INCLUDED
#define INVESTIMENTO_SERVICO_HPP_INCLUDED

#include "interface_servico_investimento.hpp"

class ServicoIInvestimentos : public ISInvestimentos {
    public:
        void criarCarteira(const Nome& nome, const Perfil& perfil) override;
};

#endif  // INVESTIMENTO_SERVICO_HPP_INCLUDED