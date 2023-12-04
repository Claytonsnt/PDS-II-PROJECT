#include "ui/avaliacao_menu.hpp"
#include "ui/biblioteca_menu.hpp"
#include "ui/loja.hpp"
#include "ui/dev_menu.hpp"

#include "model/usuario.hpp"

#include "service/jogo.hpp"
#include "service/avaliacao.hpp"

#include "repository/avaliacoes.hpp"
#include "repository/jogos.hpp"
#include "repository/desenvolvedores.hpp"

#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>

namespace tpapp::ui {
    AvaliacaoMenu::AvaliacaoMenu(model::Usuario const &usuario): _usuario(usuario) {
        salvar_usuario_conectado(_usuario);

    _title = "Menu de Autenticação";
    _options.push_back("1 - Avaliar jogo");
    _options.push_back("2 - Ver avaliacoes");
    _options.push_back("3 - [Biblioteca]");
    _options.push_back("4 - [Loja]");
    if(_usuario.desenvolvedor()){
        _options.push_back("5 - [Menu de Desenvolvedor]");
    }
    }

    Menu *AvaliacaoMenu::next(unsigned option) {
        model::Usuario usuario_conect = carregar_usuario_conectado();

        std::string nome_arquivo = "repositorio_jogos";
        repository::Jogos repositorio_jogos(nome_arquivo);
        std::vector<service::Jogo> _jogos = repositorio_jogos.enviar_jogos();

        std::string nome_arquivo_ava = "repositorio_avaliacoes";
        repository::Avaliacoes repositorio_ava(nome_arquivo_ava);

        switch(option) {
            case 1: {
                std::string pesquisa;
                std::cout << "> Insira o nome do jogo que será avaliado: " << std::endl;
                std::cin >> pesquisa;
                
                std::vector<service::Jogo> jogos_encontrados;
                for (const auto& jogo : _jogos) {
                    std::string nome_jogo_lower_case = jogo.nome();
                    std::transform(nome_jogo_lower_case.begin(), nome_jogo_lower_case.end(), nome_jogo_lower_case.begin(), ::tolower);
                    std::string pesquisa_lower_case = pesquisa;
                    std::transform(pesquisa_lower_case.begin(), pesquisa_lower_case.end(), pesquisa_lower_case.begin(), ::tolower);

                    if (nome_jogo_lower_case.find(pesquisa_lower_case) != std::string::npos) {
                        jogos_encontrados.push_back(jogo);
                    }
                }
                int count = 0;
                for(const auto& jogo_encontrado: jogos_encontrados) {
                    count++;
                }

                if (jogos_encontrados.empty()) {
                    std::cout << "Nenhum jogo encontrado com o termo '" << pesquisa << "'." << std::endl;
                    return new AvaliacaoMenu(usuario_conect);
                } else if (count == 1) {
                    for(const auto& jogo_encontrado: jogos_encontrados) {
                        std::cout << "[" << jogo_encontrado.nome() << "]  || " << jogo_encontrado.genero() << " || " << jogo_encontrado.valor() << " R$" << " || " << std::endl; 
                        unsigned opcao;
                        std::cout << "> Deseja adicionar uma avaliação a esse jogo? \n[0] SAIR \n[1] SIM \n[2] NÃO" << std::endl;
                        std::cin >> opcao;
                        if (opcao == 1) {
                            double nota;
                            std::string comentario;
                            while (nota < 0 || nota > 5) {
                                std::cout << "De uma nota para o jogo (0 a 5):" << std::endl;
                                std::cin >> nota;
                            }
                            std::cout << "Escreva uma avaliacao:" << std::endl;
                            std::cin >> comentario;

                            service::Avaliacao avaliacao(jogo_encontrado.jogo_id(), usuario_conect.usuario_id(), nota, comentario);
                            _avaliacoes.push_back(avaliacao);
                            repositorio_ava.adicionar_avaliacao(avaliacao);
                            std::cout << "A sua avaliação foi adicionada." << std::endl;

                            return new AvaliacaoMenu(usuario_conect);
                        } else {
                            return new AvaliacaoMenu(usuario_conect);
                        }
                    }
                } else {
                    std::cout << "Jogos encontrados com o termo '" << pesquisa << "':\n";
                    for (const auto& jogo_encontrado: jogos_encontrados) {
                        std::cout << "[" << jogo_encontrado.jogo_id() << "] " << "[" << jogo_encontrado.nome() << "]  || " << jogo_encontrado.genero() << " || " << jogo_encontrado.valor() << " R$" << " || " << std::endl;
                        unsigned opcao;
                        std::cout << "> Deseja adicionar um comentário a algum desses jogos? [1]SIM [2]NÃO: " << std::endl;
                        std::cin >> opcao;
                        if(opcao == 1) {
                            std::cout << "> Digite o ID do jogo desejado: " << std::endl;
                            int id;
                            std::cin >> id;
                            for (const auto& jogo_encontrado: jogos_encontrados) {
                                if(jogo_encontrado.jogo_id() == id) {
                                    double nota;
                                    std::string comentario;
                                    while (nota < 0 || nota > 5) {
                                        std::cout << "De uma nota para o jogo (0 a 5):" << std::endl;
                                        std::cin >> nota;
                                    }
                                    std::cout << "Escreva uma avaliacao:" << std::endl;
                                    std::cin >> comentario;

                                    service::Avaliacao avaliacao(jogo_encontrado.jogo_id(), usuario_conect.usuario_id(), nota, comentario);
                                    _avaliacoes.push_back(avaliacao);
                                    repositorio_ava.adicionar_avaliacao(avaliacao);
                                    std::cout << "A sua avaliação foi adicionada." << std::endl; 

                                    return new AvaliacaoMenu(usuario_conect);                                   
                                }
                            }
                        }
                    }
                }
            }
            case 2: {
                std::string pesquisa;
                std::cout << "> Insira o nome do jogo para ver as avaliações: " << std::endl;
                std::cin >> pesquisa;
                
                std::vector<service::Jogo> jogos_encontrados;
                for (const auto& jogo : _jogos) {
                    std::string nome_jogo_lower_case = jogo.nome();
                    std::transform(nome_jogo_lower_case.begin(), nome_jogo_lower_case.end(), nome_jogo_lower_case.begin(), ::tolower);
                    std::string pesquisa_lower_case = pesquisa;
                    std::transform(pesquisa_lower_case.begin(), pesquisa_lower_case.end(), pesquisa_lower_case.begin(), ::tolower);

                    if (nome_jogo_lower_case.find(pesquisa_lower_case) != std::string::npos) {
                        jogos_encontrados.push_back(jogo);
                    }
                }
                int count = 0;
                for(const auto& jogo_encontrado: jogos_encontrados) {
                    count ++;
                }

                if (jogos_encontrados.empty()) {
                    std::cout << "Nenhum jogo encontrado com o termo '" << pesquisa << "'." << std::endl;
                    return new AvaliacaoMenu(usuario_conect);
                } else if (count == 1) {
                    _avaliacoes.clear();
                    for(const auto& jogo_encontrado: jogos_encontrados) {
                        _avaliacoes = repositorio_ava.obter_avaliacoes(jogo_encontrado);
                    }
                    for (const auto& avaliacao: _avaliacoes) {
                        std::cout << "[" << avaliacao.nota() << "] - " << avaliacao.comentario() << std::endl; 
                    }
                    return new AvaliacaoMenu(usuario_conect);
                } else {
                    std::cout << "Jogos encontrados com o termo '" << pesquisa << "':\n";
                    for (const auto& jogo_encontrado: jogos_encontrados) {
                        std::cout << "[" << jogo_encontrado.jogo_id() << "] " << "[" << jogo_encontrado.nome() << "]  || " << jogo_encontrado.genero() << " || " << jogo_encontrado.valor() << " R$" << " || " << std::endl;
                    }
                    std::cout << "> Digite o ID do jogo desejado: " << std::endl;
                    int id;
                    std::cin >> id;
                    for (const auto& jogo_encontrado: jogos_encontrados) {
                        if(jogo_encontrado.jogo_id() == id) {
                            _avaliacoes.clear();
                            _avaliacoes = repositorio_ava.obter_avaliacoes(jogo_encontrado);
                            for (const auto& avaliacao: _avaliacoes) {
                                std::cout << "[" << avaliacao.nota() << "] - " << avaliacao.comentario() << std::endl; 
                            }
                            return new AvaliacaoMenu(usuario_conect);
                        } else {
                            std::cout << "ID não encontrado." << std::endl;
                        }
                    }
                }
            }
            case 3: {
                return new Biblioteca(usuario_conect);
            }
            case 4: {
                return new Loja(usuario_conect);
            }
            case 5: {
                repository::Desenvolvedores repositorio_devs("repositorio_desenvolvedores");
                model::Desenvolvedor dev = repositorio_devs.obter_desenvolvedor(usuario_conect.email());
                return new DevMenu(dev);
            }
        }
        return nullptr;
    }   

