# Introduzione a TCC

## Recall questions
    - WIP

## Nozioni di base

### Prove deduttive

Prova deduttiva: ==sequenza di affermazioni== la cui verità conduce da una ipotesi 
iniziale fino ad una tesi.

Ogni step deve essere logicamente corretto:
- i.e. si basa su ragionamenti precedenti
- i.e. si basa su teoremi dimostrati
  
### Forme dei teoremi

Alcune forme di teorema ricorrenti:
- ==if A then B==: se l'ipotesi è vera per certi parametri allora lo è anche la tesi (per gli stessi parametri)
- ==A if and only if B==: entrambi i versi di sopra
- teoremi senza ipotesi apparente

### Equivalenza di sets

Per provare l'equivalenza di 2 insiemi $E,F$ si dimostra che un ==elemento== appartenente a $E$ appartiene a $F$ e viceversa.

$E = F$ significa che:
- se $x \in E$ allora $x \in F$
- se $x \in F$ allora $x \in E$

### Il contropositivo

Il contropositivo ==non== è il ==converso==, ma una ==forma equivalente== dove i termini
appaiono negati.
- i.e. $A \to B$ diventa $\lnot A \to \lnot B$ 

### Prova tramite contraddizione e controesempi

Affermazioni come *se A allora B* possono essere dimostrate per contraddizione,
dimostrando che $A \land \lnot C \to \bot$.

Teoremi nella forma $\forall x \space then$ oppure $\not \exists x \space t.c.$ possono essere confutati tramite controesempio
- infatti la negazione logica in entrambi i casi è dimostrare almeno un caso contrario

### Prove per induzione e induzione strutturale

Prove induttive di una proprietà $S(n)$ con $n \geq i$ sono composte da:
- una ==base== 
- uno ==step induttivo==

Prove per ==induzione strutturale== si applicano su ==strutture definite ricorsivamente==:
- la base consiste nel provare che $S(X)$, ovvero che la proprietà è vera per la struttura di base X
- assunto che la proprietà sia vera per $Y_1 , \ldots , Y_k$ si dimostra che questa è nuovamente vera per
  $X$ definito come struttura risultante dall'unione di $Y_1 , \ldots , Y_k$

### Variante: induzione di Cauchy

Per provare che $P(n)$ è vera per tutti i naturali:
- base: provare $P$ per uno specifico $n$
- step forward: provare che $P(n) \to $P(i)$, dove $i = n_1 < n_2 < \ldots < n_k$ ovvero è vera per un set infinito o una sequenza di numeri naturali
- step backwards: provare che $P(m) to $P(m-1)$ 

## Concetti su automi e linguaggi

### Alfabeti, stringhe e linguaggi

==Alfabeto==: set finito e non vuoto di simboli comunemente indicato con $\Sigma$

==Stringa==: sequenza finita di simboli nel linguaggio scelto

==Potenze di alfabeti==:
- $\Sigma = \{0,1\}$ è **solo** l'alfabeto
- $\Sigma^0 = \epsilon$ per qualsiasi alfabeto 
- $\Sigma^k$ = è l'insieme di stringhe di lunghezza $k$ sull'alfabeto $\Sigma$

==Linguaggio==: set di stringhe scelte da $\Sigma^*$. Inoltre se $\Sigma$ è un alfabeto e $L \in \Sigma$ allora è detto linguaggio su $\Sigma$

### Problemi decisionali e costruttivi

==Problema==: questione di decidere se una data stringa appartiene o meno ad un certo linguaggio
- ==istanza==: input del problema

Problema ==concreto== se la risposta è una ==stringa==, ==decisionale== se la risposta ==$\in \{1,0\}$==

In seguito verranno affrontati problemi la cui versione comune è costruttiva, nel senso che si intende trovare una soluzione concreta, e.g. al problema del cammino minimo. Tuttavia sarà dimostato che in questi casi rispondere al problema decisionale associato e che questo ha difficoltà *non superiore* a quella del problema formulato in termini di ottimizzazione.

Nel caso del problema del cammino minimo, esso infatti diventa: *È possibile trovare un cammino minimo di lunghezza al più k?*, la cui soluzione può essere poi ottenuta col problema di ottimizzazione, banalmente usando un algoritmo che cerchi un cammino minimo ma di lunghezza al massimo $k$.




