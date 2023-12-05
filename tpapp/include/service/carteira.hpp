#pragma once

#include "service/transacao.hpp"

#include <iostream>
#include <string>
#include <vector>

/**
 * @class Carteira
 * @brief Contém as informações necessárias da carteira.
 *
 */
namespace tpapp::service {
class Carteira {
public:

    /// @brief Inicializa uma carteira
    ///
    /// @param saldo       O saldo da carteira
    Carteira(double saldo);

    /// @return saldo da carteira
    double saldo();

    /// @brief altera o saldo da carteira
    ///
    /// @param valor     Novo valor da carteira
    void alterar_saldo(double valor);

    /// @brief adiciona uma transação ao histórico
    void adicionar_transacao(service::Transacao t);

private:
    double _saldo;
    std::vector<service::Transacao> _historico;
};
}