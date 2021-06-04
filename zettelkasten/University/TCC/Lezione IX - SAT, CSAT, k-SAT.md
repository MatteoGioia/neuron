# Satisfiability, CSAT e k-SAT

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

### $SAT$ - satisfiability

Il problema di ==soddisfare un'espressione booleana== è un noto problema ==$NP$-completo==. Per farlo, mostriamo con una riduzione come ogni linguaggio di una $NTM$ si riduce polinomialmente al problema della soddisfacibilità.

Questo è enunciato dal ==teorema di Cook==:
> SAT è $NP$-completo

Dimostrare questo teorema è composto di due parti: mostrare che SAT è $NP$, facile, e poi mostrare come ogni linguaggio in $NP$ si riduce ad esso, difficile. 

Dimostriamo la prima parte, ossia che ==SAT è in $NP$==. Per fare ciò, dobbiamo costruire una $NTM$ che possa accettare tale problema.

Possiamo costruire una macchina che sfrutta il ==non determinismo== per "indovinare" delle assegnazioni di verità $T$ per la nostra espressione $E$ di partenza. Al termine di questo processo, se $E$ è lunga $n$, allora avremo al massimo $2^n$ descrizioni istantanee della $NTN$ che descrivono ognuna un diverso $T$. Tale generazione avviene in tempo $O(n)$ su una $NTM$ che sia multinastro.
Queste descrizioni sono poi lette da una $TM$ deterministica che le valuta e accetta se ne trova un $T$ t/c l'espressione sia soddisfatta. Se usiamo una $NTM$ multinastro tale valutazione avviene più rapidamente, in tempo $O(n^2)$.
In totale il tempo impiegato dalla $NTM$ multinastro è $O(n + n^2) = O(n^2)$, corrispondente a $O(n^4)$ per una $NTM$ mononastro. 
È evidente che $SAT \in NP$.

La parte difficile è provare che ==ogni problema $NP$ è riducibile a $SAT$==. La prova avviene, a grandi linee, in questo modo:

- $L$ generico è $\in NP$, ossia esiste una $NTM$ $M$ e un tempo polinomiale $p(n)$ tale che $M$ non ha mosse più lunghe di $p(n)$.
- se $M$ accetta una stringa $w$, allora esiste una sequenza di mosse $\alpha_0 \vdash \alpha_1 \vdash \ldots \vdash \alpha_k$ dove
  - $k < p(n)$
  - $\alpha_0$ è la ID iniziale su input $w$
  - $\alpha_k$ codifica invece uno stato di accettazione
- È possibile costruire una espressione $E_{M,w} = U \land \land N \land F$ che è soddisfacibile $\iff$ $M$ accetta $w$ dove
  - $S, N, F$ sono vere se $M$ inizia, si muove e finisce a destra,
  - $U$ è vera solo se esiste un simbolo unico in ogni cella di $M$.

![](./static/sat_reductions.png)

<small> La dimostrazione è presente sul libro, wikipedia o youtube.... ed è parecchio lunga :) </small>

---

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

### $CSAT$ e $k-SAT$

Di seguito useremo le seguenti abbreviazioni per indicare i problemi:

==$CSAT$==
> Una data espressione booleana in $CNF$ è soddisfacibile?

==$k-SAT$==
> Una data espressione booleana in $k-CNF$ è soddisfacibile? 

### Da $SAT$ a $CSAT$: conversione in $CNF$

==Equivalenza di espressioni booleane==:
> Due espressioni booleane sono equivalenti se danno lo stesso risultato per ogni assegnazione di valori di verità alle variabili.

Dobbiamo ora trovare un modo di passare da $SAT$ a $CSAT$, tuttavia la conversione in una versione equivalente può produrre ==istanze esponenziali in quella di partenza==. Per risolvere il problema notiamo però che basta che ==l'istanza $F$, ridotta da $E$, sia soddisfacibile $\iff$ lo è anche $E$==.

Tale riduzione viene operata in 2 punti:
1. in tempo $O(n^2)$ dove $n$ è la lunghezza di $E$, usando le ==leggi di De Morgan==, tutte le negazioni sono ==spinte sulle foglie dell'albero== che rappresenta l'espressione, in modo da avere un mix di $\lor$ o $\land$ e letterali negati equivalente alla exp. di partenza
2. trasformiamo l'espressione in ==$CNF$== anche introducendo nuove variabili in tempo polinomiale

