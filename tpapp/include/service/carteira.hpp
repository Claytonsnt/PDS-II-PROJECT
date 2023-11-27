#include <iostream>
#include <string>

namespace tpapp::service {
class Carteira {
public:
    Carteira(double saldo);
    void altera_saldo(double valor);
    double saldo();

private:
    double _saldo;
};
}