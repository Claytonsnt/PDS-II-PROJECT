#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "service/avaliacao.hpp"
#include "service/jogo.hpp"

/**
 * @class Avaliacoes
 * @brief É uma classe repositório.
 *
 * Contém os métodos necessários para as avaliações.
 */
namespace tpapp::repository {

class Avaliacoes {
public:

    /// @brief Inicializa um repositório de avaliações
    ///
    /// @param nome_arquivo        O nome do repositório
    Avaliacoes(const std::string& nome_arquivo);

    /// @brief adiciona uma avaliação ao repositório
    ///
    /// @param avaliacao     Avaliação a ser adicionada
    void adicionar_avaliacao(const service::Avaliacao& avaliacao);

    /// @brief busca uma avaliação no vector de avaliações
    ///
    /// @param jogo     O jogo para buscar as avaliações
    service::Avaliacao obter_avaliacao(const service::Jogo& jogo) const;

    /// @brief busca uma avaliação no vector de avaliações
    ///
    /// @param usuario_id     O ID do usuario para remover a avaliação
    /// @param jogo_id        O ID do jogo para remover a avaliação
    void remover_avaliacao(int usuario_id, int jogo_id);

    /// @brief salva a avaliação no repositório
    void salvar_avaliacao() const;

private:
    std::string _arquivo_avaliacoes;
    std::vector<service::Avaliacao> _avaliacoes;
};
}
