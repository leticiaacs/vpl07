#ifndef INTRUSO_H
#define INTRUSO_H

#include <string>
#include <vector>

class Intruso{
    /*Continue a implementação da classe Intruso*/
    std::vector<std::string> senhas_vazadas;
    std::vector<std::string> traduzidas;

    public:
        void set_senha_vazada(std::string vazou);
        std::vector<std::string> traduz_senha(int tam);
        std::string crack_senha();
};

#endif