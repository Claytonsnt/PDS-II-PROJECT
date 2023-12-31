#pragma once

#include <iostream>
#include <string>
#include <vector>

/**
 * @class Menu
 * @brief Contém as informações gerais para a exibição de um menu.
 *
 */
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