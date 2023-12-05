#include "repository/jogos.hpp"

#include "service/jogo.hpp"

#include <algorithm>
#include <fstream>
#include <iostream>

namespace tpapp::repository {

Jogos::Jogos(const std::string& nome_arquivo): _arquivo_jogos(nome_arquivo) {
    carregar_jogos();
}

void Jogos::adicionar_jogo(const service::Jogo& jogo) {
    _jogos.push_back(jogo);
    salvar_jogos();
}

void Jogos::remover_jogo(int jogo_id) {
    auto it = std::find_if(_jogos.begin(), _jogos.end(), [jogo_id] (const service::Jogo& jogo) {
        return jogo.jogo_id() == jogo_id;
    });
    if (it != _jogos.end()) {
        _jogos.erase(it);
        salvar_jogos();
        std::cout << "Jogo removido." << std::endl;
    } else {
        std::cout << "ID do jogo não encontrado." << std::endl;
    }
}

service::Jogo Jogos::obter_jogo(const service::Jogo& jogo_procurado) const {
    for (const auto& jogo : _jogos) {
        if (jogo.jogo_id() == jogo_procurado.jogo_id()) {
            return jogo;
        }else {
            std::cout << "O jogo não foi encontrado. " << std::endl;
        }
    };
}

void Jogos::exibir_jogos() {
    std::cout << "====================================" << std::endl;
    for (const auto& jogo : _jogos) {
        std::cout << "[" << jogo.jogo_id() << "] " << "- " << jogo.nome()  << " || " << jogo.valor() << " || " << std::endl;
        };
    std::cout << "====================================" << std::endl;
    }

void Jogos::atualizar_jogo(int jogo_id, const service::Jogo& novo_jogo) {
    auto it = std::find_if(_jogos.begin(), _jogos.end(), [jogo_id] (const service::Jogo& jogo) {
        return jogo.jogo_id() == jogo_id;
    });

    if(it != _jogos.end()) {
        *it = novo_jogo;
        std::cout << "Informações do jogo atualizadas." <<std::endl;
    } else {
        std::cout << "ID do jogo não encontrado." << std::endl;
    }
}

int Jogos::qnt_jogos() {
    int count = 0;
    for(const service::Jogo& jogo : _jogos) {
        count++;
    }
    return count;
}
std::vector<service::Jogo> Jogos::enviar_jogos() {
    return _jogos;
}

void Jogos::carregar_jogos() {
    std::ifstream arquivo(_arquivo_jogos, std::ios::in);

    if (arquivo.is_open()) {
        std::string nome, desenvolvedora, genero, data_lancamento;
        double valor;
        int jogo_id;
        while (arquivo >> jogo_id >> nome >> desenvolvedora >> genero >> valor >> data_lancamento) {
            service::Jogo jogo(jogo_id, nome, desenvolvedora, genero, valor, data_lancamento);
            _jogos.push_back(jogo);
        }
    } else {
        std::cerr << "Erro ao abrir o arquivo de jogos." << std::endl;
    }
    return;
}

void Jogos::salvar_jogos() const {
    std::ofstream arquivo(_arquivo_jogos);

    if (arquivo.is_open()) {
        for (const auto& jogo : _jogos) {
            arquivo << jogo.jogo_id() << " " << jogo.nome() << " " << jogo.desenvolvedora() << " " << jogo.genero() << " " << jogo.valor() << " " << jogo.data_lancamento() << std::endl;
        }
        arquivo.close();
    } else {
        std::cerr << "Erro ao salvar o arquivo de jogos." << std::endl;
    }
    return;
}
}