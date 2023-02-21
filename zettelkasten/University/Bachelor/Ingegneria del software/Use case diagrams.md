# Use case diagrams 
## Recall questions
    - Cosa specificano gli UCD? Cosa mostrano e quale valenza hanno? 
    - Come conviene realizzare gli UCD? Vanno inclusi anche i NFR? 
    - Cosa si ottiene al termine della creazione degli UCD? 
    - A cosa serve modellare i confini del dominio? 
    - Come si rappresentano gli attori? Come comunicano col sistema e che tipologie di attori ci sono? Un attore può ricoprire più ruoli? Se sì, cosa conviene fare? 
    - Come si rappresentano gli UC? Cosa indicano, a seconda della tipologia di attore? Perchè uno UC dice cosa fa il sistema ma non come? Come è strutturato uno UC? Che differenza c'è tra pre e post condizioni - ovvero quale delle 2 è più vincolante?  Cosa sono i flussi alternativi? In che forma sono istanziati gli UC? 
    - Di quanti UC e di quanti flussi sono sono istanza gli scenari? Come vengono elaborati? 
    - Che relazione c'è fra attori e UC? Che significa il verso della freccia? 
    - Quali sono le altre 2 relazioni tra UC? Cosa le differenzia? 
    - Quali sono i metodi per realizzare UCD? Perchè entrambi possono essere ripetitivi? 
 
## Use case diagrams
### Panoramica UCD
Specifica
  - le funzionalità del sistema
  - attori - umani o automatici

Mostra
  - funzionalità messe a disposizione degli attori e come questi possono usarle
  - il comportamento del sistema al di là della sua implementazione

È parte del contratto tra committente e implementatori del sistema

### Realizzare gerarchie di UCD

Usare gerarchie di UCD che mostrano funzionalità ad alto livello
    - Ampliare poi i singoli UCD in dettaglio per evitare confusione
  
Assegnare un ID ad ogni UC 

Includere esclusivamente i requisiti funzionali 

### Processo indotto da UCD
La creazione di gerarchie di UCD permette di:
  - ricavare i requisiti funzionali - use cases
  - identificare gli stakeholders - attori
  - definire relazioni tra attori - specializzazione
  - definire relazioni tra use cases - specializzazione, include e extend
  - documentare in forma tabellare i requisiti funzionali del sistema


Al termine di questo processo è possibile mappare ciò che è stato ricavato ad un diagramma UML per la fase di design

### Determinare i confini del sistema
Utile per non modellare entità al di fuori del dominio
- fase raramente inclusa

Rappresenta graficamente, all'interno di un rettangolo, tutti gli UC del sistema
- gli attori sono posti fuori

### Determinare gli attori
Rappresentati tramite stickman
  - anche se non umani - e.g. altri sistemi
  
Se implementati in una organizzazione pre esistente probabilmente sono già esistenti e vanno solo definiti

Indica insieme di ruoli che un utente assume in un dato UC
- un utente può assumere ruoli diversi in vari UC
  
Comunicano col sistema tramite messaggi
  - primari per attori attivi - funzioni proprie del sistema
  - secondari per attori passivi - fruiscono di informazioni o notifiche generate da use cases
  - gli attori possono essere attivi o passivi in UC diversi
  
Sono sempre al di fuori del sistema
- se vi è ambiguità oggetto o attore bisogna definire bene il sistema in primis

È possibile esprimerli in termini di generalizzazione quando più attori svolgono gli stessi ruoli
 - tramite un estensione indicata con una freccia vuota verso il padre

### Determinare gli UC
-Rappresentati tramite ellissi
  - hanno un nome che ne indica la funzionalità e un ID dal punto di vista dell'attore
      - e.g. report emergency (attore) e non record emergency (sistema/database)
  - hanno una breve descrizione dello scopo e ruolo dell'UC

Rappresentano i requisiti funzionali del sistema
  - descrivono insiemi di sequenze di azioni che il sistema segue per fornire agli attori risultati osservabili significativi
  - descrivono le azioni necessarie per erogare un servizio mostrando come sistema e attore interagiscono

Descrivono cosa fa un sistema - non come lo fa
  - tramite attori che lo iniziano ed altri che vengono poi coinvolti
  - tramite un flusso di eventi in formato di testo o activity/sequenze
  - tramite degli stati definiti da pre e post condizioni 
      - pre condizioni = stato in cui si trova il sistema prima dello use case
      - post condizioni= possibili stati di arrivo dopo il flusso di eventi dello UC


Flusso di eventi
  - principale - descrive funzionamento normale
  - alternativi - usati per descrivere situazioni eccezionali/irregolari
  
Gli use case sono poi ampliati in scenari 
- ovvero gli scenari sono istanze di use cases
  
### Realizzare scenari 

Istanze di UC sotto forma di descrizioni narrative

Ogni scenario è istanza di un singolo flusso possibile di uno UC
- non riportano infatti delle decisioni
  
Tipologie di scenari
  - AS-IS - illustrano situazioni attualmente possibili
  - Visionary - descrivono un sistema futuro
  - Evaluation - descrivono un compito di un utente in modo da poter valutare (l'efficienza) il sistema
  - Training - mostrano come introdurre nuovi utenti nel sistema

 Vanno descritti con termini di dominio e usati/comprensibili dal cliente
 
 Vengono creati facendo riferimento alle informazioni ottenute tramite la requirements elicitation

### Determinare relazioni tra attori e UC
Attori e UC sono connessi mediante relazioni di associazione
  - unica relazione possibile
  - ha un verso espresso tramite freccia per indicare quale attore inizia la comunicazione (?)
      - se la comunicazione iniziale avviene da entrambi i lati le frecce sono omesse
      - se la comunicazione prevede una risposta, non è necessario inserire una freccia nella parte che inizia

Gli attori attivi iniziano lo use case e quelli passivi ricevono i risultati

### Determinare relazioni tra UC
Tipologie principali
  - Generalizzazione
  - Inclusione
  - Estensione
  - Realizzazione

Generalizzazione - generalizza più UC
  - ogni UC figlio però viene eseguito esclusivamente - e.g. non in maniera concorrente con gli altri

Inclusione - UC include comportamento dell'altro
  - rappresentata da una linea tratteggiata con stereotipo <<include>> sopra
  - a volte può essere considerato come una precondizione
  - e.g. una funzione che ne chiama altre due 
  
Estensione - UC estende un altro UC se il primo dei due potrebbe includere il secondo, date certe condizioni
  - rappresentata da una linea tratteggiata con stereotipo <<extends>> sopra
  - permette di generalizzare gli UC e escludere comportamenti speciali
  - e.g. inclusione: respirare necessita della circolazione del sangue
  - e.g. estensione: farsi belli per uscire estende lo use case prepararsi per uscire, ma solo se abbiamo un appuntamento

### UC case centrici vs actor centrici
Case centric - identifica tutti gli attori per ogni UC
  - molto ripetitivo
  
Actor centric - identifica tutti gli UC per ogni attore
  - ripete ogni UC che coinvolgono più attori

