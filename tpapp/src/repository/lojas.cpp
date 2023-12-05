#include "repository/jogos.hpp"
#include "repository/lojas.hpp"

#include "service/jogo.hpp"

#include <fstream>
#include <iostream>

namespace tpapp::repository {
    Lojas::Lojas(const std::string& nome_arquivo): _arquivo_lojas(nome_arquivo) {
        carregar_lista_desejos();
    }

    bool Lojas::adicionar_jogo(const service::Jogo& jogo) {
        for (const auto& item:_lista_desejos) {
            if(jogo.nome() == item.nome()){
                std::cout << ">Esse jogo já está na sua lista de desejos." << std::endl;
                return false;
            }
        }
        _lista_desejos.push_back(jogo);
        salvar_lista_desejos();
        return true;
    }

    std::vector<service::Jogo> Lojas::enviar_lista_desejos() {
    return _lista_desejos;
    }

    void Lojas::carregar_lista_desejos() {
        std::ifstream arquivo(_arquivo_lojas, std::ios::in);

    if (arquivo.is_open()) {
        std::string nome, desenvolvedora, genero, data_lancamento;
        double valor;
        int jogo_id;
        while (arquivo >> jogo_id >> nome >> desenvolvedora >> genero >> data_lancamento >> valor) {
            service::Jogo jogo(jogo_id, nome, desenvolvedora, genero, valor, data_lancamento);
            _lista_desejos.push_back(jogo);
        }
    } else {
        std::cerr << "Erro ao abrir o arquivo lista de desejos." << std::endl;
    }
    return;
    }

    void Lojas::salvar_lista_desejos() const {
    std::ofstream arquivo(_arquivo_lojas);

    if (arquivo.is_open()) {
        for (const auto& jogo : _lista_desejos) {
            arquivo << jogo.jogo_id() << " " << jogo.nome() << " " << jogo.desenvolvedora() << " " << jogo.genero() << " " << jogo.valor() << " " << jogo.data_lancamento() << std::endl;
        }
        arquivo.close();
    } else {
        std::cerr << "Erro ao salvar o arquivo lista de desejos." << std::endl;
    }
    return;
}
}
