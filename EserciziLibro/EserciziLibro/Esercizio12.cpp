//Esercizio 11 pag 118
//Implementate un giochino di indovinelli chiamato (per qualche oscuro motivo) "Tori e Mucche". Il programma ha un vector di quattro numeri interi diversi nell'intervallo da 0 a 9 (ad esempio, 1234 ma non 1122) e il compito dell'utente è quello di scoprire questi numeri attraverso ripetute ipotesi. Supponiamo che il numero da indovinare sia 1234 e che l'utente provi con 1359; la risposta dovrebbe essere "1 toro e 1 mucca" perché l'utente ha indovinato una cifra (1) giusta e nella posizione giusta (un toro) e una cifra (3) giusta ma nella posizione sbagliata (una mucca). L'indovinello continua finché l'utente non ottiene quattro tori, cioè ha le quattro cifre corrette e nell'ordine corretto.
// Principi e Tecniche di Programmazione in C++ di Bjarne Stroustrup
// GemmaLogic

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void error(string s);
void controllo_utente(vector<int>& risposta);

int main(){
    
    try{
        cout << "Trova il numero segreto di 4 cifre. se indovini numero e posizione: (toro) solo numero: (mucca) \n";
        
        vector<int> risposta; // salveremo l'input per poi confrontarlo con segreto
        vector<int> segreto = {1,2,3,4}; // vector in cui è salvata la sequenza da trovare
        bool in_funzione = true; // indica che il ciclo è in funzione
        
        while(in_funzione){
            controllo_utente(risposta);
            in_funzione = false;
        }
        
    }
        
        catch(exception& e){
            cerr << "Error: " << e.what() << '\n';
            return 1;
        }
        catch(...){
            cerr << "Errore sconosciuto!\n";
            return 2;
        }
        return 0;
    }
    

void error(string s){
    
    throw runtime_error{s};
}


void controllo_utente(vector<int>& risposta){
    
    while(risposta.size() < 4){
        int temporanea = 0; // variabile in cui inseriremo input utente
        cin >> temporanea; // input
        if(!cin){
            // controlliamo che non venga immesso un input diverso
            error("Valore non valido");
        }
        
        else if(temporanea < 0 || temporanea > 9){
            // se <0 o > 9 reiserire il valore
            cout << "Inserisci valore compreso tra 0 e 9. Riprova!\n";
            
        }
        
        else{
            bool duplicato = false; // interruttore per controllare se numero ripetuto
            int num_mancanti = 4 - int(risposta.size()); // conta quanti numeri mancano nel vector
            for(int i = 0; i < risposta.size(); ++i){
                // controlliamo che i numeri siano diversi
                if(risposta.at(i) == temporanea){
                    // stampiamo
                    cout << "Hai gia inserito " << risposta[i] << " immetti altri "
                   << num_mancanti << " numeri\n";
                    // se numero ripetuto interruttore true
                    duplicato = true;
                }
                
            }
            if(duplicato == false){
                // se interruttore è false inseriamo nel vector
                risposta.push_back(temporanea); // inseriamo nel vector
            }
        }
        
        
    }
    for(int i: risposta){
        cout << i << ' ';
    }
}
