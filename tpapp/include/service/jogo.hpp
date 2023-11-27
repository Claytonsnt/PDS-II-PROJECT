#pragma once

#include <iostream>
#include <string>

namespace tpapp::service {
class Jogo {
public:
    Jogo(const int jogo_id, const std::string nome, const std::string desenvolvedora, const std::string genero, const double valor, std::string data_lancamento);
    int jogo_id() const;
    std::string nome() const;
    std::string desenvolvedora() const;
    std::string genero() const;
    double valor() const;
    std::string data_lancamento() const;
  
private:
    int _jogo_id;
    std::string _nome;
    std::string _desenvolvedora;
    std::string _genero;
    double _valor;
    std::string _data_lancamento;
};
}