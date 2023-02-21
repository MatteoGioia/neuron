# Rational Unified Process

## Recall questions
    - Cosa è il RUP? Chi lo ha creato?
    - Quali sono le caratteristiche del RUP? (hint: 3)
    - Quali sono le dimensioni del RUP?
    - Cosa si fa nella fase di ideazione?
    - Cosa si fa nella fase di elaborazione?
    - Cosa si fa nella fase di costruzione?
    - Cosa si fa nella fase di transizione?
## Metodi di progettazione
### Waterfall
Il modello waterfall nasce nel 1970 come modello lineare e sequenziale
- l’output di ogni fase è infatti l’input della successiva
- si è vincolati a terminare ogni stage prima di esaminare gli altri
- fa uso di throw away prototyping (prototipi da testare e scartare)

### RUP - Introduzione
Processo effettivo per lo sviluppo di SW sviluppato e aggiornato dalla Rational Software
- framework di processo, adatto ad essere esteso per varie necessità

### RUP - Caratteristiche
È Use case driven: gli use case legano il design di progetto ai requisiti funzionali
-  per definizione i casi d’uso hanno visione più ampia de;  solo problema da risolvere

È architecture centric: RUP usa un modello di architettura a 4+1 viste, la vista +1 corrisponde alla Use
Case View che è trasversale alle altre 4
- Logical View - requisiti funzionali del sistema, astrazione del modello di progettazione;
- Process View - gestione di aspetti concorrenziali, insieme a problematiche di scalabilità e troughput;
- Implementation View - gestione della programmazione dei moduli SW statici;
- Deployment View - mappatura di sf ad hw, installazione e comunicazione con altro sw e su varie piattaform

È iterativo e incrementale 
- multiple fase ripetute

### RUP - Struttura
Il RUP ha struttura bidimensionale
- parte DINAMICA (asse orizzontale): struttura dinamica del processo, mostra come nel tempo cambi il tipo di approccio con cui si lavora sul software da progettare e le varie iterazion
- parte STATICA (asse verticale): struttura statica del processo, mostra su quali attività è posto il focus durante una certa iterazione

## Fasi del RUP
### Fase di ideazione
Nella fase di ideazione bisogna definire in modo preciso i requisiti generali e determinare lo sforzo complessivo necessario allo sviluppo:
- capire obiettivi e limiti
- stabilire criteri di accettazione
- individuare use case cruciali
- stimare rischi, costi e tempi
- creare una prima bozza di architettura

### Fase di elaborazione
Nella fase di elaborazione ci si concentra sui requisiti e viene creato un prototipo dell’architettura:
- si crea una baseline di architettura;
- si crea una baseline del documento di visione;
- si crea una baseline del piano di costruzione;
- si dimostra che l’architettura progettata è una scelta sostenibile per la visione. i costi e i tempi scelti.

### Fase di costruzione
Durante la costruzione ci si concentra su progettazione ed implementazione, nel dettaglio si lavora sul prototipo già generato alla fine della fase prima, arrivando a un prodotto quasi finale
- minimizzare i costi di sviluppo ottimizzando risorse come tempo/spazio;
- raggiungere una qualità adeguata asap e creare versioni di prova usabili, come le alfa o le beta.

### Fase di transizione
Si tratta della fase più delicata, in cui il focus è terminare la realizzazione del prodotto finale e consegnarlo
- rendere autonomo l’utente del sistema;
- ottenere il consenso delle parti interessate rispetto alla completezza e alla coerenza del documento di visione
- ottenere una baseline del prodotto finale

