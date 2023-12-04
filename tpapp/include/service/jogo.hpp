#pragma once

#include <iostream>
#include <string>

/**
 * @class Jogo
 * @brief Contém as informações necessárias de um jogo.
 *
 */
namespace tpapp::service {
class Jogo {
public:

    /// @brief Inicializa um usuário
    ///
    /// @param jogo_id          ID do jogo
    /// @param nome             nome do jogo
    /// @param desenvolvedora   desenvolvedora do jogo
    /// @param genero           gênero do jogo
    /// @param valor            valor do jogo
    /// @param data_lancamento  data de lançamento do jogo
    Jogo(int jogo_id, std::string nome, std::string desenvolvedora, std::string genero, double valor, std::string data_lancamento);

    /// @return ID do jogo
    int jogo_id() const;

    /// @return nome do jogo
    std::string nome() const;

    /// @return desenvolvedora do jogo
    std::string desenvolvedora() const;

    /// @return genero
    std::string genero() const;

    /// @return data de lançamento do jogo
    std::string data_lancamento() const;

    /// @return valor do jogo
    double valor() const;
  
private:
    int _jogo_id;
    std::string _nome;
    std::string _desenvolvedora;
    std::string _genero;
    double _valor;
    std::string _data_lancamento;
};
}