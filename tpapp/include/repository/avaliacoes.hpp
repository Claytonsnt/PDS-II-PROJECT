#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "model/usuario.hpp"
#include "service/avaliacao.hpp"
#include "service/jogo.hpp"

namespace tpapp::repository {

class Avaliacoes {
public:
    Avaliacoes(const std::string& nome_arquivo);

    void adicionar_avaliacao(const service::Avaliacao& avaliacao);
    service::Avaliacao obter_avaliacao(const service::Jogo& jogo, const model::Usuario& usuario) const;
    std::vector<service::Avaliacao> obter_avaliacoes(const service::Jogo& jogo) const;
    void remover_avaliacao(int usuario_id, int jogo_id);
    void salvar_avaliacao() const;

private:
    std::string _arquivo_avaliacoes;
    std::vector<service::Avaliacao> _avaliacoes;
};
}
