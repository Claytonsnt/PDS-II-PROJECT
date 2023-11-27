#include <iostream>
#include <string>
#include <vector>
#include "ui/loja.hpp"
#include "service/jogo.hpp"

namespace tpapp::service {
class Transacao {
public:
    Transacao(const double valor, const std::string tipo, const std::string data, const std::string forma_pagamento);
    double valor() const;
    std::string tipo() const;
    std::string data() const;
    std::string forma_pagamento() const;
    //ui::Loja carrinho_de_compras();
    void comprar(service::Jogo jogo);

private:
    double _valor;
    std::string _tipo;
    std::string _data;
    std::string _forma_pagamento;
    //ui::Loja carrinho_de_compras;
};
}