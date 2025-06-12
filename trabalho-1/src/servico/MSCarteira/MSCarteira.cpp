#include "../../dominios/dominios.hpp"
#include "../../entidades/entidades.hpp"
#include <iomanip>
#include <sstream>

#include "MSCarteira.hpp"


MSCarteira* MSCarteira::instancia = nullptr;

MSCarteira::MSCarteira() {
    persistencia = new MPCarteira();
}

MSCarteira* MSCarteira::getInstancia() {
    if (!instancia) {
        instancia = new MSCarteira();
    }
    return instancia;
}

void MSCarteira::criarCarteira(std::string& nome, const std::string& perfil) {

    std::string ultimoCodigoStr = persistencia->obterUltimoCodigoCarteiraInserido();
    Codigo codigo;

    if(ultimoCodigoStr.empty()) {
        codigo.set("00001");    
    }

    if (!ultimoCodigoStr.empty()) {
        int ultimoCodigoInt = 0;
        ultimoCodigoInt = std::stoi(ultimoCodigoStr);
        int novoCodigoInt = ultimoCodigoInt + 1;

        std::ostringstream oss;
        oss << std::setw(5) << std::setfill('0') << novoCodigoInt;
        std::string novoCodigoStr = oss.str();

        codigo.set(novoCodigoStr);
    }

    Carteira carteira;
    carteira.setCodigo(codigo.get());
    carteira.setNome(nome);
    carteira.setPerfil(perfil);

    persistencia->criarCarteira(codigo.get(), nome, perfil);

}
