# Different Kind of Speed

## Recall questions 
    - Cosa differenzia una strategia da una tattica. Perchè per ottenere velocità possiamo usare più tattiche?
    - Quali sono 4 metodi per ottenere velocità comunemente usati? HINT: Agile+Runway, SPL, Code Gen, Early Feedback
    - Spiegare con un case study perchè esistono tipi di velocità diverse.
    - Cosa è il debito tecnico? Quali sono le 3 tipologie (1 extra)? Perche il debito tecnico è invisibile?  

## Strategia versus tattica

### Strategie e tattiche

==Strategia== può essere conseguita tramite ==diverse tattiche==.

Nel nostro caso la strategia di ==incrementare la velocità== è raggiunta tramite l'uso di ==agile methods== come tattica.

Le principali tattiche per incrementare la velocità sono:
- uso di ==metodi agili==
- creazione di una ==software product line==
- uso di ==tool per code generation==
- uso di ==modelli eseguibili orientati a feedback==

### Software Product Line

Il focus è sulla ==famiglia e le lineee di prodotti==, come ad esempio fa Apple: si identificano dei ==core assetts== comuni a più membri possibili. Lo scopo è infatti risparmiare (tempo e denaro).

Ogni linea di prodotto è poi comunque sviluppata in modo specifico adattando i core assets al caso.

Sul lungo periodo è una strategia molto efficace in quanto permette di riusare pesantemente features già proposte nella famiglia, ma sul breve periodo non è abbastanza veloce.

![](./static/Agile/spl_speed.png)
 
### Agile methods with architecture runway

Idea: unire la capacità di essere ==pronti a rispondere== dei metodi agili con il ==supporto di architetture ben fatte==.

Non basta infatti integrare continuamente nuove feature ma bisogna evitare che si accumuli troppo ==debito tecnico== nell'architettura (vedi sotto).

### Code generation

Uso di tool per generare il codice in automatico ad esempio in base ad una data architettura.

### Modelli eseguibili orientati a feedback nel breve periodo

Abbreviazioni:
- MIL: model in the loop, ossia modello testato nell'ambiente modellizzato stesso
- SIL: verifica del modello ma nel codice
- HIL: effettivo test di integrazione con piattagora reale\

Gli ultimi due step aumentano velocità in quanto spesso sono automatizzati tramite ==Virtual continuos integration==.

## Tipi di velocità

Ci sono diversi tipi di velocità, in quanto ogni ==situazione di mercato== richiede una velocità diversa per massimizzare il guadagno (ad esempio):
- ==first deployment speed==: tempo impiegato a entrare sul mercato
- ==replication speed==: tempo impiegato a replicare un prodotto che ha avuto successo
- ==evolution speed==: minore delle due, è il tempo necessario a aggiornare prodotti già esistenti.

È importante dunque valutare accuratemente il business case per adattare la strategia che massimizza la velocità "corretta".

### Case Study

Vediamo come 3 aziende, in ambito diverso, abbiano necessità di 3 tipi di velocità diversa:
- automotive: mercati non sincronizzati, possibile riuso di codice e dell'interfaccia già creata
- difesa: mercato lento (i.e. un prj per volta), possibilità di creare buon codice da riusare
- telecomunicazioni: architettura che deve tenere conto del variability management

Questo studio ha mostrato che:
- ==bilanciare gli sforzi== è meglio di fare sforzi selettivi
- ==mancanza di comunicazione== penalizza velocità e agilità in generale al di là del mercato
- ==support architecture==: la velocità in riuso prevede una ==integrazione e gestione della variabilità== ben fatti
- ci sono areee come prioritizzazione e outsorcing che richiedono particolare considerazione

## Il debito tecnico

### Tipologie di debito tecnico

Il debito tecnico è (S. McConnell):
>Un approccio al disegno o alla costruzione che rende rapido lo sviluppo al momento ma che produce rallentamenti tecnici in seguito ben maggiori di quanto tempo sarebbe necessario per sistemare tali scelte.

Esistono diverse tipologie di debito tecnico:
- ==non intenzionale==: guidato da pessime decisioni e codice scritto male
- ==intenzionale==: sfruttato per ottimizzare per il presente e che viene poi estinto nel breve periodo con i refactorings o nel lungo periodo.

Il grosso problema del debito tecnico è che è ==apparentemente invisibile== in quanto si scopre quando si ad esempio a implementare nuove feature.

Purtroppo esiste debito tecnico ==non prevedibile==, ad esempio a causa di un cambiamento imprevisto dell'ambiente che rende decisioni ottimali precedenti ora sub-ottimali.

