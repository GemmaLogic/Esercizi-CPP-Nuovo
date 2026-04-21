
//Esercizio 11 pag 118
//Scrivete un programma che scriva i primi N valori della serie di Fibonacci, cioè la serie che inizia con 1,1,2,3,5,8, 13, 21, 34. Il numero successivo della serie è la somma dei due precedenti. Trovate il più grande numero di Fibonacci che stia in un int.
// Principi e Tecniche di Programmazione in C++ di Bjarne Stroustrup
// GemmaLogic

#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main(){
    try{
        vector<int> numeri; // salveremo i nostri numeri
        double prossimo = 0; // variabile a cui sommeremo il numero precedente
        int controllo_num = 0; // inseriremo num_max per vedere se sta nel int
        numeri.push_back(1);
        numeri.push_back(1); // aggiungiamo  i primi due valori in modo da iniziare il ciclo
        for(int i = 1; prossimo == controllo_num ; ++i){
            prossimo = double(numeri.at(i)) + numeri.at(i-1);
            // eseguiamo una conversione in modo che la somma avvenga in double
            controllo_num = prossimo; // inseriamo il double nell int per la verifica
            if(prossimo != controllo_num){
                // verifichiamo e se non sono uguali usciamo dal ciclo
                break;
            }
            else{
                // altrimenti inseriamo nel vector
                numeri.push_back(prossimo);
            }
        }
        cout << "Il numero piu grande di Fibonacci che sta in un int è: " << numeri[numeri.size()-1]
        << '\n';
        
    }
    catch(exception& e){
        
        return 1;
    }
    catch(...){
        
        return 2;
    }
    
    return 0;
}
