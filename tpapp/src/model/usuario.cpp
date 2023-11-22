#include "model/usuario.hpp"
#include <string>

namespace tpapp:: model {
Usuario::Usuario(std::string usuario_login, std::string email, InfoPessoal info, bool desenvolvedor): _usuario_login(usuario_login), _email(email), _info(info), _desenvolvedor(desenvolvedor) {}

std::string Usuario::usuario_login() const {
  return _usuario_login;
}

std::string Usuario::email() const {
  return _email;
}

std::string Usuario::nome() const {
  return _info.primeiro_nome + " " + _info.sobrenome;
}

unsigned Usuario::idade() const {
  return _info.idade;
}

bool Usuario::desenvolvedor() const {
  return _desenvolvedor;
}

std::string Usuario::to_string() const {
  return nome() + " (" + _email + ", " + std::to_string(idade()) + " anos)";
}
}