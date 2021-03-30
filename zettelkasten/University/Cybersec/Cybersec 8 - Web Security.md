# Server side security

## Web security

### Tipologie e testing

Tipologie di web security:
- ==server side==:vulnerabilità del server remoto
- ==client side==: vulnerabilità del client, ad esempio sfruttate mandando un link al malcapitato

Metodologie per scoprire le vulnerabilità:
- ==black box==: si sa tutto del sistema che si attacca
- ==white box==: la struttura del sistema attaccato è ignota

Nel testing blackbox è utile l'==enumeration==, ovvero testare combinazioni che potrebbero farci scoprire vulnerabilità
- i.e. studiare le funzioni del sistema e identificare quelle potenzialmente insicure
- i.e. inserire keyword in campi di input

Nel testing white box invece il pentester è più avvantaggiato in quanto conosce il sistema e ==l'approccio è più efficace== in generale nello scoprire falle di sicurezza
- i.e. ha tool di debug a disposizione

### Tooling

Lista dei tool usati per testare alcune vulnerabilità (ce ne sono molti, qui vengono mostrati solo quelli usati nel lab):
- il broswer stesso
- comandi come `curl` o `wget`
- `requests`, libreria di python per effettuare richieste
- burp suite e/o zap proxy, permettono di editare in tempo reale richieste e risposte http
- test server, come phpdev e httpsimplepython
- ngrok, crea un tunnel pubblico con http/tcp verso la propria macchina

## File disclosure

### Che cosa è

Si tratta dell'==impatto== di certe vulnerabilità, in particolare di quelle che conducono a ==diffusione di file riservati per il server== e quindi importanti. La gravità dunque varia in base all'importanza dei file diffusi.

Un classico caso di file disclosure è ==il furto file di configurazione== del server che possono contenere informazioni sensibili
- i.e. file di configurazione del db che contengono credenziali di accesso a quest'ultimo

Un altro caso di file disclosure è ==il furto di codice sorgente== del sito:
- permette ad un attaccante di trovare più vulnerabilità. 
- permette di rivendere il codice del prodotto

### Cause comuni di file disclosure

Ogni aspetto del server/client legato a file può portare a file disclosure, in particolare ci sono degli ==standard sinks== che se esposti all'utente costituiscono un rischio.

Alcuni ==sinks==:
- funzioni come `fopen` o `send_file` e simili, molto comuni
- funzioni come `curl` usate per aprire i file, meno comuni

Altre falle comuni sono quelle legate:
- a ==code execution==, che permettono di eseguire codice esterno che può quindi rubare file sensibili
- a ==directory esposte==, i.e. quella `.git`
- a ==web server misrouting==

### Path Traversal

Vulnerabilità presente quando ==un input controllato da utente riesce a fare una `open`==, ad esempio.
In generale questo avviene anche quando ==l'input non viene sanitizzato== e ad esempio si riesce a risalire a directories protette.

I ==vari casi in injection== sono:
- ==plain== injection, i.e. `open($input)`
- ==prepended== injection, i.e `open($input + 'foobar')`
- ==appended== injection, i.e `open('foobar' + $input)`
- ==appended + prepended== injection, i.e `open('foo' + $input + 'bar')`

### Preventing Path Traversal

Un classico fix sono le ==blacklist== di parole riservate che triggerano in automatico la sanitizzazione o il blocco dell'input, tuttavia non sono abbastanza. Questo perchè le directories, i termini e i collegamenti da blacklistare sono molti ed è facile dimenticarne alcuni.

Una valida aggiunta è quella di rendere ==tutti i path normalizzati==, oppure (e anche) usare `chroot`, in modo da bloccare tutti gli accessi all'infuori di quel path. 
- vedi anche https://en.wikipedia.org/wiki/Chroot

## Server-Side Request Forgery

### Che cosa è

Vulnerabilità che permette di mandare una ==network request== da un'applicazione remota. Questa richiesta viene poi ad esempio propagata nel resto della rete (esterna o interna).

Vedi anche https://en.wikipedia.org/wiki/Server-side_request_forgerys

### Tipologie di SSRF

==Blind SSRF==: non ha output e permette di ==mappare internamente la rete del malcapitato== o/e triggerare azioni dell'host dietro il firewall.

