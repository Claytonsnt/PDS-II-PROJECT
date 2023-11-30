#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "ui/loja.hpp"
#include "service/jogo.hpp"

namespace tpapp::service {
class Transacao {
public:
    Transacao(const std::string tipo, const double valor, const std::string forma_pagamento, const std::string data);  
    
    std::string tipo() const;
    double valor() const;
    std::string forma_pagamento() const;
    std::string data() const;

private:
    std::string _tipo;
    double _valor;
    std::string _forma_pagamento;
    std::string _data;
};
}