Al termine dei due step $F$ sarà soddisfacibile $\iff E$ lo è (ma non sarà necessariamente equivalente). Più precisamente, vediamo che se esiste $T$, un'assegnazione che soddisfa $E$, $F$ è soddisfacibile da ==estensioni $S$ di $T$==. Una ==estensione== di $T$ non fa altro che assegnare alle variabili che sono anche in $T$ i valori originali, ma può assegnare a quelle aggiunte valori a piacimento.

Introduciamo inoltre un teorema che dimostra il primo step, ossia ==il passaggio ad una versione con la negazione solo ai letterali==:
> Per ogni espressione booleana $E$ esiste un'espressione equivalente $F$ in cui le negazioni compaiono solo nei letterali, cioè si applicano direttamente alle variabili. Inoltre la lunghezza di $F$ è lineare nel numero di simboli $E$, e $F$ si costruisce da $E$ in tempo polinomiale.

==Dimostrazione== del teorema:
- **Claim**: per ogni $E$ esiste una espressione equivalente $F$ con la negazione solo ai letterali e se $E$ ha $\geq 1$ operatori allora $F$ ne ha $\leq 2n - 1$. *Considerazione da aggiungere* 
- **Base induttiva**: se $E$ possiede un operatore, allora deve essere nella forma $\lnot x$, $x \lor y$ oppure $xy$. In ogni caso, sia $E$ che $F$ hanno 1 solo operatore, quindi la formula rimane valida
- **Passo induttivo**: assumiamo che il teorema sia vero per tutte le espressioni con meno operatori di $E$; dobbiamo mostrare 3 casi: 
  - $E = E_1 \lor E_2$
  - $E = E_1 \land E_2$
  - $E = \lnot E_1$ 

Nel primo e secondo caso vediamo che per ipotesi induttiva da $E_1, E_2$ possiamo costruire $F = F_1 \lor F_2$ oppure $F = F_1 \land F_2$. Dobbiamo ancora verificare che l'affermazione sul numero di operatori è vera. Se $E_1, E_2$ hanno rispettivamente $a,b$ operatori, allora in entrambi i casi $E$ ne ha esattamente uno in più, ovvero $a + b + 1$. Per ipotesi sappiamo che $F_1$ ha $2a - 1$ operatori e $F_2$ ne ha $2b - 1$, ovvero $F$ ne ha $2a + 2b - 1$, sicuramente $\leq 2(a + b + 1) - 1= 2a + 2b + 1$.

Il terzo caso è il più complesso, in quanto si articola a sua volta in 3 sottocasi:
1. $E_1 = \lnot E_2$: dato che la negazione è doppia, $E = E_2$. Per ipotesi induttiva, deve esistere $F_2$ equivalente a $E_2$ che soddisfa l'affermazione iniziale. Se creiamo $F = F_2$ questa contiene al più 2 volte gli operatori di $E_2$ meno uno, che sono $\leq$ doppio di operatori di $E$ - 1.
2. $E_1 = E_2 \lor E_3$: se applichiamo la legge di De Morgan possiamo considerare in realtà che $E = \lnot (E_2 \lor E_3)$ vediamo che questa è uguale a $\lnot E_2 \land \lnot E_3$. Possiamo quindi costruire le equivalenti $F_2, F_3$ e poi $F = F_2 \land F_3$, equivalente a $E$. Se $E_2, E_3$ avevano rispettivamente $a,b$ operatori, $E$ ne ha $a + b + 2$. La loro negazione $\lnot E_2, \lnot E_3$ ne ha uno in più, quindi $F_2, F_3$ hanno al più $2(a + 1) - 1$ e $2(b + 1) - 1$ operatori, quindi $F$ ne ha $2a + 2b + 3 = 2(a + b + 2) - 1$, che rispetta l'ipotesi di partenza (essendo il doppio di $E$ meno uno).
3. La dimostrazione è la stessa di sopra: prima si applica la legge di De Morgan e poi si procede al conteggio degli operatori.

