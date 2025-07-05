#ifndef CARTEIRA_SERVICO_HPP_INCLUDED
#define CARTEIRA_SERVICO_HPP_INCLUDED

/**
 * @file carteira_servico.hpp
 * @brief Implementação da camada de serviço para a entidade Carteira.
 *
 * @details Este arquivo define a classe `ServicoICarteira`, que implementa a
 * interface `ISCarteira` e contém a lógica de negócio principal para
 * o gerenciamento de carteiras. 
 * Ela coordena as operações, aplica regras de negócio e interage com a camada de persistência.
 *
 * @author Matheus Duarte
 * @date 03/07/2025
 */

#include <sstream>
#include <iomanip>

#include "../../persistencia/carteira/interface_repositorio_carteira.hpp"

#include "interface_servico_carteira.hpp"

/**
 * @class ServicoICarteira
 * @brief Implementação concreta do serviço de negócio de Carteira.
 *
 * @details Esta classe implementa os métodos definidos em `ISCarteira`,
 * atuando como um intermediário entre a camada de apresentação e a de persistência,
 * garantindo que todas as regras de negócio sejam cumpridas.
 */
class ServicoICarteira : public ISCarteira { 
private:
    IPCarteira* persistencia;

    void verificarSessao(SessaoUsuario& sessao);
    std::string getCPFSessao();
    std::vector<Ordem> getOrdensCarteira(const std::string codCarteira);

public:
    /**
     * @brief Construtor que recebe a dependência da camada de persistência.
     * 
     * @param persistencia Ponteiro para uma implementação de `IPCarteira`.
     */
    ServicoICarteira(IPCarteira* persistencia);
    
    // Documentação já apresentada na interface
    void criarCarteira(const Nome& nome, const Perfil& perfil) override;
    void editarNomeCarteira(const std::string& codigo, const Nome& novoNome) override;
    void editarPerfilCarteira(const std::string& codigo, const Perfil& novoPerfil) override;
    void excluirCarteira(const std::string& codigo) override;
    void excluirCarteirasUsuario() override;
    std::vector<CarteiraComValor> getCarteiras() override;
};

#endif  // CARTEIRA_SERVICO_HPP_INCLUDED
