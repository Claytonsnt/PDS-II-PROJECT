#include <iostream>
#include <vector>
#include <string>

class Jogo {
public:
    int jogo_id;
    std::string nome;
    std::string desenvolvedora;
    std::string data_lancamento;
    std::string genero;
    float avaliacao_media;
    float valor;


};

class Desenvolvedor {};


class Usuario {
public:
    int usuario_id;
    std::string nome;
    std::string email;
    std::string senha;
    std::vector<Jogo> lista_desejos;
    float saldo;
    Desenvolvedor desenvolvedor;




};