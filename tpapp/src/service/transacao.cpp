#include "service/transacao.hpp"
#include <iostream>
#include <string>

namespace tpapp:: service {
Transacao::Transacao(const double valor, const std::string tipo, const std::string data, const std::string forma_pagamento): _valor(valor), _tipo(tipo), _data(data), _forma_pagamento(forma_pagamento){}

double Transacao::valor() const {
    return _valor;
}

std::string Transacao::tipo() const {
    return _tipo;
}

std::string Transacao:: data() const {
    return _data;
}

std::string Transacao:: forma_pagamento() const {
    return _forma_pagamento;
}

// void Transacao::comprar(service::Jogo jogo) {
//     return;
// }
}