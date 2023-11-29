#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "service/jogo.hpp"

namespace tpapp::repository {

class Jogos {
public:
    Jogos(const std::string& nome_arquivo);

    void adicionar_jogo(const service::Jogo& jogo);
    service::Jogo obter_jogo(const service::Jogo& jogo) const;
    void carregar_jogos();
    void salvar_jogos() const;

private:
    std::string _arquivo_jogos;
    std::vector<service::Jogo> _jogos;
};
}
