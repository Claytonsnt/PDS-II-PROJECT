#include <iostream>
#include <string>
#include <vector>
#include "service/transacao.hpp"

namespace tpapp::service {
class Carteira {
public:
    Carteira(double saldo);
    double saldo();
    void alterar_saldo(double valor);
    void adiciona_transacao(service::Transacao t);

private:
    double _saldo;
    std::vector<service::Transacao> _historico;
};
}