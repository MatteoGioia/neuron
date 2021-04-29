# Problemi Intrattabili II

## Recall questions
    - Come possiamo rappresentare istanze di SAT in modo da renderle accettabili per una TM?
    - Cosa è SAT? Come si dimostra che è NP completo e perchè è utile?
    - A cosa ci servono le versioni ristrette di SAT?
    - Cosa sono i letterali, le clausole, la CNF e le k-CNF?
    - Cosa è CSAT e k-SAT?
    - Come si passa da una exp. di SAT a una di CSAT? Sono necessariamente equivalenti? Che step dobbiamo fare?

## Problemi intrattabili 

<small> Per la notazione specifica cfr. pg 403,404,405</small>

### Rappresentazione delle istanze di SAT

Di seguito le $NTM$ che accettano $SAT$ riceveranno istanze dove i simboli $x_1 , \ldots , x_n$ sono rappresentati nella forma $X$ + binary
(es. $x_4 = X100$). Gli operatori logici (e le virgole) saranno invece rappresentati da se stessi.

Il motivo  di tale scelta è che in tal modo i simboli dell'alfabeto sono finiti (solo 8), ma possiamo comunque rappresentare gli infiniti simboli che potrebbero fare parte di una espressione booleana. Questo ci permette di trattare $SAT$ come un ==problema== risolvibile da una $TM$.

<small> Per capire meglio l'ultima considerazione vedi anche #[[Lezione VII - Undecidability II]]</small>

### SAT - satisfiability

Il problema di ==soddisfare un'espressione booleana== è un noto problema ==$NP$-completo==. Per farlo, mostriamo con una riduzione come ogni linguaggio di una $NTM$ si riduce polinomialmente al problema della soddisfacibilità.

Questo è enunciato dal ==teorema di Cook==:
> SAT è $NP$-completo

Dimostrare questo teorema è composto di due parti: mostrare che SAT è $NP$, facile, e poi mostrare come ogni linguaggio in $NP$ si riduce ad esso, difficile. 

Dimostriamo la prima parte, ossia che ==SAT è in $NP$==. Per fare ciò, dobbiamo costruire una $NTM$ che possa accettare tale problema.

Possiamo costruire una macchina che sfrutta il ==non determinismo== per "indovinare" delle assegnazioni di verità $T$ per la nostra espressione $E$ di partenza. Al termine di questo processo, se $E$ è lunga $n$, allora avremo al massimo $2^n$ descrizioni istantanee della $NTN$ che descrivono ognuna un diverso $T$. Tale generazione avviene in tempo $O(n)$ su una $NTM$ che sia multinastro.
Queste descrizioni sono poi lette da una $TM$ deterministica che le valuta e accetta se ne trova un $T$ t/c l'espressione sia soddisfatta. Se usiamo una $NTM$ multinastro tale valutazione avviene più rapidamente, in tempo $O(n^2)$.
In totale il tempo impiegato dalla $NTM$ multinastro è $O(n + n^2) = O(n^2)$, corrispondente a $O(n^4)$ per una $NTM$ mononastro. 
È evidente che $SAT \in NP$.

La parte difficile è provare che ==ogni problema $NP$ è riducibile a $SAT$. La prova avviene, a grandi linee, in questo modo:

- $L$ generico è $\in NP$, ossia esiste una $NTM$ $M$ e un tempo polinomiale $p(n)$ tale che $M$ non ha mosse più lunghe di $p(n)$.
- se $M$ accetta una stringa $w$, allora esiste una sequenza di mosse $\alpha_0 \vdash \alpha_1 \vdash \ldots \vdash \alpha_k$ dove
  - $k < p(n)$
  - $\alpha_0$ è la ID iniziale su input $w$
  - $\alpha_k$ codifica invece uno stato di accettazione
