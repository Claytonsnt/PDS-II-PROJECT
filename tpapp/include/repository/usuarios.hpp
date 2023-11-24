#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include "model/usuario.hpp"

namespace tpapp::repository {

class Usuarios {
public:
    Usuarios(const std::string& nome_arquivo);

    bool verificarUsuarioEmail(const std::string& email) const;
    void adicionarUsuario(const model::Usuario& usuario);
    model::Usuario obterUsuario(const std::string& email) const;
    int qnt_usuarios();

private:
    std::string _arquivo_usuarios;
    std::vector<model::Usuario> _usuarios;

    void carregarUsuarios();
    void salvarUsuarios() const;

};
}