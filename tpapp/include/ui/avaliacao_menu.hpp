#pragma once

#include "model/usuario.hpp"

#include "service/jogo.hpp"
#include "service/avaliacao.hpp"

#include "ui/menu.hpp"

#include <iostream>
#include <string>
#include <vector>

/**
 * @class AvaliacaoMenu
 * @brief É uma subclasse do Menu.
 *
 * Contém as informações necessárias para a exibição de um menu de avaliação.
 */
namespace tpapp::ui {
class AvaliacaoMenu : public Menu {
public:

    /// @brief Inicializa o menu de avaliação
    ///
    /// @param usuario      O usuário conectado
    /// @param jogo         O jogo a ser avaliado
    AvaliacaoMenu(model::Usuario const &usuario);
    Menu *next(unsigned option) override;

    /// @brief salva os dados do usuário conectado
    ///
    /// @param usuario          O usuário conectado
    void salvar_usuario_conectado(const model::Usuario& usuario) const;

private:
    model::Usuario const &_usuario;
    std::vector<service::Avaliacao> _avaliacoes;
    std::vector<service::Jogo> _jogos;

    /// @brief carrega os dados do usuário conectado
    ///
    model::Usuario carregar_usuario_conectado();
};
}