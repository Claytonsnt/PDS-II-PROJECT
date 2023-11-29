#pragma once

#include <iostream>
#include <string>

namespace tpapp::service {
class Jogo {
public:
    Jogo(int jogo_id, std::string nome, std::string desenvolvedora, std::string genero, double valor, std::string data_lancamento);
    int jogo_id() const;
    std::string nome() const;
    std::string desenvolvedora() const;
    std::string genero() const;
    std::string data_lancamento() const;
    double valor() const;
  
private:
    int _jogo_id;
    std::string _nome;
    std::string _desenvolvedora;
    std::string _genero;
    double _valor;
    std::string _data_lancamento;
};
}