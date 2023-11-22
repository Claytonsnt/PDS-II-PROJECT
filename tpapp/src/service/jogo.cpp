#include "service/jogo.hpp"
#include <string>
#include <ctime>

namespace tpapp::service {
Jogo::Jogo(int jogo_id, std::string nome, std::string desenvolvedora, std::string genero, double valor, std::string data_lancamento): _jogo_id(jogo_id), _nome(nome),_desenvolvedora(desenvolvedora), _genero(genero), _valor(valor), _data_lancamento(data_lancamento) {}

int Jogo::jogo_id() const{
    return _jogo_id;
}

std::string Jogo::nome() const{
    return _nome;
}

std::string Jogo::desenvolvedora() const{
    return _desenvolvedora;
}

std::string Jogo::genero() const{
    return _genero;
}

double Jogo::valor() const{
    return _valor;
}

std::string Jogo::data_lancamento() const{
    return _data_lancamento;
}
}