#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "service/jogo.hpp"

namespace tpapp::repository {
    
class Lojas {
public:
    Lojas(const std::string &nome_arquivo);

    bool adicionar_jogo(const service::Jogo& jogo);
    std::vector<service::Jogo> enviar_lista_desejos();

private:
    std::string _arquivo_lojas;
    std::vector<service::Jogo> _lista_desejos;

    void carregar_lista_desejos();
    void salvar_lista_desejos() const;
};
}