#pragma once

#include <string>

namespace tpapp::model {
struct InfoPessoal {
std::string primeiro_nome;
std::string sobrenome;
unsigned idade;
};

class Usuario {
public:
    Usuario(int usuario_id, std::string usuario_login, std::string senha, std::string email, InfoPessoal info, bool desenvolvedor, unsigned saldo);
    int usuario_id() const;
    std::string usuario_login() const;
    std::string email() const;
    std::string nome() const;
    std::string senha() const;
    unsigned idade() const;
    unsigned saldo() const;
    bool desenvolvedor() const;
    void alterar_saldo(unsigned valor);
    model::InfoPessoal info() const;

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