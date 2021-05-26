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
