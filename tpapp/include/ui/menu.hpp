#pragma once

#include <iostream>
#include <vector>
#include <string>


namespace tpapp::ui {
class Menu {
public:
    virtual ~Menu() = default;
    virtual Menu *next(unsigned option) = 0;
    virtual void render() const;

protected:
    std::string _title = "Menu de Opções";
    std::vector<std::string> _options = {"0 - Sair"};
};
}