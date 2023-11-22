#include "model/desenvolvedor.hpp"
#include "model/usuario.hpp"

#include "ui/dev_menu.hpp"
#include "ui/biblioteca_menu.hpp"

#include "service/jogo.hpp"

#include "repository/usuarios.hpp"


#include <iostream>
#include <string>

namespace tpapp::ui {
DevMenu::DevMenu(model::Desenvolvedor const &usuario_dev): _usuario_dev(usuario_dev) {
_title = "Área do Desenvolvedor";
_options.push_back("1 - Adicionar Jogo");
_options.push_back("2 - Remover Jogo");
_options.push_back("3 - Atualizar Jogo");
_options.push_back("4 - Biblioteca");
_options.push_back("5 - Loja");
}

    Menu* DevMenu::next(unsigned option) {
        while(option != 0) {
            switch(option) {
                case 1: {

                    int jogo_id;


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

                    service::Jogo jogo(jogo_id, nome, desenvolvedora, genero, data_lancamento, valor);
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
                    model::Usuario usuario = repositorio_usuarios.obterUsuario(_usuario_dev.email());
                    return new Biblioteca(usuario);
                }
            }
        }
    }
}