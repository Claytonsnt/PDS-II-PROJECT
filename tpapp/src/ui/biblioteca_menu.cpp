#include "ui/biblioteca_menu.hpp"

#include "model/usuario.hpp"

#include <iostream>
#include <string>

namespace tpapp::ui {
Biblioteca::Biblioteca(model::Usuario const &usuario) : _usuario(usuario) {
    _title = 'BIBLIOTECA';
    _options.push_back("1 - Visualizar Jogos");
    _options.push_back("2 - Pesquisar Jogo");
    _options.push_back("3 - Adicionar Jogo aos Favoritos");

    Menu *Biblioteca::next(unsigned option) {
        switch(option) {
        case 1: {
            std::cout << "Jogos na biblioteca: " << std::endl;
            for(const Jogo& jogo : jogos) {
                std::cout << jogo.nome() << std::endl;
            }
        }
        case 2: {
            std::cout << "> Digite o nome do jogo: ";
            std::cin >> nomeJogo;
            for(Jogo& jogo : jogos) {
                if(jogo.nome() == nomeJogo) {
                    std::cout << "> " << nomeJogo << " - Está na sua biblioteca.";
                }
            }
        }
        }
    }
}
}