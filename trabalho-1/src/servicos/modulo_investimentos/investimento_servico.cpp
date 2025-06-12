#include <iomanip>
#include <sstream>

#include "investimento_servico.hpp"
#include "../../libs/dominios/dominios.hpp"
#include "../../persistencia/investimentos/investimento_repositorio.hpp"

void ServicoIInvestimentos::criarCarteira(const Nome& nome, const Perfil& perfil) {
    auto& persistencia = RepositorioIPInvestimento::getInstancia();
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
