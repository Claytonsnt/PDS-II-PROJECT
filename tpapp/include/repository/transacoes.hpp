#pragma once

#include "model/usuario.hpp"

#include "service/transacao.hpp"
#include "service/jogo.hpp"


#include <iostream>
#include <string>
#include <vector>

/**
 * @class Transacoes
 * @brief É uma classe repositório.
 *
 * Contém os métodos necessários para as transações.
 */

namespace tpapp::repository {

class Transacoes {
public:
    /// @brief Inicializa um repositório de transações
    ///
    /// @param nome_arquivo        O nome do repositório
    Transacoes(const std::string& nome_arquivo);

    /// @brief adiciona uma transação ao repositório
    ///
    /// @param transacao     transação a ser adicionada
    void adicionar_transacao(const service::Transacao& transacao);

    /// @brief      Carrega o repositório
    ///
    /// Carrega as transações do arquivo
    void carregar_transacoes();

    /// @brief      Salva o repositório
    ///
    /// Salva as transações no arquivo
    void salvar_transacoes();

    /// @brief Realiza uma manobra de compra
    ///
    /// @param jogo        O jogo a ser comprado
    /// @param usuario     O usuário que está comprando
    void comprar(const service::Jogo& jogo, const model::Usuario& usuario);

    /// @brief exibe as transações
    void exibir_transacoes();

    /// @brief Obtem a data
    ///
    /// @return           A data atual da transação
    std::string obter_data();
private:
    std::string _arquivo_transacoes;
    std::vector<service::Transacao> _transacoes;
};
}