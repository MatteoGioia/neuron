# No Big Upfront 

## Recall questions
    - Cosa è l'idea di no big upfront? Come viene applicata ai metodi agili?
    - Come viene effettuata l'elicitazione dei requisiti nei metodi agili? Hint: sparisce quasi..
    - Quali sono le problematiche legate a fare elicitation lunghe e complesse?
    - Cosa si può fare per velocizzare la fase di ricerca dei requisiti senza renderla inaccurata? Light PreDev + Accurate PostDev
    - Cosa succede all'architettura di un progetto con il passare del tempo? È inevitabile?
    - Quali sono gli antipattern identificati dai metodi agili nei modi classici di progettare le architetture?
    - Come fanno i metodi agili a produrre architetture continuamente al passo con i tempi? Cosa è il refactoring?

## No Big Upfront Requirements

### Requiments elicitation nei metodi agili

L'analisi dei requisiti nei metodi agili ==non prevede== una fase iniziale di analisi o design immutabile per il resto del progetto, ma tutto il lavoro avviene in cicli ripetuti nello sprint. 

Uno dei motivi è proprio ==evitare di produrre grandi quantitativi== di documentazione.
- *Think Lean*

È anche vero però che esistono ==proprietà del dominio==: queste non cambiano nel tempo e possono essere fissate anche subito.

È problematica anche la progettazione in ambito ==safety critical==, dove spesso molte decisioni devono essere prese all'inizio del processo di sviluppo.

### Problematiche legate a Elicitation complesse  

Le problematiche più comuni legati a processi di Elicitation articolati sono varie:
- processi ==document centric== sono lenti e i cambiamenti sono comunque spesso notificati in primo luogo tramite comunicazione diretta
- rigidità nei casi di progetti ==safety critical==
- requisiti ==immutabili==: una volta fatta la fase i requisiti sono congelati fino alla fine, inoltre si è vincolati a soddisfare requisiti che si potrebbero rivelare molto complessi in seguito
- ==isolamento dei gruppi==: bisogna coordinare ingegneri e programmatori e fare in modo che tali requisiti siano ==strutturati e organizzati== per facilitare il lavoro del programmatore.
- requisiti ==difficili da testare== prima di implementarli

### Allineare requisiti e testing automatizzato

Un elemento chiave dei metodi è effettuare testing più che raccogliere in modo sistematico i requisiti.

Il testing deve soprattutto ==testare i corner cases==: tutti quei casi "particolari" ma in cui il sistema deve comunque funzionare.

### Lightweight pre-dev RE and precise post-dev specification

L'idea è quella di realizzare una documentazione di partenza ==rapida e semplice==, in modo da poter partire con lo sviluppo, sotto forma di user stories e simili. 
In seguito la specifica viene resa precisa nella fase post-sviluppo.

## No Big Upfront Architecture

### Architecture in practice

Fenomeno dell'==architecture degradation==: come l'architettura implementata è diversa da quella pensata
- architectural ==drift==: discrepanze che però non violano decisioni del progetto originale dell'architettura
- architectural ==erosion==: discrepanze che violano decisioni del progetto originale dell'architettura

Questo accade per varie ragioni, dai ==time costraints== al fatto che ==alcuni requisiti sono mutati==.

Queste inconsistenze comportano conseguenze di varia gravità in seguito.

Incredibilmente, ==le inconsistenze non figurano== nelle priorità più importanti degli sviluppatori. 

### Cambio dell'architettura nel tempo

Con il cambio dell'architettura nel tempo il peso delle inconsistenze si aggrava.

Nei metodi agili questo forza a ==essere consistenti== e unna buona idea è creare sia una ==architettura corrente== che ==una futura==, che tenga conto di necessità/cambiamenti che si potrebbero poi verificare.

### Antipattern identificati

==GoldPlating==: un archietettura perfetta ma... descrive il sistema sbagliato.

==Ivory tower==: isolamento degli architetti, spesso scollegati dagli sviluppatori.

==Architecture watch==: gli architetti non fanno il loro lavoro ma supervisionano e basta le scelte prese, ad esempio, dai devs.

### Architettura agile : JIT Architecture

Alcune idee per creare architetture nei metodi agili:
- ==sistema o software architecture versatile e facile da evolvere== ma comunque resiliente a futuri cambiamenti
- ==un metodo agile di creare architetture==, in modo iterativo e che permetta di apportare cambiamenti con l'evoluzione (*nota bene: diverso da quello di sopra!*)
- ==identificare le decisioni architetturali== più importanti che ==supportino uno sviluppo agile e un deployment continuo==.

In questo contesto è definita la ==Just In Time Architecture==, un`architettura ben definita che permetta i cambiamenti.

## No Big Upfront Design

### Design vs Implementation

Nei progetti SCRUM il design è ==emergente==, ovvero non è pianificato a priori ma emerge durante la realizzazione.