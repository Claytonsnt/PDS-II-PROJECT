#pragma once

#include <iostream>
#include <vector>
#include <string>

#include "ui/menu.hpp"
#include "model/usuario.hpp"
#include "service/jogo.hpp"


namespace tpapp::ui {
class Loja: public Menu {
public:
    Loja(model::Usuario const &usuario);
    Menu *next(unsigned option) override;

    void salvar_jogos_arquivo(const std::string& nome_arquivo) const;
    void carregar_jogos_arquivo(const std::string& nome_arquivo);
    void comprar(unsigned valor);
    model::Usuario const &_usuario;

private:
    std::vector<service::Jogo> _jogos;
    std::vector<service::Jogo> _lista_desejos;
    std::vector<service::Jogo> _carrinho_compras;
    void salvar_usuario_conectado(const model::Usuario& usuario) const;
    model::Usuario carregar_usuario_conectado();
    
};
}