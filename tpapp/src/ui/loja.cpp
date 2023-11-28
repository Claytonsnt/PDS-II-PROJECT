#include "ui/loja.hpp"
#include "ui/biblioteca_menu.hpp"
#include "ui/dev_menu.hpp"

#include "service/jogo.hpp"

#include "model/usuario.hpp"
#include "model/desenvolvedor.hpp"

#include "repository/usuarios.hpp"
#include "repository/desenvolvedores.hpp"
#include "repository/jogos.hpp"

#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <map>

namespace tpapp::ui {
    Loja::Loja(model::Usuario const &usuario) : _usuario(usuario) {
    salvar_usuario_conectado(_usuario);

    _title = "Loja";
    std::string nome_arquivo = "repositorio_jogos";
    repository::Jogos repositorio(nome_arquivo);
    repositorio.exibir_jogos();
    std::cout << "***PARA COMPRAR ALGUM JOGO VOCÊ DEVE [2]BUSCAR JOGO OU [3]IR À LISTA DE DESEJOS***" << std::endl;
    _options.push_back("1 - Exibir jogos");
    _options.push_back("2 - buscar jogos");
    _options.push_back("3 - Visualizar lista de desejos");
    _options.push_back("4 - [Biblioteca]");
    if(_usuario.desenvolvedor()){
        _options.push_back("5 - [Menu de Desenvolvedor]");
    }
}

