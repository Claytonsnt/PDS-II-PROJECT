#pragma once

#include "ui/menu.hpp"
#include<string>

namespace::tpapp::ui {
class LoginMenu: public Menu {
public:
    LoginMenu();

    Menu *next(unsigned option) override;
};
}