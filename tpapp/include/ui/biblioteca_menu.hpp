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

    model::Usuario const &_usuario;

private:    
    std::vector<service::Jogo> _biblioteca;
    std::vector<service::Jogo> _favoritos;
    void salvar_usuario_conectado(const model::Usuario& usuario) const;
    model::Usuario carregar_usuario_conectado();
};
}