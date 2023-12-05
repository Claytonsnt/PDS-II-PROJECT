#include "service/avaliacao.hpp"

#include <iostream>
#include <string>

namespace tpapp::service {
Avaliacao::Avaliacao(int jogo_id, int usuario_id, double nota, std::string comentario): _jogo_id(jogo_id), _usuario_id(usuario_id), _nota(nota), _comentario(comentario) {}

int Avaliacao::jogo_id() const {
    return _jogo_id;
}

int Avaliacao::usuario_id() const {
    return _usuario_id;
}

double Avaliacao::nota() const {
    return _nota;
}

std::string Avaliacao::comentario() const {
 return _comentario;
}
}