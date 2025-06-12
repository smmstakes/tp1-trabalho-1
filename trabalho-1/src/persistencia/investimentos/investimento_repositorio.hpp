#ifndef INVESTIMENTO_REPOSITORIO_HPP_INCLUDED
#define INVESTIMENTO_REPOSITORIO_HPP_INCLUDED

#include "interface_repositorio_investimento.hpp"

#include "../../../libs/sqlite/sqlite3.h"
#include "../../../libs/dominios/dominios.hpp"

class RepositorioIPInvestimento : public IPInvestimento {
    private:
        RepositorioIPInvestimento();
        ~RepositorioIPInvestimento();

        RepositorioIPInvestimento(const RepositorioIPInvestimento&) = delete;
        RepositorioIPInvestimento& operator=(const RepositorioIPInvestimento&) = delete;

        static const char* NOME_DB;
        sqlite3* db;
        bool conectado;
        void conectar() override;
        void desconectar() override;
        bool criarTabelas() override;

    public:
        static RepositorioIPInvestimento& getInstancia();  // Acesso à instância única -> singleton

        void salvarCarteira(const std::string& codigo, const std::string& nome, const std::string& perfil) override;
        std::string obterUltimoCodigoCarteiraInserido() override;
};


#endif  // INVESTIMENTO_REPOSITORIO_HPP_INCLUDED
