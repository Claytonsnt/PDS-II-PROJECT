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
    Usuario(std::string email, InfoPessoal info);
    int id_usuario;
    std::string email() const;
    std::string nome() const;
    unsigned idade() const;

    std::string to_string() const;

private:
    std::string _email;
    InfoPessoal _info;
};
}