Fatta questa parte dobbiamo mostrare la riduzione vera e propria, ossia come ==passiamo da una formula con le negazioni ai letterali a una formula in CNF==.

Vogliamo provare che (==teorema==):
> CSAT è NP-completo

La riduzione avviene nel seguente modo:
1. Convertiamo $E$ nella versione in cui la negazione appare solamente accanto ai letterali. Per il teorema precedente sappiamo che il risultato è una exp. equivalente a quella di partenza.
2. Convertiamo $E$ in una espressione $F$ in $CNF$ soddisfacibile $\iff$ $E$ lo è. 

Il secondo step (la costruzione di $F$), avviene per induzione sulla lunghezza di $E$, in particolare sul numero di simboli presenti all'interno $n$:
1. $F$ è in $CNF$ e non è formata da più di $n$ clausole
2. $F$ si può costruire da $E$ in tempo non superiore a $c |E|^2$
3. Un assegnamento di valori di verità $T$ per $E$ rende $E$ vera $\iff$ c'è un'estensione $S$ di $T$ che rende vera $F$.

I passi dell'induzione sono i seguenti:
- **Base induttiva** $n=1, n=2$: se $E$ consiste di uno o due simboli,è un letterale. Un letterale è una clausola e quindi è in CNF.
- **Passo induttivo**: Assumiamo che ogni espressione più corta di $E$ si possa convertire in prodotto di clausole in temponon superiore a $c |E|^2$ per $E$ lunga $n$. Dobbiamo distinguere anche qui 2 casi:
  - $E = E_1 \land E_2$
  - $E = E_1 \lor E_2$

Mostriamo il ==primo caso==: per ipotesi induttiva esistono $F_1, F_2$, entrambe in $CNF$, derivate esattamente da $E_1, E_2$. Tutti e soli gli assegnamenti soddisfacenti per $E_1(E_2)$ possono essere estesi per soddisfare $F_1(F_2)$. Inoltre, w.l.g, supponiamo che gli insiemi di variabili di $F_1,F_2$ siano disgiunti, tranne per le variabili che figurano in $E$, e se dobbiamo introdurre nuove variabili le scegliamo diverse. 
Costruiamo $F = F_1 \land F_2$, che sicuramente è in $CNF$ essendo *and logico* di due formule in $CNF$ e mostriamo come estendere $T$ che soddisfa $E$ a $S$ che soddisfa $F \iff T$ soddisfa $E$.

**SE**: supponiamo che $T$ soddisfi $E$. Sia $T_1$ esattamente come $T$ ma limitato alle variabili presenti in $E_1$, stessa cosa per $T_2$ limitatamente a $E_2$. Per ipotesi induttiva, sappiamo che $T_1,T_2$ possono essere estesi a $S_1,S_2$ che soddisfano $F_1,F_2$. Definiamo quindi $S$ in accordo con $S_1, S_2$; poichè le sole variabili comuni a $F_1,F_2$ sono quelle di $E$ e $S_1,S_2$ devono coincidere su esse se entrambe definite, è sempre possibile costruire $S$, estensione di $T$ che soddisfa $F$.

**SOLO SE**: sia $S$ un estensione di $T$ che soddisfa $F$. Sia $T_1(T_2)$ come $T$, ma limitato alle variabili di $E_1(E_2)$. Sia $S_1(S_2)$ una restrizione di $S$ rispetto le variabili di $F_1(F_2)$. Allora $S_1, S_2$ estendono rispettivamente $T_1,T_2$. Poichè $F = $F_1 \land F_2$, allora $S_1, S_2$ soddisfano $F_1,F_2$. Per ipotesi induttiva, $T_1,T_2$ soddisfano $E_1,E_2$ e quindi $T$ soddisfa $E$.

