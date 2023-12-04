#pragma once

#include <string>

/**
 * @class Usuario
 * @brief Contém as informações necessárias de um usuário
 *
 */
namespace tpapp::model {
struct InfoPessoal {
std::string primeiro_nome;
std::string sobrenome;
unsigned idade;
};

class Usuario {
public:
    /// @brief Inicializa um usuário
    ///
    /// @param usuario_id       ID do usuário
    /// @param usuario_login    Login do usuário
    /// @param senha            Senha do usuário
    /// @param email            Email do usuário
    /// @param info             Informações pessoais do usuário
    /// @param desenvolvedor    Contém a informação se o usuário é ou não um desenvolvedor
    /// @param saldo            Saldo da carteira do usuário
    Usuario(int usuario_id, std::string usuario_login, std::string senha, std::string email, InfoPessoal info, bool desenvolvedor, unsigned saldo);

    /// @return ID do usuário
    int usuario_id() const;

    /// @return login do usuário
    std::string usuario_login() const;

    /// @return email do usuário
    std::string email() const;

    /// @return nome do usuário
    std::string nome() const;

    /// @return senha do usuário
    std::string senha() const;

    /// @return idade do usuário
    unsigned idade() const;

    /// @return saldo do usuário
    unsigned saldo() const;

    /// @return usuario é desenvolvedor ou não
    bool desenvolvedor() const;

    /// @brief Altera o saldo do usuário
    ///
    /// @param valor  novo saldo
    void alterar_saldo(unsigned valor);

    /// @return retorna as informações pessoais do usuário
    model::InfoPessoal info() const;

    /// @return uma string com as informações importantes do usuário
    std::string to_string() const;

private:
    int _usuario_id;
    std::string _usuario_login;
    std::string _email;
    std::string _senha;
    InfoPessoal _info;
    bool _desenvolvedor;
    unsigned _saldo;
};
}