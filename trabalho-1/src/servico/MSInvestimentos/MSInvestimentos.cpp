#include "MSInvestimentos.hpp"
#include "../MSPersistencia/MSPersistencia.hpp"
#include "../../dominios/dominios.hpp"
#include <iomanip>
#include <sstream>

void MSInvestimentos::criarCarteira(const Nome& nome, const Perfil& perfil) {
    auto& persistencia = MSPersistencia::getInstancia();
    std::string ultimoCodigoStr = persistencia.obterUltimoCodigoCarteiraInserido();
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

    persistencia.salvarCarteira(codigo.get(), nome.get(), perfil.get());
}
