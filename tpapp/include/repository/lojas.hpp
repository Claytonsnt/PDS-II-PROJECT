#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "service/jogo.hpp"

/**
 * @class Lojas
 * @brief É uma classe repositório.
 *
 * Contém os métodos necessários para a lista de desejos.
 */
namespace tpapp::repository {
    
class Lojas {
public:
    /// @brief Inicializa um repositório de desejos
    ///
    /// @param nome_arquivo        O nome do repositório
    Lojas(const std::string &nome_arquivo);

    /// @brief adiciona um jogo ao repositório de desejos
    ///
    /// @param jogo     jogo a ser adicionado na lista
    bool adicionar_jogo(const service::Jogo& jogo);

    /// @return      A lista de desejos 
    std::vector<service::Jogo> enviar_lista_desejos();

private:
    std::string _arquivo_lojas;
    std::vector<service::Jogo> _lista_desejos;

    /// @brief      Carrega os jogos no repositório
    ///
    /// Carrega os jogos do arquivo
    void carregar_lista_desejos();

    /// @brief      Salva os jogos no repositório
    ///
    /// Salva os jogos no arquivo
    void salvar_lista_desejos() const;
};
}