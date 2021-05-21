# Problemi NP-completi

## Recall questions
    - WIP

## Problemi NP-completi celebri

### Albero delle riduzioni

![](./static/NP-reds.png)

### Problema dell'Indipendent Set ($IS$)

==Problema di trovare un insieme di nodi su un grafo senza archi in comune==.
Nel nostro caso, avendo un problema decisionale, siamo interessati a vedere se ==esiste un lower bound $k$, scelto tra 1 e $|V(G)|$, per tale $IS$==, ovvero se esiste un set indipendente di $k$ nodi.

Dimostriamo ora che:
> $IS$ è $NP$-completo

Che $IS$ sia $NP$ è facile vederlo: dobbiamo cercare combinazioni di $k$ nodi sul grafo $G$ che siano indipendenti. Una $NTM$ può facilmente farlo in tempo polinomiale.

Mostriamo ora la riduzione da $3-SAT$: partiamo da un'espressione $E = e_1 \land e_2 \land \ldots \land e_m$ in $3-CNF$. Costruiamo poi il grafo $G$ come mostrato in figura (**aggiungere**)

Per creare tale grafo associamo un nodo ad ogni letterale e poi connettiamo i nodi in una stessa clausola, che corrisponderanno alle colonne. Inoltre aggiungiamo degli archi anche tra un letterale e il suo complemento per evitare che siano entrambi elementi dell'$IS$. Se costruiamo il grafo in questo nodo, il bound $k$ per questo grafo diventa proprio $m$ (il numero di clausole).

Questa riduzione è ovviamente ==polinomiale==, in quanto la costruzione di questo grafo e il calcolo del suo bound, a partire da $E$, possono essere realizzati in un tempo pari al quadrato della lunghezza di $E$.

Dobbiamo infine mostrare che questa riduzione è valida, ovvero che:
> $E$ è soddisfacibile $\iff G$ ha un $IS$ $I$ di taglia esattamente $m$

**SE**: Se $G$ ha un set indipendente $I$ di taglia $m$, siamo sicuri che questo, per costruzione, **non** include nodi di una stessa clausola. Inoltre, il set indipendente non include nodi che corrispondano a un letterale e la sua negazione, i.e. $x, \lnot x$.
Possiamo costruire un assegnamento $T$ a partire da $I$ che soddisfi $E$ nel seguente modo:
- se un nodo che corrisponde a $x$ si trova in $I$, allora $T(x) = 1$ 
- se un nodo che corrisponde a $\lnot x$ si trova in $I$, allora $T(x) = 0$
- se $x, \lnot x$ non corrisponde a nessun nodo allora la assegniamo arbitrariamente (??)

In questo modo ogni clausola di $E$ ha almeno un letterale vero, nel dettaglio quelli che si trovano nell'$IS$ $I$.

**SOLO SE**: Se $E$ è soddisfacibile, mostriamo come costruire un $IS$ sul grafo $G$ costruito all'inizio.
Essendo $E$ soddisfacibile, esiste un assegnamento di verità $T$ che la soddisfa e che rende vero almeno un letterale per ogni clausola. In alcuni casi ce ne potrebbe essere più di uno, ma basterà sceglierne uno arbitrariamente. Per ogni letterale scelto, infine, viene costruito un set di $m$ nodi con le seguenti proprietà:
- in $I$ non ci possono essere archi tra nodi provenienti dalla stessa clausola
- in $I$ non ci possono essere archi tra un letterale e la sua negazione

Facendo così siamo in grado di costruire un $IS$ di taglia $m$ a partire da $E$.
**ERRORE: se più clausole hanno lo stesso letterale il set non ha taglia m, dobbiamo inserire un vincolo che specifica che il letterale scelto deve essere diverso da quelli precedenti**

### Problema del Node Cover ($NC$)

==Problema di trovare un insieme di nodi su un grafo che ricopra tutti gli archi==. Anche qui, avendo un problema di decisione, saremo interessati a verificare se esiste un ==limite superiore $k$ scelto tra 0 e $|V(G)|$, per tale $NC$==, ovvero se esiste una copertura di $k$ nodi.

In questo caso la riduzione avviene dal problema dell'$IS$, anche perchè ne è complemento (ma nulla vieta, essendo $NP$-completo, di ridurlo ad esempio partendo da $SAT$). Partiamo da un grafo $G$ con limite inferiore $k$ per la sua istanza di $IS$. Se $|G| = n$, allora costruiremo un'istanza di $NC$ con esattamente $n - k$ nodi. Come prima, tale trasformazione può essere fatta in tempo lineare.

Mostriamo dunque che:
> $G$ ha un $IS$ di taglia $k \iff G$ ha un $NC$ di taglia $n - k$

**SE**: $G$ ha un $NC$ di taglia $n - k$, sia inoltre $N$ il suo set di nodi. $N \setminus C$ è un set indipendente. Se non lo fosse, allora ci sarebbe un paio di nodi adiacenti $v,w \in N \setminus C$. Dato che nessuno dei due si trova in $C$, allora l'arco che li collega non si può trovare in $C$, che per ipotesi era un'istanza di $NC$. **contraddizione**

