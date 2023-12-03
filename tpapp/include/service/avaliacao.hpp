#pragma once

#include <iostream>
#include <string>
#include <vector>

namespace tpapp::service {
class Avaliacao {
public:
    Avaliacao(int jogo_id, int usuario_id, double nota, std::string comentario);
    int jogo_id() const;
    int usuario_id() const;
    double nota() const;
    std::string comentario() const;

private:
    int _jogo_id;
    int _usuario_id;
    double _nota;
    std::string _comentario;
    std::vector<int> _curtidas;
};
}