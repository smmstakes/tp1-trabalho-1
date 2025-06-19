#include "carteira_servico.hpp"

ServicoICarteira::ServicoICarteira() {
    this->persistencia = &RepositorioIPCarteira::getInstancia();
}

// Meyers' Singleton: A instância é criada na primeira chamada e destruída automaticamente.
ServicoICarteira& ServicoICarteira::getInstancia() {
    static ServicoICarteira instancia;
    return instancia;
}

void ServicoICarteira::verificarSessao(SessaoUsuario& sessao) {
    if (!sessao.estaLogado()) {
        throw std::runtime_error("Usuário não está logado.");
    }
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

void ServicoICarteira::excluirCarteira(const std::string& codigo) {
    SessaoUsuario& sessao = SessaoUsuario::getInstance();
    verificarSessao(sessao);

    std::string cpfUsuario = sessao.getContaLogada().getCpf();

    if(!persistencia->excluirCarteira(codigo, cpfUsuario))
        throw std::invalid_argument("O código informado não corresponde aos das carteiras.");    
}

std::vector<Carteira> ServicoICarteira::listarCarteiras() {
    SessaoUsuario& sessao = SessaoUsuario::getInstance();
    verificarSessao(sessao);

    std::string cpfUsuario = sessao.getContaLogada().getCpf();

    return persistencia->listarCarteiras(cpfUsuario);
}
