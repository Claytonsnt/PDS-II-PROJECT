#include "model/usuario.hpp"

#include "repository/avaliacoes.hpp"

#include "service/avaliacao.hpp"

#include <algorithm>
#include <fstream>
#include <vector>

namespace tpapp::repository {
Avaliacoes::Avaliacoes(const std::string& nome_arquivo): _arquivo_avaliacoes(nome_arquivo) {
    carregar_avaliacoes();
}

void Avaliacoes::adicionar_avaliacao(const service::Avaliacao& avaliacao) {
    _avaliacoes.push_back(avaliacao);
    salvar_avaliacao();
}

service::Avaliacao Avaliacoes::obter_avaliacao(const service::Jogo& jogo, const model::Usuario& usuario) const {
    for (const auto& avaliacao : _avaliacoes) {
        if (avaliacao.jogo_id() == jogo.jogo_id() && avaliacao.usuario_id() == usuario.usuario_id()) {
            return avaliacao;
        }else {
            std::cout << "Esse jogo ainda nao foi avaliado por você." << std::endl;
        }
    }
}

std::vector<service::Avaliacao> Avaliacoes::obter_avaliacoes(const service::Jogo& jogo) const{
    std::vector<service::Avaliacao> avaliacoes_jogo;
    for (const auto& avaliacao : _avaliacoes) {
        if (avaliacao.jogo_id() == jogo.jogo_id()) {
            avaliacoes_jogo.push_back(avaliacao);
        }
    }
    return avaliacoes_jogo;
}

void Avaliacoes::remover_avaliacao(int jogo_id, int usuario_id) {
    _avaliacoes.erase(std::remove_if(_avaliacoes.begin(), _avaliacoes.end(), [usuario_id, jogo_id] (const service::Avaliacao& avaliacao) {
        return avaliacao.usuario_id() == usuario_id && avaliacao.jogo_id() == jogo_id;
    }), _avaliacoes.end());
}

void Avaliacoes::salvar_avaliacao() const {
    std::ofstream arquivo(_arquivo_avaliacoes);

    if (arquivo.is_open()) {
        for (const auto& avaliacao : _avaliacoes) {
            arquivo << avaliacao.jogo_id() << " " << avaliacao.usuario_id() << " " << avaliacao.nota() << " " << avaliacao.comentario() << std::endl;
        }
        arquivo.close();
    }   else {
        std::cerr << "Erro ao salvar o arquivo de avaliacoes." << std::endl;
    }
}

void Avaliacoes::carregar_avaliacoes() {
    std::ifstream arquivo(_arquivo_avaliacoes, std::ios::in);

    if (arquivo.is_open()) {
        std::string comentario;
        double nota;
        int jogo_id, usuario_id;
        while (arquivo >> jogo_id >> usuario_id >> nota >> comentario) {
            service::Avaliacao avaliacao(jogo_id, usuario_id, nota, comentario);
            _avaliacoes.push_back(avaliacao);
        }
    } else {
        return;
    }
    return;
}
}