#pragma once

#include "service/jogo.hpp"
#include "model/usuario.hpp"
#include "ui/menu.hpp"
#include "service/avaliacao.hpp"

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
    AvaliacaoMenu(model::Usuario const &usuario, service::Jogo const &jogo);
    Menu *next(unsigned option) override;

    void salvar_usuario_conectado(const model::Usuario& usuario) const;
    void salvar_jogo(const service::Jogo& jogo) const;
    double nota_media(int const jogo_id);
    void criar_avaliacao();
    void comentar_avaliacao();
    void curtir_avaliacao();

private:
    model::Usuario const &_usuario;
    service::Jogo const &_jogo;
    double _nota;
    std::string _comentario;
    std::vector<service::Avaliacao> _avaliacoes;
};
}