Mostriamo ora il ==secondo caso==: anche qui facciamo le assunzioni fatte precedentemente su $F_1,F_2$. Dovendo costruire una $CNF$, non possiamo fare solo l'*and* delle espressioni di partenza, tuttavia non dovendo mantenere l'equivalenza, possiamo alterare la costruzione in modo da ottenere una $CNF$. Supponiamo infatti che $F_1 = g_1 \land g_2 \land \ldots \land g_p$ e $F_2 = h_1 \land h_2 \land \ldots \land h_q$, dove le varie $g,h$ sono tutte clausole. Introduciamo una nuova variabile, $y$, e la inseriamo nella formula $F$:
> $F = (y + g_1) \land (y + g_2) \land \ldots \land (y + g_p) \land (\lnot y + h_1) \land (\lnot y + h_2) \land \ldots \land (\lnot y + h_q)$

Notare che avendo aggiunto una variabile in *or* le clausole rimangono tali. 

**SOLO SE**: supponiamo che $T$ soddisfi $E$. Come nel caso 1, siano $T_1,T_2$ come $T$ ma limitatamente a $E_1,E_2$. Dato che $E$ è un *or* di espressioni, o $T_1$ soddisfa $E_1$ o $T_2$ soddisfa $E_2$. Possiamo suppore che soddisfi $E_1$ (in caso sia $E_2$ può essere fatto il ragionamento analogo). Allora $T_1$ può essere esteso a $S_1$ che soddisfa $F_1$. Costruiamo $F$ in modo tale che soddisfi la $F$ costruita sopra:
1. Per ogni variabile $x$ in $F$, $S(x) = S_1(x)$
2. $S(y) = 0$: facendo così le clausole nella seconda parte derivate da $F_2$ diventano tutte vere
3. Per ogni variabile $x$ presente in $F_2$ ma non in $F_1$, questa coincide con la sua assegnazione in $T$ se definita, altrimenti può variare liberamente.

L'estensione $S$ così definita soddisfa quindi $F$. In caso $E_2$ fosse stata la formula che soddisfaceva quella di partenza, basta porre $S(y) = 1$ e operare lo stesso ragionamento. (**e se erano entrambe vere in partenza???**) 

**SE**: Supponiamo di estendere l'assegnamento di valori di verità di $T$ per $E$ ad un assegnamento $S$ per $F$, e che $S$ soddisfi $F$. A seconda del valore di verità assegnato a $y$, ci sono due casi.
1. $S(y) = 0$: tutte le clausole $F$ derivate dalla parte $h$ sono vere, quindi la formula originale non doveva curarsi della prima parte $F_1$ perchè era già vera. Prendiamo $S_1$, la parte di $S$ relativa solo a $F_1$. Questa è estensione di $T_1$, assegnamento di valori di verità relativo a $E_1$ che lo soddisfa per induzione. Quindi $T$ soddisfa $E$ perchè $T_1$ soddisfa $F_1$.
2. $S(y) = 1$: simmetrico al caso precedente.

Rimane dunque da mostrare solo la complessità temporale per costruire $F$ da $E$, che vogliamo dimostrare essere ==al massimo quadratica in $n$==, in modo da poter dire che la riduzione è polinomiale.
In ogni caso la separazione di $E$ in $E_1, E_2$ e la costruzione di $F$ da $F_1,F_2$ richiedono ==tempo lineare== nella dimensione di $E$. Se $dn$ è un limite superiore al tempo impiegato per dividere $E$ sommato a quello per costruire $F$, allora il tempo totale per costruire $F$ è dato da un'equazione di ricorrenza del tipo:
> $T(1) = T(2) \le e$, con $e$ che è una costante \
> $T(n) \le dn + c \space max_{0 < i < n-1}(T(i) + T(n-1-i))$

