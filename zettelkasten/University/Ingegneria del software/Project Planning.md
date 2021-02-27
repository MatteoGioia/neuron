# Project Planning
## Recall questions
    - Cosa si decide nella fase di agreement?  Cosa viene prodotto? 
    - Come si crea la lista delle task?  Quali tipologie (macro) di tasks esistono? 
    - Quali sono le figure chiavi di un team di sviluppo? 
    - In cosa consiste lo scheduling delle tasks? 
    - Cosa è il WBS? Quali sono i 2 metodi principali e che differenze ci sono? Si possono usare entrambi nello stesso progetto?
    - Come si può fare una stima rapida e informale dei costi?
    - Quali sono i metodi informali di stima dei tempi? Quelli formali? 
    - Quali sono i ruoli esterni al progetto di cui tenere sempre conto? 
    - Quali sono i metodi più comuni per prendere decisioni riguardanti il progetto? 
    - In cosa consiste il risk management? 


## Fase pre-progettuale
### Agreement
Decisione su carta dei criteri di successo
- ben definiti, dare garanzie

Focus su uno tra Money,Time and Quality

Viene creato un Project initiation Document
- Data, Versione e Autore
- Descrizioni precise di tempistiche, servizi e costi


### Lista delle task
Brainstorming - buttare giù le idee di ogni fase progettuale

Breakdown del lavoro - organizzazione gerarchica delle task
        - indicare dipendenza di alcune task da altre
        - individuare tipologia

Tipologie di task
- sviluppo sw - software o oggetti necessari per lo sviluppo sw
- acquisizione di hw - hw necessario per il progetto
- administrative tasks - e.g. ottenere permessi
- communication tasks - e.g. parlare con cliente

Ask an expert - consigli di esperti 

### Assemblare un team
Team leader - prende le decisioni

Designer - potenzialmente più di uno , e.g. per UI, UX e così via

Client-side developer - si occupa di realizzare interfaccia lato client (UI)

Server-side developer - si occupa del lato server 

Database admin - facoltativo, se il progetto è molto grande si occupa lui del database

## Fase organizzativa
### Scheduling
Schedule del lavoro - identificare task e creare Work Breakdown 
- associare a ogni task le risorse necessarie
- creare un calendario con le task da portare a termine

Costi - identificare costo delle task (task/hr) 

Identificazione delle dipendenze tra tasks - se già fatta basta copiare quella iniziale

Processo che si può reiterare all'occorrenza

### Work Breakdown Structure
Riguarda le task - idealmente si crea a partire dalla loro rappresentazione gerarchica

Path critici - punti di sviluppo cruciali
- se fatti in ritardo, posticipano l'intero progetto
- dare priorità a fronte invece di quelli a cui si può levare tempo, indicati da un TF (total float)

Carta di Pert - Program evaluation and Review tecnique  (DOMANDA ???)
- usata per trovare dipendenze e tempo minimo per lo scheduling
- ideale per ogni taglia di progetto 
   
Carta di Gantt  - versione "potenziata" di una pert chart
- mostra dipendenze temporali
- mostra task sul calendario
- alloca risorse per le task
- utile per progetti molto grandi
           
### Stima dei costi
Metodo informale - stima a metà tra il worst case e il caso medio
- usare il caso buono potrebbe essere un lower bound troppo lasco - e.g. nella realtà le cose tendono verso più uso del budget

### Tecniche di stima dei tempi 
Legge di Parkinson - il lavoro si espande per occupare tutto il tempo a disposizione

Metodi informali - guidati da esperienza e altro
  - Giudizio di un esperto - poco costoso ma efficace solo se l'esperto ha esperienza con progetti simili
  - Stima tramite analogia - efficace solo se sono stati svolti progetti simili, può inoltre essere inaccurata se i progetti sono abbastanza differenti
  - Metodo delphi - unisce un gruppo di esperti bilanciati da un moderatore
      - gli esperti creano stime singolarmente e il moderatore le colleziona
      - il moderatore esprime le stime senza fare i nomi e eventualmente ne vengono generate nuove
      - il processo continua fino al consenso unanime

Metodi formali - guidati da equazioni matematiche/ algoritmi
  - modello EFFORT - tiene conto delle linee di codice, bilanciato su fattori come dependability ed esperienza del team
      - infatti poche linee di codice possono richiedere molto tempo per essere perfezionate
  - modello COCOMO - ricava il tempo come k(PM)^n, dove PM sono le persone per mese impiegate a lavorare sul progetto
      - PM viene deciso come $k(KDSI)^m$, dove KDSI sono migliaia di source instructions da consegnare


### Definizione ruoli (anche esterni)
Sponsor - chi sponsorizza il progetto

Business experts - analizzano e approvano le stime su tempi e costi

Project manager e team - già decisi prima

End users

### Metodi decisionali
Brainstorming - tutti partecipano fornendo idee fino ad arrivare al consenso

Voting - sono fornite delle alternative, ognuna sottoposta a votazione

Delphi - come mostrato prima ma sotto forma di questionario
        - permette meno bias

Consensus selection - si punta ad ottenere il massimo consenso a fronte delle alternative proposte

AHP - progetto modellato sotto forma di goals
### Risk management
Identificare i rischi e pianificare delle soluzioni in anticipo

Rischi a livello di sw ma anche di risorse (e.g. hw, tempo e soldi)

