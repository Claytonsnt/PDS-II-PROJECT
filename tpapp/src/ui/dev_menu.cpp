#include "model/desenvolvedor.hpp"
#include "model/usuario.hpp"

#include "ui/dev_menu.hpp"
#include "ui/biblioteca_menu.hpp"
#include "ui/loja.hpp"

#include "repository/usuarios.hpp"
#include "repository/desenvolvedores.hpp"
#include "repository/jogos.hpp"

#include "service/jogo.hpp"

#include <iostream>
#include <string>

namespace tpapp::ui {
DevMenu::DevMenu(model::Desenvolvedor const &usuario_dev): _usuario_dev(usuario_dev) {
    salvar_usuario_conectado(_usuario_dev);
_title = "Área do Desenvolvedor";
_options.push_back("1 - Adicionar Jogo");
_options.push_back("2 - Remover Jogo");
_options.push_back("3 - Atualizar Jogo");
_options.push_back("4 - [Biblioteca]");
_options.push_back("5 - [Loja]");
}

    void DevMenu::salvar_usuario_conectado(const model::Usuario &usuario) const {
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

    model::Usuario DevMenu::carregar_usuario_conectado() {
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

    Menu* DevMenu::next(unsigned option) {
        repository::Desenvolvedores repositorio_devs("repositorio_desenvolvedores");
        model::Usuario usuario_conect = carregar_usuario_conectado();
        model::Desenvolvedor dev = repositorio_devs.obter_desenvolvedor(usuario_conect.email());
            switch(option) {
                case 1: {

                    std::cout << "> Passe as informações do jogo: " << std::endl;
                    std::string nome, desenvolvedora, genero, data_lancamento;
                    double valor;
                    int jogo_id;
                    std::cout << "o- Nome: " << std::endl;
                    std::cin >> nome;
                    std::cout << "o- Desenvolvedora: " << std::endl;
                    std::cin >> desenvolvedora;
                    std::cout << "o- Gênero: " << std::endl;
                    std::cin >> genero;
                    std::cout << "o- Data de Lançamento [dd/mm/aaaa]: " << std::endl;
                    std::cin >> data_lancamento;
                    std::cout << "o- Preço em reais: " << std::endl;
                    std::cin >> valor;

                    std::string nome_arquivo = "repositorio_jogos";
                    repository::Jogos repositorio(nome_arquivo);

                    jogo_id = repositorio.qnt_jogos();

                    service::Jogo jogo(jogo_id, nome, desenvolvedora, genero, valor, data_lancamento);
                    repositorio.adicionar_jogo(jogo);
                    std::cout << "Jogo Salvo..." << jogo.nome() << std::endl;
                    return new DevMenu(dev);
                }

                case 2: {
                    std::string nome_arquivo = "repositorio_jogos";
                    repository::Jogos repositorio(nome_arquivo);
                    repositorio.exibir_jogos();

                    int jogo_id;
                    std::cout << "> Digite o ID do jogo para removê-lo: " << std::endl;        
                    std::cin >> jogo_id;

                    repositorio.remover_jogo(jogo_id);
                    return new DevMenu(dev);
                }

                case 3: {
                    std::cout << "> Para alterar um jogo será necessário fornecer todas as informações novamente: " << std::endl;
                    std::string nome, desenvolvedora, genero, data_lancamento;
                    double valor;
                    int jogo_id;
                    std::cout << "o- Nome: " << std::endl;
                    std::cin >> nome;
                    std::cout << "o- Desenvolvedora: " << std::endl;
                    std::cin >> desenvolvedora;
                    std::cout << "o- Gênero: " << std::endl;
                    std::cin >> genero;
                    std::cout << "o- Data de Lançamento [dd/mm/aaaa]: " << std::endl;
                    std::cin >> data_lancamento;
                    std::cout << "o- Preço: " << std::endl;
                    std::cin >> valor;

                    std::string nome_arquivo = "repositorio_jogos";
                    repository::Jogos repositorio(nome_arquivo);
                    repositorio.exibir_jogos();

                    std::cout << "o- Será necessário informar o ID do jogo: " << std::endl;
                    std::cin >> jogo_id;
                    return new DevMenu(dev);
                }
                case 4: {
                    repository::Usuarios repositorio_usuarios("repositorio_usuarios");
                    model::Usuario usuario_conect = carregar_usuario_conectado();
                    std::string email = usuario_conect.email();
                    model::Usuario usuario = repositorio_usuarios.obter_usuario(email);                     
                    return new Biblioteca(usuario);
                }
                case 5: {
                    repository::Usuarios repositorio_usuarios("repositorio_usuarios");
                    model::Usuario usuario_conect = carregar_usuario_conectado();
                    //std::string email = ;
                    model::Usuario usuario = repositorio_usuarios.obter_usuario(usuario_conect.email());                     
                    return new Loja(usuario);
                }
            }
        return nullptr;
    }
}