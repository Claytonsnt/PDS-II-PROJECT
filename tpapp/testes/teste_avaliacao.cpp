#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "service/avaliacao.hpp"

namespace tpapp::service {
    TEST_CASE("Testes para a classe Avaliacao") {
    SUBCASE("Verificar informações da avaliação") {
        tpapp::service::Avaliacao avaliacao(1, 10, 4.5, "Ótimo jogo!");

        CHECK(avaliacao.jogo_id() == 1);
        CHECK(avaliacao.usuario_id() == 10);
        CHECK(avaliacao.nota() == doctest::Approx(4.5));
        CHECK(avaliacao.comentario() == "Ótimo jogo!");
    }
}
}