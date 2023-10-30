#include <iostream>
#include <vector>
#include <string>

class Jogo {
public:
    int jogo_id; 
    float valor;
    std::string nome;
    std::string desenvolvedora;
    std::string data_lancamento;
    std::string genero;
};

class Desenvolvedor {
public:
    int desenvolvedora_id;

    void adicionar_jogo();
    void remover_jogo();
    void atualizar_jogo();
};

class Usuario {
public:
    int usuario_id;
    std::string nome;
    std::string email;
    std::vector<Jogo> lista_desejos;
    Desenvolvedor desenvolvedor;
};

class Avaliacao {
public:
    float nota;
    int curtidas;
    std::string comentario;

    float calcular_avaliacao_media();
    void criar_avaliacao();
    void editar_avaliacao();
    void remover_avaliacao();
    void curtir_avaliacao();
    void comentar_avaliacao();
};

class Biblioteca {
public:
    std::vector<Jogo> jogos;
    std::vector<Jogo> favoritos;
    
    void buscar_jogo();
    void adicionar_jogo();
    void adicionar_favoritos();
    void criar_pasta_perconalizada();
    void atualizar_pasta_personalizada();
};

class Loja {
public:
    std::vector<Jogo> colecao_jogos;
    std::vector<Jogo> carrinho_de_compras;

    void buscar();
    void ordenar_avaliacao();
    void ordenar_data();
    void adicionar_carrinho();
    void remover_carrinho();
};

class Transacao {
public:
    std::string tipo;
    float valor;
    std::string data;
    std::string forma_pagamento;

    Loja carrinho_de_compras;
    void comprar();
};

class Carteira {
public:
    float saldo;
    std::vector<Transacao> historico;

    void adicionar_fundo();
};