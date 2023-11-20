#include "ui/biblioteca_menu.hpp"

#include "model/usuario.hpp"

#include <iostream>
#include <string>

namespace tpapp::ui {
Biblioteca::Biblioteca(model::Usuario const &usuario) : _usuario(usuario) {
    _title = "Biblioteca";
    _options.push_back("1 - Visualizar Jogos");
    _options.push_back("2 - Pesquisar Jogo");
    _options.push_back("3 - Adicionar Jogo aos Favoritos");
}

    Menu *Biblioteca::next(unsigned option) {
        switch(option) {
        case 1: {
            std::cout << "Jogos na biblioteca: " << std::endl;
            for(const service::Jogo& jogo : _jogos) {
               std::cout << jogo.nome() << std::endl;
            }
            return;
            }

        case 2: {
            std::string nome_jogo;
            std::cout << "> Digite o nome do jogo: ";
            std::cin >> nome_jogo;
            for(service::Jogo& jogo : _jogos) {
                if(jogo.nome() == nome_jogo) {
                    std::cout << "> " << nome_jogo << " - Está na sua biblioteca." << std::endl;
                    return;
                }
                else{
                    std::cout << ">" << nome_jogo << "- NÃO está na sua biblioteca." << std::endl;
                }
            }
            }
        case 3: {

        }
        }
    return nullptr;
    }
}

