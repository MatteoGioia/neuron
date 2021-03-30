# Ulteriori costrutti per le Macchine di Turing

## Recall questions 
    - Cosa sono le macchine di Turing ristrette?
    - Come funziona una macchina a nastri semi infiniti? Provare che è equivalente ad una normale TM.
    - Come si può creare un PDA che accetta gli stessi linguaggi di una TM? Come viene implementato e come funziona?

## Macchine di Turing

### Macchine di Turing ristrette

Esamineremo ora delle versioni ristrette della classica macchina di Turing che, sebbene abbiano limitazioni, sono comunque modelli di calcolo equivalenti a quella originale (ossia accettano gli stessi linguaggi).

### Macchina di Turing con nastri semi infiniti

Assumiamo che i nastri della $TM$ in questione ==non abbiano celle a sx dell'input==. Per simulare una $TM$ regolare $M$, possiamo costruire la $TM \space M_1$ come segue:
- $M_1$ possiede due tracce: una dove sono contenuti i simboli a SX del nastro di $M$ e nell'altra quelli a DX 
- è presente un simbolo speciale che evita che la testina strabordi a SX
- $M_1$ non scrive mai blanks, ovvero il nastro, in ogni istante, è un prefisso di simboli non vuoti (non blank) seguiti da una sequenza infinita di blank e questa sequenza di simboli non vuoti inizia sempre all'inizio della posizione iniziale del nastro.

![](./static/semi_infiniteTM.png)

Vogliamo ora provare che (==teorema==):
> Ogni linguaggio accettato da una $TM$ $M$ è anche accettato da una $TM$ $M_1$ cone le seguenti restrizioni: 
> - la testa di $M_1$ non si muove mai a sinistra della posizione iniziale
> - $M_1$ non scrive mai un blank

Per soddisfare la ==seconda condizione==, possiamo costruire una $M_2$ dalla $M$ e aggiungere un nuovo simbolo di blank $B_1$. La funzione di transizione $\delta_2$ in $M_2$ è la stessa di $\delta$, ossia ne è una copia, in $M$ ma con i seguenti cambiamenti:
- se $\delta_2(q,X) = (p,B,D)$ allora viene cambiata con $\delta_2(q,X) = (p,B_1,D)$
- $\delta_2(q,B_1) = \delta_2(q,B)$, ovvero la macchina accetta i nuovi blank al posto di quelli vecchi che sono stati già sostituiti.

Per soddisfare invece la condizione 1, si costruisce $M_1$ a partire da $M_2$. 

![](./static/restricted_TM_costr.png)

Le ultime due transizioni servono a gestire il caso particolare in cui si trova a inizio input e quindi bisogna scavallare per evitare che la $TM$ si muova appunto a sinistra.

### Macchina multi stack

Una macchina di Turing può accettare linguaggi che ==non sono accettati== da PDA (push down automatas) con una sola pila. Ma se un PDA avesse più pile?

Introduciamo quindi una ==macchina a k-stack== (o pile), ossia un ==PDA deterministico con $k$ pile==:
- ottiene l'input da una stringa sorgente in input
- ha un controllo finiito (che si può trovare in un numero finito di stati)
- ha un alfabeto di stack finito che usa per tutti gli stack
- le mosse dipendono dallo stato del controllo finito, il simbolo in input e i simboli in cima ad ogni stack

Per rendere il PDA deterministico sono concesse le $\epsilon$ moves ma solo quando sono l'unica alternativa, i.e. non ci sono più scelte che non siano la $\epsilon$ move.

==Una mossa della macchina multistack== consiste in:
- un cambio di stato
- rimpiazzare il simbolo in cima a ogni pila con una stringa di simboli della pila (anche lunga 0), ovvero le transizioni sono del tipo $\delta(q,a,X_1, \ldots, X_k) = (p, \gamma_1, \ldots, \gamma_k)$

La macchina di Turing multistack si ferma in uno stato di accettazione $p$ e fa inoltre uso di ==un endmarker== che indica la fine dell'input, il simbolo \$.

Dimostriamo ora che (==teorema==):
> Se un linguaggio $L$ è accettato da una $TM$, allora $L$ è accettato da una macchina a 2 pile

Infatti se $L \in RE$, allora esiste una $TM$ $M$ a un nastro che lo riconosce. 
Per dimostrare il teorema basta mostrare come la macchina a due pile $S$ simuli $M$. Una pila 
conterrà quello che si trova a sinistra della testina e l'altra quello che si trova a destra:
- $S$ inizia con un marker di fine stack, il simbolo *, in ogni stack
- quando legge l'input $w\$$,$S$ copia la stringa nel primo stack, e poi dal primo al secondo
- $S$ entra in uno stato che simula quello iniziale di $M$ e fa una mossa
- se $M$ si trova in uno stato di accettazione, allora $S$ si ferma, altrimenti simula un'altra mossa
  
La doppia copia serve in quanto la stringa, venendo copiata nel primo stack, è capovolta, e poi viene riportata al verso iniziale copiandola nuovamente.

Nel dettaglio, la ==simulazione avviene in questo modo==:
- $S$ conosce ovviamente lo stato di $M$, i.e. $q$, in quanto lo simula nel suo controllo finito
- $S$ conosce anche il simbolo $X$ letto dalla testina di $M$: infatti è quello in cima al secondo stack; se questo contiene solo * allora $M$ era finita su un blank
- $S$ qunidi conosce la prossima mossa di $M$ sapendo $\delta(q,X)$ e cambia il nuovo stato nel controllo finito
- se $\delta_M(q,X) = (p,Y,R)$, allora $S$ *pusha* $Y$ nel primo stack, tranne se questo è vuoto e $Y = B$, e fa *pop* di $X$ dal secondo, tranne se ovviamente $X=$*.
- se $\delta_M(q,X) = (p,Y,L)$, allora $S$ fa *pop* di $Z$ dal primo stack e rimpiazza $X$ nel secondo con $ZY$, tranne se $Z = *$, caso in cui viene *pushato* $BY$.

### Macchine a contatori

Le macchine a contatori possono essere pensate in 2 modi:
1. come ==macchina multistack== ma ==con contatori al posto degli stack==; questi contatori contengono interi non negativi e la $TM$ può solo sapere se questo contatore è 0 o diverso da 0 e, in una mossa,
  - cambiare stato
  - aggiungere o sottrarre 1 da uno qualsiasi dei contatori, tranne nel caso in cui questo sia 0
2. come una ==macchina multistack ristretta==
  - gli stack hanno due simboli: * e $X$
  - ogni stack è inizializzato con *
  - \* può essere rimpiazzato solo da $X^i$*, con $i \geq 0$
  - $X$ può essere rimpiazzato solo con $X^i$ con $i \geq 0$

<small> Vedi anche #[[Lezione II - Macchine di Turing]] </small>

