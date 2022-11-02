#include "intruso.hpp"
#include <string>
#include <vector>
#include <iostream>

void Intruso::set_senha_vazada(std::string vazou){

    senhas_vazadas.push_back(vazou);
}

std::vector<std::string> Intruso::traduz_senha(){
	
    std::string senha;
    std::string traduzida;
    int i = 0;

    for(i=0; i<senhas_vazadas.size(); i++){
		
		std::string traduzida;
		senha = senhas_vazadas[i];
        int c = 0;
			
        for(c = 20; c < 31; c+=2){
			
			if(senha[c] == 'A'){
                traduzida.push_back(senha[0]);
                traduzida.push_back(senha[2]);
            }else if(senha[c] == 'B'){
				traduzida.push_back(senha[4]);
				traduzida.push_back(senha[6]);
            }else if(senha[c] == 'C'){
                traduzida.push_back(senha[8]);
                traduzida.push_back(senha[10]);
            }else if(senha[c] == 'D'){
				traduzida.push_back(senha[12]);
				traduzida.push_back(senha[14]);
            }else if(senha[c] == 'E'){
                traduzida.push_back(senha[16]);
                traduzida.push_back(senha[18]);
			}		
        }
		traduzidas.push_back(traduzida);
	}
			
	return traduzidas;
}

std::string Intruso::crack_senha(){

    std::vector<std::string> v = traduz_senha();
    std::string respFinal;
    std::vector<int> num1;
    std::vector<int> num2;
    std::vector<int> num3;
    std::vector<int> num4;
    std::vector<int> num5;
    std::vector<int> num6;
    

    for(int i = 0; i<traduzidas.size(); i++ ){ 
		
		std::string aux;
        aux = v[i];
		
        num1.push_back(aux[0] - 48);
        num1.push_back(aux[1] - 48);


        num2.push_back(aux[2] - 48);
        num2.push_back(aux[3] - 48);
        
        
        num3.push_back(aux[4] - 48);
        num3.push_back(aux[5] - 48);
        
        
        num4.push_back(aux[6]-48);
        num4.push_back(aux[7]-48);
        
        
        num5.push_back(aux[8]-48);
        num5.push_back(aux[9]-48);
        
        
        num6.push_back(aux[10]-48);
        num6.push_back(aux[11]-48);
	
    }

    std::vector<int> auxiliar1;
	std::vector<int> auxiliar2;
	std::vector<int> auxiliar3;
	std::vector<int> auxiliar4;
	std::vector<int> auxiliar5;
	std::vector<int> auxiliar6;
	
        for(int i = 0; i<10; i++){
            auxiliar1.push_back(0);
			auxiliar2.push_back(0);
			auxiliar3.push_back(0);
			auxiliar4.push_back(0);
			auxiliar5.push_back(0);
			auxiliar6.push_back(0);
        }

    for(int i=0; i<(2*traduzidas.size()); i++){
        
        auxiliar1[num1[i]]++;
        auxiliar2[num2[i]]++;
        auxiliar3[num3[i]]++;
        auxiliar4[num4[i]]++;
        auxiliar5[num5[i]]++;
        auxiliar6[num6[i]]++;
    }
	
    for(int i = 0; i<(2*traduzidas.size()); i++) {

        if(auxiliar1[num1[i]] >= 2){
            respFinal[0] = num1[i] + 48;
        }

        if(auxiliar2[num2[i]] >= 2){
            respFinal[1] = num2[i] + 48;
        }

        if(auxiliar3[num3[i]] >= 2){
            respFinal[2] = num3[i] + 48;
        }

        if(auxiliar4[num4[i]] >= 2){
            respFinal[3] = num4[i]+ 48;
        }

        if(auxiliar5[num5[i]] >= 2){
            respFinal[4] = num5[i] + 48;
        }

        if(auxiliar6[num6[i]] >= 2){
            respFinal[5] = num6[i] + 48;
        }

    }
	
		for(int i = 0; i<6; i++) {
		    
		    if(i == 0) {
		        resposta+=respFinal[i];
		    } else {
		    resposta+= " ";
			resposta+= respFinal[i];
		    }
		}
	
    return resposta;
	
}