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

### 📂 [NOME NUOVO PROGETTO/CAPITOLO]
*(Spazio per il prossimo aggiornamento...)*
**Esercizi completati:** ...

**Cosa ho imparato:**
- ...
- ...
