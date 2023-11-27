#pragma once

#include <iostream>
#include <vector>
#include <string>

#include "ui/menu.hpp"
#include "model/desenvolvedor.hpp"

namespace tpapp::ui {
class DevMenu: public Menu {
public:
    DevMenu(model::Desenvolvedor const &usuario_dev);
    Menu *next(unsigned option) override;

    model::Desenvolvedor const &_usuario_dev;

    //void adicionar_jogo(const service::Jogo& jogo);
    //void remover_jogo(const service::Jogo& jogo);
    //void atualizar_jogo(const service::Jogo& jogo);
private:
    void salvar_usuario_conectado(const model::Usuario& usuario) const;
    model::Usuario carregar_usuario_conectado();
};
}