#include "ui/avaliacao_menu.hpp"
#include "model/usuario.hpp"
#include "service/jogo.hpp"
#include "service/avaliacao.hpp"
#include "repository/avaliacoes.hpp"

#include <iostream>
#include <string>
#include <fstream>

namespace tpapp::ui {
AvaliacaoMenu::AvaliacaoMenu(model::Usuario const &usuario, service::Jogo const &jogo) : _usuario(usuario), _jogo(jogo) {
    _title = "Menu de Autenticação";
    _options.push_back("1 - Avaliar jogo");
    _options.push_back("2 - Ver avaliacoes");
    _options.push_back("3 - ");
}

Menu *AvaliacaoMenu::next(unsigned option) {};

void salvar_usuario_conectado(const model::Usuario& usuario) {
    std::string nome_arquivo = "usuario_conectado";
    std::ofstream arquivo(nome_arquivo);
    arquivo.clear();

    if (arquivo.is_open()) {
        arquivo << usuario.usuario_id() << ' ' << usuario.usuario_login() << ' ' << usuario.email() <<' '<< usuario.nome()<<' '<< usuario.idade() <<' '<< usuario.desenvolvedor() <<'\n';
        arquivo.close();
    } else {
        std::cerr << "> Erro ao salvar usuário conectado. " << nome_arquivo << std::endl;
    }
}

void salvar_jogo(const service::Jogo& jogo) {
    std::string nome_arquivo = "jogo_atual";
    std::ofstream arquivo(nome_arquivo);
    arquivo.clear();

    if (arquivo.is_open()) {
        arquivo << jogo.jogo_id() << ' ' << jogo.nome() << ' ' << jogo.desenvolvedora() <<' '<< jogo.genero()<<' '<< jogo.valor() <<' '<< jogo.data_lancamento() <<'\n';
        arquivo.close();
    } else {
        std::cerr << "> Erro ao salvar o jogo. " << nome_arquivo << std::endl;
    }
}

double AvaliacaoMenu::nota_media(int const jogo_id) {

}
void AvaliacaoMenu::criar_avaliacao(model::Usuario const &usuario, service::Jogo const &jogo) {
    double nota;
    std::string comentario;
    while (nota < 0 || nota > 5) {
        std::cout << "De uma nota para o jogo (0 a 5):" << std::endl;
        std::cin >> nota;
    }
    std::cout << "Escreva uma avaliacao:" << std::endl;
    std::cin >> comentario;

    service::Avaliacao avaliacao(jogo.jogo_id(), usuario.usuario_id(), nota, comentario);
    repository::Avaliacoes 

}
void AvaliacaoMenu::curtir_avaliacao() {

}
void AvaliacaoMenu::comentar_avaliacao() {

}

}