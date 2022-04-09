# Indecidibilità

## Recall questions
    - Cosa è una riduzione di un problema?
    - Descrivere il teorema sulle riduzioni.
    - Descrivere i linguaggi L_ne e L_e.
    - Cosa dice il teorema di Rice? Perchè riassume buona parte delle dimostrazioni precedenti? 
    - Dimostrare il th. di Rice.

## Trasformazione di problemi

### Riduzione

==Riduzione== (definizione):
>Una riduzione da $P_1$ a $P_2$ è una $TM$ che prende un'istanza di $P_1$ scritta sul nastro e si ferma con un'istanza di $P_2$ sul nastro.

Più semplicemente si tratta di un algoritmo che converte istanze di $P_1$ in instanze di $P_2$ che abbiano la stessa risposta.

È importante che mentre tutte le istanze di $P_1$ devono poter essere trasformate, ==non tutte quelle di $P_2$ devono e possono essere ricondotte a $P_1$==.

Le riduzioni sono utili a ==mostrare che $P_2$ è difficile almeno quanto $P_1$==, come se mettessimo una sorta di lower bound alla complessità del problema.

### Teoremi sulle riduzioni

Mostriamo ora un teorema utile sulle riduzioni

==Teorema== sulle riduzioni:
>Se esiste una riduzione da $P_1$ a $P_2$:
>- se $P_1$ è indecidibile lo è anche $P_2$
>- se $P_2$ è non-$RE$ lo è anche $P_2$

Dimostriamo i due punti teorema:
1. se $P_2$ fosse decidibile, possiamo combinare la riduzione da $P_1$ per fare in modo di costruire una $TM$ che, presa un'istanza di $P_1$, la traduce in una di $P_2$. Questa macchina poi accetterà se $P_1$ accetta, altrimenti non accetterà, in quanto stiamo facendo uso della riduzione. In questo modo abbiamo costruito una macchina che decide $P_1$, ovvero un algoritmo, ma per ipotesi $P_1$ era indecidibile (**contraddizione**);
2. se $P_2$ fosse $RE$, allora possiamo sfruttare di nuovo la riduzione. Se infatti un'istanza del problema (che non può essere accettato da una $TM$) viene dato in input alla $TM$ per $P_2$ dopo essere stato ridotta, questa accetterà se $P_2$ accetta. Ma in questo modo abbiamo costruito una $TM$ che accetta indirettamente istanze di $P_1$, che per ipotesi era non-$RE$. (**contraddizione**)

## Linguaggi $L_e$ e  $L_{ne}$ (complementari)

### Linguaggio $L_{ne}$

Si tratta del linguaggio ==delle codifiche di tutte le $TM$ con almeno una stringa nel linguaggio, ovvero che accettano almeno una stringa==. 

Mostriamo ora che ==(theorem)==:
>$L_{ne} \in RE$, ossia è ricorsivamente enumerabile

La dimostrazione consiste nel creare una $TM$ non-deterministica che accetta $L_{ne}$, che chiameremo $M$:
- $M$ prende il codice per la $TM$ $M_i$ con input
- $M$ "indovina", facendo uso del non-determinismo, una input $w$ per $M_i$
- $M$ poi testa se $M_i$ accetta l'input $w$ simulando la $TM$ del linguaggio universale $U$
- se $U$ accetta allora lo fa anche $M_i$ e di conseguenza $M$ accetta

Mostriamo ora che ==(theorem)==:
>$L_{ne} \in R$, ossia non è ricorsivo

Dimostrando questo teorema ne verrà ovviamente che $L_e \notin RE$, in quanto se entrambi fossero in $RE$ allora sarebbero anche in $R$. Lo faremo riducendo il linguaggio universale a $L_ne$, ossia mostrando che questo è difficile almeno quanto $L_u$ che sappiamo essere in $RE$.

