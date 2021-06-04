# Altre classi di complessità

## Recall questions
    - WIP

## Classi di complessità addizionali

### Diagramma delle classi di complessità

![](./static/additional-complexity-classes.png)

Come è possibile vedere nel disegno, esistono molte classi di complessità oltre quelle già mostrate. Nel dettaglio, andremo a vedere:
- ==$co-NP$==, la classe dei ==complementi dei linguaggi in $NP$==;
- ==$RP$ a.k.a. random polinomial languages==, la classe degli ==algoritmi che girano in tempo polinomiale e che accettano una stringa del linguaggio con una probabilità $P > 0$==;
- ==$ZPP$ a.k.a zero error, probabilistic polinomial==, linguaggi degli ==algoritmi che accettano stirnghe nel linguaggio con tempo atteso di esecuzione polinomiale==;
- COMING SOON 

### La classe $co-NP$

La classe $co-NP$ è interessante in quanto sebbene $P$ sia noto essere ==chiuso per quanto riguarda il complemento==, non lo è per $NP$, tant'è vero che ==si pensa sia proprio una classe a parte==, assunto che $P = NP$.

![](./static/npvsconp.png)

Due esempi celebri di problemi complemento che sono reputati essere in $co-NP$ sono i seguenti:
- $USAT$: si tratta del problema di mostrare che ==una espressione booleana è insoddisfacibile== (include nella formulazione anche le espressioni malformate) e si crede ==non sia in $NP$==, tuttavia non esiste una dimostrazione per tale affermazione.
- $TAUT$: anche questo problema è potenzialmente in $co-NP$ ma non in $NP$. Infatti una tautologia ==è una espressione che è soddisfacibile per qualsiasi assegnamento di valori di verità== o, equivalentemente, non è insoddisfacibile, ovvero se $E$ è l'espressione allora $\lnot E$ deve essere istanza di $USAT$ che ipotizziamo essere in $co-NP$.

Mostriamo ora un ==teorema== su $co-NP$:
> $NP = co-NP \iff \exists$ un problema $NP$-completo il cui complemento è in $NP$.

**SOLO SE**: se $NP = co-NP$ allora $P \in NP$, problema generico $NP-completo$ in $NP$, appartiene anche a $co-NP$, ma allora il suo complemento $\lnot P$ è in $NP$ (appunto perchè le due classi sono la stessa cosa)

**SE**: Se $P \in NP$ e $\lnot P \in NP$ allora esiste una riduzione polinomiale da ogni $L \in NP$ a $P$, che è anche una riduzione da $\lnot L$ a $\lnot P$. Proviamo quindi che $NP = co-NP$ mostrando che (doppia inclusione) $NP \subseteq co-NP$ e $co-NP \subseteq NP$:
- $NP \subseteq co-NP$: $\forall L \in NP, \lnot L \in co-NP$. Combinando la riduzione polinomiale da $\lnot L$ a $\lnot P$ con l'algoritmo $NP$ per $\lnot P$, otteniamo un algoritmo $NP$ per $\lnot L$. Quindi $\forall L \in NP, \lnot L \in NP$
- $co-NP \subseteq NP$. Supponiamo $L \in co-NP$. Allora esiste una riduzione polinomiale da $\lnot L$ a $P$ e $\lnot L \in NP$, che è anche una riduzione da $L$ a $\lnot P$. Siccome $\lnot P \in NP$, la riduzione, combinata con l'algoritmo $NP$ per $\lnot P$ è un algoritmo $NP$ per $L$.

<small> per algoritmo $NP$ si intende un algoritmo non deterministico polinomiale per una $NTM$ </small>

---  

### Le classi $PS$ e $NPS$

Introduciamo ora due classi di complessità relative allo ==spazio, inteso come numero di celle visitate, da parte di una $TM$==, ma abbiamo prima bisogno della seguente ==definizione==:
> Una macchina di Turing è ==polynomial space bounded== se esiste un qualche polinomio $p(n)$ per il quale, su un input $w$ di lunghezza $n$, la macchina di Turing non visita più di $p(n)$ celle del nastro.

In questo caso si assume che il nastro sia ==semi infinito== e che la macchina ==non vada mai a sx del proprio input==.

