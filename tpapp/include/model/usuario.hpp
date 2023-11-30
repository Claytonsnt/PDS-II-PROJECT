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
    Usuario(int usuario_id, std::string usuario_login, std::string email, InfoPessoal info, bool desenvolvedor);
    int usuario_id() const;
    std::string usuario_login() const;
    std::string email() const;
    std::string nome() const;
    unsigned idade() const;
    bool desenvolvedor() const;

    std::string to_string() const;

private:
    int _usuario_id;
    std::string _usuario_login;
    std::string _email;
    InfoPessoal _info;
    bool _desenvolvedor;
};
}