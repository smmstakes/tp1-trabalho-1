#ifndef PERSISTENCIA_HPP
#define PERSISTENCIA_HPP

#include "ISPersistencia.hpp"
#include "../../dominios/dominios.hpp"
#include "sqlite3.h"

class MSPersistencia : public ISPersistencia {
    private:
        MSPersistencia();
        ~MSPersistencia();

        MSPersistencia(const MSPersistencia&) = delete;
        MSPersistencia& operator=(const MSPersistencia&) = delete;

        static const char* NOME_DB;
        sqlite3* db;
        bool conectado;
        void conectar() override;
        void desconectar() override;
        bool criarTabelas() override;

    public:
        static MSPersistencia& getInstancia();  // Acesso à instância única -> singleton

        void salvarCarteira(const std::string& codigo, const std::string& nome, const std::string& perfil) override;
        std::string obterUltimoCodigoCarteiraInserido() override;
};


#endif
