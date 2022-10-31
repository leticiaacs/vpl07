#include "intruso.hpp"

void Intruso::set_senha_vazada(std::string vazou){
    senhas_vazadas.push_back(vazou);
}

std::vector<std::string> Intruso::traduz_senha(int tam){

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

std::string Intruso::crack_senha(){

    traduz_senha();

    std::string respFinal;
    std::vector<int> num1;
    std::vector<int> num2;
    std::vector<int> num3;
    std::vector<int> num4;
    std::vector<int> num5;
    std::vector<int> num6;
    std::string aux;

    for(int i = 0; i<traduzidas.size(); i++ ){    
        
        v[i] = aux;
        
        num1.push_back(stoi(aux[0]));
        num1.push_back(stoi(aux[1]));


        num2.push_back(stoi(aux[2]));
        num2.push_back(stoi(aux[3]));
        
        
        num3.push_back(stoi(aux[4]));
        num3.push_back(stoi(aux[5]));
        
        
        num4.push_back(stoi(aux[6]));
        num4.push_back(stoi(aux[7]));
        
        
        num5.push_back(stoi(aux[8]));
        num5.push_back(stoi(aux[9]));
        
        
        num6.push_back(stoi(aux[10]));
        num6.push_back(stoi(aux[11]));

    }

    std::vector<int> auxiliar;

        for(int i = 0; i<9; i++){
            auxiliar.push_back(0);
        }

    for(int i=0; i<(2*traduzidas.size()); i++){
        
        auxiliar[num1[i]]++;
        auxiliar[num2[i]]++;
        auxiliar[num3[i]]++;
        auxiliar[num4[i]]++;
        auxiliar[num5[i]]++;
        auxiliar[num6[i]]++;
    }

    for(int i = 0; i<(2*traduzidas.size()); i++) {

        if(auxiliar[num1[i]] == 2){
            respFinal[0] = num1[i] + '0';
        }

        if(auxiliar[num2[i]] == 2){
            respFinal[1] = num2[i] + '0';
        }

        if(auxiliar[num3[i]] == 2){
            respFinal[2] = num3[i] + '0';
        }

        if(auxiliar[num4[i]] == 2){
            respFinal[3] = num4[i] + '0';
        }

        if(auxiliar[num5[i]] == 2){
            respFinal[4] = num5[i] + '0';
        }

        if(auxiliar[num6[i]] == 2){
            respFinal[5] = num6[i] + '0';
        }

    }

    return respFinal;
}

