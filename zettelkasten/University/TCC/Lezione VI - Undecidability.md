# Indecidibilità

## Recall questions 
    - Cosa signica avere un algoritmo? Perchè è utile per definire i problemi indecidibili?

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

![](./static/l_rec_complementary.png)

==Complemento di un linguaggio $RE$== (th):
>Se $L \in RE e \neg L \in RE, allora L \in R e \neg L \in R$

...

### Classificazione problemi indecidibili

Due classi di problemi accettati dalle macchine di Turing:
- quelli con un algoritmo, ovvero che finiscono sia per input accettati che non;
- quelli che sono risolti solo da macchine di Turing che potenzialmente vanno in loop su alcuni input senza dire se accettano o meno.

Il secondo caso rende difficile, se non impossibile, definire l'indecidibilità in termini di accettazione o meno dell'input, per questo motivo decidiamo di ==mostrare che questi problemi sono indecidibili== in termini di algoritmo.

Presentiamo ora dei linguaggi (problemi) e mostriamo la classe a cui appartengono.

## Linguaggi/problemi e la loro decidibilità 

### Codifica di stringhe e TM

Troviamo dunque un modo per ==assegnare coppie di interi a delle stringhe definite sull'alfabeto $\Sigma$==:
- se $w$ è una stringa binaria, allora le mappiamo $1w$ come intero (ossia la precediamo con un 1)
- $w_i$ invece fa riferimento alla $i$-esima stringa.

![](./static/string_TM_mapping.png)

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

==Lingauggio di diagonalizzazione==:
>Il linguaggio $L_d$ è il set di stringhe $w_i$ tali che $w_i \notin $L(M_i)$, ovvero che non è accettato dalla $TM$.

Il motivo per cui questo linguaggio è detto di diagonalizzazione è il seguente:
costruiamo una tabella dove $i$ riporta la $TM \space M_i$ e $j$ la stringa $w_j$ e inseriamo 1 se la stringa è accettata, 0 altrimenti. Ogni riga $i$ ci dirà il ==vettore caratteristico== di $M_i$, ossia quali stringhe sono nel suo linguaggio.
È facile vedere che la diagonale, una volta fatto il ==complemento==, restituisce le stringhe per cui è valida la definizione di sopra.

![](./static/diagonalization_lang.png)

Notare che questo vettore caratteristico ==non può essere confuso con una $TM$== in quanto si trova in disaccordo con almeno una riga.

In altre parole $L_d$ è ==il set di stringhe non accettate dalla $TM$ che esse stesse definiscono==, quando vengono fornite come input.

Mostriamo infine che, ==Teorema==:
>$L_d$ non è un linguaggio ricorsivamente enumerabile

Supponiamo che $L_d$ sia accettato da qualche $M$, ossia è $L(M)$. Siccome $L_d$ è un linguaggio su {0,1}, deve trovarsi nella lista delle macchine di Turing della tabella costruita precedentemente. Quindi $M = M_i$ per qualche $i$:
- se $w_i \in L_d$, $M_i$ accetta $w_i$, ma per definizione questa allora non si può trovare nel linguaggio di diagonalizzazione (**contraddizione**)
- se $w_i \notin L_d$, allora $M_i$ non la accetta, ma per definizione il linguaggio di diagonalizzazione contiene proprio le stringhe non accettate con indici $M_i, w_i$ uguali (**contraddizione**)  

Quindi la $TM$ definita non può esistere, $L_d \notin RE$ e quindi non esistono $TM$ che lo accettino. Ricordiamo che ==l'inaccettabiità è condizione più forte dell'indecidibilità==.


### Visualizzazione dei linguaggi e la loro classe