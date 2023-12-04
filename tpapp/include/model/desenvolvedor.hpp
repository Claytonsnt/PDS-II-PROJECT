#pragma once

#include "model/usuario.hpp"
#include <string>

/**
 * @class Desenvolvedor
 * @brief É uma subclasse do Usuário.
 *
 * Contém as informações necessárias de um usuário e desenvolvedor.
 */
namespace tpapp::model {
class Desenvolvedor : public Usuario {
public:

    /// @brief Inicializa um desenvolvedor
    ///
    /// @param usuario_id           ID do usuário
    /// @param usuario_login        Login do usuário
    /// @param senha                Senha do usuário
    /// @param desenvolvedora_id    ID da desenvolvedora
    /// @param email                Email do usuário
    /// @param info                 Informações pessoais do usuário
    /// @param saldo                Saldo da carteira do usuário
    Desenvolvedor(int usuario_id, std::string usuario_login, std::string senha, std::string desenvolvedora_id, std::string email,
	              InfoPessoal info, unsigned saldo);

    /// @return ID da desenvolvedora
    std::string desenvolvedora_id() const;

    /// @return uma string com as informações importantes do usuário
    std::string to_string() const;

private:

    std::string _desenvolvedora_id;
};
}