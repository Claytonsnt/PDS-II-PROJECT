#include "ui/loja.hpp"
#include "ui/biblioteca_menu.hpp"
#include "ui/dev_menu.hpp"

#include "service/jogo.hpp"
#include "service/transacao.hpp"

#include "model/usuario.hpp"
#include "model/desenvolvedor.hpp"

#include "repository/usuarios.hpp"
#include "repository/desenvolvedores.hpp"
#include "repository/jogos.hpp"
#include "repository/transacoes.hpp"

#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <map>

namespace tpapp::ui {
    Loja::Loja(model::Usuario const &usuario) : _usuario(usuario) {
    salvar_usuario_conectado(_usuario);

    _title = "Loja";
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
            arquivo << usuario.usuario_id() << ' ' << usuario.usuario_login() << ' ' << usuario.email() <<' '<< usuario.nome()<<' '<< usuario.idade() <<' '<< usuario.desenvolvedor() << ' ' << usuario.saldo() << std::endl;
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
            unsigned idade, saldo;
            bool desenvolvedor;
            std::string usuario_login, email, nome, sobrenome;
            
            arquivo >> usuario_id >> usuario_login >> email >> nome >> sobrenome >> idade >> desenvolvedor >> saldo;
            model::InfoPessoal info;
            info.primeiro_nome = nome;
            info.sobrenome = sobrenome;
            info.idade = idade;

            model::Usuario usuario_conectado(usuario_id, usuario_login, email, info, desenvolvedor, saldo);
            arquivo.close();
            return usuario_conectado;
        } else {
            std::cerr << " ERRO ao abrir o arquivo de Usuários." << std::endl;
        }
    }

    Menu *Loja::next(unsigned option) {
        model::Usuario usuario_conect = carregar_usuario_conectado();

        std::string nome_arquivo = "repositorio_jogos";
        repository::Jogos repositorio(nome_arquivo);
        std::vector<service::Jogo> _jogos = repositorio.enviar_jogos();

        switch(option) {
            case 1: {
                std::cout << "> Como deseja exibir? " << std::endl;
                std::cout << "> Você pode ordenar por: " << std::endl;
                std:: cout << " \n [(1) - ALFABETICA] \n [(2) - GENERO] \n [(3) - AVALIAÇÃO] \n [(4) - DATA]" << std::endl; // criar logica da data
                unsigned ordem;
                std::cin >> ordem;
                switch(ordem) {
                    case 1: {
                        std::vector<service::Jogo> jogos_ordenados = _jogos;

                        std::sort(jogos_ordenados.begin(), jogos_ordenados.end(), [](const service::Jogo& jogo1, const service::Jogo& jogo2) {
                            return jogo1.nome() < jogo2.nome();
                        });
                        std::cout << "Jogos em ordem alfabética:\n";
                        for (const auto& jogo : jogos_ordenados) {
                            std::cout << "[" << jogo.jogo_id() << "] - " << jogo.nome() << " || " << jogo.valor() << " R$ || " << std::endl;
                        }
                        break;
                    }
                    case 2: {
                        std::map<std::string, std::vector<service::Jogo>> jogos_genero;

                        for (const auto& jogo : _jogos) {
                            jogos_genero[jogo.genero()].push_back(jogo);
                        }

                        for(const auto& [genero, jogos]: jogos_genero) {
                            for(const auto& jogo: jogos) {
                                std::cout <<"[" << genero << "] - " << jogo.nome() << " || " << jogo.valor() << " R$ || " << std::endl;  
                            }
                        }
                        break;
                    }
                }
                return new Loja(usuario_conect);
            }

            case 2: {  
                std::cout << "\n> CARTEIRA: " << usuario_conect.saldo() << "R$" << std::endl;              
                std::string pesquisa;
                std::cout << "> Insira o nome do jogo: " << std::endl;
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
                    return new Loja(usuario_conect);
                } 
                else if (count == 1) {
                    for(const auto& jogo_encontrado: jogos_encontrados) {
                        std::cout << "[" << jogo_encontrado.nome() << "]  || " << jogo_encontrado.genero() << " || " << jogo_encontrado.valor() << " R$" << " || " << std::endl; 
                        unsigned opcao;
                        std::cout << "> Deseja adicionar esse jogo ao carrinho de compras, lista de desejos ou sair? \n[0] SAIR \n[1] CARRINHO DE COMPRAS \n[2] LISTA DE DESEJOS" << std::endl;
                        std::cin >> opcao;
                        if(opcao == 1) {
                            _carrinho_compras.push_back(jogo_encontrado);
                            unsigned opcao1;
                            std::cout << "> Deseja finalizar as compras? [1]SIM [2]NÃO: "   <<std::endl;
                            std::cin >> opcao1;
                            if(opcao1 == 1) {
                                std::string nome_arquivo = "Transacoes - " + usuario_conect.usuario_login();
                                repository::Transacoes repositorio_transacoes(nome_arquivo);
                                repositorio_transacoes.comprar(jogo_encontrado, usuario_conect);
                            } else {
                                return new Loja(usuario_conect);
                            }
                        } else if(opcao == 2) {
                            _lista_desejos.push_back(jogo_encontrado);
                            std::cout << "Jogo adicionado a sua lista de desejos:" <<std::endl;
                            for (const auto& desejo: _lista_desejos) {
                                std::cout << "[" << desejo.nome() << "]  || " << desejo.genero() << " || " << desejo.valor() << " R$" << " || " << std::endl;
                                return new Loja(usuario_conect);
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
                            std::cout << "> Digite o ID do jogo desejado: " << std::endl;
                            int id;
                            std::cin >> id;
                            for (const auto& jogo_encontrado: jogos_encontrados) {
                                if(jogo_encontrado.jogo_id() == id) {
                                    _carrinho_compras.push_back(jogo_encontrado);
                                    std::cout << "O jogo foi adicionado ao carrinho de compras." << std::endl;
                                }
                            }
                            unsigned opcao1;
                            std::cout << "> Deseja finalizar as compras? [1]SIM [2]NÃO: "  <<std::endl;
                            std::cin >> opcao1;
                            if(opcao1 == 1) {
                                std::string nome_arquivo = "Transacoes - " + usuario_conect.usuario_id();
                                repository::Transacoes repositorio_transacoes(nome_arquivo);

                                for (const auto& jogo_carrinho: _carrinho_compras) {
                                    repositorio_transacoes.comprar(jogo_carrinho, usuario_conect);
                                }
                                return new Loja(usuario_conect);
                            } else {
                                return new Loja(usuario_conect);
                            }
                        } else {
                            return new Loja(usuario_conect);
                        }                                
                    }
                }
                return new Biblioteca(usuario_conect);
            }

            case 3: {
                std::cout << "\n> CARTEIRA: " << usuario_conect.saldo() << "R$" << std::endl;
                //implementar a lista de desejos no repositorio de usuarios
                if(_lista_desejos.empty()) {
                    std::cout << "Sua Lista de Desejos está vazia, começe a desejar agora mesmo!" << std::endl;
                    return new Loja(usuario_conect);
                } else {
                    for(const auto& desejo: _lista_desejos) {
                        std::cout << " || " << desejo.jogo_id()<< " || " <<  "[" << desejo.nome() << "] || " << desejo.valor() << " R$" << " || " << std::endl;
                    }
                }
                unsigned opcao;
                std::cout << "> Deseja adquirir um item da sua lista, todos os itens ou sair? [1]UM ITEM [2]TODOS OS ITENS [3]SAIR " << std::endl;
                std::cin >> opcao;

                std::string nome_arquivo = "Transacoes - " + usuario_conect.usuario_id();
                repository::Transacoes repositorio_transacoes(nome_arquivo);

                if(opcao == 1) {
                    std::cout << "> Digite o ID do jogo desejado: " << std::endl;
                    int id;
                    std::cin >> id;
                    for(const auto& desejo: _lista_desejos) {    
                        if (desejo.jogo_id() == id) { 
                            repositorio_transacoes.comprar(desejo, usuario_conect);
                        }
                    }
                    return new Loja(usuario_conect);
                } 
                else if(opcao == 2) {
                    unsigned valor_total = 0;
                    for(const auto& desejo: _lista_desejos) {
                        valor_total = valor_total + desejo.valor();
                    }
                    std::cout << "> Valor total dos itens da sua lista é " << valor_total << "R$, porém será necessário realizar a transação de cada um separadamente." << std::endl;
                    for(const auto& desejo: _lista_desejos) {
                        repositorio_transacoes.comprar(desejo, usuario_conect);
                    }
                    return new Loja(usuario_conect);
                }
                else {
                    return new Loja(usuario_conect);
                }
                return new Loja(usuario_conect);
            }

            case 4: {
                model::Usuario usuario_conect = carregar_usuario_conectado();
                return new Biblioteca(usuario_conect);
            }
            
            case 5: {
                repository::Desenvolvedores repositorio_devs("repositorio_desenvolvedores");
                model::Desenvolvedor dev = repositorio_devs.obter_desenvolvedor(usuario_conect.email());
                return new DevMenu(dev);
            }
        }
        return nullptr;
    }
}