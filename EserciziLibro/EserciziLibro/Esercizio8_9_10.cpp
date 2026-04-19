//Esercizio 8, 9, 10 pag 118
// Principi e Pratiche di Programmazione in C++ di Bjarne Stroustrup
// Lorenzo Gemma

#include<iostream>
#include<vector>
#include<string>

using namespace std;

void error(string s);
int somma_num(vector<int> n, int quanti_num);

int main(){
    
    try{
        int quanti_num = 0; // var dove salviamo quanti numeri del vector sommare
        int numero = 0; // input numero
        vector<int> numeri; // vector dove verranno salvati i numeri
        
        cout << "Quanti numeri vuoi sommare?\n";
        cin >> quanti_num; // aggiorniamo quanti numeri
        
        if(!cin){
            // controlliamo che valore sia valido
            error("Valore non valido");
        }
        
        cout << "Somma numeri. Inserisci numeri uno alla volta\n";
        
        while(cin >> numero){
            numeri.push_back(numero); // inseriamo nel vector i numeri
            }
        if(!cin){
            // inseriamo !cin fuori dal ciclo cosi in caso di input errato ciclo termina e
            //viene controllata la condizione
            cin.clear(); // puliamo errore
            char carattere = ' '; // var dove salviamo carattere da controllare se 'l'
            cin >> carattere; //mettiamo il carattere nella variabile
            if(carattere != 'l'){
                error("Valore non valido");
            }
        }
        int risultato = somma_num(numeri, quanti_num); // var che contiene risultato della somma
        cout << "Il risultato della somma dei " << quanti_num << " primi numeri è: " << risultato << '\n';
        }
    
    
    catch(exception& e){
        cerr << "Error: " << e.what() << '\n';
    }
    catch(...){
        cerr << "Errore sconosciuto!\n";
    }
    return 0;
}

void error(string s){
    throw runtime_error{s};
}

int somma_num(vector<int> n, int quanti_num){
    // funzione che restituisce la somma di quanti num nel vector
    // argomenti se vector vuoto errore
    // argomenti se quanti num > vector.size() errore
    // argomenti quanti num è negativo o 0 errore
    // se somma non sta dentro a int dare errore postcondizione
    if(n.size() == 0){
        error("Vector è vuoto errore!");
    }
    else if(quanti_num>n.size()){
        error("Non ci sono abbastanza numeri da sommare");
    }
    else if(quanti_num<= 0){
        error("Serve almeno 1 numero da sommare");
    }
    double somma_d = 0; // salveremo la somma dei numeri in un double
    for(int i = 0; i< quanti_num; ++i){
        somma_d += n.at(i);
    }
    int risultato = somma_d; // passeremo somma_d per controllare che il numero non sia troppo grande per un int
    if(risultato != somma_d){
        error("Valore troppo grande o errato");
    }
    return risultato; // restituiamo risultato
}
