#include "service/jogo.hpp"
#include <string>

namespace tpapp::service {
Jogo::Jogo(int jogo_id, std::string nome,std::string desenvolvedora, const std::string genero, 
const std::string data_lacamento, const double valor):
 _jogo_id(jogo_id), _nome(nome),_desenvolvedora(desenvolvedora), _genero(genero), _data_lancamento(data_lacamento), _valor(valor) {}

std::string Jogo::nome() const{
    return _nome;
}

std::string Jogo::desenvolvedora() const{
    return _desenvolvedora;
}

std::string Jogo::genero() const{
    return _genero;
}

std::string Jogo::data_lacamento() const{
    return _data_lancamento;
}

double Jogo::valor() const{
    return _valor;
}
int Jogo::jogo_id() const{
    return _jogo_id;
}
}