#include "repository/desenvolvedores.hpp"
#include "model/desenvolvedor.hpp"

#include <fstream>

namespace tpapp::repository {
Desenvolvedores::Desenvolvedores(const std::string& nome_arquivo): _arquivo_desenvolvedores(nome_arquivo) {
    carregarDesenvolvedores();
} 

model::Desenvolvedor Desenvolvedores::obterDesenvolvedor(const std::string& email) const {
    for (const auto& desenvolvedor : _desenvolvedores) {
        if (desenvolvedor.email() == email){
            return desenvolvedor;
        }
    }
    throw std::runtime_error("Usuário não encontrado.");
}

void Desenvolvedores::adicionarDesenvolvedor(const model::Desenvolvedor& desenvolvedor) {
    _desenvolvedores.push_back(desenvolvedor);
    salvarDesenvolvedores();
}

void Desenvolvedores::salvarDesenvolvedores() const {
    std::ofstream arquivo(_arquivo_desenvolvedores);

    if (arquivo.is_open()) {
        for (const auto& dev : _desenvolvedores) {
            arquivo << dev.usuario_id() << ' ' << dev.usuario_login() <<' '<< dev.desenvolvedora_id() <<' '<< dev.email() <<' '<< dev.nome()<<' '<< dev.idade() <<' '<< true <<'\n';
        }
        arquivo.close();
    } else {
        std::cerr << "Erro ao salvar o arquivo de desenvolvedores." << std::endl;
    }
}

void Desenvolvedores::carregarDesenvolvedores() {
    std::ifstream arquivo(_arquivo_desenvolvedores, std::ios::in);

    if(arquivo.is_open()) {
        std::string usuario_login, email, nome, sobrenome;
        int usuario_id;
        unsigned idade, desenvolvedora_id;

        while(arquivo >> usuario_id >> usuario_login >> desenvolvedora_id >> email >> nome >> sobrenome >> idade) {
            model::InfoPessoal info;
            info.primeiro_nome = nome;
            info.sobrenome = sobrenome;
            info.idade = idade;

            model::Desenvolvedor dev(usuario_id, usuario_login, desenvolvedora_id, email, info);
            _desenvolvedores.push_back(dev);
        }
        arquivo.close();
    } else {
        std::cerr << " ERRO ao abrir o arquivo de Usuários." << std::endl;
    }
}
}