Costruiamo un algoritmo di riduzione $RED$ che converte un input $(M,w)$ nel codice di una $TM$ $M_1$ tale che $L(M_1) \neq \emptyset$ se e solo se $M$ accetta $w$:
- $M_1$ ignora il suo input $x$, qualsiasi esso sia, e lo reimpiazza con la coppia $(M,w)$
- procede poi simulando la $TM$ del linguaggio universale $U$
- se $U$ accetta, allora $M_1$ accetta

Avremo in output una $TM$ che accetta sempre (qualunque sia l'input) se la coppia $(M,w)$ è accettata da $U$, altrimenti rifiuterà sempre. Avendo compiuto una riduzione,conlcudiamo quindi che $L_{ne}$ è difficile almeno quanto $L_u$ e quindi non si può trovare in $R$.

![](../../..//TCC/reduction_from_universal_to_nonempty.png)

### Linguaggio $L_e$

Si tratta del linguaggio ==delle codifiche di tutte le $TM$ con linguaggio vuoto, ovvero che non accettano stringhe==. 

Formalmente $L_e = \{M | (L(M) = \emptyset\}$ e $L_{ne} = \{M | (L(M) \neq \emptyset\}$

Ovviamente, date le conclusioni precedenti (==theorem==):
>$L_e \notin RE$

Per ricapitolare:

![](../../..//TCC/second_lang_classificiation.png)

## Th. Rice e proprietà linguaggi in $RE$

### Proprietà dei linguaggi

Una ==proprietà dei linguaggi $RE$== non è altro che ==un insieme di linguaggi $RE$==.
- un esempio sono tutti i $CFL$

Diremo inoltre che una ==proprietà== è:
- ==banale== se l'insieme di linguaggi è vuoto o è tutto $RE$
- ==non-banale== altrimenti

Di seguito faremo riferimento non tanto ai linguaggi con certe proprietà quanto a macchine di Turing che li accettino. Questo perchè i linguaggi, per loro definizione, sono infiniti e quindi non potrebbero essere input di un algoritmo che riconosce se verificano una certa proprietà.
==Quindi se $P$ è una proprietà dei linguaggi $RE$, allora $L_p$ è il linguaggio che rappresenta l'insieme di $TM$ $M_i$ tali che $L(M_i)$ è un linguaggio in $P$==.
==Quando parliamo di decidibilità di una proprietà $P$, intendiamo la decidibilità di $L_p$==.

### Teorema di Rice

==Teorema di Rice==:
>Ogni proprietà non banale dei linguaggi $RE$ non è decidibile, ovvero non esiste una $TM$ che riconosce se una stringa che codifichi una $TM$ rispetti la proprietà.

Dimostriamo ora il teorema: sia $P$ una proprietà non banale e supponiamo che il linguaggio vuoto non sia in $P$ - ovvero che ci sia almeno una macchina che riconosce un linguggio con tale proprietà. Sia $L$ tale linguaggio e $L = L(M_L)$. Se riduciamo $L_u$ a $L_p$ proviamo che questo è indecidibile.

![](../../..//TCC/rice_theorem_proof1.png)

La riduzione prende in input una coppia $(M,w)$ e produce il codice per $M_1$:
- se $M$ accetta $w$, allora $L(M_1) = L$
- altrimenti $L(M_1) = \emptyset$

$M_1$ sarà una macchina a due nastri:
- il primo simula $M$ su input $w$
- il secondo simula $M_L$ su input $x$

E si comporta nel seguente modo:
- simula $M$ su input $w$ con la $TM$ universale
- se $M$ non accetta $w$ non fa nient'altro
- se accetta, allora simula $M_L$ su input $x$

È chiaro che questa modifica può essere scritta sotto forma di un algoritmo, quindi abbiamo effetivamente una riduzione che prova che il generico $L_p$ dove $P$ è una ==proprietà non banale== è difficile almeno quanto $L_u$.

Rimane solo il caso in cui $\emptyset \in P$. Se consideriamo il complemento di $P$, ossia $\neg P$, sappiamo che questo è indecidibile (per il th. di Rice). È facile vedere che se $P$ fosse stato decidibile,  allora lo sarebbe stato anche il suo complemento, che per ipotesi è però indecidibile (**contraddizione**).