Definiamo ora rispettivamente le classi $PS$ e $NPS$:
> $PS$ o ==polynomial space== è la classe dei linguaggi $L(M)$ di tutte e sole le macchine deterministiche $M$ polynomial space bounded.

> $NPS$ o ==non deterministic polynomial space== è la classe dei linguaggi $L(M)$ di tutte e sole le macchine non deterministiche $M$ polynomial space bounded.

### Teoremi su $PS$ e $NPS$

È stato dimostrato che:
> $P \subseteq PS, NP \subseteq NPS$ - infatti se una macchina fa un numero polinomiale di mosse visita al massimo un numero polinomiale di celle.

È opportuno inoltre considerare qualoria sia possibile che una $TM \in PS$ possa non trovarsi nei linguaggi ricorsivi, in quanto abbiamo detto che usa un numero polinomiale di spazi ma nulla sull'accettazione. Ebbene, possiamo mostrare due teoremi che insieme implicano che:

![](./static/actually_in_rec.png)

Il primo teorema dice che: 
> Se $M$ è una $TM$ polynomial space bounded da $p(n)$, allora esiste una costante $c$ t.c. se $M$ accetta il suo input $w$ di lunghezza $n$ lo fa in $c^{1+p(n)}$ mosse.

==Dimostrazione==: sia $t = |\Gamma|$ e $s = |Q|$. Quando $p(n)$ celle di nastro sono utilizzate, le $ID$ di $M$ diverse sono al massimo $s p (n) t^{p(n)}$, dove $t^{p(n)}$ sono tutte le combinazioni di simboli di nastro di lunghezza $p(n)$, mentre $s p(n)$ indica tutte le possibili combinazioni del simbolo che marca lo stato su $p(n)$ celle. Se scegliamo la costante $c = s + t$, notiamo che:
> $c^{1+p(n)} = (s + t)^{1 + p(n)} = t^{1+p(n)} + (1 + p(n))st^{p(n)} + \ldots$

La seconda quantità nel binomio sviluppato è già maggiore di $s p (n) t^{p(n)}$, quindi possiamo tranquillamente affermare che:
> $c^{1+p(n)} = (s + t)^{1 + p(n)} \geq s p (n) t^{p(n)}$

Se per assurdo la $TM$ facesse una sequenza più lunga di $c^{1+p(n)}$ $IDs$ prima di accettare, allora esisterebbe una sequenza più corta che accetta comunque senza ripetere una $ID$. In altre parole, se $M$ accetta $w$, lo può fare senza ripetere $ID$ e quindi ogni sequenza di accetazione non può essere più lunga del numero massimo di $ID$ uniche, che è $c^{1+p(n)}$. 

Enunciamo ora il secondo teorema:
> Se $L$ è un linguaggio in $PS$ (risp. in $NPS$) allora $L$ è accettato da una $TM$ polynomial space bounded $M$ che si ferma dopo aver fatto al massimo $c^{q(n)}$ mosse per qualche polinomio $q(n)$ e una costante $c > 1$.

==Dimostrazione==: sia $L$ accettato da una $TM$ $M_1$ che è polynomial space bound da $p(n)$ - in questo caso sappiamo per il teorema precedente che lo fa entro $c^{1 + p(|w|)}$ mosse. Possiamo dunque costruire $M_2$, che ha due nastri: sul primo simula $M_1$, sul secondo conta in base $c$ fino a $c^{1 + p(|w|)}$. Se si arriva a tale numero allora la $TM$ si ferma senza accettare. Abbiamo inoltre la garanzia che su entrambi i nastri le $TM$ non usino più di $p(|w|)$ celle.
Possiamo quindi convertire $M_2$ in $M_3$ mononastro, che per un teorema precedente impiega tempo al massimo $O(c^{2 p(n)})$. Quindi $M_3$ non fa più di $dc^{2 p(n)}$ mosse per qualche costante $d$. Se scegliamo $q(n) = 2 p(n) + \log_c d$ allora $M_3$ fa proprio non più di $c^{q(n)}$ mosse. 
Inoltre $M_3$ si ferma sempre (poichè lo faceva $M_2$) e accetta $L$ (poichè lo faceva $M_1$).

Un'altro aspetto interessante di queste due classi è che a differenza di $P$ e $NP$, per il ==teorema di Savitch==:
> $PS = NPS$