    void AvaliacaoMenu::salvar_usuario_conectado(const model::Usuario &usuario) const {
        std::string nome_arquivo = "usuario_conectado";
        std::ofstream arquivo(nome_arquivo);
        arquivo.clear();

        if (arquivo.is_open()) {
            arquivo << usuario.usuario_id() << ' ' << usuario.usuario_login() << ' ' << usuario.senha() << ' ' << usuario.email() <<' '<< usuario.nome()<<' '<< usuario.idade() <<' '<< usuario.desenvolvedor() << ' ' << usuario.saldo() << std::endl;
            arquivo.close();
        } else {
            std::cerr << "> Erro ao salvar usuário conectado " << nome_arquivo << std::endl;
        }
    }

    model::Usuario AvaliacaoMenu::carregar_usuario_conectado() {
        std::string nome_arquivo = "usuario_conectado";
        std::ifstream arquivo(nome_arquivo, std::ios::in);

        if(arquivo.is_open()) {
            int usuario_id;
            unsigned idade, saldo;
            bool desenvolvedor;
            std::string usuario_login, email, nome, sobrenome, senha;
            
            arquivo >> usuario_id >> usuario_login >> senha >> email >> nome >> sobrenome >> idade >> desenvolvedor >> saldo;
            model::InfoPessoal info;
            info.primeiro_nome = nome;
            info.sobrenome = sobrenome;
            info.idade = idade;

            model::Usuario usuario_conectado(usuario_id, usuario_login, senha, email, info, desenvolvedor, saldo);
            arquivo.close();
            return usuario_conectado;
        } else {
            std::cerr << " ERRO ao abrir o arquivo de Usuários." << std::endl;
        } 
    }
}
