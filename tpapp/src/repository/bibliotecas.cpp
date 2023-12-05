#include "repository/bibliotecas.hpp"
#include "repository/jogos.hpp"

#include "service/jogo.hpp"

#include <fstream>
#include <iostream>

namespace tpapp::repository {
    Bibliotecas::Bibliotecas(const std::string& nome_arquivo): _arquivo_biblioteca(nome_arquivo) {
        carregar_biblioteca();
    }

    bool Bibliotecas::adicionar_jogo(const service::Jogo& jogo) {
        for (const auto& item:_biblioteca) {
            if(jogo.nome() == item.nome()){
                std::cout << ">Esse jogo já está na sua biblioteca." << std::endl;
                return false;
            }
        }
        _biblioteca.push_back(jogo);
        salvar_biblioteca();
        return true;
    }

    std::vector<service::Jogo> Bibliotecas::enviar_biblioteca() {
    return _biblioteca;
    }
    
    void Bibliotecas::carregar_biblioteca() {
        std::ifstream arquivo(_arquivo_biblioteca, std::ios::in);

    if (arquivo.is_open()) {
        std::string nome, desenvolvedora, genero, data_lancamento;
        double valor;
        int jogo_id;
        while (arquivo >> jogo_id >> nome >> desenvolvedora >> genero >> data_lancamento >> valor) {
            service::Jogo jogo(jogo_id, nome, desenvolvedora, genero, valor, data_lancamento);
            _biblioteca.push_back(jogo);
        }
    } else {
        return;
    }
    return;
    }

    void Bibliotecas::salvar_biblioteca() const {
    std::ofstream arquivo(_arquivo_biblioteca);

    if (arquivo.is_open()) {
        for (const auto& jogo : _biblioteca) {
            arquivo << jogo.jogo_id() << " " << jogo.nome() << " " << jogo.desenvolvedora() << " " << jogo.genero() << " " << jogo.valor() << " " << jogo.data_lancamento() << std::endl;
        }
        arquivo.close();
    } else {
        std::cerr << "Erro ao salvar o arquivo de Biblioteca." << std::endl;
    }
    return;
}
}