#include <iostream>
#include <vector>
#include <string>

namespace tpapp:: service {
class Jogo {
public:
    Jogo(const std::string nome);
    std::string nome() const;
    int jogo_id;


private:
    std::string _nome;
};
}