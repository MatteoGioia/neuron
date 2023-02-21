# Secure Programming

## Software Vulnerabilities and Bugs

### Bugs and Vulnerabilities

==Vulnerabilità più generiche dei bugs==, in quanto un bug è un ==errore o un difetto che causa un fallimento== del sistema.

Alcune code vulnerabilities comuni sono:
- ==information leakage==: informazioni riservate sono ottenute da utenti non autorizzati
- ==buffer overflow==: il mancato controllo/sanificazione degli input permette all'utente di modificare altre aree dello stack 
- ==race conditions==: finestra temporale tra i controlli di sicurezza su una risorsa e il suo uso effettivo, i.e. TOCTOU (vedi #[[Cybersec 6 - Weaknesses]])
- ==invalid data processing==: vengono fatte assunzioni sui dati che vengono processati, i.e. campo di input che si aspetta solo plaintext riceve script, crosscripting, etc...

La causa principale di tutte queste vulnerabilità è una ==inadeguata conoscenza di pratiche per scrivere codice in modo sicuro==

### Secure coding practices

1. Scrivere codice semplice e chiaro
2. Evitare di fare troppe assunzioni e controllare che queste siano vere a runtime
3. Fare testing approfondito, anche dei casi limite
4. Il tempo speso a creare software sicuro è sempre minore di quello passato a sistemarlo...

## Secure Programming

### Che cosa è il secure programming

Secure programming è la pratica di ==scrivere codice protetto da tutti i tipi di vulnerabilità==. 

Software sicuro è sottoinsieme di software di qualità e reliable. (Cfr. [[Non functional requirements]])

Questa pratica è difficile in quanto è soggetta ad un ==Defender dilemma==:
- il difensore deve testare il sw sotto ogni punto di vista, ma l'attacante può sfruttare uno qualsiasi dei punti deboli
- il difensore può solo preparsi contro attacchi noti, ma l'attacante può scoprire vulnerabilità ignote
- il difensore deve essere sempre vigile, perchè l'attaccante può attacare quando vuole

### Principi di sicurezza

1. Imparare dagli errori - capire le vulnerabilità, fixarle e scrivere reports
2. Minimizzare superficie di attacco - i.e. evitare di installare o attivare moduli non utili
3. Non dipendere da altri sistemi per la protezione ma gestire la sicurezza di ogni layer dell'applicazione
4. Assumere che i sistemi all'esterno siano insicuri - ovvero qualsiasi dato che arriva dall'esterno è potenzialmente compromesso

### Tecniche di secure programming

==Defensive programming==
>Tecnica che mira a progettare software che può continuare ad operare anche se sotto attacco. Necessita quindi che tutti gli aspetti dell'esecuzione siano gestiti, in particolare gli stati di errore in cui si può trovare il sw quando è sotto attacco.

In generale questo si concretizza nel verificare che ==delle precondizioni siano rispettate== prima di eseguire certi metodi, spesso pubblici o esposti, e che queste siano rispettate durante l'esecuzione. È un tipo di tecnica normalmente usata nei moduli usati nel *frontend*.

==Security by Design==
>Tecnica che considera gli aspetti di sicurezza in tutte le fasi dello sviluppo del software, dal design fino al deployment.

Questa tecnica fa uso di ==threat modelling==, ovvero durante la fase di design si studiano quali attacchi il sw potrebbe subire e le potenziali contromisure. Si prosegue poi con test in esecuzione e sul campo.

## Analisi statica e dinamica

### Analisi statica del codice

Analisi del codice ==sorgente o binario== senza eseguire il programma.

### Analisi dinamica del codice

Analisi del codice ==eseguito in tempo reale su un processore virtuale o fisico==.
Questo tipo di analisi può essere limitata usando tecniche anti debugging:
- ==self debugging==: siccome solo un processo di debugging può essere attivo ad un tempo, il sw previene il debugging da parte dell'utente facendolo risultare già in corso; questa tecnica può essere comunque aggirata saltando le istruzioni che avviano il self debugging

## Memory corruption

### Tipologie di memory corruption

1. Buffer overflow
2. Stack corruption
3. Heap overflow
4. Shellcode injection

<small> Psst... questa parte finale è poco dettagliata in quanto l'argomento viene affrontato in dettaglio nel laboratorio. </small>