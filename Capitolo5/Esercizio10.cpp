//Esercizio 10 pag 118
// Principi e Pratiche di Programmazione in C++ di Bjarne Stroustrup
// Lorenzo Gemma

#include<iostream>
#include<vector>
#include<string>

using namespace std;

void error(string s);
double somma_num(const vector<double>& n, int quanti_num);
void calcola_diff(const vector<double>& n, vector<double>& diff);
int main(){
    
    try{
        int quanti_num = 0; // var dove salviamo quanti numeri del vector sommare
        double numero = 0; // input numero
        vector<double> numeri; // vector dove verranno salvati i numeri
        vector<double> differenze; // salveremo le differenze come richiesto dall'esercizio
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
        if(quanti_num>numeri.size()){
            error("Non ci sono abbastanza numeri");
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
        double risultato = somma_num(numeri, quanti_num); // var che contiene risultato della somma
        cout << "Il risultato della somma dei " << quanti_num << " primi numeri è: " << risultato << '\n';
        cout << "Il risultato delle differenze sono:\n";
        calcola_diff(numeri, differenze); //calcoliamo le differenze e poniamole nel vector differenze e stampiamo
        for(int i = 0; i<differenze.size(); ++i){
            cout << differenze.at(i) << ' ';
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

double somma_num(const vector<double>& n, int quanti_num){
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
    //int risultato = somma_d; // passeremo somma_d per controllare che il numero non sia troppo grande per un int
    //if(risultato != somma_d){
        //error("Valore troppo grande o errato");
    //}
    return somma_d; // restituiamo risultato
}

void calcola_diff(const vector<double>& n, vector<double>& diff){
    // se n.size()< 2 errore non ci sono abbastanza numeri
    if(n.size()<2){
        error("Non ci sono abbastanza numeri da sottrarre.");
    }
    for(int i = 1; i<n.size(); ++i){
        double d = n.at(i)-n.at(i-1); // valore attuale meno il precedente
        diff.push_back(d); // salviamo la differenza nel vector differenze
    }
    
}
