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

### Considerazioni su $PS$ e $NPS$

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