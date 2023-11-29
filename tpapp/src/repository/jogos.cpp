#include "repository/jogos.hpp"
#include "service/jogo.hpp"

#include <fstream>

namespace tpapp::repository {

Jogos::Jogos(const std::string& nome_arquivo): _arquivo_jogos(nome_arquivo) {
    carregar_jogos();
}

void Jogos::adicionar_jogo(const service::Jogo& jogo) {
    _jogos.push_back(jogo);
    salvar_jogos();
}

service::Jogo Jogos::obter_jogo(const service::Jogo& jogo_procurado) const {
    for (const auto& jogo : _jogos) {
        if (jogo.jogo_id() == jogo_procurado.jogo_id()) {
            return jogo;
        }
    }
}

void Jogos::carregar_jogos() {
    std::ifstream arquivo(_arquivo_jogos, std::ios::in);

    if (arquivo.is_open()) {
        std::string nome, desenvolvedora, genero, data_lancamento;
        double valor;
        int jogo_id;
        while (arquivo >> jogo_id >> nome >> desenvolvedora >> genero >> data_lancamento >> valor) {
            service::Jogo jogo(jogo_id, nome, desenvolvedora, genero, data_lancamento, valor);
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