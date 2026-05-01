//
//  Morra_Cinese.cpp
//  Altro
//
//  Created by GemmaLogic on 01/05/26.

#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <limits>

using namespace std;

void error(string s);
void controllo_utente(int& valore_risp);
void genera_valore(int& valore_gen);
void confronto(const int& risp, const int& val_gen);
void termina_gioco(bool& ciclo);

int main(){
    try{
        cout << "Morra cinese\n";
        
        bool ciclo = true; // interruttore ciclo
        int valore_risp = 0; // assegneremo un valore a risposta sasso 0 carta 1 forbice 2
        int valore_gen = 0; // valore generato da programma casuale da 0 a 2
        
            while(ciclo){
                controllo_utente(valore_risp);
                genera_valore(valore_gen);
                confronto(valore_risp, valore_gen);
                termina_gioco(ciclo);
            }
            
        
    }
    catch(runtime_error& e){
        cerr << "Error " << e.what() << '\n';
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


void controllo_utente(int& valore_risp){
    
    vector <string> risposte_possibili = {"sasso","Sasso","carta","Carta","forbice","Forbice"};
    // risposte posssibili
    bool ciclo = true; // interrutore ciclo
    string risposta; // creiamo una variabile input
    while (ciclo){
        cout << "Scegli sasso carta o forbice.\n";
        
        cin >> risposta; // input
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // puliamo il cin
        bool controllo = false; // interruttore che controlla se risposta è giusta
        for(string x: risposte_possibili){
            if(x == risposta){
                controllo = true; // usciamo se risposta è corretta
                break;
            }
            
        }
        if(controllo){
            ciclo = false; // usciamo dal ciclo principale
            break;
        }
        else{
            // altrimenti
            cout << "inserisci una risposta valida!\n";
            cin.clear(); // puliamo errore
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // puliamo cin
        }
    }
    
    if(risposta == "sasso" || risposta == "Sasso"){
        valore_risp = 0;
    }
    else if(risposta == "carta" || risposta == "Carta"){
        valore_risp = 1;
    }
    else if (risposta == "forbice" || risposta == "Forbice"){
        valore_risp = 2;
    }
    
    else{
        error("controllo_utente valore_risp null");
        
    }
    
}

void genera_valore(int& valore_gen){
    // creiamo un numero causale e aggiorniamo la nostra variabile che sara la scelta del pc
    static random_device rd;
    static default_random_engine engine(rd());
    uniform_int_distribution<int> distr(0, 2);
    valore_gen = distr(engine); // creiamo num casuale
    switch (valore_gen) {
        case 0:
            cout << "Scelgo sasso!\n";
            break;
        case 1:
            cout << "Scelgo carta!\n";
            break;
        case 2:
            cout << "Scelgo forbice!\n";
            break;
        default:
            error("Genera valore qualcosa è andato storto");
            break;
    }
}


void confronto(const int& risp, const int& val_gen){
    // calcoliamo chi vince!
    int risultato = (risp-val_gen + 3) % 3;
    switch (risultato) {
        case 0:
            cout << "Pareggio!\n";
            break;
        case 1:
            cout << "Hai vinto!\n";
            break;
        case 2:
            cout << "Hai perso!\n";
            break;
            
        default:
            error("confronto valore non valido");
            break;
    }
}

void termina_gioco(bool& ciclo){
    bool giro =true;
    while(giro){
    cout << "Vuoi giocare ancora? (y/n)\n";
    char scelta = ' ';
    cin >> scelta;
        switch (scelta) {
            case 'y':
                cout << "Rigiochiamo!\n";
                giro = false;
                break;
            case 'n':
                cout << "grazie per aver giocato!\n";
                giro = false;
                ciclo = false;
                break;
            default:
                cout << "Risposta non valida!\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
        }
    }
}
