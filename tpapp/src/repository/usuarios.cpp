#include "repository/usuarios.hpp"

namespace tpapp::repository {

Usuarios::Usuarios(const std::string& nome_arquivo): _arquivo_usuarios(nome_arquivo) {
    carregarUsuarios();
} 

bool Usuarios::verificarUsuario(const std::string& email) const {
    for (const auto& usuario : _usuarios) {
        if (usuario.email() == email) {
            return true;
        }
    }
    return false;
}

void Usuarios::adicionarUsuario(const model::Usuario& usuario) {
    _usuarios.push_back(usuario);
    //salvarUsuarios();
}

void Usuarios::carregarUsuarios() {
    std::ifstream arquivo(_arquivo_usuarios);

    if(arquivo.is_open()) {
        std::string usuario_login, email;

        while(arquivo >> usuario_login >> email) {
            model::InfoPessoal info;

            model::Usuario usuario(usuario_login, email, info);
            _usuarios.push_back(usuario);
        }
        arquivo.close();
    } else {
        std::cerr << " ERRO ao abrir o arquivo de Usuários." << std::endl;
    }
}

}