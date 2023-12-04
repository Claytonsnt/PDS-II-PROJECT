#pragma once

#include <iostream>
#include <vector>
#include <string>

#include "ui/menu.hpp"
#include "model/usuario.hpp"
#include "service/jogo.hpp"

/**
 * @class Loja
 * @brief É uma subclasse do Menu.
 *
 * Contém as informações necessárias para a exibição de um menu Loja.
 */
namespace tpapp::ui {
class Loja: public Menu {
public:

    /// @brief Inicializa o menu de loja
    ///
    /// @param usuario      O usuário conectado
    Loja(model::Usuario const &usuario);
    Menu *next(unsigned option) override;

    model::Usuario const &_usuario;
    std::vector<service::Jogo> _jogos;

private:
    
    std::vector<service::Jogo> _lista_desejos;
    std::vector<service::Jogo> _carrinho_compras;
    /// @brief salva os dados do usuário conectado
    ///
    /// @param usuario          O usuário conectado
    void salvar_usuario_conectado(const model::Usuario& usuario) const;

    /// @brief carrega os dados do usuário conectado
    ///
    model::Usuario carregar_usuario_conectado();

};
}