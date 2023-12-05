#include "model/desenvolvedor.hpp"
#include "model/usuario.hpp"

#include "repository/desenvolvedores.hpp"
#include "repository/usuarios.hpp"

#include "ui/biblioteca_menu.hpp"
#include "ui/dev_menu.hpp"
#include "ui/login_menu.hpp"

#include <iostream>
#include <regex>
#include <string>

namespace tpapp::ui {
LoginMenu::LoginMenu() {
    _title = "Menu de Autenticação";
    _options.push_back("1 - Entrar");
    _options.push_back("2 - Criar Usuário");
    _options.push_back("3 - Criar Usuário Desenvolvedor");
}

Menu *LoginMenu::next(unsigned option) {

    auto ler_autenticacao = []() { //teste para email
        unsigned sair = 0;
        do {
        std::string email;
        std::cout << "> Email: ";
        std::cin >> email;
        std::regex padrao_email(R"([a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,})");
        if (std::regex_match(email, padrao_email)) {
            std::cout << "O email inserido é válido." << std::endl;
            sair = 1;
            return email;
        } else {
            std::cout << "O email inserido NÃO é válido." << std::endl;
        }
        } while (sair == 0);

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
            
            std::string email = ler_autenticacao();
            
            std::string nome_arquivo = "repositorio_usuarios";
            repository::Usuarios repositorio(nome_arquivo);

            std::string senha;
            std::cout << ">Digite sua senha: " << std::endl;
            std::cin >> senha;
            std::string senha_cripto = repositorio.criptografar_senha(senha);

            std::cout << "Verificando usuário: " << email << std::endl;

            if (repositorio.verificar_usuario_email(email) && repositorio.verificar_usuario_senha(senha_cripto)) {
                std::cout << "Usuário verificado." << std::endl;
                model::Usuario usuario = repositorio.obter_usuario(email);
                if (usuario.desenvolvedor() == true) {
                    std::string nome_arquivo = "repositorio_desenvolvedores";
                    repository::Desenvolvedores repositorio_dev(nome_arquivo);
                    model::Desenvolvedor dev = repositorio_dev.obter_desenvolvedor(email);
                    return new DevMenu(dev);
                } else {
                    return new Biblioteca(usuario);
                }    
            } else {
                std::cout << "Senha ou email inválidos." << std::endl;
                return new LoginMenu();
            }
            break;
        
        }
        case 2: {

            bool desenvolvedor = false;
            std::string usuario_login;
            std::cout << "> Digite o nome de usuário desejado: ";
            std::cin >> usuario_login;

            std::string email = ler_autenticacao();

            std::string nome_arquivo = "repositorio_usuarios";
            repository::Usuarios repositorio(nome_arquivo);
            
            if (repositorio.verificar_usuario_email(email)) {
                std::cout << "E-mail já utilizado." << std::endl;
                break;
            } else {
                std::cout << "E-mail disponível." << std::endl;
            }

            std::string senha;
            std::cout << ">Digite a senha desejada: ";
            std::cin >> senha;

            std::string senha_criptografada = repositorio.criptografar_senha(senha); 

            int usuario_id = repositorio.qnt_usuarios();

            model::InfoPessoal info;
            ler_info_pessoal(info);

            unsigned saldo = 00.00;

            model::Usuario usuario(usuario_id, usuario_login, email, senha_criptografada, info, desenvolvedor, saldo);
            
            repositorio.adicionar_usuario(usuario);
            
            std::cout << "Salvando Usuário: " << usuario.to_string() << std::endl;
            return new Biblioteca(usuario);
        }
        case 3: {

            std::string arquivo_dev = "repositorio_desenvolvedores";
            repository::Desenvolvedores repositorio_dev(arquivo_dev);

            std::string desenvolvedora_id;
            std::cout << "> Desenvolvedora ID: ";
            std::cin >> desenvolvedora_id;

            if (repositorio_dev.verificar_desenvolvedora(desenvolvedora_id)) {
                std::cout << "Desenvolvedora confirmada." << std::endl;
            } else {
                std::cout << "Desenvolvedora não encontrada." << std::endl;
                break;
            }

            std::string usuario_login;
            std::cout << "> Digite o nome de usuário desejado: ";
            std::cin >> usuario_login;

            std::string email = ler_autenticacao();

            std::string nome_arquivo = "repositorio_usuarios";
            repository::Usuarios repositorio_usu(nome_arquivo);

            if (repositorio_usu.verificar_usuario_email(email)) { 
                std::cout << "E-mail já utilizado." << std::endl;
                break;
            } else {
                std::cout << "E-mail disponível." << std::endl;
            }

            std::string senha;
            std::cout << ">Digite a senha desejada: ";
            std::cin >> senha;

            std::string senha_criptografada = repositorio_usu.criptografar_senha(senha);

            int usuario_id = repositorio_usu.qnt_usuarios();

            model::InfoPessoal info;
            ler_info_pessoal(info);

            unsigned saldo = 00.00;

            model::Desenvolvedor dev(usuario_id, usuario_login, senha_criptografada, desenvolvedora_id, email, info, saldo);
            model::Usuario usuario(usuario_id, usuario_login, senha_criptografada, email, info, true, saldo);

            repositorio_dev.adicionar_desenvolvedor(dev);
            repositorio_usu.adicionar_usuario(usuario);
            std::cout << "Salvando Usuário Desenvolvedor: " << dev.to_string() << std::endl;
            return new DevMenu(dev);
        }
    }
}

    return nullptr;
}
}