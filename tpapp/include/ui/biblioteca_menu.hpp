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

    void salvar_jogos_arquivo(const std::string& nome_arquivo) const;
    void carregar_jogos_arquivo(const std::string& nome_arquivo);
    model::Usuario const &_usuario;

private:    
    std::vector<service::Jogo> _jogos;
    std::vector<service::Jogo> _favoritos;
    void salvar_usuario_conectado(const model::Usuario& usuario) const;
    model::Usuario carregar_usuario_conectado();
};
}