#include "dados_historicos_servico.hpp"
#include <fstream>
#include <stdexcept>
#include <iostream>

ServicoDadosHistoricos::ServicoDadosHistoricos() {
    this->carregarDados();
}

void ServicoDadosHistoricos::carregarDados() {
    std::string linha;
    std::ifstream arquivo("../DADOS_HISTORICOS.TXT");

    if (!arquivo.is_open()) {
        throw std::runtime_error("Nao foi possivel abrir o arquivo de dados historicos: DADOS_HISTORICOS.TXT");
    }

    while (getline(arquivo, linha)) {
        if (linha.substr(0, 2) != "01") {
            continue;
        }

        std::string codigoNaLinha = linha.substr(12, 12);
        std::string dataNaLinha = linha.substr(2, 8);
        double precoMedio = std::stod(linha.substr(56, 13)) / 100.0;

        codigoNaLinha.erase(codigoNaLinha.find_last_not_of(" \n\r\t")+1);
        
        cacheDePrecos[codigoNaLinha][dataNaLinha] = precoMedio;
    }
    arquivo.close();
}

double ServicoDadosHistoricos::getPrecoMedioNaData(const CodigoNegociacao& codNegociacao, const Data& data) {
    try {
        return cacheDePrecos.at(codNegociacao.get()).at(data.get());
    }
    catch (const std::out_of_range& oor) {
        throw std::invalid_argument("Preco para o ativo na data informada nao foi encontrado.");
    }
}   