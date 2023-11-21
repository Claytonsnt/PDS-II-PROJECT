#include "service/jogo.hpp"
#include <string>

namespace tpapp::service {
Jogo::Jogo(int jogo_id, std::string nome): _jogo_id(jogo_id), _nome(nome) {}

std::string Jogo::nome() const{
    return _nome;
}

int Jogo::jogo_id() const{
    return _jogo_id;
}
}