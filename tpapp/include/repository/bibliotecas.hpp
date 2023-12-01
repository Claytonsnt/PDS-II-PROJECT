#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "service/jogo.hpp"

namespace tpapp::repository {
    
class Bibliotecas {
public:
    Bibliotecas(const std::string &nome_arquivo);

    bool adicionar_jogo(const service::Jogo& jogo);
    std::vector<service::Jogo> enviar_biblioteca();

private:
    std::string _arquivo_biblioteca;
    std::vector<service::Jogo> _biblioteca;

    void carregar_biblioteca();
    void salvar_biblioteca() const;
};
}