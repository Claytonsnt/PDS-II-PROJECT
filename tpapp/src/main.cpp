#include "ui/login_menu.hpp"
#include <iostream>

namespace ui = tpapp::ui;
int main() {
    ui::LoginMenu login;
    login.render();

    unsigned option;
    std:: cin >> option;

    ui::Menu *menu = login.next(option);
    return 0;
};