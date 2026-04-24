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
void trova_toro(const vector<int>& risp, const vector<int>& segr, int& toro);
void trova_mucca(const vector<int>& risp, const vector<int>& segr, int& mucca);
int main(){
    
    try{
        cout << "Trova il numero segreto di 4 cifre. se indovini numero e posizione: (toro) solo numero: (mucca) \n";
        
        vector<int> risposta; // salveremo l'input per poi confrontarlo con segreto
        vector<int> segreto = {1,2,3,4}; // vector in cui è salvata la sequenza da trovare
        bool in_funzione = true; // indica che il ciclo è in funzione
        int toro = 0; // salveremo toro
        int mucca = 0; //salveremo mucca
        
        while(in_funzione){
            
            controllo_utente(risposta);
            trova_toro(risposta, segreto, toro);
            trova_mucca(risposta, segreto, mucca);
            cout << "Hai trovato " << toro << " toro e " << mucca << " mucca\n";
            if(toro == 4){
                in_funzione = false;
            }
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
    risposta.clear(); // resettiamo il vector ad ogni giro
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
            
            for(int i = 0; i < risposta.size(); ++i){
                // controlliamo che i numeri siano diversi
                if(risposta.at(i) == temporanea){
                    // stampiamo
                    cout << "Hai gia inserito " << risposta[i] << " sostituiscilo con un numero valido\n";
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

void trova_toro(const vector<int>& risp, const vector<int>& segr, int& toro){
    // resettiamo toro ad ogni giro
    // argomenti se num in risposta è uguale e nella stessa psoizione toro agg
    toro = 0;
    for(int i = 0; i < risp.size(); ++i){
        // ciclo controlliamo sia posizione sia se sono uguali
        if(risp.at(i) == segr.at(i)){
            ++toro; // incrementiamo toro
        }
    }
}

void trova_mucca(const vector<int>& risp, const vector<int>& segr, int& mucca){
    mucca = 0; // resettiamo mucca ad ognio giro
    for(int i = 0; i < risp.size(); ++i){
        // ciclo passiamo ogni elemento di risp
        for(int x = 0; x < segr.size(); ++x){
            // ciclo passiamo ogni elemento di segr
            if(risp.at(i) == segr.at(x) && risp.at(i) != segr.at(i)){
                // se elemento di risp è uguale a elemento di segr e non è nella stessa posizione
                ++mucca; // incrementiamo mucca
            }
        }
    }
    
}
