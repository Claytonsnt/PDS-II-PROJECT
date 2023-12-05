#include "doctest.h"

#include "service/carteira.hpp"

tpapp::service::Carteira carteira_test;

TEST_CASE("Teste compra sem saldo") {
    carteira_test.alterar_saldo(-50);
    CHECK(carteira_test.saldo() == -50);
}