#include "ui/login_menu.hpp"
#include "ui/biblioteca_menu.hpp"
#include "ui/dev_menu.hpp"

#include "model/usuario.hpp"
#include "model/desenvolvedor.hpp"

#include "repository/usuarios.hpp"
#include "repository/desenvolvedores.hpp"

#include <iostream>
#include <string>

namespace tpapp::ui {
LoginMenu::LoginMenu() {
    _title = "Menu de Autentificação";
    _options.push_back("1 - Entrar");
    _options.push_back("2 - Criar Usuário");
    _options.push_back("3 - Criar Usuário Desenvolvedor");
}

Menu *LoginMenu::next(unsigned option) {
    auto ler_autenticacao = [](std::string &email) {
        std::cout << "> Email: ";
        std::cin >> email;
    };

    auto ler_info_pessoal = [](model::InfoPessoal &info) {
        std::cout << "> Primeiro nome: ";
        std::cin >> info.primeiro_nome;

        std::cout << "> Sobrenome: ";
        std::cin >> info.sobrenome;

        std::cout << "> Idade: ";
        std::cin >> info.idade;
    };
    while(option != 0) {

    switch(option) {

        case 1: {
            std::string email;
            ler_autenticacao(email);
            
            std::string nome_arquivo = "repositorio_usuarios";
            repository::Usuarios repositorio(nome_arquivo);

            std::cout << "Verificando usuário: " << email << std::endl;

            if (repositorio.verificarUsuarioEmail(email)) {
                std::cout << "Usuário verificado." << std::endl;
                model::Usuario usuario = repositorio.obterUsuario(email);
                if (usuario.desenvolvedor() == true) {
                    std::string nome_arquivo = "repositorio_desenvolvedores";
                    repository::Desenvolvedores repositorio_dev(nome_arquivo);
                    model::Desenvolvedor dev = repositorio_dev.obterDesenvolvedor(email);
                    return new DevMenu(dev);
                } else {
                    return new Biblioteca(usuario);
                }    
            } else {
                std::cout << "Usuário não encontrado." << std::endl;
                return new LoginMenu();
            }
            break;
        
        }
        case 2: {

            bool desenvolvedor = false;
            std::string usuario_login;
            std::cout << "> Digite o nome de usuário desejado: ";
            std::cin >> usuario_login;

            std::string email;
            ler_autenticacao(email);

            std::string nome_arquivo = "repositorio_usuarios";
            repository::Usuarios repositorio(nome_arquivo);
            
            if (repositorio.verificarUsuarioEmail(email)) {
                std::cout << "E-mail já utilizado." << std::endl;
                break;
            } else {
                std::cout << "E-mail disponível." << std::endl;
            }

            int usuario_id = repositorio.qnt_usuarios();

            model::InfoPessoal info;
            ler_info_pessoal(info);

            model::Usuario usuario(usuario_id, usuario_login, email, info, desenvolvedor);
            
            repositorio.adicionarUsuario(usuario);
            
            std::cout << "Salvando Usuário: " << usuario.to_string() << std::endl;
            return new Biblioteca(usuario);
        }
        case 3: {
            unsigned desenvolvedora_id;
            std::cout << "> Desenvolvedora ID: ";
            std::cin >> desenvolvedora_id;

            std::string usuario_login;
            std::cout << "> Digite o nome de usuário desejado: ";
            std::cin >> usuario_login;

            std::string email;
            ler_autenticacao(email);

            std::string nome_arquivo = "repositorio_usuarios";
            repository::Usuarios repositorio_usu(nome_arquivo);

            std::string arquivo_dev = "repositorio_desenvolvedores";
            repository::Desenvolvedores repositorio_dev(arquivo_dev);

            if (repositorio_usu.verificarUsuarioEmail(email)) {
                std::cout << "E-mail já utilizado." << std::endl;
                break;
            } else {
                std::cout << "E-mail disponível." << std::endl;
            }

            int usuario_id = repositorio_usu.qnt_usuarios();

            model::InfoPessoal info;
            ler_info_pessoal(info);

            model::Desenvolvedor dev(usuario_id, usuario_login, desenvolvedora_id, email, info);
            model::Usuario usuario(usuario_id, usuario_login, email, info, true);

            repositorio_dev.adicionarDesenvolvedor(dev);
            repositorio_usu.adicionarUsuario(usuario);
            std::cout << "Salvando Usuário Desenvolvedor: " << dev.to_string() << std::endl;
            return new DevMenu(dev);
        }
    }
}

    return nullptr;
}
}