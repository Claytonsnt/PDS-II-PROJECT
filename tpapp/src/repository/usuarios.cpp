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

int Usuarios::qnt_usuarios() {
    int count = 0;
    for(const model::Usuario& usuario : _usuarios) {
        count++;
    }
    return count;
}

void Usuarios::carregarUsuarios() {
    std::ifstream arquivo(_arquivo_usuarios, std::ios::in);

    if(arquivo.is_open()) {
        int usuario_id;
        unsigned idade;
        bool desenvolvedor;
        std::string usuario_login, email, nome, sobrenome;
        

        while(arquivo >> usuario_id >> usuario_login >> email >> nome >> sobrenome >> idade >> desenvolvedor ) {
            model::InfoPessoal info;
            info.primeiro_nome = nome;
            info.sobrenome = sobrenome;
            info.idade = idade;

            model::Usuario usuario(usuario_id, usuario_login, email, info, desenvolvedor);
            _usuarios.push_back(usuario);
        }
        arquivo.close();
    } else {
        std::cerr << " Erro ao abrir o arquivo de Usuários." << std::endl;
    }
}

void Usuarios::salvarUsuarios() const {
    std::ofstream arquivo(_arquivo_usuarios);

    if (arquivo.is_open()) {
        for (const auto& usuario : _usuarios) {
            arquivo << usuario.usuario_id() << ' ' << usuario.usuario_login() << ' ' << usuario.email() <<' '<< usuario.nome()<<' '<< usuario.idade() <<' '<< usuario.desenvolvedor() <<'\n';
        }
        arquivo.close();
    } else {
        std::cerr << "Erro ao salvar o arquivo de usuários." << std::endl;
    }
}

}