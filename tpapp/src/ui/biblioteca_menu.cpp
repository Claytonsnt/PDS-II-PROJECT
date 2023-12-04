#include "ui/biblioteca_menu.hpp"
#include "ui/dev_menu.hpp"
#include "ui/loja.hpp"

#include "service/jogo.hpp"

#include "model/usuario.hpp"
#include "model/desenvolvedor.hpp"

#include "repository/usuarios.hpp"
#include "repository/desenvolvedores.hpp"

#include <iostream>
#include <string>
#include <fstream>

namespace tpapp::ui {
Biblioteca::Biblioteca(model::Usuario const &usuario) : _usuario(usuario) {
    salvar_usuario_conectado(_usuario);
    _title = "Biblioteca";
    _options.push_back("1 - Visualizar Jogos");
    _options.push_back("2 - Pesquisar Jogo");
    _options.push_back("3 - Adicionar Jogo aos Favoritos");
    _options.push_back("4 - Visualizar Favoritos");
    _options.push_back("5 - [Loja]");
    if(_usuario.desenvolvedor()){
        _options.push_back("6 - [Menu de Desenvolvedor]");
    }
}

    void Biblioteca::salvar_usuario_conectado(const model::Usuario &usuario) const {
        std::string nome_arquivo = "usuario_conectado";
        std::ofstream arquivo(nome_arquivo);
        arquivo.clear();

        if (arquivo.is_open()) {
            arquivo << usuario.usuario_id() << ' ' << usuario.usuario_login() << ' ' << usuario.email() <<' '<< usuario.nome()<<' '<< usuario.idade() <<' '<< usuario.desenvolvedor() <<'\n';
            arquivo.close();
        } else {
            std::cerr << "> Erro ao salvar usuário conectado " << nome_arquivo << std::endl;
        }
    }

    model::Usuario Biblioteca::carregar_usuario_conectado() {
        std::string nome_arquivo = "usuario_conectado";
        std::ifstream arquivo(nome_arquivo, std::ios::in);

    if(arquivo.is_open()) {
        int usuario_id;
        unsigned idade;
        bool desenvolvedor;
        std::string usuario_login, email, nome, sobrenome;
        
        arquivo >> usuario_id >> usuario_login >> email >> nome >> sobrenome >> idade >> desenvolvedor;
        model::InfoPessoal info;
        info.primeiro_nome = nome;
        info.sobrenome = sobrenome;
        info.idade = idade;

        model::Usuario usuario_conectado(usuario_id, usuario_login, email, info, desenvolvedor);
        arquivo.close();
        return usuario_conectado;
    } else {
        std::cerr << " ERRO ao abrir o arquivo de Usuários." << std::endl;
    }
    }

    Menu *Biblioteca::next(unsigned option) {
        model::Usuario usuario_conect = carregar_usuario_conectado();
        switch(option) {
            case 1: {
                std::string nome_arquivo = "BIBLIOTECA - " + _usuario.usuario_login();
                Biblioteca carregar_jogos_arquivo(std::string nome_arquivo);
                std::cout << "Jogos na biblioteca: " << std::endl;
                for(const service::Jogo& jogo : _jogos) {
                std::cout << jogo.nome() << std::endl;
                }
                return new Biblioteca(usuario_conect);
                }

            case 2: {
                std::string nome_jogo;
                std::cout << "> Digite o nome do jogo: " << std::endl;
                std::cin >> nome_jogo;
                if(_jogos.empty()) {
                    std::cout << "Sua biblioteca está vazia." << std::endl;
                    return new Biblioteca(usuario_conect);
                }else {
                for(service::Jogo& jogo : _jogos) {
                    if(jogo.nome() == nome_jogo) {
                        std::cout << "> " << nome_jogo << " - Está na sua biblioteca." << std::endl;
                        return new Biblioteca(usuario_conect);
                    }
                    else{
                        std::cout << ">" << nome_jogo << "- NÃO está na sua biblioteca." << std::endl;
                        return new Biblioteca(usuario_conect);
                    }
                }
                }
                }
            case 3: {
                std::cout << "Jogos na biblioteca: " << std::endl;
                if(_jogos.empty()){
                    std::cout << "Sua biblioteca está vazia." << std::endl;
                    return new Biblioteca(usuario_conect);
                }else {
                for(const service::Jogo& jogo : _jogos) {
                std::cout <<"ID: " <<jogo.jogo_id() << " - " << jogo.nome() << std::endl;
                }
                int id;
                std::cout << "> Digite o do jogo que deseja adicionar aos Favoritos" << std::endl;
                std:: cin >> id; 
                for(const service::Jogo& jogo : _jogos) {
                    if (jogo.jogo_id() == id) {
                        _favoritos.push_back(jogo);
                        std::cout << "O jogo " << jogo.nome() << " foi adicionado aos favoritos." << std::endl;
                        return new Biblioteca(usuario_conect);
                    } else {
                        std::cout << "O ID digitado é inválido." << std::endl;
                        break;
                    }
                }
                }
                return new Biblioteca(usuario_conect);
            }

            case 4: {
                std::cout << "Jogos Favoritos: " << std::endl;
                if(_favoritos.empty()) {
                    std::cout << "> Você ainda não possui nenhum jogo favorito." << std::endl;
                    return new Biblioteca(usuario_conect);
                } else {
                    for(const service::Jogo& jogo : _favoritos) {
                        std::cout << jogo.nome() << std::endl;
                        return new Biblioteca(usuario_conect);
                    }
                }
                }
                

            case 5: {
                //repository::Usuarios repositorio_usuarios("repositorio_usuarios");
                //model::Usuario usuario = repositorio_usuarios.obterUsuario(usuario_conect.email());
                model::Usuario usuario_conect = carregar_usuario_conectado();
                return new Loja(usuario_conect);
            }

            case 6: {
                repository::Desenvolvedores repositorio_devs("repositorio_desenvolvedores");
                model::Desenvolvedor dev = repositorio_devs.obter_desenvolvedor(usuario_conect.email());
                return new DevMenu(dev);
            }
        }
    return nullptr;
    }

    void Biblioteca::salvar_jogos_arquivo(const std::string& nome_arquivo) const {
        std::ofstream arquivo(nome_arquivo);

        if (arquivo.is_open()) {
            for (const auto& jogo : _jogos) {
                arquivo << jogo.jogo_id() << ',' << jogo.nome() << ',' << jogo.desenvolvedora() << ',' << jogo.genero() << ',' << jogo.valor() << ',' << jogo.data_lancamento() << '\n';
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

            int jogo_id;
            std::string nome, desenvolvedora_id, genero, data_lancamento;
            double valor;

            while (arquivo >> jogo_id >> nome >> desenvolvedora_id >> genero >> valor >> data_lancamento ) {
                service::Jogo jogo(jogo_id, nome, desenvolvedora_id, genero, valor, data_lancamento);
                _jogos.push_back(jogo);
            }
            arquivo.close();
            std::cout << "> Dados dos jogos carregados de " << nome_arquivo << std::endl;
        } else {
            std:: cerr << "> ERRO para carregar os jogos de " << nome_arquivo << std::endl;
        }
    }
}

