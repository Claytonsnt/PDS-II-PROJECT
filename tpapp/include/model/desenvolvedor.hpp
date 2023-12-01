#pragma once

#include "model/usuario.hpp"
#include <string>

namespace tpapp::model {
class Desenvolvedor : public Usuario {
public:

    Desenvolvedor(int usuario_id, std::string usuario_login, std::string desenvolvedora_id, std::string email,
	              InfoPessoal info, unsigned saldo);
    std::string desenvolvedora_id() const;
    std::string to_string() const;

private:

    std::string _desenvolvedora_id;
};
}