#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include "model/desenvolvedor.hpp"

namespace tpapp::repository {
class Desenvolvedores {
public:
    Desenvolvedores(const std::string& nome_arquivo);

    model::Desenvolvedor obterDesenvolvedor(const std::string& email) const;
    void adicionarDesenvolvedor(const model::Desenvolvedor& desenvolvedor);

private:
    std::string _arquivo_desenvolvedores;
    std::vector<model::Desenvolvedor> _desenvolvedores;

    void carregarDesenvolvedores();
    void salvarDesenvolvedores() const;

};
}