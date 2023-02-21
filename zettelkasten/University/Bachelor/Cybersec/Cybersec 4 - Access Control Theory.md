# Access Control Theory

## Access Control

### Di cosa si tratta

==Processo di mediazione di ogni richiesta di accesso== alle risorse e i dati mantenuti dal sistema per verificare se deve essere approvata o negata.

All'interno del corso viene usato il seguente modello:
- il reference monitor si occupa di verificare l'identità
- si occupa anche di controllare le autorizzazioni definite in base alle policies presenti
![acl_simplified](../../../CYS/acl_simplified.png)

È importante notare come l'access control sia una pratica ==adottata a vari livelli==
- i.e. a livello di network 
- oppure a livello di applicazione  

### 3 Pillars dell'access control

I 3 elementi chiave sono:
- ==authentication==: verifica dell'identità dell'utente
- ==authorization==: specifica quali priviligi e diritti d'accesso sono concessi a una data identità (?)
- ==accounting==: raccoglie tutte le azioni relative alla sicurezza per poterle analizzare e eventualmente segnalare all'admin

È inoltre fondamentale definire identità

### Policies di sicurezza

Una polizza di sicurezza stabilisce ==un set di regole== per determinare chi ha accesso a determinate risorse.
Inoltre, descrive anche ==stati di protezione== accettabili in un access control system.  

Ogni polizza determina quando i ==soggetti== possono accedere a certi ==oggetti==, ovvero dispongono di 
==permessi di accesso==.

Tipologie di access control:
- DAC o ==Discretionary==: (authorization based) le polizze di accesso sono basate sull'identità del richiedente e su regole che descrivono cosa i vari tipi di richiedente possono o non possono fare
- MAC o ==Mandatory==: funziona comparando dei ==security labels== con i ==security clearances== al momento vigenti.
- RBAC o ==Role Based==: simile l DAC ma i permessi sono garantiti in base ai ruoli (i.e. un'identità può avere più ruoli associati)
- ABAC o ==Attribute Based==: basate su attributi dell'utente, le risorse a cui si vuole accedere, le regole di accesso e le correnti condizioni ambientali (*needs further clarification*)

Queste polizze non sono mutualmente esclusive e possono essere combinate.

## Access matrix

### Framework per la gestione degli accessi

Una matrice di accesso fornisce un ==framework== per descrivere gli stati di protezioni in un access control system. 

![ac_matrix](../../../CYS/ac_matrix.png)

### Capabilities

Enumerano la ==lista delle risorse== a cui un soggetto ha accesso e i ==poteri di accesso== che quell'utente ha.

Corrispondono alle ==righe== della matrice di accesso. 

### Access control list

Le ACLs sono comunemente usate per implementare delle matrici di accesso ed enumerano, per ogni ==identificatore di risorsa==, ==quali soggetti== possiedono poteri di accesso.

Corrispondo infatti alle ==colonne== nella matrice degli accessi.

### ACLs vs Capabilites

Le ACLs si basano su una ==visione ad oggetti== della matrice di accesso: ogni entry specifica, per un dato oggetto (risorsa), gli utenti che hanno accesso e quali permessi hanno.
Sono usate sui sistemi Linux / UNIX.

Le Capability List si basano su una ==visione a soggetto== della matrice di accesso e sono usate in configurazioni distributite.

È importante notare che le ==ACL sono più restrittive==, in quanto è il ==solo proprietario della risorsa== che ha ==diritto di garantire, revocare o diminuire i diritti di accesso== a quest'ultima.

## Permissions Management

### Assegnare permessi

Approccio DAC: gestito dai ==soggetti della matrice==.

Approccio MAC: gestito da ==autorità centralizzata==

### Discretionary access control

I permessi sono gestiti dal ==possessore della risorsa==. È un approccio flessibile ma che rende difficile revocare o cambiare permessi. 

### Mandatory access control

I permessi sono gestiti da ==autorità centralizzata==. È un approccio inflessibile e moltro granulare, per questo ha alto overhead.
