#pragma once

#include <iostream>
#include <string>
#include <vector>

/**
 * @class Avaliação
 * @brief Contém as informações necessárias de uma avaliação.
 *
 */
namespace tpapp::service {
class Avaliacao {
public:

    /// @brief Inicializa uma avaliação
    ///
    /// @param jogo_id          O ID do jogo a ser avaliado
    /// @param usuario_id       O ID do usuário que fez a avaliação
    /// @param nota             A nota que o usuário atribuiu ao jogo
    /// @param comentario       O comentário feito pelo usuário
    Avaliacao(int jogo_id, int usuario_id, double nota, std::string comentario);

    /// @return ID do jogo
    int jogo_id() const;

    /// @return ID do usuário
    int usuario_id() const;

    /// @return A nota atribuída ao jogo
    double nota() const;

    /// @return O comentário atribuído ao jogo.
    std::string comentario() const;

private:
    int _jogo_id;
    int _usuario_id;
    double _nota;
    std::string _comentario;
    std::vector<int> _curtidas;
};
}