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
2. come una ==macchina multistack ristretta==, definizione che useremo di seguito in quanto più comoda:
  - gli stack hanno due simboli: * e $X$
  - ogni stack è inizializzato con *
  - \* può essere rimpiazzato solo da $X^i$*, con $i \geq 0$
  - $X$ può essere rimpiazzato solo con $X^i$ con $i \geq 0$

Sottolineamo inoltre che:
- ==se $L$ è accettato da una $CM$ allora $L \in RE$==
- ==se $L$ è accettato da una $CM$ a un solo contatore, allora $L \in CFL$== (context free languages)
e
Dimostriamo ora due teoremi utili in seguito:
> ==TM 3 counter / 2 stack equivalence==
> ==TM 3 counter / 2 counter equivalence==

Per dimostrare il ==primo teorema==, dobbiamo ==simulare due stack con 3 contatori==.
Supponiamo che ci siano $r-1$ simboli di nastro usati dalla stack machine $SC$, identificati con i numeri da 1 a $r-1$. Lo stack $X_1 X_2 \ldots X_n$ in questo modo viene espresso come una sequenza in ==base $r$== del tipo $X_n r^{n-1} + X_{n-1} r^{n-2} + \ldots + X_2 r + X_1$.

Avremo quindi ==2 contatori con all'interno il contenuto dei 2 stack==, uno a testa, mentre il ==terzo sarà usato come supporto== agli altri nelle operazioni di moltiplicazione e divisione per $r$.

![](./static/3_stack_2_equiv.png)

Per effettuare una ==operazione di pop== sostituiremo $i$ con $i / r$ senza considerare il resto. Iniziando con il terzo contatore a 0, riduciamo ripetutamente $i$ di $r$ e incrementiamo il terzo contatore di 1. Quando il contatore che aveva $i$ al suo interno diventa 0 ci fermiamo e poi lo reicrementiamo fino a quando il suo valore diventa quello ora memorizzato nel contatore di supporto, che nel contempo riportiamo a 0.

Per effettuare invece una ==sostituzione==, se $Y > X$ allora andremo a incrementare di $Y - X$, altrimenti a decrementare di $X - Y$ con l'aiuto del 3 counter. 

Per fare una ==operazione di push== su un contatore con $i$ all'interno, rimpiazziamo $i$ con $i r + X$. Inizialmente moltiplichiamo $i$ per $r$ volte, decrementando $i$ e incrementando il terzo contatore di $r$. Quando il contatore originale diventa 0, allora nel terzo abbiamo $i r$. Si copia quindi nel contatore originale, riportando a 0 quello di supproto, e poi si icrementa di $X$.

Per dimostrare invece il ==secondo teorema==, adottiamo una doppia equivalenza. Mostriamo infatti che ==una macchina a 2 contatori è equivalente ad una con 3 contatori==.
Per fare ciò rappresentiamo i 3 contatori originali, $i,j,k$ come un singolo intero contenuto nel primo counter, i.e. $m = 2^i3^j5^k)$. L'altro, come nel caso precedente, farà da supporto.
Ovviamente dovendo simulare una macchina a contatori dovremo simulare l'incremento, il decremento o il check se diverso da 0.

Per simulare ==l'incremento o il decremento==, basta moltiplicare per uno dei tre primi a seconda di quale contatore scegliamo di incrementare. Per farlo, adottiamo la stessa tecnica precedentemente mostrata.

Per controllare se ==un contatore è zero== invece dobbiamo controllare se il contatore è divisibile per il primo corrispondente (i.e. 2 per il contatore $i$). Per fare ciò copiamo $m$ nel secondo contatore usando lo stato finito della $CM$ per ricordare se lo abbiamo, nel caso di $i$, decrementato un numero pari di volte o un numero dispari di volte. Se questa cifra è pari quando $m$ è zero, allora il numero era divisibile per 2. In modo simile possiamo operare per 3 e 5. 


<small> Per emulare una CM3 con una CM2 viene silenziosamente sfruttato il fatto che ogni numero può essere rappresentato in modo univoco come prodotto di potenze di numeri primi </small>

<small> Vedi anche #[[Lezione II - Macchine di Turing]] </small>




