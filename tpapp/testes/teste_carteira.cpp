#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "service/carteira.hpp"

namespace tpapp::service {
TEST_CASE("Testes para a classe Carteira") {
    SUBCASE("Criar carteira com saldo inicial") {
        service::Carteira carteira(100.0);
        CHECK(carteira.saldo() == doctest::Approx(100.0));
    }

    SUBCASE("Fazer compra com saldo") {
        service::Carteira carteira(100.0);
        carteira.alterar_saldo(-50.0);
        CHECK(carteira.saldo() == doctest::Approx(50.0));
    }
    SUBCASE("Fazer compra sem saldo") {   
        service::Carteira carteira(100.0);
        carteira.alterar_saldo(-200.0);
        CHECK(carteira.saldo() == doctest::Approx(100.0));
    }
}
}