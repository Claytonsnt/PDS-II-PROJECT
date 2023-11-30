#pragma once

#include <iostream>
#include <string>

namespace tpapp::service {
class Avaliacao {
public:
    Avaliacao(int jogo_id, int usuario_id, double nota, std::string comentario);
    int usuario_id();
    int jogo_id();
    double nota();
    std::string comentario();

    // Levar para Menu de Avaliacao
    // double calcular_avaliacao_media();
    // void criar_avaliacao();
    // void editar_avaliacao();
    // void remover_avaliacao();
    // void comentar_avaliacao();

private:
    int _usuario_id;
    int _jogo_id;
    double _nota;
    std::string _comentario;
};
}