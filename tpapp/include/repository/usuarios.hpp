#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include "model/usuario.hpp"

namespace tpapp::repository {

class Usuarios {
public:
    Usuarios(const std::string& nome_arquivo);

    bool verificar_usuario_email(const std::string& email) const;
    bool verificar_usuario_senha(const std::string& senha) const;
    void adicionar_usuario(const model::Usuario& usuario);
    model::Usuario obter_usuario(const std::string& email) const;
    int qnt_usuarios();
    void salvar_usuarios() const;
    void alterar_usuario(const model::Usuario& usuario);
    std::string criptografar_senha(std::string& senha); 

private:

    std::string _arquivo_usuarios;
    std::vector<model::Usuario> _usuarios;
    void carregar_usuarios();
    

};
}