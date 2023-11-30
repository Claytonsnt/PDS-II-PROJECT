#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "service/transacao.hpp"

namespace tpapp::repository {

class Transacoes {
public:
    Transacoes(const std::string& nome_arquivo);

    void adicionar_transacao(const service::Transacao& transacao);
    void carregar_transacoes();
    void salvar_transacoes();
    void comprar(unsigned saldo_carteira, unsigned valor);
    
private:
    std::string _arquivo_transacoes;
    std::vector<service::Transacao> _transacoes;
};
}