#include "repository/bibliotecas.hpp"
#include "repository/transacoes.hpp"
#include "repository/jogos.hpp"

#include "service/transacao.hpp"
#include "service/carteira.hpp"
#include "service/jogo.hpp"

#include "model/usuario.hpp"

#include "ui/loja.hpp"
#include "ui/biblioteca_menu.hpp"
#include "ui/menu.hpp"

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
    salvar_transacoes();
    return;
}

void Transacoes::comprar(const service::Jogo& jogo, const model::Usuario& usuario) {
    std::cout << ">Como deseja realizar sua compra?\n [1] SALDO DA CARTEIRA \n" << "**NO MOMENTO SO ESTAMOS ACEITANDO COMPRAS PELO SALDO DA CARTEIRA**" <<std::endl;
    int opcao;
    std::cin >> opcao;
    if(opcao == 1) { 
        if (usuario.saldo() < jogo.valor()) {
            std::cout << "> Seu saldo é insufuciente para realizar a compra." << std::endl;
            return;
        } else {
            std::string nome_arquivo = "Biblioteca - " + usuario.usuario_login();
            repository::Bibliotecas repositorio(nome_arquivo);
            repositorio.adicionar_jogo(jogo);
            service::Transacao transacao("compra", jogo.valor(), "carteira", jogo.data_lancamento()); //implementar data na transacao
            Transacoes::adicionar_transacao(transacao);
            std::cout << "> Seu jogo já está disponível na sua biblioteca." << std::endl;
            return;
        }
    } else {
        std::cout << ">Voltando a loja..." << std::endl;
        return;
    }
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