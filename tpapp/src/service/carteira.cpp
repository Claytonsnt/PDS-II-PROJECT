#include "service/carteira.hpp"

#include <iostream>
#include <string>

namespace tpapp::service {
Carteira::Carteira(double saldo = 0): _saldo(saldo) {}

void Carteira::alterar_saldo(double valor) {
    if ((_saldo + valor) < 0) {
        std::cout <<"Voce nao tem saldo suficiente para realizar essa operacao" << std::endl;
        return;
    }
    else { 
        _saldo = _saldo + valor;
    }
    return;
}

double Carteira::saldo() {
    return _saldo;
}

void Carteira::adicionar_transacao(service::Transacao t) {
    _historico.push_back(t);
    return;
}   
}