    void Loja::salvar_usuario_conectado(const model::Usuario &usuario) const {
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

    model::Usuario Loja::carregar_usuario_conectado() {
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

    Menu *Loja::next(unsigned option) {
        model::Usuario usuario_conect = carregar_usuario_conectado();
        while(option != 0){
            switch(option) {
                case 1: {
                    std::string nome_arquivo = "repositorio_jogos";
                    repository::Jogos repositorio(nome_arquivo);
                    repositorio.exibir_jogos();
                    std::cout << "> Como deseja exibir? " << std::endl;
                    std::cout << "> Você pode ordenar por: " << std::endl;
                    std:: cout << "\n[(1) - ALFABETICA] \n [(2) - GENERO] \n [(3) - AVALIAÇÃO] \n [(4) - DATA]" << std::endl; // criar logica da data
                    unsigned ordem;
                    std::cin >> ordem;

                    Loja carregar_jogos_arquivo(std::string nome_arquivo);

                    switch(ordem) {
                        case 1: {
                            std::vector<service::Jogo> jogos_ordenados = _jogos;

                            std::sort(jogos_ordenados.begin(), jogos_ordenados.end(), [](const service::Jogo& jogo1, const service::Jogo& jogo2) {
                                return jogo1.nome() < jogo2.nome();
                            });
                            std::cout << "Jogos em ordem alfabética:\n";
                            for (const auto& jogo : jogos_ordenados) {
                                std::cout << jogo.nome() << std::endl;
                            }
                            unsigned sair = 0;
                            //std::cout << "> Deseja voltar a loja? [0]-SIM [1]-NÃO. " << std::endl;
                            //std::cin >> sair;
                            break;
                        }
                        case 2: {
                            std::map<std::string, std::vector<service::Jogo>> jogos_genero;

                            for (const auto& jogo : _jogos) {
                                jogos_genero[jogo.genero()].push_back(jogo);
                            }

                            for(const auto& [genero, jogos]: jogos_genero) {
                                for(const auto& jogo: jogos) {
                                    std::cout <<"[" << genero << "] - " << jogo.nome() << std::endl;  
                                }
                                unsigned sair = 0;
                                break;
                            }
                        }
                    }
                    return new Loja(usuario_conect);
                }

                case 2: {
                    std::string nome_arquivo = "repositorio_jogos";
                    Loja carregar_jogos_arquivo(std::string nome_arquivo);
                    
                    std::string pesquisa;
                    std::cout << "> Insira o nome do jogo: " << std::endl;
                    
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
                        break;
                    } 
                    else if (count == 1) {
                        for(const auto& jogo_encontrado: jogos_encontrados) {
                            std::cout << "[" << jogo_encontrado.nome() << "]  || " << jogo_encontrado.genero() << " || " << jogo_encontrado.valor() << " R$" << " || " << std::endl; 
                            unsigned opcao;
                            std::cout << "> Deseja adicionar esse jogo ao carrinho de compras? [1]SIM [2]NÃO: " << std::endl;
                            std::cin >> opcao;
                            if(opcao == 1) {
                                _carrinho_compras.push_back(jogo_encontrado);
                                unsigned opcao1;
                                std::cout << "> Deseja finalizar as compras? [1]SIM [2]NÃO: "   <<std::endl;
                                std::cin >> opcao1;
                                if(opcao1 == 1) {
                                    //Loja::comprar(jogo_encontrado.valor());
                                } else {
                                    break;
                                }
                            } else {
                                return new Loja(usuario_conect);
                            }
                        }
                    }
                    else {
                        std::cout << "Jogos encontrados com o termo '" << pesquisa << "':\n";
                        for (const auto& jogo_encontrado: jogos_encontrados) {
                            std::cout << "[" << jogo_encontrado.jogo_id() << "] " << "[" << jogo_encontrado.nome() << "]  || " << jogo_encontrado.genero() << " || " << jogo_encontrado.valor() << " R$" << " || " << std::endl;
                            unsigned opcao;
                        std::cout << "> Deseja adicionar algum desses jogos ao carrinho de compras? [1]SIM [2]NÃO: " << std::endl;
                        std::cin >> opcao;
                        if(opcao == 1) {
                            _carrinho_compras.push_back(jogo_encontrado);
                            unsigned opcao1;
                            std::cout << "> Deseja finalizar as compras? [1]SIM [2]NÃO: "  <<std::endl;
                            std::cin >> opcao1;
                            if(opcao1 == 1) {
                                //Loja::comprar(jogo_encontrado.valor());
                            } else {
                                return new Loja(usuario_conect);
                            }
                        } else {
                            return new Loja(usuario_conect);
                        }                                
                        }
                    }
                }

                case 3: {
                    for(const auto& desejo: _lista_desejos) {
                        if(_lista_desejos.empty()) {
                            std::cout << "Sua Lista de Desejos está vazia, começe a desejar agora mesmo!" << std::endl;
                            return new Loja(usuario_conect);
                        } else {
                            std::cout << "[" << desejo.nome() << "] || " << desejo.valor() << " R$" << " || " << std::endl;
                        }
                    }
                    unsigned opcao;
                    std::cout << "> Deseja finalizar as compras? [1]SIM [2]NÃO: " << std::endl;
                    if(opcao == 1) {
                        unsigned valor_total = 0;
                        for(const auto& desejo: _lista_desejos) {
                            valor_total = valor_total + desejo.valor();
                        }
                        //Loja::comprar(valor_total);
                    }
                    else {
                        return new Loja(usuario_conect);
                    }
                }

                case 4: {
                    repository::Usuarios repositorio_usuarios("repositorio_usuarios");
                    model::Usuario usuario_conect = carregar_usuario_conectado();
                    model::Usuario usuario = repositorio_usuarios.obterUsuario(usuario_conect.email());
                    return new Biblioteca(usuario);
                }
                
                case 5: {
                    repository::Desenvolvedores repositorio_devs("repositorio_usuarios");
                    model::Usuario usuario_conect = carregar_usuario_conectado();
                    model::Desenvolvedor dev = repositorio_devs.obterDesenvolvedor(usuario_conect.email());
                    return new DevMenu(dev);
                }
            }
            }
            return nullptr;
        }
        

    void Loja::salvar_jogos_arquivo(const std::string& nome_arquivo) const {
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

    void Loja::carregar_jogos_arquivo(const std::string& nome_arquivo) {
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