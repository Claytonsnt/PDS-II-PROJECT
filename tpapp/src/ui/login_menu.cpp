#include "ui/login_menu.hpp"

#include "model/usuario.hpp"
#include "model/desenvolvedor.hpp"


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

    switch(option) {
        case 1: {
            std::string email;
            ler_autenticacao(email);

            std::cout << "Logando: " << email << std::endl;
            break;
        }
        case 2: {
            std::string usuario_login;
            std::cout << "> Digite o nome de usuário desejado: ";
            std::cin >> usuario_login;

            std::string email;
            ler_autenticacao(email);

            model::InfoPessoal info;
            ler_info_pessoal(info);

            model::Usuario usuario(email, info);
            std::cout << "Salvando Usuário: " << usuario.to_string() << std::endl;
            break;
        }
        case 3: {
            unsigned desenvolvedora_id;
            std::cout << "> Desenvolvedora ID: ";
            std::cin >> desenvolvedora_id;

            std::string email;
            ler_autenticacao(email);

            model::InfoPessoal info;
            ler_info_pessoal(info);

            model::Desenvolvedor dev(desenvolvedora_id, email, info);
            std::cout << "Salvando Usuário Desenvolvedor: " << dev.to_string() << std::endl;
            break;
        }
    }
    return nullptr;
}
}