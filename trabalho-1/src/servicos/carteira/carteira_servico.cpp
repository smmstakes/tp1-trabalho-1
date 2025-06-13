#include <iomanip>
#include <sstream>

#include "carteira_servico.hpp"
#include "../../libs/dominios/dominios.hpp"
#include "../../persistencia/carteira/carteira_repositorio.hpp"

ServicoICarteira::ServicoICarteira() {
    this->persistencia = &RepositorioIPCarteira::getInstancia();
}

// Meyers' Singleton: A instância é criada na primeira chamada e destruída automaticamente.
ServicoICarteira& ServicoICarteira::getInstancia() {
    static ServicoICarteira instancia;
    return instancia;
}

void ServicoICarteira::criarCarteira(const Nome& nome, const Perfil& perfil) {
    std::string ultimoCodigoStr = this->persistencia->obterUltimoCodigoCarteiraInserido();
    Codigo codigo;
    int novoCodigoInt = 1;

    if(!ultimoCodigoStr.empty()) {
        novoCodigoInt = std::stoi(ultimoCodigoStr) + 1;  
    }

    std::ostringstream oss;
    oss << std::setw(5) << std::setfill('0') << novoCodigoInt;
    codigo.set(oss.str());

    this->persistencia->criarCarteira(codigo.get(), nome.get(), perfil.get());
}
