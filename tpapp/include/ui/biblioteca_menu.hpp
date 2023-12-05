#pragma once

#include "model/usuario.hpp"

#include "service/jogo.hpp"

#include "ui/menu.hpp"

#include <iostream>
#include <string>
#include <vector>

/**
 * @class Biblioteca
 * @brief É uma subclasse do Menu.
 *
 * Contém as informações necessárias para a exibição de um menu biblioteca.
 */
namespace tpapp::ui {
class Biblioteca : public Menu{
public:

    /// @brief Inicializa o menu de biblioteca
    ///
    /// @param usuario      O usuário conectado
    Biblioteca(model::Usuario const &usuario);
    Menu *next(unsigned option) override;

    /// @brief salva os dados do usuário conectado
    ///
    /// @param usuario          O usuário conectado
    void salvar_usuario_conectado(const model::Usuario& usuario) const;

private:   

    model::Usuario const &_usuario;
    std::vector<service::Jogo> _jogos;
    std::vector<service::Jogo> _biblioteca;
    std::vector<service::Jogo> _favoritos;
    

    /// @brief carrega os dados do usuário conectado
    ///
    model::Usuario carregar_usuario_conectado();
};
}