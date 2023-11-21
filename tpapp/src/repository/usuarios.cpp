#include "repository/usuarios.hpp"
#include "model/usuario.hpp"

#include <fstream>

namespace tpapp::repository {

Usuarios::Usuarios(const std::string& nome_arquivo): _arquivo_usuarios(nome_arquivo) {
    carregarUsuarios();
} 

bool Usuarios::verificarUsuarioEmail(const std::string& email) const {
    for (const auto& usuario : _usuarios) {
        if (usuario.email() == email) {
            return true;
        }
    }
    return false;
}

model::Usuario Usuarios::obterUsuario(const std::string& email) const {
    for (const auto& usuario : _usuarios) {
        if (usuario.email() == email){
            return usuario;
        }
    }
    throw std::runtime_error("Usuário não encontrado.");
}

void Usuarios::adicionarUsuario(const model::Usuario& usuario) {
    _usuarios.push_back(usuario);
    salvarUsuarios();
}

void Usuarios::carregarUsuarios() {
    std::ifstream arquivo(_arquivo_usuarios, std::ios::in);

    if(arquivo.is_open()) {
        std::string usuario_login, email, nome, sobrenome;
        unsigned idade;

        while(arquivo >> usuario_login >> email >> nome >> sobrenome >> idade ) {
            model::InfoPessoal info;
            info.primeiro_nome = nome;
            info.sobrenome = sobrenome;
            info.idade = idade;

            model::Usuario usuario(usuario_login, email, info);
            _usuarios.push_back(usuario);
        }
        arquivo.close();
    } else {
        std::cerr << " ERRO ao abrir o arquivo de Usuários." << std::endl;
    }
}

void Usuarios::salvarUsuarios() const {
    std::ofstream arquivo(_arquivo_usuarios);

    if (arquivo.is_open()) {
        for (const auto& usuario : _usuarios) {
            arquivo << usuario.usuario_login() << ' ' << usuario.email() <<' '<< usuario.nome()<<' '<< usuario.idade() << '\n';
        }
        arquivo.close();
    } else {
        std::cerr << "Erro ao salvar o arquivo de usuários." << std::endl;
    }
}

}