Ovvero è dimostrata l'equivalenza tra questi due spazi - ne consegue ovviamente che tutto quello che viene provato per $PS$ può essere provato anche per $NPS$.
Il ==cuore della prova== è un test ricorsivo e deterministico (ossia una $TM$, un algoritmo) per verificare se una $NTM$ $N$ può muoversi tra due $ID$, $I, J$, in al massimo $m$ mosse.
Una $TM$ deterministica $D$ infatti proverà tutte le descrizioni istantanee $K$ nel mezzo della transizione tra $I,J$ per vedere se $I \to K$ in $\lfloor{\frac{m}{2}}\rfloor$ e $K \to J$ in $\lceil{\frac{m}{2}}\rceil$ mosse.
Sul nastro di $D$, che funge da stack per le chiamate ricorsive, saranno posti gli argomenti $I,J,m$ di ogni chiamata, poi verrà eseguito il seguente algoritmo:

```
    BOOLEAN FUNCTION reach(I,J,m)
        ID: I,J; INT: m;
        BEGIN
            IF (m==1) THEN BEGIN
                test if I == J or I can become J after one move
                RETURN TRUE if so, FALSE if not;
        END;
        ELSE BEGIN
            FOR each possible ID K DO
                IF reach(I,K,floor(m/2)) AND reach(K,J, ceil(m)) THEN
                    RETURN TRUE
                RETURN FALSE
        END
    END
```

Le 2 chiamate di `reach` sono eseguite una alla volta, non in parallelo, quindi sullo stack possono esserci al massimo $log_2 m$ chiamate alla funzione se il massimo di partenza era $m$. Dato che sappiamo che la $NTM$ $N$ non deve fare più di $c^{p(n)}$ mosse, non ci serve un numero più grande. Quindi il numero di frame dello stack è appunto $log_2 c^{p(n)} = O(p(n))$

A questo punto è ovvia la ==relazione $PS \subseteq NPS$==, quindi bisogna dimostrare l'altro verso dell'inclusione. Per fare ciò, mostriamo che se $L$ è accettato da una $NTM$ con bound polinomiale sullo spazio $p(n)$, allora $L$ è accettato anche da $D$, con un bound polinomiale $q(n) = O(p^2(n))$.
Se $N$ accetta, lo fa infatti in $c^{1 + p(n)}$ mosse. Dato un input $w$ di lunghezza $n$, $D$ può scoprire cosa fa $N$ verificando se, tra gli stati di accettazione e quello di partenza, ne esiste una combinazione che porta ad accettazione (o rifiuto) in $m = c^{1 + p(n)}$ step. Infatti sul nastro vengono posti:
- $I_0$, stato iniziale di $N$ con input $w$
- tutti i $J$, ossia gli stati di accetazione di $N$
- $m = c^{1 + p(n)}$

