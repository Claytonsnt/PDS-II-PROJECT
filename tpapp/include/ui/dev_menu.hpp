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

    //void adicionar_jogo(const service::Jogo& jogo);
    //void remover_jogo(const service::Jogo& jogo);
    //void atualizar_jogo(const service::Jogo& jogo);
private:
    model::Desenvolvedor const &_usuario_dev;
};
}