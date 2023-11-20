#include "service/jogo.hpp"
#include <string>

namespace tpapp::service {
Jogo::Jogo(std::string nome): _nome(nome) {}

std::string Jogo::nome() const{
    return _nome;
}
}