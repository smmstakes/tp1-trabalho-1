#include "ordem_servico.hpp"

ServicoIOrdem::ServicoIOrdem(IPOrdem* persistenciaOrdem, IPCarteira* persistenciaCarteira, IServicoDadosHistoricos* servicoDados)
    : persistenciaOrdem(persistenciaOrdem), persistenciaCarteira(persistenciaCarteira), servicoDados(servicoDados) {}

void ServicoIOrdem::verificarSessao(SessaoUsuario& sessao) {
    if (!sessao.estaLogado()) {
        throw std::runtime_error("Usuário não está logado.");
    }
}

std::string ServicoIOrdem::getCPFSessao() {
    SessaoUsuario& sessao = SessaoUsuario::getInstance();
    verificarSessao(sessao);
    return sessao.getContaLogada().getCpf();
}

void ServicoIOrdem::criarOrdem(const CodigoNegociacao& codNegociacao, const Quantidade& quantidade, const Data& data, const Codigo& codigoCarteira) {
    std::string cpfUsuario = getCPFSessao();

    std::vector<CarteiraComValor> carteiras = persistenciaCarteira->getCarteiras(cpfUsuario);
    bool carteiraValida = false;
    for (const auto& c : carteiras) {
        if (c.carteira.getCodigo() == codigoCarteira.get()) {
            carteiraValida = true;
            break;
        }
    }
    if (!carteiraValida) {
        throw std::runtime_error("Carteira informada nao pertence ao usuario logado.");
    }

    std::string ultimoCodigoStr = persistenciaOrdem->obterUltimoCodigoOrdemInserido();
    int novoCodigoInt = 1;

    if (!ultimoCodigoStr.empty()) {
        novoCodigoInt = std::stoi(ultimoCodigoStr) + 1;
    }

    std::ostringstream oss;
    oss << std::setw(5) << std::setfill('0') << novoCodigoInt;
    
    Codigo novoCodigoDominio;
    novoCodigoDominio.set(oss.str());
    
    double precoMedio = servicoDados->getPrecoMedioNaData(codNegociacao, data);
    double precoFinal = precoMedio * quantidade.get();

    persistenciaOrdem->criarOrdem(
        novoCodigoDominio.get(),
        codNegociacao.get(),
        data.get(),
        precoFinal,
        quantidade.get(),
        codigoCarteira.get()
    );
}

void ServicoIOrdem::excluirOrdem(const Codigo& codigoOrdem, const Codigo& codigoCarteira) {
    std::string cpfUsuario = getCPFSessao();

    std::vector<CarteiraComValor> carteiras = persistenciaCarteira->getCarteiras(cpfUsuario);
    bool carteiraValida = false;
    for (const auto& c : carteiras) {
        if (c.carteira.getCodigo() == codigoCarteira.get()) {
            carteiraValida = true;
            break;
        }
    }
    if (!carteiraValida) {
        throw std::runtime_error("Operação não permitida. A carteira não pertence a você.");
    }
    
    bool sucesso = persistenciaOrdem->excluirOrdem(codigoOrdem.get(), codigoCarteira.get());
    
    if (!sucesso) {
        throw std::runtime_error("Ordem não encontrada nesta carteira.");
    }
}

std::vector<Ordem> ServicoIOrdem::listarOrdens(const Codigo& codigoCarteira) {
    std::string cpfUsuario = getCPFSessao();

    std::vector<CarteiraComValor> carteiras = persistenciaCarteira->getCarteiras(cpfUsuario);
    bool carteiraValida = false;
    for (const auto& c : carteiras) {
        if (c.carteira.getCodigo() == codigoCarteira.get()) {
            carteiraValida = true;
            break;
        }
    }
    if (!carteiraValida) {
        throw std::runtime_error("Carteira não encontrada ou não pertence a você.");
    }

    return persistenciaOrdem->getOrdensPorCarteira(codigoCarteira.get());
}