#include <iostream>
#include <string>

namespace tpapp:: service {
class Jogo {
public:
    Jogo(const int jogo_id, const std::string nome);
    std::string nome() const;
    int jogo_id() const;

private:
    std::string _nome;
    int _jogo_id;
};
}