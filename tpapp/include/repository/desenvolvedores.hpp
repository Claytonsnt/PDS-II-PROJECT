#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include "model/desenvolvedor.hpp"

namespace tpapp::repository {
class Desenvolvedores {
public:
    Desenvolvedores(const std::string& nome_arquivo);

    model::Desenvolvedor obter_desenvolvedor(const std::string& email) const;
    void adicionar_desenvolvedor(const model::Desenvolvedor& desenvolvedor);
    void salvar_desenvolvedores() const;
    void alterar_desenvolvedor(const model::Desenvolvedor& dev);


private:
    std::string _arquivo_desenvolvedores;
    std::vector<model::Desenvolvedor> _desenvolvedores;

    void carregar_desenvolvedores();

};
}