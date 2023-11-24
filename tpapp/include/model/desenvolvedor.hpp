#pragma once

#include "model/usuario.hpp"
#include <string>

namespace tpapp::model {
class Desenvolvedor : public Usuario {
public:
    Desenvolvedor(int usuario_id, std::string usuario_login, unsigned desenvolvedora_id, std::string email,
	              InfoPessoal info);
    unsigned desenvolvedora_id() const;
    std::string to_string() const;
private:
    unsigned _desenvolvedora_id;
};
}