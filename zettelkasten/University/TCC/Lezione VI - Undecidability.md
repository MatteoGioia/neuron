# Indecidibilità

## Recall questions 
    - Definire cosa sono le classi RE e R. Cosa significa che un problema è indecidibile>?
    - Come funzionano i complementi dei linguaggi R e RE?
    - Come si possono dunque classificare i linguaggi in modo più "semplice" in termine di algoritmo?
    - Mostrare come vengono codificate le TM in modo da mappare ogni stringa a una TM valida o meno.
    - Cosa è il linguaggio di diagonalizzazione? È RE, R o nessuno dei due?
    - Cosa è il linguaggio universale? È RE, R o nessuno dei due?
    - Rivedere codifica M separatore w per linguaggio universale.

## Classi di problemi

### Linguaggi RE e Ricorsivi

Ricordiamo che un linguaggio è ==$RE$== se è accettato da una macchina di Turing ma non abbiamo garanzie che questa si fermi se l'input non appartiene al linguaggio di tale macchina.

Ricordiamo che il linguaggio $L$ è invece ==ricorsivo $R$== se $L = L(M)$ per qualche $TM \space M$ tale che:
- se $w \in L$ allora $M$ lo accetta
- altrimenti si ferma

In seguito faremo riferimento al termine ==algoritmo== in modo interscambiabile con ==linguaggio ricorsivo==. Un algoritmo infatti ha un numero finito di step dopo i quali si ferma sempre (sia che accetti o meno l'input).

==Problema decidibile e indecidibile==
>Un problema è decidibile se è un linguaggio ricorsivo, altrimenti è indecidibile

Il motivo per cui questa definzione è data in termini di algoritmo viene chiarita più avanti. 

### Complemento dei linguaggi R e RE

==Complemento di un linguaggio $R$== (th):
>Se $L \in R, allora \neg L \in R$

La dimostrazione è semplice: se abbiamo la garanzia che la $TM$ si fermi per stringhe non nel linguaggio, allora basta "invertirne" il funzionamento per avere unaa $TM$ che opera con $\neg  L$ e abbiamo garanzia che si fermi sempre:
- gli stati di accettazione nella $M$ originale vengono trasformati in stati di non accettazione
- quelli di non accettazione invece ora possono proseguire in uno stato di accettazione con una nuova transizione

![](../../..//TCC/l_rec_complementary.png)

==Complemento di un linguaggio $RE$== (th):
>Se $L \in RE$ e $\neg L \in RE$, allora $L \in R$ e $\neg L \in R$

Anche qui la dimostrazione è semplice: costruiamo una $TM$, $N$, che opera simulando le due $TM$, una che accetta $L(M)$ e uno che accetta il suo complemento, tramite due nastri in parallelo:
- se $w \in L$, allora $M$ accetta e quindi lo fa anche $N$
- se $w \in L$, allora $\neg M$ accetta e quindi $N$ si ferma senza accettare

Quindi $N$ si ferma su tutti gli input, ossia $L = L(M)$ e quindi $L \in R$ (e di conseguenza anche il suo complemento)

### Classificazione problemi e indecidibilità

Due classi di problemi accettati dalle macchine di Turing:
- quelli con un algoritmo, ovvero che finiscono sia per input accettati che non;
- quelli che sono risolti solo da macchine di Turing che potenzialmente vanno in loop su alcuni input senza dire se accettano o meno.

Il secondo caso rende difficile, se non impossibile, definire l'indecidibilità in termini di accettazione o meno dell'input, per questo motivo decidiamo di ==mostrare che questi problemi sono indecidibili== in termini di algoritmo.

Di seguito mostriamo uno schema riassuntivo di come possono essere disposti i linguaggi:

![](../../..//TCC/problem_compl_class.png)

Presentiamo ora dei linguaggi (problemi) e mostriamo la classe a cui appartengono.

## Linguaggi/problemi e la loro decidibilità 

### Codifica di stringhe e TM

In seguito dovremo discutere di macchine di Turing e stringhe in modo più astratto, quindi conviene trovare un modo per ==fa corrispondere un intero binario a una stringa e viceversa==:
- se $w$ è una stringa binaria, allora le mappiamo $1w$ come intero (ossia la precediamo con un 1)
- $w_i$ invece fa riferimento alla $i$-esima stringa.

![](../../..//TCC/string_TM_mapping.png)

Adesso invece definiamo un ==codice binario== che possa ==descrivere macchine di Turing== con alfabeto {0,1} e che ci permetta di ==mappare la $TM i$-esima alla corrispondente stringa binaria==.

La nostra settupla $M = (Q, \{0,1\}, \Gamma, \delta, q_1, B, F)$ sarà codificata nel modo seguente:
- gli stati saranno $q_1, ..., q_r$ per qualche $r$, inoltre $q_1$ sarà sempre lo stato iniziale e $q_2$ quello di accettazione;
- i simboli di nastro saranno $X_1, ..., X_s$ per qualche $s$, inoltre $X_1$ sarà sempre il simbolo 0, $X_2$ il simbolo 1 e $X_3$ il simbolo blank
- le direzioni diventeranno $L = D_1$ e $R = D_2$

Una volta definiti i simboli, potremo codificare anche le regole di transizione: data una transizione $\delta(q_i, X_j) = (q_k, X_l, D_m)$ la codifichiamo con la stringa $0^i10^j10^k10^l10^m$. 
Le regole di transizione, ossia ==la $TM$ vera e propria==, verranno poi elencate nel formato $C_1 11 C_2 11 ... 11 C_n$ dove ogni $C$ corrisponde ad una regola di transizione
- notare che le possibili enumerazioni diverse in questo caso sono $n!$ 
- è facile vedere che, in ogni pezzo $C$ il numero di 0 identifica a quale simbolo/stato/direzione si fa riferimento, essendo questi numerati in ordine crescente

### Linguaggio di diagonalizzazione

Il nostro obiettivo è ==provare che questo linguaggio==, definito come segue, ==è indecidibile==: coppie $(M, w)$ dove
- $M$ è una Turing machine con $\Sigma = \{0,1\}$
- $w$ è una stringa in $\Sigma^*$
- $M$ accetta $w$ come input

Questo ovviamente implicherà che l'affermazione è vera anche per linguaggi più complessi dell'alfabeto binario.

==Linguaggio di diagonalizzazione==:
>Il linguaggio $L_d$ è il set di stringhe $w_i$ tali che $w_i \notin L(M_i)$, ovvero che non è accettato dalla $TM$.

Il motivo per cui questo linguaggio è detto di diagonalizzazione è il seguente:
costruiamo una tabella dove $i$ riporta la $TM \space M_i$ e $j$ la stringa $w_j$ e inseriamo 1 se la stringa è accettata, 0 altrimenti. Ogni riga $i$ ci dirà il ==vettore caratteristico== di $M_i$, ossia quali stringhe sono nel suo linguaggio.
È facile vedere che la diagonale, una volta fatto il ==complemento==, restituisce le stringhe per cui è valida la definizione di sopra.

![](../../..//TCC/diagonalization_lang.png)

Notare che questo vettore caratteristico ==non può essere confuso con una $TM$== in quanto si trova in disaccordo con almeno una riga.

In altre parole $L_d$ è ==il set di stringhe non accettate dalla $TM$ che esse stesse definiscono==, quando vengono fornite come input.

Mostriamo infine che, ==Teorema==:
>$L_d$ non è un linguaggio ricorsivamente enumerabile

Supponiamo che $L_d$ sia accettato da qualche $M$, ossia è $L(M)$. Siccome $L_d$ è un linguaggio su {0,1}, deve trovarsi nella lista delle macchine di Turing della tabella costruita precedentemente. Quindi $M = M_i$ per qualche $i$:
- se $w_i \in L_d$, $M_i$ accetta $w_i$, ma per definizione questa allora non si può trovare nel linguaggio di diagonalizzazione (**contraddizione**)
- se $w_i \notin L_d$, allora $M_i$ non la accetta, ma per definizione il linguaggio di diagonalizzazione contiene proprio le stringhe non accettate con indici $M_i, w_i$ uguali (**contraddizione**)  

Quindi la $TM$ definita non può esistere, $L_d \notin RE$ e quindi non esistono $TM$ che lo accettino. Ricordiamo che ==l'inaccettabiità è condizione più forte dell'indecidibilità==.

### Linguaggio Universale 

Introduciamo ora il ==linguaggio universale==:
>$L_u$ è il set di stringhe binarie che codificano $(M,w)$ dove $M$ è una $TM$ con input binario e $w$ una stringa binaria tale che $w \in L(M)$.

In parole semplici, si tratta dell'insieme di ==stringhe binarie che codificano una $TM$ e un input da essa accettato==.

Per mostrare le proprietà di questo linguaggio è però necessaria una rappresentazione. Ogni paio $(M,w)$ verrà scritto come $M \space 111 \space w$ in modo che i 3 uno facciano da separatore. Questo però introduce un problema: siccome ==tutte le stringhe binarie codificano $TM$==, ben o malformate che siano, ci serve un modo per capire che i 3 uno sono il separatore e non parte di una macchina mal definita.
Per fare ciò, prima di concatenare $M, w$ e 111, raddopiamo ogni bit di $M$ in modo tale da non confondere il separatore.

Mostriamo ora che ==(theorem)==:
>$L_u \in RE$ 

Lo faremo creando un $TM \space U$ che accetta proprio $L_u$.
$U$ è costruita come macchina multinastro:
- il primo contiene le coppie $M,w$
- il secondo simula $M$
- il terzo contiene lo stato simulato di $M$

$U$ ==opera== nel seguente modo:
- se $M$ è un codice per una $TM$ valida copia $w$ nel secondo nastro e simula $M$ 
- altrimenti si ferma senza accettare

Notare che $w$ viene codificata in modo da essere compatabile con la notazione di $M$, ovvero viene mappato 0 con 10 e 1 con 100 etc... Per comodità, come step addizionale, si possono anche raddoppiare, ossia 0 = 1100 e 1 = 110000, in modo tale da semplificare ulteriormente i controlli sulle transizioni.

Continua poi:
- piazzando 0 nella prima cella del nastro e mettendo la testina sulla prima cella del secondo
- simulando un mossa di $M$: se $M$ non ha più transizioni allora $U$ si ferma senza accettare, altrimenti prosegue con la simulazione
- se $M$ entra in uno stato di accettazione allora $U$ si ferma e accetta

La simulazione di una mossa avviene nel seguente modo:
- si muove a sinistra alla ricerca di una transizione t.c. lo stato sia uguale a quello nel terzo nastro e il simbolo sia uguale a quello correntemente letto
- cambia lo stato nel terzo nastro
- cambia il simbolo letto con quello indicato nella transizione e fa uso di un nastro di supporto nel caso in cui questo sia più corto/lungo del precedente
- muove la testina sul secondo nastro a dx o sx sul prossimo bit simulato

Mostriamo ora che ==(theorem)==:
> $L_u \notin R$

Per fare ciò mostriamo come sarebbe possibile costruire una macchina che accetta $L_d$ (che non è $RE$) se tale affermazione fosse falsa.

Supponiamo che $L_u \in R$, allora il suo complemento $\neg L \in R$ e deve esiste una $TM$ t.c $\neg L_u = L(M)$. Costuriamo $M_1$:
- dato $w$ in input, lo cambia in $d(w) + 111 + $w$, dove $d(\dot)$ raddoppia la stringa per codificare una $TM$ valida
- $M_1$ simula il comportamento di $M$ su tale stringa e accetta se $M$ accetta, rifiuta se $M$ rifiuta

Ora $M_1$ accetta $w_i$ se e solo se $M_i$ non accetta $w_i$, ossia se $w_i \in L_d$, ma questa è una **contraddizione**. Abbiamo infatti mostrato che non esiste una $TM$ per il linguaggio di diagonalizzazione.

### Visualizzazione dei linguaggi e la loro classe

![](../../..//TCC/first_lang_classificiation.png)

<small> Attenzione, nelle slide si usa un separatore diverso per la TM universale, ossia 01 - il risultato finale è uguale</small>


<small> Attenzione, nelle slide si usa una notazione leggermente diversa per la negazione ma assolutamente equivalente</small>