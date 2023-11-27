#include "service/carteira.hpp"
#include <iostream>
#include <string>

namespace tpapp::service {
Carteira::Carteira(double saldo): _saldo(saldo) {}

void Carteira::altera_saldo(double valor) {
    if ((_saldo + valor) < 0) {
        std::cout <<"Voce nao tem saldo suficiente para realizar essa operacao" << std::endl;
        return;
    }
    else { 
        _saldo = _saldo + valor;
    }
    return;
}

double saldo() {
    return 0;
}
}