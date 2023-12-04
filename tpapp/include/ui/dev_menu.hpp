#pragma once

#include <iostream>
#include <vector>
#include <string>

#include "ui/menu.hpp"
#include "model/desenvolvedor.hpp"

/**
 * @class DevMenu
 * @brief É uma subclasse do Menu.
 *
 * Contém as informações necessárias para a exibição de um menu de desenvolvedor.
 */
namespace tpapp::ui {
class DevMenu: public Menu {
public:

    /// @brief Inicializa o menu de desenvolvedor
    ///
    /// @param usuario_dev      O usuário conectado
    DevMenu(model::Desenvolvedor const &usuario_dev);
    Menu *next(unsigned option) override;

    model::Desenvolvedor const &_usuario_dev;

private:

    /// @brief salva os dados do usuário conectado
    ///
    /// @param usuario          O usuário conectado
    void salvar_usuario_conectado(const model::Usuario& usuario) const;

    /// @brief carrega os dados do usuário conectado
    ///
    model::Usuario carregar_usuario_conectado();
};
}