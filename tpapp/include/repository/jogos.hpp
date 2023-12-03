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
    void remover_jogo(const int jogo_id);
    service::Jogo obter_jogo(const service::Jogo& jogo) const;
    void exibir_jogos();
    void atualizar_jogo(int jogo_id, const service::Jogo& novo_jogo);
    int qnt_jogos();
    std::vector<service::Jogo> enviar_jogos();
    void carregar_jogos();
    void salvar_jogos() const;

private:
    std::string _arquivo_jogos;
    std::vector<service::Jogo> _jogos;
};
}
