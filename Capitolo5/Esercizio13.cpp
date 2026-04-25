//Esercizio 13 pag 118
// esercizio 12: Implementate un giochino di indovinelli chiamato (per qualche oscuro motivo) "Tori e Mucche". Il programma ha un vector di quattro numeri interi diversi nell'intervallo da 0 a 9 (ad esempio, 1234 ma non 1122) e il compito dell'utente è quello di scoprire questi numeri attraverso ripetute ipotesi. Supponiamo che il numero da indovinare sia 1234 e che l'utente provi con 1359; la risposta dovrebbe essere "1 toro e 1 mucca" perché l'utente ha indovinato una cifra (1) giusta e nella posizione giusta (un toro) e una cifra (3) giusta ma nella posizione sbagliata (una mucca). L'indovinello continua finché l'utente non ottiene quattro tori, cioè ha le quattro cifre corrette e nell'ordine corretto.
//Esercizio 13: lI programma è un po' noioso, perché la risposta è codificata nel programma. È possibile creare una versione in cui l'utente può giocare più volte (senza fermare e riavviare il programma) e ogni partita ha una nuova serie di quattro cifre. È possibile ottenere quattro cifre casuali chiamando il generatore di numeri casuali random_int (0,9) da PPP_support (e §4.7.5) per quattro volte. Noterete che il programma eseguito più volte sceglierà la stessa sequenza di quattro cifre a ogni avvio. Per evitare che ciò accada, chiedete all'utente di inserire un numero (qualsiasi numero) e chiamate seed (n), sempre da PPP_support, dove n è il numero inserito dall'utente prima di chiamare random_int(0,10). Questo n è chiamato seme, e semi diversi danno sequenze diverse di numeri casuali.
// Principi e Tecniche di Programmazione in C++ di Bjarne Stroustrup
// GemmaLogic

#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <limits>

using namespace std;

void error(string s);
void controllo_utente(vector<int>& risposta);
void trova_toro(const vector<int>& risp, const vector<int>& segr, int& toro);
void trova_mucca(const vector<int>& risp, const vector<int>& segr, int& mucca);
void genera_segreto(vector<int>& segr);
void termina_programma(bool& in_funzione);
int main(){
    
    try{
        cout << "Trova il numero segreto di 4 cifre. se indovini numero e posizione: (toro) solo numero: (mucca) \n";
        
        vector<int> risposta; // salveremo l'input per poi confrontarlo con segreto
        vector<int> segreto;; // vector in cui è salvata la sequenza da trovare
        bool in_funzione = true; // indica che il ciclo è in funzione
        int toro = 0; // salveremo toro
        int mucca = 0; //salveremo mucca
        
        
        while(in_funzione){
            genera_segreto(segreto);
            while(in_funzione){
                
                controllo_utente(risposta);
                trova_toro(risposta, segreto, toro);
                trova_mucca(risposta, segreto, mucca);
                cout << "Hai trovato " << toro << " toro e " << mucca << " mucca\n";
                if(toro == 4){
                    break;
                }
            }
            termina_programma(in_funzione);
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
    cout << "Inserisci 4 int separati compresi tra 0 e 9 e non ripeterli\n";
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
void genera_segreto(vector<int>& segr){
    segr.clear(); // ogni partita partirà con segr vuoto
    
    cout << "Immetti un numero per generare il codice segreto\n";
    int n = 0; // salveremo input utente
    cin >> n; // input
    
    if(!cin){
        // errore se input diverso
        error("Valore non valido\n");
    }
    else{
        bool trovato = false; // interruttore true: numero gia presente in segr false: non presente
        bool in_funzione = true; // interruttore che indica che il ciclo è in funzione
        int temporanea = 0; // salveremo il valore "casuale"
    default_random_engine engine(n); // chiamiamo il nostro motore e passiamo come seed n
    uniform_int_distribution<int> distr(0,9); // diciamo al nostro distributore di generare numeri da 0 a 9
        
        while(in_funzione){
            trovato = false; // resettiamo interruttore ad ogni giro
            temporanea = distr(engine); // generiamo numero "casuale"
            for(int i = 0; i < segr.size(); ++i){
                // ciclo che passa in rassegna ogni elemento di segr
                if(segr.at(i) == temporanea){
                    // se elemento di segr è uguale al nostro numero
                    trovato = true; // interruttore true e verra ripetuto tutto
                    
                }
            }
            if(trovato == false){
                // se interruttore è false inseriamo nel vector segr
                segr.push_back(temporanea);
            }
            if(segr.size() == 4){
                // quando segr avra 4 elementi ciclo while finisce
                in_funzione = false;
            }
        }

    }
    
}



// dare modo all utente che ogni fine partita se vuole rigiocare o terminare il programma

void termina_programma(bool& in_funzione){
    int num_giro = 0; // contatore giri
    bool giro = true; // interruttore ciclo
    char risposta = ' '; // salviamo l input utente
    while(giro){
        // finche ciclo in funzione possiamo scegliere se rigiocare
        cin.clear(); // spegniamo errore nel cin
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // puliamo il cin
    cout << "Vuoi giocare ancora? (y/n)\n";
    
    cin >> risposta; // input
        switch (risposta) {
            case 'y':
                cout << "Rigiochiamo!\n";
                giro = false; // usciamo
                break;
            case 'n':
                cout << "Grazie per aver giocato!\n";
                giro = false; // usciamo
                in_funzione = false; // chiudiamo programma
                break;
                
            default:
                cout << "Valore non valido!\n";
                break; // ripetiamo il ciclo
        }
        ++num_giro; // ad ogni giro di ciclo aumentiamo num_giri
        if(num_giro >= 3){
            // se num_giri è 3 o maggiore
            cout << "Grazie per aver giocato!\n";
            giro = false; //usciamo
            in_funzione = false; // chiudiamo programma
        }
    }
    
}