**SOLO SE**: $G$ ha un $IS$ di taglia $k$, quindi $N \setminus I$ è un $NC$. Se nbn lo fosse, ci sarebbe un arco $v,w$ non coperto da $N \setminus I$, ovvero $v,w$ sono entrambi in $I$ e collegati da un arco. Ma $I$ è un set indipendente. **contraddizione**

### Problema del Directed Hamilton Circuit ($DHC$)

==Problema di trovare un circuito hamiltoniano su un grafo diretto==. In questo caso il problema di decisione è proprio quello di ==decidere se tale grafo esiste, ovvero se esiste un cammino orientato che passa per tutti i nodi==. Il motivo per cui scegliamo la variante diretta è che dimostrare la $NP$-completezza del problema di trovare un $HC$ è molto maggiore di quella per $DHC$.

In questo caso la riduzione avviene da $3-SAT$. Dimostriamo quindi che:
> $DHC$ è $NP$-completo

La dimostrazione che $DHC \in NP$ è semplice: avendo un grafo $G$ dobbiamo calcolare una permutazione degli archi che formi un ciclo e ricopra tutti i nodi del grafo. Per fare ciò una $NTM$ è perfetta in quanto può calcolarle in tempo polinomiale e controllare se ve ne è una che soddisfa la proprietà.

Per quanto riguarda la riduzione, invece, partiremo da un'istanza $E$ di $3-SAT$ e arriveremo ad un'istanza $G$ di $DHC$.
Sia $x_1, x_2, \ldots, x_n$ le variabili in $E$. Per ogni clausola e ogni variabile, costruiamo un ==gadget==, ossia un sottografo $H_i$ particolare:

![](./static/DHC_red1.png)

