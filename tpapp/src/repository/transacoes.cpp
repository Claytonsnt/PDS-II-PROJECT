#include "repository/bibliotecas.hpp"
#include "repository/transacoes.hpp"
#include "repository/jogos.hpp"

#include "service/transacao.hpp"
#include "service/carteira.hpp"
#include "service/jogo.hpp"

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

namespace tpapp::repository {

Transacoes::Transacoes(const std::string& nome_arquivo): _arquivo_transacoes(nome_arquivo) {
    carregar_transacoes();
}

void Transacoes::adicionar_transacao(const service::Transacao& transacao) {
    _transacoes.push_back(transacao);
    return;
}

void Transacoes::comprar(unsigned saldo_carteira, unsigned valor) {
    
}

void Transacoes::carregar_transacoes() {
    std::ifstream arquivo(_arquivo_transacoes, std::ios::in);

    if (arquivo.is_open()) {
        std::string tipo, data, forma_pagamento;
        double valor;
        while (arquivo >> tipo >> valor >> forma_pagamento >> data) {
            service::Transacao transacao(tipo, valor, forma_pagamento, data);
            _transacoes.push_back(transacao);
        }
    } else {
        std::cerr << "Erro ao abrir o arquivo de transacoes." << std::endl;
    }
    return;
}

void Transacoes::salvar_transacoes() {
    std::ofstream arquivo(_arquivo_transacoes);

    if (arquivo.is_open()) {
        for (const auto& transacao : _transacoes) {
            arquivo << transacao.tipo() << " " << transacao.valor() << " " << transacao.forma_pagamento() << " " << transacao.data() << std::endl;
        }
        arquivo.close();
    } else {
        std::cerr << "Erro ao salvar o arquivo de transacoes." << std::endl;
    }
    return;
}
}