#pragma once

#include <iostream>
#include <vector>
#include <string>

#include "ui/menu.hpp"
#include "model/usuario.hpp"
#include "service/jogo.hpp"


namespace tpapp::ui {
class Biblioteca : public Menu{
public:
    Biblioteca(model::Usuario const &usuario);
    Menu *next(unsigned option) override;
    std::vector<Jogo> jogos();
    std::vector<Jogo> favoritos();
private:
    model::Usuario const &_usuario;
    std::vector<Jogo> _jogos;
    std::vector<Jogo> _favoritos;
};
}