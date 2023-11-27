#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "service/jogo.hpp"

namespace tpapp::repository {

class Jogos {
public:
    Jogos(const std::string& nome_arquivo);

    void adicionar_jogo(const service::Jogo& jogo);
    service::Jogo obter_jogo(const service::Jogo& jogo) const;

private:
    std::string _arquivo_jogos;
    std::vector<service::Jogo> _jogos;

    void carregar_jogos();
    void salvar_jogos() const;
};
}
