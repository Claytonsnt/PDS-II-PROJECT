#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "service/jogo.hpp"

/**
 * @class Jogos
 * @brief É uma classe repositório.
 *
 * Contém os métodos necessários para os jogos.
 */
namespace tpapp::repository {

class Jogos {
public:

    /// @brief Inicializa um repositório de jogos
    ///
    /// @param nome_arquivo        O nome do repositório
    Jogos(const std::string& nome_arquivo);
    
    /// @brief adiciona um jogo ao repositório
    ///
    /// @param jogo     jogo a ser adicionado
    void adicionar_jogo(const service::Jogo& jogo);

    /// @brief remove um jogo ao repositório
    ///
    /// @param jogo     jogo a ser removido
    void remover_jogo(const int jogo_id);

    /// @brief remove um jogo ao repositório
    ///
    /// @param jogo     jogo a ser removido
    service::Jogo obter_jogo(const service::Jogo& jogo) const;

    /// @brief exibe os jogos no repositório
    void exibir_jogos();

    /// @brief atualiza um jogo do repositório
    ///
    /// @param jogo_id      ID do jogo a ser atualizado
    /// @param novo_jogo    Jogo para substituir
    void atualizar_jogo(int jogo_id, const service::Jogo& novo_jogo);

    /// @return      Envia a lista de jogos 
    std::vector<service::Jogo> enviar_jogos();

    /// @return      retorna a quantidade de usuários no repositório
    int qnt_jogos();

private:
    std::string _arquivo_jogos;
    std::vector<service::Jogo> _jogos;

    /// @brief      Carrega os jogos no repositório
    ///
    /// Carrega os jogos do arquivo
    void carregar_jogos();

    /// @brief      Salva os jogos no repositório
    ///
    /// Salva os jogos no arquivo
    void salvar_jogos() const;
};
}
