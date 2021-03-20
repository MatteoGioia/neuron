# Weaknesses

## Confused Deputy

### Che cosa è 

Si tratta di un tipo di ==privilege escalation== che sfrutta il modello ==ACL==. I sistemi che usano capabilities non ne sono invece affetti.

### Un esempio semplificato 

Abbiamo un programma P che conserva dati sensibili su un file, X, non visibile e modificabile dall'utente.

L'utente può usare P per generare dati da scrivere su Y, file di destinazione da lui scelto.

Nel momento in cui l'utente decide di usare X come file di output, il programma sovrascrive ignaro i dati sensibili.

### Un esempio reale

Programmi con ==Open SetUID== permettono all'utente di ==essere eseguiti come il proprietario==: ergo devono fornire accuratamente le proprie funzionalità.

Nel caso esempio, l'utente malevolo usava questa vulnerabilità per scrivere su un file a cui effettivamente non aveva accesso.

### Come difendersi

I programmi con Open SetUID ==devono fornire solo alcune capabilites== che permettano di salvaguardare il sistema.
- e.g. eseguire solo comandi predefiniti.

### Altri esempi

Esempi interessanti di come sfruttare la confused deputy sono visibili a https://en.wikipedia.org/wiki/Confused_deputy_problem

## Race conditions

### Time of Check, Time of Use

A.k.a ==TOCTOU==, crea una ==race window== in cui:
- prima ==controlla== il race object
- poi ==usa== il race object

Le operazioni concorrenti, in questo modello, possono avvenire solo tra ==checking e using==.

### Exploiting TOCTOU

Immaginiamo di poter modificare il file eseguito da un processo prima che questo lo possa eseguire: potenzialmente potremmo fare ==eseguire a un utente root codice diverso da quello che pensa==.

Ad esempio, si può fare in modo di far leggere al programma root un link simbolico a un file innocuo A, ma poi cambiare tale link al file desiderato B poco prima dell'esecuzione (in questo modo il path rimane lo stesso).

Si tratta comunque di una vulnerabilità ==non deterministica==, ovvero bisogna effettuare varie volte questa operazione sperando di ottenere una traccia in cui si riesca a cambiare il file prima di eseguirlo.


