#include "service/transacao.hpp"

#include <iostream>
#include <string>

namespace tpapp:: service {
Transacao::Transacao(const std::string tipo, const double valor, const std::string data, const std::string forma_pagamento): _tipo(tipo), _valor(valor), _forma_pagamento(forma_pagamento), _data(data) {}

std::string Transacao::tipo() const {
    return _tipo;
}

double Transacao::valor() const {
    return _valor;
}

std::string Transacao:: forma_pagamento() const {
    return _forma_pagamento;
}

std::string Transacao:: data() const {
    return _data;
}
}