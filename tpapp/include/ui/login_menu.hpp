#pragma once

#include "ui/menu.hpp"

#include <string>

/**
 * @class LoginMenu
 * @brief É uma subclasse do Menu.
 *
 * Contém as informações necessárias para a exibição de um menu de login.
 */
namespace tpapp::ui {
class LoginMenu: public Menu {
public:
    /// @brief Inicializa o menu de login
    ///
    LoginMenu();

    Menu *next(unsigned option) override;
};
}