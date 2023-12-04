#include "model/desenvolvedor.hpp"
#include "model/usuario.hpp"

namespace tpapp::model {
Desenvolvedor::Desenvolvedor(int usuario_id, std::string usuario_login, std::string senha, std::string desenvolvedora_id, std::string email, InfoPessoal info, unsigned saldo):
                Usuario(usuario_id, usuario_login, senha, email, info, true, saldo), _desenvolvedora_id(desenvolvedora_id) {}

std::string Desenvolvedor::desenvolvedora_id() const {
    return _desenvolvedora_id;
}
std::string Desenvolvedor::to_string() const {
    return Usuario::to_string();
}
}