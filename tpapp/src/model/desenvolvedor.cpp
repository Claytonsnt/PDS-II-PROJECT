#include "model/desenvolvedor.hpp"
#include "model/usuario.hpp"

namespace tpapp::model {
Desenvolvedor::Desenvolvedor(unsigned desenvolvedora_id, std::string email, InfoPessoal info):
                Usuario(email, info), _desenvolvedora_id(desenvolvedora_id) {}

unsigned Desenvolvedor::desenvolvedora_id() const {
    return _desenvolvedora_id;
}
std::string Desenvolvedor::to_string() const {
    return Usuario::to_string(), " (", _desenvolvedora_id, ")";
}
}