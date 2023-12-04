#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "service/transacao.hpp"
#include "service/jogo.hpp"

#include "model/usuario.hpp"

namespace tpapp::repository {

class Transacoes {
public:
    Transacoes(const std::string& nome_arquivo);

    void adicionar_transacao(const service::Transacao& transacao);
    void carregar_transacoes();
    void salvar_transacoes();
    void comprar(const service::Jogo& jogo, const model::Usuario& usuario);
    void exibir_transacoes();
    std::string obter_data();
private:
    std::string _arquivo_transacoes;
    std::vector<service::Transacao> _transacoes;
};
}