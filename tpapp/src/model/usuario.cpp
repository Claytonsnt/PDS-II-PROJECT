#include "model/usuario.hpp"
#include <string>

namespace tpapp:: model {
Usuario::Usuario(int usuario_id, std::string usuario_login, std::string email, InfoPessoal info, bool desenvolvedor, unsigned saldo): _usuario_id(usuario_id), _usuario_login(usuario_login), _email(email), _info(info), _desenvolvedor(desenvolvedor), _saldo(saldo) {}

int Usuario::usuario_id() const {
  return _usuario_id;
}

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

unsigned Usuario::saldo() const {
  return _saldo;
}

std::string Usuario::to_string() const {
  return nome() + " (" + _email + ", " + std::to_string(idade()) + " anos)";
}
}