- È possibile costruire una espressione $E_{M,w} = U \land \land N \land F$ che è soddisfacibile $\iff$ $M$ accetta $w$ dove
  - $S, N, F$ sono vere se $M$ inizia, si muove e finisce a destra,
  - $U$ è vera solo se esiste un simbolo unico in ogni cella di $M$.

![](./static/placeholder.png)

<small> La dimostrazione è presente sul libro, wikipedia o youtube.... ed è parecchio lunga :) </small>

### Versione ristretta di $SAT$

Di seguito useremo un problema più semplice da trattare rispetto a $SAT$, detto $3-SAT$. Questo problema è una riduzione di un'istanza generica di $SAT$, tuttavia, visto che tale istanza ridotta può avere dimensione esponenziale in quella originale, dovremo fare manipolazioni algebriche scaltre per avere una ==riduzione polinomiale==. Infatti non ci interessa che le due istanze siano equivalenti, ma solo che la risposta alla domanda sulla soddisfaciblità sia la stessa.

Questo ci sarà utile in quanto useremo $3-SAT$ per dimostrare che altri problemi sono $NP$-completi, operando una riduzione da $3-SAT$, che mostreremo $NP$-completo, a tali problemi.

### Definizioni utili

Di seguito diamo delle definizioni utili allo studio del problema da presentare.

==Letterale==
> Variabile oppure variabile negata 

==Clausola==
> Disgiunzione logica ($\lor$) di uno o più letterali (anche il letterale solo è considerato una clausola)

==Forma normale congiuntiva (CNF)==
> Espressioni che sono congiunzione ($\land$) di una o più clausole

==$k-CNF$==:
> Espressione booleana in $CNF$  dove le clausole sono somme di $k$ letterali

Per brevita inoltre sarà usato $+$ al posto di $\lor$ e il prodotto al posto di $\land$

### CSAT e k-SAT

Di seguito useremo le seguenti abbreviazioni per indicare i problemi:

==$CSAT$==
> Una data espressione booleana in $CNF$ è soddisfacibile?

==$k-SAT$==
> Una data espressione booleana in $k-CNF$ è soddisfacibile? 

### Da $SAT$ a $CSAT$: conversione in $CNF$

==Equivalenza di espressioni booleane==:
> Due espressioni booleane sono equivalenti se danno lo stesso risultato per ogni assegnazione di valori di verità alle variabili.

Dobbiamo ora trovare un modo di passare da $SAT$ a $CSAT$, tuttavia la conversione in una versione equivalente può produrre ==istanze esponenziali in quella di partenza==. Per risolvere il problema notiamo però che basta che ==l'istanza $F$, ridotta da $E$, sia soddisfacibile $\iff$ lo è anche $E$.

Tale riduzione viene operata in 2 punti:
- in tempo $O(n^2)$ dove $n$ è la lunghezza di $E$, usando le ==leggi di De Morgan==, tutte le negazioni sono ==spinte sulle foglie dell'albero== che rappresenta l'espressione, in modo da avere un mix di $\lor$ o $\land$ e letterali negati equivalente alla exp. di partenza
- trasformiamo l'espressione in ==$CNF$== anche introducendo nuove variabili in tempo polinomiale

Al termine dei due step $F$ sarà soddisfacibile $\iff E$ lo è (ma non sarà necessariamente equivalente). Più precisamente, vediamo che se esiste $T$, un'assegnazione che soddisfa $E$, $F$ è soddisfacibile da ==estensioni $S$ di $T$==. Una ==estensione== di $T$ non fa altro che assegnare alle variabili che sono anche in $T$ i valori originali, ma può assegnare a quelle aggiunte valori a piacimento.

Introduciamo inoltre un teorema utile alla dimostrazione del primo step:
> Per ogni espressione booleana $E$ esiste un'espressione equivalente $F$ in cui le negazioni compaiono solo nei letterali, cioè si applicano direttamente alle variabili. Inoltre la lunghezza di $F$ è lineare nel numero di simboli $E$, e $F$ si costruisce da $E$ in tempo polinomiale.