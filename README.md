# 📘 C++ Percorso: Da Apprendista a Developer
### Repository di Lorenzo G. - Esercizi dal manuale di Bjarne Stroustrup

Benvenuti nella mia "cassaforte" di codice. Questo repository documenta il mio percorso attraverso il libro **"Principi e Tecniche di Programmazione in C++" ** del creatore del linguaggio, Bjarne Stroustrup. 

Non si tratta solo di risolvere problemi, ma di imparare a scrivere codice robusto, sicuro e professionale.

---

## 🛠️ Stack Tecnologico e Obiettivi
- **Linguaggio:** C++ (Standard moderno)
- **Ambiente:** macOS / Xcode / GitHub Desktop
- **Focus:** Programmazione Difensiva, gestione della memoria, architettura pulita.

---

## 🚀 Cronologia dei Progressi

---
### 📂 Capitolo 5 - Gestione degli Errori e Stabilità
**Esercizi completati:** 8 , 9, 10 (Somma di vettori con controlli di sicurezza)(calcolo delle differenze di elementi del vector)

**Cosa ho imparato:**
Invece di scrivere un semplice algoritmo di somma, mi sono concentrato sulla **Programmazione Difensiva**:
- **Gestione Buffer:** Uso di `!cin` e `cin.clear()` per prevenire crash da input errati (es. lettere invece di numeri).
- **Precondizioni (Fail-Fast):** Controlli rigorosi sulle dimensioni del vettore e input logici impossibili.
- **Postcondizioni (Overflow):** Uso preventivo di tipi `double` per intercettare overflow di memoria prima che corrompano il risultato `int`.
- **Utilizzo di const e riferimenti:** Utilizzato const e riferimento per passare un vector in modo da essere solo letto con const e il riferimento per utilizzare lo stesso vector rendendo tutto piu veloce

---
Esercizi completati:** 11 (Trovare int piu grande Fibonacci)

**Cosa ho imparato:**
 La sfida principale è stata intercettare l'overflow prima che il dato venisse corrotto. Ho imparato che la precedenza degli operatori e il casting esplicito sono fondamentali per la sicurezza dei dati.

- **Gestione dell'Integer Overflow** Per individuare il limite massimo della serie di Fibonacci rappresentabile in un int, ho implementato una tecnica di Narrowing Check.

Type Promotion: Ho forzato la promozione esplicita degli operandi a double (static_cast<double>(a) + b) per eseguire il calcolo in uno spazio di memoria a 64-bit, evitando l'overflow silenzioso della CPU.

Validazione: Il risultato viene poi confrontato con la sua "ombra" troncata in un intero; una divergenza tra i due valori segnala il superamento del limite fisico del tipo int.

---
**Esercizi completati:** 12 (Creare un minigioco di indovinelli)

**Cosa ho imparato:**
Ho imparato a gestire piu input utente utilizzando una sola variabile locale temporanea in modo da alleggerire il programma. Creato una funzione che gestiva l'input e i sui casi
- **Variabile temporanea** Uso di una variabile che viene aggiornata con un ciclo per salvare ogni input in un vector.
- **Ciclo bool** Utilizzo di un bool come condizione di un ciclo while in modo da terminare solo se ce una condizione.
- **Bool controllo:** Usato un bool per controllare se un numero è stato ripetuto, in caso di false aggiunto input a vector.
- **Gestione posizione** Controllato posizione di elementi in due vector. Nella prima funzione (trova_toro) è stato controllato se i numeri nelle stesse posizioni fossero uguali. Nella seconda funzione (trova_mucca) è stato controllato se il numero del vector (risposta) era presente nel vector (segreto) ma non nella stessa posizione.

nota: Nel prossimo esercizio verrà aggiunto un sistema di numeri casuali da trovare ad ogni partita.

---
**Esercizi completati:** 13 (Modifica esercizio precedente con aggiunta di motore casuale e prompt termina programma)

**Cosa ho imparato:**
Ho imparato a generare numeri "casuali" in base ad un input utente (come richiesto dall'esercizio) e un sistema che chiede all'utente se vuole rigiocare o terminare il programma
- **Engine** Uso di un motore per generare un numero in base ad un input utente.
- **Distributore** Uso di un distributore per generare numeri nell'intervallo da 0 a 9.
- **Adattamento** e stato creato un sistema che genera numeri mai uguali rispecchiando le condizioni dettate all'input utente.
- **Termina Programma** e stato creata una funzione contenente un ciclo di massimo 3 tentativi in cui veniva chiesto all'utente se voleva rigiocare una partita o chiudere il programma.

---
### 📂 [NOME NUOVO PROGETTO/CAPITOLO]
*(Spazio per il prossimo aggiornamento...)*
**Esercizi completati:** ...

**Cosa ho imparato:**
- ...
- ...
