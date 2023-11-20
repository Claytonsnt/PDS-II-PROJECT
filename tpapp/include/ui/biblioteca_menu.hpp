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
    
private:
    model::Usuario const &_usuario;
    std::vector<service::Jogo> _jogos;
    std::vector<service::Jogo> _favoritos;  
};
}