dove il valore della costante $c$ deve essere determinato in modo tale che $T(n) \le cn^2$. La formula di base corrisponde a quando $E$ è fatta di 1o 2 simboli, ossia un letterale. La clausola ricorsiva invece sfrutta il fatto che $E$ è composta da $E_1,E_2$, lunghe rispettivamente $i, n - i - 1$ (-1 corrisponde al simbolo $\land$ o $\lor$ che le unisce). Infatti la formula finale è la somma del tempo usato per splittare $E$ e quello per costruire $F$, che è $dn$, sommato al tempo per convertire $E_1,E_2$ in $F_1,F_2$, che calcoliamo invece con la ricorsione.
Dimostriamo dunque, tramite l'induzione, che esite sempre una costante $c$ che rende vero $ T(n) \le cn^2$:
- **Base induttiva**: per $n=1,2$, basta scegliere $c \geq e$ 
- **Passo induttivo**: supponiamo vero l'enunciato per lunghezze inferiori a $n$. Allora $T(i) \le ci^2$ e $T(n - i - 1) \le c(n - i - 1)^2$. Da questo ne deriva che $T(i) + T(n - i - 1) \le c(n^2 - 2i(n-i) - 2(n-i) + 1)$. Poichè $n \geq 3$ e $0 < i < n - 1$, $2(n-i) \geq 2$. Quindi il membro destro della formula è minore di $n^2 - n$ per ogni valore ammissibile di $i$. La parte ricorsiva della formula diventa quindi $T(n) \le dn + cn^2 - cn$. Scegliendo $c \geq d$ deduciamo che $T(n) \le cn^2$ è vera per $n$. La costruzione di $F$ da $E$ richiede tempo $O(n^2)$.
  
---

### Da $CSAT$ a $3-SAT$

Mostriamo infine una ==restrizione di $CSAT$==, detta $k-SAT$. Nel dettaglio noi ci concentreremo su ==$3-SAT$, dove le clausole hanno tutte 3 letterali==, e mostreremo che:
> $3-SAT$ è $NP$-completo

In generale $k-SAT$ è $NP$-completo per $k \geq 3$.

Per mostrare l'$NP$-completezza, dato che sappiamo che il problema è in $NP$, ci basta operare una riduzione polinomiale. Questa riduzione partirà proprio da $CSAT$, in quanto creeremo una formula in $3-SAT$ soddisfacibile $\iff$ lo è quella di partenza in $CNF$, nel dettaglio esisterà ==un'estensione di un assegnamento di valori di verità per la formula di partenza== che la rende tale.

Partendo da un espressione in $CNF$, $E = e_1 \land e_2 \land \ldots e_k$, formiamo una espressione sostituendo le $e$ come indicheremo di seguito, a seconda del caso:
1. Se $e_i$ è un singolo letterale, poniamo $x$, introduciamo due nuove variabili $v,u$ e sostituiamo la clausola $e_i = x$ con $e_i = (x + u + v)(x + \lnot u + v)(x + u + \lnot v)(x + \lnot u + \lnot v)$. Le variabili $u,v$ compaiono in tutte le combinazioni (negate e non), quindi l'unico modo di rendere vera la formula è rendere vera $x$. 
2. Se $e_i = x + y$, allora la sostituiamo con $e_i = (x + y + v)(x + y + \lnot v)$: anche qui il solo modo di rendere vera l'espressione di è rendere vera o $x$, oppure $y$.
3. Se $e_i$ è gia la somma di 3 letterali possiamo lasciarla invariata
4. Se $e_i = x_1 + x_2 + x_3 + \ldots x_m$, con $m \geq 4$, allora creiamo $y_1, y_2, \ldots y_{m-3}$ e sostituiamo $e_i = (x_1 + x_2 + y_1)(x_3 + \lnot y_1 + y_2)(x_4 + \lnot y_2 + y_3) \ldots$$(x_{m-2} + \lnot y_{m-4} + y_{m-3})(x_{m-1} + x_m + \lnot y_{m-3})$. In questo caso vediamo che un assegnamento $T$ che soddisfa $E$ dovrà rendere vero almeno un letterale di $e_i$, sia $x_j$. Se dichiariamo $y_1 \ldots y_{j-2}$ vere e $y_{j-1}, y_{j+1}, \ldots, y_{m-3}$ false, allora tutte le clausole di questa nuova formula diventano vere. Inoltre non è possibile creare estensioni che rendano vera la formula se quella di partenza era falsa, in quanto le clausole sono $m-2$ clausole, ma solo $m-3$ variabili $y$ che possono rendere vera una sola clausola a testa.

È facile anche vedere che la costruzione viene fatta in tempo lineare (nel caso peggiore l'espansione dei simboli è al massimo di un fattore $\frac{32}{3}$, come nel caso 1), inoltre è possibile costruire un'estensione $T$ che soddisfi la formula $\iff$ quella di partenza lo era. Ne deriva che $3-SAT \in NP-complete$