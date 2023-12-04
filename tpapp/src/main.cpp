#include "ui/login_menu.hpp"
#include <iostream>

namespace ui = tpapp::ui;
int main() {
    ui::LoginMenu login;
    login.render();

    unsigned option;
    std:: cin >> option;

    ui::Menu *menu = login.next(option);
    while (menu != nullptr) {
        menu->render();
        std::cin >> option;

        ui::Menu *old_menu = menu;
        menu = menu->next(option);

        delete old_menu;
    }
    return 0;
};