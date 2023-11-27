#include "model/desenvolvedor.hpp"
#include "model/usuario.hpp"

#include "ui/dev_menu.hpp"
#include "ui/biblioteca_menu.hpp"

#include "repository/usuarios.hpp"
#include "repository/jogos.hpp"

#include <iostream>
#include <string>

namespace tpapp::ui {
DevMenu::DevMenu(model::Desenvolvedor const &usuario_dev): _usuario_dev(usuario_dev) {
    salvar_usuario_conectado(_usuario_dev);
_title = "Área do Desenvolvedor";
_options.push_back("1 - Adicionar Jogo");
_options.push_back("2 - Remover Jogo");
_options.push_back("3 - Atualizar Jogo");
_options.push_back("4 - Biblioteca");
_options.push_back("5 - Loja");
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
        while(option != 0) {
            switch(option) {
                case 1: {

                    //int jogo_id;
                    // buscar os jogos no repositorio de jogos ler todos os jogos e contar a quant e adicionar o jogos_id 


                    std::string nome;
                    std::cout << "Digite o nome do jogo: " <<std::endl;
                    std::cin >> nome;

                    std::string desenvolvedora;
                    std::cout << "Digite a desenvolvedora do jogo: " <<std::endl;
                    std::cin >> desenvolvedora;

                    std::string genero;
                    std::cout << "Digite o gênero do jogo: " << std::endl;
                    std::cin >> genero;

                    std::string data_lancamento;
                    std::cout << "Digite a data de lançamento do jogo: " << std::endl;
                    std::cin >> data_lancamento;

                    double valor;
                    std::cout << "Digite o preço do jogo em reais: " << std::endl;
                    std::cin >> valor;

                    //service::Jogo jogo(jogo_id, nome, desenvolvedora, genero, data_lancamento, valor);
                    //repositorio jogos puxa o jogo
                }

                case 2: {
                    //le o repositorio e remove o jogo desejado
                }

                case 3: {
                    //busca o jogo no repositório e atualiza o que deseja
                }
                case 4: {
                    repository::Usuarios repositorio_usuarios("repositorio_usuarios");
                    model::Usuario usuario_conect = carregar_usuario_conectado();
                    std::string email = usuario_conect.email();
                    model::Usuario usuario = repositorio_usuarios.obterUsuario(usuario_conect.email());
                    return new Biblioteca(usuario);
                }
            }
        }
        return nullptr;
    }
}