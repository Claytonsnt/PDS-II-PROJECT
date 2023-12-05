#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "model/usuario.hpp"


namespace tpapp::model {
TEST_CASE("Testes para a classe Usuario") {

    SUBCASE("Criar usuário válido") {
        model::InfoPessoal info{"João", "Pedro", 30};
        model::Usuario usuario(05,"joaopedro", "senha123", "joaopedro@example.com", info, false, 100);
        CHECK(usuario.usuario_login() == "joaopedro");
        CHECK(usuario.email() == "joaopedro@example.com");
        CHECK(usuario.saldo() == 100);
    }

    SUBCASE("Verificar nome de usuário único") {
        model::InfoPessoal info1{"João", "Pedro", 30};
        model::InfoPessoal info2{"Alice", "Silva", 25};
        model::Usuario usuario1(05,"joaopedro", "senha123", "joaopedro@example.com", info1, false, 100);
        model::Usuario usuario2(06, "joaopedro", "senha123", "alice@example.com", info2, false, 150);
        CHECK(usuario1.usuario_login() == usuario2.usuario_login());
    }
}
}