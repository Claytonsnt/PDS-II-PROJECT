#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include "model/usuario.hpp"

/**
 * @class Usuarios
 * @brief É uma classe repositório.
 *
 * Contém os métodos necessários para os usuários.
 */
namespace tpapp::repository {

class Usuarios {
public:

    /// @brief Inicializa um repositório de usuários
    ///
    /// @param nome_arquivo        O nome do repositório
    Usuarios(const std::string& nome_arquivo);

    /// @brief Verifica se o usuário existe
    ///
    /// @param email     email do usuário a ser verificado
    bool verificar_usuario_email(const std::string& email) const;

    /// @brief Verifica a senha inserida
    ///
    /// @param senha     senha do usuário a ser verificada
    bool verificar_usuario_senha(const std::string& senha) const;

    /// @brief adiciona um usuario ao repositório
    ///
    /// @param usuario     usuario a ser adicionado
    void adicionar_usuario(const model::Usuario& usuario);

    /// @brief obtem um usuario a partir da lista do repositório
    ///
    /// @param email        email para busca no vector de usuario
    model::Usuario obter_usuario(const std::string& email) const;

    /// @return         retorna a quantidade de usuários no repositório
    int qnt_usuarios();

    /// @brief      Salva os usuários no repositório
    ///
    /// Salva os usuários no arquivo
    void salvar_usuarios() const;

    /// @brief altera um usuário do repositório
    ///
    /// @param usuario     usuário a ser alterado   
    void alterar_usuario(const model::Usuario& usuario);

    /// @brief criptografa a senha
    ///
    /// @param senha       senha a ser criptografada
    /// @return            retorna a senha criptografada
    std::string criptografar_senha(std::string& senha); 

private:

    std::string _arquivo_usuarios;
    std::vector<model::Usuario> _usuarios;

    /// @brief      Carrega o repositório de usuarios
    ///
    /// Carrega o repositório do arquivo
    void carregar_usuarios();
    

};
}