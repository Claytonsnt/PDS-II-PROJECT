#include "repository/usuarios.hpp"
#include "model/usuario.hpp"

#include <fstream>

namespace tpapp::repository {

Usuarios::Usuarios(const std::string& nome_arquivo): _arquivo_usuarios(nome_arquivo) {
    carregar_usuarios();
} 

bool Usuarios::verificar_usuario_email(const std::string& email) const {
    for (const auto& usuario : _usuarios) {
        if (usuario.email() == email) {
            return true;
        }
    }
    return false;
}

model::Usuario Usuarios::obter_usuario(const std::string& email) const {
    for (const auto& usuario : _usuarios) {
        if (usuario.email() == email){
            return usuario;
        }
    }
    throw std::runtime_error("Usuário não encontrado.");
}

void Usuarios::adicionar_usuario(const model::Usuario& usuario) {
    _usuarios.push_back(usuario);
    salvar_usuarios();
    return;
}

int Usuarios::qnt_usuarios() {
    int count = 0;
    for(const model::Usuario& usuario : _usuarios) {
        count++;
    }
    return count;
}

void Usuarios::carregar_usuarios() {
    std::ifstream arquivo(_arquivo_usuarios, std::ios::in);

    if(arquivo.is_open()) {
        int usuario_id;
        unsigned idade, saldo;
        bool desenvolvedor;
        std::string usuario_login, email, nome, sobrenome;
        
        while(arquivo >> usuario_id >> usuario_login >> email >> nome >> sobrenome >> idade >> desenvolvedor >> saldo) {
            model::InfoPessoal info;
            info.primeiro_nome = nome;
            info.sobrenome = sobrenome;
            info.idade = idade;

            model::Usuario usuario(usuario_id, usuario_login, email, info, desenvolvedor, saldo);
            _usuarios.push_back(usuario);
        }
        arquivo.close();
    } else {
        std::cerr << "Erro ao abrir o arquivo de usuários." << std::endl;
    }
}

void Usuarios::salvar_usuarios() const {
    std::ofstream arquivo(_arquivo_usuarios);

    if (arquivo.is_open()) {
        for (const auto& usuario : _usuarios) {
            arquivo << usuario.usuario_id() << ' ' << usuario.usuario_login() << ' ' << usuario.email() <<' '<< usuario.nome()<<' '<< usuario.idade() <<' '<< usuario.desenvolvedor() << ' ' << usuario.saldo() <<'\n';
        }
        arquivo.close();
    } else {
        std::cerr << "Erro ao salvar o arquivo de usuários." << std::endl;
    }
}

}