Possiamo notare che ogni grafo contiene più nodi connessi tra di loro e gli indici (eccetto quelli del primo e dell'ultimo) variano da $i0$ fino a $im_i$, dove $m_i$ è il maggior numero di occorrenze tra $x, \lnot x$. Ogni nodo è $b$ è connesso con quello $c$ sull'altra colonna e viceversa, inoltre sono connessi rispettivamente al nodo $c$ (risp. $b$) successivo. Notiamo anche che su questo grafo i possibili cammini hamiltoniani sono solo 2: se si sceglie uno dei due lati si è poi costretti a scendere su uno solo tra i due percorsi per evitare di saltare i nodi. Queste discese corrispondono ad assegnare rispettivamente i valori falso e vero alla variabile in questione, infatti di seguito se si andrà da $a_i \to b_{i0}$ la variabile $x_i$ sarà considerata come assegnata al vero, se si andrà da $a_i \to c_{i0}$ falsa.

Una volta fatto ciò, concateniamo tutti questi sottografi $H_i$ e creiamo un arco dal primo all'ultimo. Notiamo che, dato che possiamo fare $2^n$ scelte di assegnazione dei valori di verità per ogni sottografo $H$, il grafo risultante avrà $2^n$ cammini hamiltoniani.

![](./static/DHC_red2.png)

Creiamo ora degli altri sottografi $I_j$, questa volta però associati a ogni clausola $e_j$ e costruiti nel seguente modo:

![](./static/DHC_red3.png)

Questi sottografi hanno la particolarità che bisogna uscire dalla colonna in cui si entrati se si vogliono toccare tutti i nodi. **DA INCLUDERE??** Infatti (la dimostrazione è simmetrica per ogni primo nodo nel ciclo di tale grafo) mostriamo come sia vero per $r_j$:
- se i due vertici successivi nel ciclo sono $s_j$ e $t_j$, se il ciclo andasse a $w_j$ e poi $v_j$ e uscisse allora non potrebbe tocccare $u_j$
-  se i due vertici successivi sono $s_j$ e $v_j$, il ciclo deve passare da $u_j$ che altrimenti poi è inaccessibile; se infine passa per $w_j$ non può più passare per $t_j$. Includere $t_j$ non permetterebbe inoltre di includere $v_j$ in quanto non si può proseguire
-  il circuito va a $u_j$, poi $w_j$, allora $t_j$ non può comparire nel ciclo perchè i predecessori sono già stati usati. Anche qui il circuito è costretto a uscire da $u_j$

Dobbiamo quindi infine collegare i vari $I_j$ agli $H_i$. Per fare ciò guardiamo ogni variabile delle clausole, prendiamo ad esempio $x_i$ della clausola $e_j$ e il blocco $I_j$ legato a tale clausola: 
- se $x_i$ non è negata, allora scegliamo un nodo $c_{ip}$ non ancora usato per allacciarsi ai blocchi $I_j$ con $p$ compreso tra $0$ e $m_i - 1$, a quel punto aggiungiamo un arco da $c_{ip}$ a $r_{j}$ e da $u_j$ a $b_{ip+1}
- se $x_i$ è negata, allora scegliamo un nodo $b_{ip}$ non ancora usato per allacciarsi ai blocchi con $p$ compreso tra $0$ e $m_i - 1$, a quel punto aggiungiamo un arco da $b_{ip}$ a $r_{j}$ e da $u_j$ a $c_{ip+1}

Le altre due variabili in ogni clausola saranno trattate in modo simile, ma useranno rispettivamente i nodi $(s,v)$ e $(w,t)$ per fare i collegamenti. Ogni $I_j$ sarà dunque connesso alle 3 variabili che compaiono nella clausola corrisponente.
Vogliamo ora dimostrare che il grafo costruito ==possiede un circuito hamiltoniano $\iff$ l'espressione di partenza è soddisfacibile==.

**SE**: Supponiamo esista $T$ che soddisfa $E$. Per costruire $H$:
1. Per ogni $H_i$, il cammino andrà da $a_i$ verso $b_{i0}$ o $c_{i0}$ a seconda che la variabile sia rispettivamente vera o negata.
2. Se il ciclo costruito finora percorre un arco da $b_{ip}$ a $c_{ip+1}$, ma esiste un arco da $b_{ip}$ verso un $I_j$ non ancora incluso nel ciclo, allora deviamo $b_{ip}$ verso tale $I_j$ e poi, dopo averne percorso tutti e 6 i nodi, torniamo a $c_{ip+1}$. 
3. Allo stesso modo facciamo andare un arco da $c_{ip}$ verso un $I_j$ e tornare a $b_{ip+1}$ dopo aver passato i 6 nodi nel caso complementare. Dato che $T$ soddisfa $E$, in ogni $H$ avremo almeno un arco che va da un lato ad un altro e che ci permette quindi di includere i nodi di un $I_j$. Avendo $e_j$ clausole, avremo la certezza di poter inserire gli $I_j$ nel grafo e avere un circuito hamiltoniano orientato.

**SOLO SE**: Supponiamo che $G$ abbia un $DHC$. Proviamo che $E$ è soddisfacibile: se ignoriamo le deviazioni, il circuito Hamiltoniano è una delle $2^n$ scelte possibili, che a loro volta sono vettori caratteristici di $E$. Ora abbiamo la garanzia che se una di queste scelte include gli $I_j$ (nel dettaglio proprio il cammino hamiltoniano sotto esame con le deviazioni incluse) allora $E$ è soddisfacibile. Se il ciclo va da $a$ a $b_{i0}$, allora possiamo deviare verso $I_j$ solo se in tale clausola $e_j$ $x_i$ compare come letterale, viceversa verso $c_{i0}$ per il letterale negato. Per tale motivo, se riusciamo a includere tutti gli $I_j$ almeno una variabile per ogni clausola sarà vera e quindi $E$ soddisfatta. 

### Problema del Circuito Hamiltoniano ($HC$)

In questo caso il problema può essere ridotto da quello immediatamente precedente. ==A partire da un grafo orientato costruiamo un grafo indiretto, tale che questo abbia un circuito hamiltoniano se e solo se quello di partenza aveva un $DHC$==.
In tempo polinomiale infatti, per ogni nodo $v$ di $G_d$, poniamo in $G_u$ tre nodi $v^0, v^1, v^2$ e:
- creiamo due archi ($v^0,v^1$) e ($v^1,v^2$)
- inoltre creiamo un arco $(v^2,w^0)$ per ogni arco $(v,w)$ in $G_d$

![](./static/HC_red1.png)

Dimostriamo che $G_u$ ha un circuito hamiltoniano $\iff$ $G_d$ ha un $DHC$:

**SE**: se esiste un circuito hamiltoniano orientato su $G_d$, sia $v_1, v_2, v_3, \ldots v_n$ allora $v^{0}_{1}, v^{1}_{1}, v^{2}_{1}, \ldots v^{0}_{n}, v^{1}_{n}, v^{2}_{n}$ è un circuito hamiltoniano su $G_u$, che percorre ogni colonna e salta al nodo successivo alla fine.

**SOLO SE**: esiste un circuito hamiltoniano su $G_u$; sappiamo inoltre che ogni nodo originale al suo interno ha la forma $v^0, v^1, v^2$. In altre parole, un ciclo avrà la forma $0 1 2 0 1 2 \ldots 0 1 2$ oppure $2 1 0 2 1 0 \ldots 2 1 0$. Possiamo quindi prendere un circuito hamiltoniano e costruire quello orientato, tenendo in considerazione che gli archi che uniscono apici $2,0$ devono essere percorsi nel verso originale in quanto uniscono due archi sul grafo diretto.

### Problema del Traveling Salesperson ($TSP$)

In questo caso la riduzione è semplice. Infatti partendo da un grafo $G$ su cui siamo sicuri esista un circuito hamiltoniano, non facciamo altro che crearne uno identico con peso $1$ su tutti i lati. Il $TSP$ è definito come il problema di trovare un circuito hamiltoniano di peso minimo, nel nostro caso il problema di decisione è vedere se ==esiste un $HC$ di peso $k$==. Avendo $n$ nodi, poniamo $k=n$. È facile vedere che se esiste un circuito hamiltoniano, allora esisterà anche una soluzione del $TSP$ con peso esattamente $k$, viceversa se esiste una soluzione al $TSP$ questa è valida (senza considerare i pesi) come circuito hamiltoniano.
