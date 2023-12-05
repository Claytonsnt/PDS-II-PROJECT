#pragma once

#include "service/jogo.hpp"

#include "ui/loja.hpp"

#include <iostream>
#include <string>
#include <vector>

/**
 * @class Transacao
 * @brief Contém as informações necessárias de uma transação.
 *
 */
namespace tpapp::service {
class Transacao {
public:

    /// @brief Inicializa uma transação
    ///
    /// @param tipo             O tipo da transação
    /// @param valor            O valor da transação
    /// @param forma_pagamento  A forma de pagamento
    /// @param data             A data da transação
    Transacao(const std::string tipo, const double valor, const std::string forma_pagamento, const std::string data);  
    
    /// @return o tipo da transação
    std::string tipo() const;

    /// @return o valor da transação
    double valor() const;

    /// @return A forma de pagamento
    std::string forma_pagamento() const;

    /// @return A data da transação
    std::string data() const;

private:
    std::string _tipo;
    double _valor;
    std::string _forma_pagamento;
    std::string _data;
};
}