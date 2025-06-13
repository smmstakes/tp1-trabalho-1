#ifndef CARTEIRA_SERVICO_HPP_INCLUDED
#define CARTEIRA_SERVICO_HPP_INCLUDED

#include "interface_servico_carteira.hpp"
#include "../../persistencia/carteira/interface_repositorio_carteira.hpp"

class ServicoICarteira : public ISCarteira { 
private:
    IPCarteira* persistencia;
    ServicoICarteira();

public:
    ServicoICarteira(const ServicoICarteira&) = delete;
    ServicoICarteira& operator=(const ServicoICarteira&) = delete;

    static ServicoICarteira& getInstancia();
    void criarCarteira(const Nome& nome, const Perfil& perfil) override;
};

#endif  // CARTEIRA_SERVICO_HPP_INCLUDED
