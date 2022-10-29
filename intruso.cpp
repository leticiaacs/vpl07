#include "intruso.hpp"

void Intruso::set_senha_vazada(std::string vazou){
    senhas_vazadas.push_back(vazou);
}

std::vector<std::string> Intruso::traduz_senha(int tam){
    std::vector<std::string> traduzidas;
    std::string senha;
    std::string traduzida;
    int i = 0, b = 0;

    for(i=0; i<tam; i++){
        senha = senhas_vazadas[i];

        int a = 0, c = 0;

        for(a=0; a<12; i+=2){
            for(c = 10+b; c < 16; i++){
                if(senha[c] == 'A'){
                    traduzida[a] = senha[0];
                    traduzida[a+1] = senha[1];
                }else if(senha[c] == 'B'){
                    traduzida[a] = senha[2];
                    traduzida[a+1] = senha[3];
                }else if(senha[c] == 'C'){
                    traduzida[a] = senha[4];
                    traduzida[a+1] = senha[5];
                }else if(senha[c] == 'D'){
                    traduzida[a] = senha[6];
                    traduzida[a+1] = senha[7];
                }else if(senha[c] == 'E'){
                    traduzida[a] = senha[8];
                    traduzida[a+1] = senha[9];
                }
            }
        }
        traduzidas.push_back(traduzida);
        b++;
    }

    return traduzidas;
}