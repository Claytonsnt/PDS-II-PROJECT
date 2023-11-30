#include "repository/desenvolvedores.hpp"
#include "model/desenvolvedor.hpp"

#include <fstream>
#include <iostream>
#include <algorithm>

namespace tpapp::repository {
Desenvolvedores::Desenvolvedores(const std::string& nome_arquivo): _arquivo_desenvolvedores(nome_arquivo) {
    carregar_desenvolvedores();
} 

model::Desenvolvedor Desenvolvedores::obter_desenvolvedor(const std::string& email) const {
    for (const auto& desenvolvedor : _desenvolvedores) {
        if (desenvolvedor.email() == email){
            return desenvolvedor;
        }
    }
    throw std::runtime_error("Usuário não encontrado.");
}

void Desenvolvedores::adicionar_desenvolvedor(const model::Desenvolvedor& desenvolvedor) {
    _desenvolvedores.push_back(desenvolvedor);
    salvar_desenvolvedores();
}

void Desenvolvedores::alterar_desenvolvedor(const model::Desenvolvedor& novo_dev) {
    std::string email = novo_dev.email();
    auto it = std::find_if(_desenvolvedores.begin(), _desenvolvedores.end(), [email] (const model::Desenvolvedor& dev) {
        return dev.email() == email;
    });
    if (it != _desenvolvedores.end()) {
        _desenvolvedores.erase(it);
        _desenvolvedores.push_back(novo_dev);
        std::cout << "Desenvolvedor atualizado." << std::endl;
    } else {
        std::cout << "Não foi possível atualizar o desenvolvedor." << std::endl;
    }
}

void Desenvolvedores::salvar_desenvolvedores() const {
    std::ofstream arquivo(_arquivo_desenvolvedores);

    if (arquivo.is_open()) {
        for (const auto& dev : _desenvolvedores) {
            arquivo << dev.usuario_id() << ' ' << dev.usuario_login() <<' '<< dev.desenvolvedora_id() <<' '<< dev.email() <<' '<< dev.nome()<<' '<< dev.idade() <<' '<< true << ' ' << dev.saldo() <<'\n';
        }
        arquivo.close();
    } else {
        std::cerr << "Erro ao salvar o arquivo de desenvolvedores." << std::endl;
    }
}

void Desenvolvedores::carregar_desenvolvedores() {
    std::ifstream arquivo(_arquivo_desenvolvedores, std::ios::in);

    if(arquivo.is_open()) {
        std::string usuario_login, email, nome, sobrenome;
        int usuario_id;
        unsigned idade, desenvolvedora_id, saldo;

        while(arquivo >> usuario_id >> usuario_login >> desenvolvedora_id >> email >> nome >> sobrenome >> idade >> saldo) {
            model::InfoPessoal info;
            info.primeiro_nome = nome;
            info.sobrenome = sobrenome;
            info.idade = idade;

            model::Desenvolvedor dev(usuario_id, usuario_login, desenvolvedora_id, email, info, saldo);
            _desenvolvedores.push_back(dev);
        }
        arquivo.close();
    } else {
        std::cerr << " ERRO ao abrir o arquivo de Usuários." << std::endl;
    }
}
}
