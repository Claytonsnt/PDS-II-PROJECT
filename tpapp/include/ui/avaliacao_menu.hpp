#pragma once

#include "service/jogo.hpp"
#include "model/usuario.hpp"
#include "ui/menu.hpp"

#include <iostream>
#include <string>
#include <vector>

namespace tpapp::ui {
class AvaliacaoMenu : public Menu {
public:
    AvaliacaoMenu(model::Usuario const &usuario, service::Jogo const &jogo);
    Menu *next(unsigned option) override;

    // double calcular_avaliacao_media();
    // void criar_avaliacao();
    // void editar_avaliacao();
    // void remover_avaliacao();
    // void comentar_avaliacao();

private:

    int _usuario_id;
    int _jogo_id;
    double _nota;
    std::string _comentario;
};
}