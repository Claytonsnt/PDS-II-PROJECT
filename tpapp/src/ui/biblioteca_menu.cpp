#include "ui/biblioteca_menu.hpp"
#include "service/jogo.hpp"
#include "model/usuario.hpp"

#include <iostream>
#include <string>
#include <fstream>

namespace tpapp::ui {
Biblioteca::Biblioteca(model::Usuario const &usuario) : _usuario(usuario) {
    _title = "Biblioteca";
    _options.push_back("1 - Visualizar Jogos");
    _options.push_back("2 - Pesquisar Jogo");
    _options.push_back("3 - Adicionar Jogo aos Favoritos");
    _options.push_back("4 - Visualizar Favoritos");
}

    Menu *Biblioteca::next(unsigned option) {
        while(option != 0){
            switch(option) {
            case 1: {
                std::string nome_arquivo = "BIBLIOTECA - " + _usuario.usuario_login();
                Biblioteca carregar_jogos_arquivo(std::string nome_arquivo);
                std::cout << "Jogos na biblioteca: " << std::endl;
                for(const service::Jogo& jogo : _jogos) {
                std::cout << jogo.nome() << std::endl;
                }
                break;
                }

            case 2: {
                std::string nome_jogo;
                std::cout << "> Digite o nome do jogo: ";
                std::cin >> nome_jogo;
                for(service::Jogo& jogo : _jogos) {
                    if(jogo.nome() == nome_jogo) {
                        std::cout << "> " << nome_jogo << " - Está na sua biblioteca." << std::endl;
                        break;
                    }
                    else{
                        std::cout << ">" << nome_jogo << "- NÃO está na sua biblioteca." << std::endl;
                    }
                }
                break;
                }
            case 3: {
                std::cout << "Jogos na biblioteca: " << std::endl;
                for(const service::Jogo& jogo : _jogos) {
                std::cout <<"ID: " <<jogo.jogo_id() << " - " << jogo.nome() << std::endl;
                }
                int id;
                std::cout << "> Digite o do jogo que deseja adicionar a biblioteca" << std::endl;
                std:: cin >> id; 
                for(const service::Jogo& jogo : _jogos) {
                    if (jogo.jogo_id() == id) {
                        _favoritos.push_back(jogo);
                    } else {
                        std::cout << "O ID digitado é inválido." << std::endl;
                    }
                }
                break;
            }

            case 4: {
                std::cout << "Jogos Favoritos: " << std::endl;
                for(const service::Jogo& jogo : _favoritos) {
                std::cout << jogo.nome() << std::endl;
                }
                break;
                }
            }
        }
    return nullptr;
    }

    void Biblioteca::salvar_jogos_arquivo(const std::string& nome_arquivo) const {
        std::ofstream arquivo(nome_arquivo);

        if (arquivo.is_open()) {
            for (const auto& jogo : _jogos) {
                arquivo << jogo.jogo_id() << ',' << jogo.nome() << '\n';
            }
            arquivo.close();
            std::cout << "> Dados dos jogos salvos em " << nome_arquivo << std::endl;
        } else {
            std::cerr << "> Erro ao abrir o arquivo " << nome_arquivo << std::endl;
        }
    }

    void Biblioteca::carregar_jogos_arquivo(const std::string& nome_arquivo) {
        std::ifstream arquivo(nome_arquivo);

        if (arquivo.is_open()) {
            _jogos.clear();

            int id;
            std::string nome;

            while (arquivo >> id >> std::ws && std::getline(arquivo, nome)) {
                _jogos.emplace_back(id, nome);
            }

            arquivo.close();
            std::cout << "> Dados dos jogos carregados de " << nome_arquivo << std::endl;
        } else {
            std:: cerr << "> ERRO para carregar os jogos de " << nome_arquivo << std::endl;
        }
    }
}

