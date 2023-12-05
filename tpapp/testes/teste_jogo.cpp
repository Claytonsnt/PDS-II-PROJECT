#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "service/jogo.hpp"

namespace tpapp::service {
TEST_CASE("Testes para a classe Jogo") {
    SUBCASE("Criar jogo válido") {
        service::Jogo jogo(1, "NomeDoJogo", "Desenvolvedora", "Genero", 50.0, "DataLancamento");
        CHECK(jogo.jogo_id() == 1);
        CHECK(jogo.nome() == "NomeDoJogo");
        CHECK(jogo.desenvolvedora() == "Desenvolvedora");
        CHECK(jogo.genero() == "Genero");
        CHECK(jogo.data_lancamento() == "DataLancamento");
        CHECK(jogo.valor() == doctest::Approx(50.0));
    }
}
}