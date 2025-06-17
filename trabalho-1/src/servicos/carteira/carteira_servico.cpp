#include "carteira_servico.hpp"

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

std::vector<Carteira> ServicoICarteira::listarCarteiras() {
    SessaoUsuario& sessao = SessaoUsuario::getInstance();

    // Sempre verificar se o usuário está logado
    if (!sessao.estaLogado()) {
        throw std::runtime_error("Usuário não está logado.");
    }

    Conta contaLogada = sessao.getContaLogada();
    std::string cpf = contaLogada.getCpf();

    return this->persistencia->listarCarteiras(cpf);
}
