#include "dados_historicos_servico.hpp"
#include <fstream>
#include <stdexcept>
#include <iostream>

ServicoDadosHistoricos::ServicoDadosHistoricos() {
    this->carregarDados();
}

void ServicoDadosHistoricos::carregarDados() {
    const int POS_TIPO_REGISTRO = 0;
    const int POS_DATA_PREGAO = 2;
    const int POS_CODIGO_NEGOCIACAO = 12;
    const int POS_PRECO_MEDIO = 113;

    const int LEN_TIPO_REGISTRO = 2;
    const int LEN_DATA_PREGAO = 8;
    const int LEN_CODIGO_NEGOCIACAO = 12;
    const int LEN_PRECO_MEDIO = 13;
    const int TAMANHO_MINIMO_LINHA = 126; // Posição final do preço médio

    std::string linha;
    std::ifstream arquivo("../DADOS_HISTORICOS.TXT");

    if (!arquivo.is_open()) {
        throw std::runtime_error("FALHA AO ABRIR DADOS_HISTORICOS.TXT");
    }

    while (getline(arquivo, linha)) {
        if (linha.length() < TAMANHO_MINIMO_LINHA || linha.substr(POS_TIPO_REGISTRO, LEN_TIPO_REGISTRO) != "01") {
            continue;
        }

        try {
            std::string codigoNaLinha = linha.substr(POS_CODIGO_NEGOCIACAO, LEN_CODIGO_NEGOCIACAO);
            std::string dataNaLinha = linha.substr(POS_DATA_PREGAO, LEN_DATA_PREGAO);
            double precoMedio = std::stod(linha.substr(POS_PRECO_MEDIO, LEN_PRECO_MEDIO)) / 100.0;

            size_t endpos = codigoNaLinha.find_last_not_of(" \t\r\n");
            if (std::string::npos != endpos) {
                codigoNaLinha = codigoNaLinha.substr(0, endpos + 1);
            }
            
            cacheDePrecos[codigoNaLinha][dataNaLinha] = precoMedio;

        } catch (const std::invalid_argument& e) {
            continue;
        }
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