Anche qui è opportuna un considerazione sullo spazio: non ci saranno mai più di $log_2 c^{1 + p(n)} = O(p(n))$
chiamate ricorsive sullo stack, quindi anche qui il numero di celle è polynomial space bounded. Ogni frame richiede $O(p(n))$ spazio, in quanto le due $ID$ occupano $1 + p(n)$ celle (essendo $N$ p.s.b da $p(n)$) e, se scriviamo $m$ in binario, $log_2 c^{1 + p(n)} = O(p(n))$ celle per $m$.
Quindi facciamo $O(p(n))$ chiamate, ognuna che occupa $O(p(n)$ celle, per uno spazio complessivo di $O(p^2(n))$.

![](./static/complexity_spaces_adv.png)

### $PS$-completezza

> Diciamo che un problema è ==$PS$-completo== se:
> - $P \in PS$
> - $\forall$ linguaggi $L \in PS$ esiste una riduzione polinomiale da $L \to P$

Questa definizione è comoda in quanto ci potrebbe permettere, qualora esista un problema $PS$-completo che si trova in $P$ (risp. $NP$), allora $PS = P$ (risp. $PS = NP$). Come sempre il bound è imposto anche sull'output della riduzione, in quanto altrimenti pur girando con uno spazio polinomiale le $TM$ potrebbe restituire output di taglia esponenziale. Un teorema formalizza quanto appena detto:

> Se *P* è $PS$-completo,
> 1. Se *P* $\in P$, allora $PS = P$ 
> 2. Se *P* $\in NP$, allora $PS = NP$

La dimostrazione è la seguente: per ogni linguaggio $L$ in $PS$, esiste una rid. polinomiale da $L$ a $P$, che prende tempo $q(n)$. Se *P* $\in P$, allora esiste una algoritmo polinomiale per *P* che gira in tempo $p(n)$. Data quindi una stringa $w$ di lunghezza $n$, possiamo testare se appartiene a $L$ facendo una riduzione polinomiale al problema *P*, che sappiamo prende tempo $q(n)$ e rispondere in tempo $p(n)$, per un tempo complessivo $q(n) + p(q(n))$. Dato che esiste un algoritmo polinomiale per $L$, allora $PS \subseteq P$. Poichè $P \subseteq PS$ per ovvi motivi, allora $P = PS$.

### $QBF$, Quantified Boolean Formula

Una ==$QBF$ è una formula booleana in cui compaiono dei quantificatori all'interno==. I quantificatori sono due:
- $\forall$, indica che in espressione del tipo $\forall x (E)$ sarà vera se, sostituendo tutte le $x$ con vero $E$ sarà vera **e** sostituendo tutte le $x$ con falso $E$ sarà vera;
- $\exists$ indica che in espressione del tipo $\exists x (E)$ sarà vera se, sostituendo tutte le $x$ con vero $E$ sarà vera **o** sostituendo tutte le $x$ con falso $E$ sarà vera.

Per motivi di semplicità non tratteremo formule in cui per una variabile ci sono più di due quantificatori.
Per ridurre il numero di parentesi annidate superflue, espressioni del tipo $(\forall x (\exists y (\forall z (E))))$ saranno scritte come $(\forall x) (\exists y) (\forall z) (E)$ 

Formula booleana quantificata di esempio:
> $(\forall x)((\exists y)(xy) + (\forall z)(\lnot x + z))$

Definiamo dunque una $QBF$ in modo ==ricorsivo==:
- $0,1$ o un qualsiasi letterale sono $QBF$
- se $E$ e $F$ sono $QBF$, allora lo sono anche $(E)$, $\lnot (E)$, $(E) \land $(F)$ e $(E) \lor (F)$
- se $E$ è una $QBF$ che non include quantificatori per $x$, allora $\forall x (E)$ e $\exists x (E)$ sono $QBF$ e $E$ è nello ==scope== di $x$.

Diremo che una variabile che compare nello scope di un qualche quantificatore è ==vincolata==, altrimenti diremo che è ==libera==. Se ci limitiamo a formule senza variabili libere, il valore di un'espressione può essere solo 0 o 1. Per tale motivo possiamo calcolare il valore di una $QBF$ per induzione sulla lunghezza $n$.

**Base induttiva** (n=1): l'espressione ha valore 0 o 1 in quanto possono comparire solo queste due costanti, non possiamo avere variabili altrimenti dovremmo vincolarle;
**Passo induttivo**: assumiamo vero per ogni expr. lunga meno di $n$;
**Induzione**: analizziamo 6 possibili casi:
1. $(E)$: $E$ ha lunghezza $n-2$ e può essere valutata.
2. $\lnot E$: $E$ ha lunghezza $n-1$ e può essere valutata.
3. $EF$: entrambe le expr. hanno lunghezza inferiore di $n$ quindi possono essere valutate. Il risultato è l'and logico dei loro valori.
4. Stesso ragionamento del punto 3, in questo caso il risultato è l'or logico dei loro valori.
5. $(\forall x) (E)$: si rimpiazzano tutti i valori di $x$ con $0,1$, ottenendo rispettivamente $E_0,E_1$. Queste due espressioni non hanno variabili libere e inoltre sono di lunghezza $n-6$ quindi possono essere valutate. Il risultato sarà vero solo se entrambe $E_0,E_1$ sono vere, falso altrimenti.
6. $(\exists x) (E)$: come prima, ma il risultato sarà vero solo se una o entrambe $E_0,E_1$ sono vere, falso se entrambe sono false.

![esempioqbf](./static/qbf_solved.png)

### $QBF$ e $PS$-completezza

Esaminiamo ora il problema di risolvere una $QBF$, ossia dire se ==è soddisfacibile o meno==. Possiamo usare uno stack per risolvere tale problema: partiamo da una formula $F$ di cardinalità $n$. Con spazio $O(n)$ possiamo creare una entry nello stack che memorizza la formula e quale sub-espressione di essa stiamo analizzando. Anche qui avremo nuovamente i 6 casi di prima:
1. $F = (F_1)$: in questo caso creiamo una porzione di nastro con lunghezza $n-2$ e vi copiamo $F_1$ per valutarla. 
2. $F = \lnot F_1$: anche in questo caso creiamo una porzione di nastro con lunghezza $n-1$ e vi copiamo $F_1$ per valutarla. 
3. $F = F_1 + F_2$: in questo caso creiamo una porzione di nastro dove valutare $F_1$, di cui salviamo il risultato e se positivo ritorniamo vero senza calcolare $F_2$, altrimenti facciamo lo stesso per $F_2$. Il risultato sarà l'or dei valori calcolati. 
4. $F = F_1 F_2$: in questo caso creiamo una porzione di nastro dove valutare $F_1$, di cui salviamo il risultato, e valutiamo $F_2$ solo se $F_1$ = 1. Il risultato sarà l'and dei valori calcolati. 
5. $F = (\forall x)(F_1)$: in questo caso creiamo una porzione di nastro dove valutare $F_1$, prima con tutte le $x$ sostituite con $1$: se questa è vera procediamo, altrimenti ritorniamo falso. Valutiamo poi $F_1$ con tutte le $x$ poste a $0$: se anche in questo caso è vera allora ritorniamo $F$ vera. 
6. $F = (\exists x)(F_1)$ : in questo caso creiamo una porzione di nastro dove valutare $F_1$, prima con tutte le $x$ sostituite con $1$: se questa è vera ritorniamo $F$ vera, altrimenti valutiamo $F_1$ con tutte le $x$ poste a $0$: se in questo caso è vera allora ritorniamo $F$ vera, altrimenti se anche questa è falsa ritorniamo falso. 

Come è possibile notare, esaminiamo ogni subespressione una alla volta (idealmente facciamo una visita $DFS$ dell'albero che la rappresenta) e ogni volta analizziamo un record più corto di quello originale. Per tale motivo, anche se da una expr. lunga $n$ possiamo generare $n$ records, abbiamo la garanzia che la loro dimensione sia sempre inferiore ad $n$ e quindi ogni parte di nastro per un record non eccede mai $O(n)$ in lunghezza. Per quanto riguarda invece lo spazio complessivo il bound è $O(n^2)$.
Per quanto riguarda il tempo di esecuzione, sia con una $TM$ che una $NTM$, avremo un ==tempo esponenziale==.

È dunque evidente che:
> $QBF \in PS$

Inoltre mostriamo che:
> $QBF$ è $PS$-completo

La prova funziona, a grandi linee, in questo modo:
- Sia $L \in PS$ un linguaggio accettato da una $TM$ $M$ che usa $p(n)$ spazio su un input lungo $n$. Per un teorema precedente, questa accetta in $c^{1 + p(n)}$ mosse per qualche costante $c$.
- Si costruisce una riduzione polinomiale da $L$ a $QBF$, in modo tale che la formula costruita è soddisfacibile se e solo se la stringa $w$ data come input appartiente a $L$.
- Si creano delle variabili di $ID$ $y_{jA}$ che asseriscono se la $j$-esima posizione della $ID$ ha simbolo $A$ (con $0 < j < p(n)$)
- Si creano $\exists I$ e $\forall I$, dove $I$ è una variabile di $ID$ e indica la combinazione $\forall x_1 \ldots \forall x_m$ (risp. con simbolo $\exists$) per una $ID$ $I$ dove compaiono $x_1 \ldots x_m$.
- Si costruisce dunque la $QBF$: $(\exists I_0)(\exists I_f)(S \land N \land F)$. In questa formula:
  - $I_0, I_f$ rappresentano le $ID$ di inizio e accettazione
  - $S$ indica che $I_0$ è effettivamente la $ID$ di inizio per $M$
  - $N$ indica che $M$ si muove da $I_0$ a $I_f$
  - $F$ indica che $M$ finisce effettivamente con $I_f$