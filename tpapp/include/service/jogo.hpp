#pragma once

#include <iostream>
#include <string>

namespace tpapp:: service {
class Jogo {
public:
    Jogo(const int jogo_id, const std::string nome, std::string desenvolvedora, const std::string genero, const std::string data_lacamento, const double valor);

    int jogo_id() const;
    std::string nome() const;
    std::string desenvolvedora() const;
    std::string genero() const;
    std::string data_lacamento() const;
    double valor() const;

private:
    int _jogo_id;
    std::string _nome;
    std::string _desenvolvedora;
    std::string _genero;
    std::string _data_lancamento;
    double _valor;
};
}