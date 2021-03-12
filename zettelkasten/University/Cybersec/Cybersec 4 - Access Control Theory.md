# Access Control Theory

## Recall questions
    - WIP

## Access Control

### Di cosa si tratta

==Processo di mediazione di ogni richiesta di accesso== alle risorse e i dati mantenuti dal sistema per verificare se deve essere approvata o negata.

All'interno del corso viene usato il seguente modello semplificato:
- insert image here (vedi pg 12)

È importante notare come l'access control sia una pratica ==adottata a vari livelli==
- i.e. a livello di network
- oppure a livello di applicazione $\ldots$

### 3 Pillars dell'access control

I 3 elementi chiave sono:
- ==authentication==: specifica privilegi e diritti d'accesso
- ==authorization==: specifica quali priviligi e diritti d'accesso sono concessi a una data identità (?)
- ==accounting==: raccoglie tutte le azioni relative alla sicurezza per poterle analizzare e eventualmente segnalare all'admin

È inoltre fondamentale definire identità

### Policies di sicurezza

Una polizza di sicurezza stabilisce ...

Ogni polizza determina quando i ==soggetti== possono accedere a certi ==oggetti==, ovvero dispongono di 
==permessi di accesso==.

Tipologie di access control:
- DAC o ==Discretionary==
- MAC o ==Mandatory==
- RBAC o ==Role Based==
- ABAC o ==Attribute Based==

Queste polizze non sono mutualmente esclusive e possono essere combinate.

## Access matrix

### Framework per la gestione degli accessi

Una matrice di accesso fornisce un ==framework== per descrivere gli stati di protezioni in un access control system. (?)

### Capabilities

.....

### Access control list

Le ACLs sono comunemente usate per implementare delle matrici di accesso.
Corrispondo infatti ad una colonna nella matrice degli accessi.

### ACLs vs Capabilites

Le ACLs si basano su una ==visione ad oggetti== della matrice di accesso: ogni entry ..
Sono usate sui sistemi Linux / UNIX.

Le Capability List sono usate invece in configurazioni distributite...

## Permissions Management

### Assegnare permessi

Approccio DAC: gestito dal singolo

Approccio MAC: gestito da ==autorità centralizzata==

### Discretionary access control

I permessi sono gestiti dal ==possessore della risorsa==. È un approccio flessibile ma che rende difficile revocare o cambiare permessi.

### Mandatory access control

I permessi sono gestiti da ==autorità centralizzata==. È un approccio inflessibile e moltro granulare, per questo ha alto overhead.
