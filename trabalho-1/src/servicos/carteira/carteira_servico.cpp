#include "carteira_servico.hpp"

ServicoICarteira::ServicoICarteira(IPCarteira* persistencia) : persistencia(persistencia) {}

void ServicoICarteira::verificarSessao(SessaoUsuario& sessao) {
    if (!sessao.estaLogado()) {
        throw std::runtime_error("Usuário não está logado.");
    }
}

std::string ServicoICarteira::getCPFSessao() {
    SessaoUsuario& sessao = SessaoUsuario::getInstance();
    verificarSessao(sessao);

    return sessao.getContaLogada().getCpf();
}

std::vector<Ordem> ServicoICarteira::getOrdensCarteira(const std::string codCarteira) {
    verificarSessao(SessaoUsuario::getInstance());

    return persistencia->getOrdensCarteira(codCarteira);
}

void ServicoICarteira::criarCarteira(const Nome& nome, const Perfil& perfil) {
    std::string cpfUsuario = getCPFSessao();

    int qtdCarteirasUsuario = persistencia->contarCarteirasUsuario(cpfUsuario);

    if(qtdCarteirasUsuario >= 5) {
        throw std::runtime_error("Limite de 5 carteiras por conta atingido.");
    }
    
    std::string ultimoCodigoStr = persistencia->obterUltimoCodigoCarteiraInserido();
    Codigo codigo;
    int novoCodigoInt = 1;

    if(!ultimoCodigoStr.empty()) {
        novoCodigoInt = std::stoi(ultimoCodigoStr) + 1;  
    }

    std::ostringstream oss;
    oss << std::setw(5) << std::setfill('0') << novoCodigoInt;
    codigo.set(oss.str());

    persistencia->criarCarteira(codigo.get(), nome.get(), perfil.get(), cpfUsuario);
}

void ServicoICarteira::editarNomeCarteira(const std::string& codigo, const Nome& novoNome) {
    std::string cpfUsuario = getCPFSessao();

    bool sucesso = persistencia->editarNomeCarteira(codigo, cpfUsuario, novoNome.get());

    // Se o repositório não alterou nenhuma linha, significa que a carteira
    // não foi encontrada ou não pertence ao usuário logado.
    if (!sucesso) {
        throw std::runtime_error("Carteira não encontrada ou não pertence a você.");
    }
}

void ServicoICarteira::editarPerfilCarteira(const std::string& codigo, const Perfil& novoPerfil) {
    std::string cpfUsuario = getCPFSessao();

    bool sucesso = persistencia->editarPerfilCarteira(codigo, cpfUsuario, novoPerfil.get());

    if (!sucesso) {
        throw std::runtime_error("Carteira não encontrada ou não pertence a você.");
    }
}

void ServicoICarteira::excluirCarteira(const std::string& codigo) {
    std::string cpfUsuario = getCPFSessao();

    if(!persistencia->excluirCarteira(codigo, cpfUsuario))
        throw std::invalid_argument("O código informado não corresponde aos das carteiras.");    
}

std::vector<CarteiraComValor> ServicoICarteira::getCarteiras() {
    std::string cpfUsuario = getCPFSessao();

    return persistencia->getCarteiras(cpfUsuario);
}
