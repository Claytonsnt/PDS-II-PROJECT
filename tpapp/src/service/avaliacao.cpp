#include "service/avaliacao.hpp"
#include <iostream>
#include <string>

namespace tpapp::service {
Avaliacao::Avaliacao(int usuario_id, int jogo_id, double nota, std::string comentario): _usuario_id(usuario_id), _jogo_id(jogo_id), _nota(nota), _comentario(comentario) {}

int Avaliacao::usuario_id() {
    return _usuario_id;
}

int Avaliacao::jogo_id() {
    return _jogo_id;
}

double Avaliacao::nota() {
    return _nota;
}

std::string Avaliacao::comentario() {
 return _comentario;
}
}