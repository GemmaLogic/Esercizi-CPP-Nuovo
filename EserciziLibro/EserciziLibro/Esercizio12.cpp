//Esercizio 11 pag 118
//Implementate un giochino di indovinelli chiamato (per qualche oscuro motivo) "Tori e Mucche". Il programma ha un vector di quattro numeri interi diversi nell'intervallo da 0 a 9 (ad esempio, 1234 ma non 1122) e il compito dell'utente è quello di scoprire questi numeri attraverso ripetute ipotesi. Supponiamo che il numero da indovinare sia 1234 e che l'utente provi con 1359; la risposta dovrebbe essere "1 toro e 1 mucca" perché l'utente ha indovinato una cifra (1) giusta e nella posizione giusta (un toro) e una cifra (3) giusta ma nella posizione sbagliata (una mucca). L'indovinello continua finché l'utente non ottiene quattro tori, cioè ha le quattro cifre corrette e nell'ordine corretto.
// Principi e Tecniche di Programmazione in C++ di Bjarne Stroustrup
// GemmaLogic

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void error(string s);

int main(){
    
    try{
        
        
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
