#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "service/jogo.hpp"

/**
 * @class Bibliotecas
 * @brief É uma classe repositório.
 *
 * Contém os métodos necessários para as bibliotecas.
 */
namespace tpapp::repository {
    
class Bibliotecas {
public:

    /// @brief Inicializa um repositório de biblioteca
    ///
    /// @param nome_arquivo        O nome do repositório
    Bibliotecas(const std::string &nome_arquivo);

    /// @brief adiciona um jogo ao repositório
    ///
    /// @param jogo     Jogo a ser adicionado
    bool adicionar_jogo(const service::Jogo& jogo);

    /// @return      Envia a biblioteca para o usuário 
    std::vector<service::Jogo> enviar_biblioteca();

private:
    std::string _arquivo_biblioteca;
    std::vector<service::Jogo> _biblioteca;

    /// @brief      Carrega a biblioteca do repositório
    ///
    /// Carrega a biblioteca do usuário a partir do nome do arquivo
    void carregar_biblioteca();

    /// @brief      Salva a biblioteca no repositório
    ///
    /// Salva a biblioteca do usuário a partir do nome do arquivo
    void salvar_biblioteca() const;
};
}