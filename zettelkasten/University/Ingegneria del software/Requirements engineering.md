  # Requirements engineering

  ## Recall questions
    - Cosa sono i requisiti?
    - Cosa sono i requisiti funzionali e non? 
    - Quali sono i 4 step fondamentali del processo di analisi dei requisiti?
    - A cosa bisogna fare attenzione quando si individuano i requisiti? 
    - Come si chiama il processo di richiesta dei requisiti? Cosa bisogna individuare? 
    - Quali sono problemi comuni della scoperta di requisiti? 
    - Quali sono i metodi per scoprire i requisiti? E le euristiche?
    - Chi sono gli stakeholders? Perchè sono importanti?
    - È possibile classificare i requisiti? 
    - Quali sono le 4 modalità di specifica dei requisiti? 
    - Quali problemi sono comunemente legati ad esprimere i requisiti in linguaggio naturale? 
 

## Requirements Engineering Introduction
### Requisiti: di cosa si tratta  
 Definisce  servizi richiesti dal cliente  

 Definisce  qualità del sistema e i suoi servizi 

 Definisce i vincoli entro cui i primi due operano
### Terminologia 
 Servizi =  requisiti funzionali 

 Qualità =  requisiti non funzionali 

 Constraints =  vincoli di sistema 
###  Requisiti funzionali e non 
Funzionale =  indica  quali servizi il sistema deve garantire , come deve comportarsi per certi input e situazioni
  - A volte indicano anche cosa il sistema non deve fare
  - Spesso comunicati in linguaggio naturale
  - Devono essere più dettagliati possibile
  
Non funzionali =  non legati al sistema 
  - E.g. tempo, standards, tecnologie da usare, integrazione con altri sistemi
  
###  Requisiti imprecisi, completi e consistenti 
 Requisiti imprecisi possono portare a incomprensioni 

 Requisiti  completi  i ncludono descrizioni di tutte le funzioni che servono 

Requisiti  consistenti non hanno contraddizioni 
## Requirements elicitation
###  Requirements elicitation: di cosa si tratta  
 Lo staff tecnico lavora con i clienti per indagare il  dominio applicativo , i  servizi necessari  e i  costraints operazionali   del sistema
 
 È un processo  ciclico 

 Può essere di varie tipologie
 - greenfield: primo progetto di quel tipo
 - interface engineering: parte da servizi di un nuovo ambiente o richieste di nuovi mercati
 - re-engineering: reimplementazione di vecchi sistemi

Step: 
- discovery
- classification and organization
- prioritization and negoziation

###  Problemi comuni scoperta requisiti 
 Gli stakeholder non sanno cosa vogliono, si esprimono a parole loro o cambiano e i nuovi hanno  interessi conflittuali 

In generale i requisiti  cambiano nel tempo 
- Per questo è bene essere specifici e mettere tutto su carta in anticipo
###  Metodi di scoperta dei requisiti 
Questionari  e  interviste  con il cliente

Etnografia  = osservazione degli utenti

 Feedback utente e scenari   =  storie astratte  di come il sistema può essere realmente usato 
- Possono essere completati da una presentazione, testo, immagini
- Devono avere un  punto di inizio, flusso normale di eventi  e  gestione di possibili errori 
-  Use cases  = non inquadrano solo il problema ma tutta la situazione

###  Eurisitiche di ricerca dello scenario  
Domande :
 -  Cosa fa  il sistema
 -  Quali dati  deve manipolare
 - Influenza di cambiamenti esterni sul sistema
 - Informazioni necessarie all'utenza

Questionari

Osservazione  

###  Gli stakeholders 
Esistono vari tipi di stakeholders
  - utenti finali
  - manager di sistema
  - proprietari del sistema
  - stakeholder esterni (e.g. partners compagnia)

Sono tutti  persone che vengono influenzate o/e devono usare il sistema 
## Requiriments Classification & Organisation
###  Di cosa si tratta 
  Classificare i requisiti sotto vari campi 

 Tassonomia requisiti non funzionali
- Requisiti del prodotto
- Requisiti organizzativi
- Requisiti estrerni
###  Sistematizzazione del processo organizzativo  
 È utile usare dei tool e avere template che  sistematizzano la definizione e l'organizzazione dei requisiti 
## Requirements Prioritization and Negotiation
###  Priorità dei requisiti 
Alcuni requisiti sono più importanti
-  Altà priorità  = definiti durante analisi, design e in implementazione,  vanno mostrati al cliente 
-  Media priorità  = definiti durante analisi e design e mostrati dopo
-  Bassa priorità  = definiti durante analisi
    - Spesso si tratta di potenzialità future del sistema
###  Requirements negotiation 
 Processo di  discussione dei requisiti con il committente e di chiarimento di punti di incertezza 
## Requirements specification
###  Modalità di documentazione dei requisiti 
- Linguaggio  naturale  o  naturale strutturato  - la versione strutturata prevede la presenza di un template a cui fare riferimento
-  Linguaggi di specifica dei requisiti  - raramente usato, fa uso di linguaggi (come nel caso della programmazione) per definire ad alto livello i requisiti
-  Notazione grafica  -uso di diagrammi e disegni corredati da testo esplicativo, come in  UML 
-  Specifica matematica   - difficile da spiegare al committente in quanto si basa su  FSA  (Finite State Automata)
###  Problemi del linguaggio naturale 
 Definizioni poco chiare dei requisiti 
  
 Requisiti funzionali e non mischiati o espressi insieme 

Multipli requisiti espressi insieme  