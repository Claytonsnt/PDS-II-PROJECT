#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include "model/desenvolvedor.hpp"

/**
 * @class Desenvolvedores
 * @brief É uma classe repositório.
 *
 * Contém os métodos necessários para os desenvolvedores.
 */
namespace tpapp::repository {
class Desenvolvedores {
public:

    /// @brief Inicializa um repositório de desenvolvedores
    ///
    /// @param nome_arquivo        O nome do repositório
    Desenvolvedores(const std::string& nome_arquivo);

    /// @brief obtem um desenvolvedor a partir da lista do repositório
    ///
    /// @param email        email para busca no vector de desenvolvedores
    model::Desenvolvedor obter_desenvolvedor(const std::string& email) const;

    /// @brief adiciona um desenvolvedor ao repositório
    ///
    /// @param desenvolvedor     Desenvolvedor a ser adicionado
    void adicionar_desenvolvedor(const model::Desenvolvedor& desenvolvedor);

    /// @brief      Salva os desenvolvedores no repositório
    ///
    /// Salva os desenvolvedores no arquivo
    void salvar_desenvolvedores() const;

    /// @brief altera um desenvolvedor do repositório
    ///
    /// @param dev     Desenvolvedor a ser alterado   
    void alterar_desenvolvedor(const model::Desenvolvedor& dev);

    /// @brief Verifica se a desenvolvedora existe
    ///
    /// @param id     ID da desenvolvedora a ser verificada
    bool verificar_desenvolvedora(const std::string& id);


private:
    std::string _arquivo_desenvolvedores;
    std::vector<model::Desenvolvedor> _desenvolvedores;

    /// @brief      Carrega o repositório de desenvolvedores
    ///
    /// Carrega o repositório a partir do nome do arquivo
    void carregar_desenvolvedores();

};
}