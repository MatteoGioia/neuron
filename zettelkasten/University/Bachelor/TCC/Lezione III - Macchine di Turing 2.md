# Ulteriori costrutti per le Macchine di Turing

## Recall questions 
    - Cosa sono le descrizioni istantee?
    - Cosa sono le descrizioni tabellari?
    - Cosa sono le descrizioni con macchine a stati?
    - Descrivere le distinzioni tra i linguaggi accettati dalla macchina di Turing. Cosa è l'halting?
    - In cosa consistono le varianti della macchina di Turing con memoria dello stato e a tracce multiple?

## Macchine di Turing 

### Descrizione istantanee

Si tratta di una notazione abbreviata per configurazioni o ==descrizioni istantanee== (ID):
- ==nastro==: viene mostrata solo la parte tra i due non blank più a SX e DX
- ==testina e stato==: lo stato è aggiunto a SX di ogni cella appena letta 
  
Le ==mosse== di una $TM$ $M$ sono indicate da:
- $|-_M$ oppure $|-$ per indicare una mossa 
- $|-_{M}^{*}$ oppure $|-^*$ zero, una o più mosse

Alcuni esempi di descrizioni istantanee:

![](../../../TCC/ist_desc.png)

### Descrizioni Tabellari di Macchine di Turing 

Le transizioni $\delta$ Macchina di Turing (cfr. #[[Lezione II - Macchine di Turing]]) può essere scritta sotto forma di tabella.

Questa macchina, ad esempio, rimpiazza i simboli della grammatica con $X,Y$:

![](../../../TCC/turing_ex1.png)

### Descrizioni con Diagrammi di Transizione di Macchine di Turing

Un altro modo di descrivere le macchine di Turing è fare uso di macchine a stati:
- i ==nodi== indicano lo ==stato corrente==
- gli ==archi== indicano le ==transizioni==
- i ==label== indicano il contenuto delle transizioni
  - i.e. $0 / X \to$ significa che viene rimpiazzato il simbolo 0 con X e si va a DX

![](../../../TCC/turing_diagram.png)

--- 

### Linguaggio delle Macchine di Turing

Se $M = (Q,\Sigma,\Gamma, \delta, q_0,B,F)$ allora il ==linguaggio di tale macchina== $L(M)$ è definito come il set di stringhe di input per le quali la macchina entra in uno stato di accettazione, ovvero:
- $L(M) = \{w \in \Sigma \space s.t. \space q_0w \space |-^* \space \alpha p \beta \space ; \space p \in F \}$ 

==Linguaggi Ricorsivamente Enumerabili==:
>Set di linguaggi che possiamo accettare usando una macchina di Turing

==Halting==:
>Una macchina di turing ==si ferma== se entra in uno stato $q$ dopo aver letto un simbolo $X$ sul nastro e non ci sono mosse in quella situazione, ossia $\delta(q,X)$ non è definito. 
Possiamo assumere che ogni macchina di Turing si fermi (halts) se arriva in uno stato di accettazione.

==Non è sempre possibile==, invece, ==verificare che una macchina di Turing si fermi==, ad esempio se non va in uno stato di accettazione (cfr. https://en.wikipedia.org/wiki/Halting_problem)

==Linguaggi Ricorsivi==
>Linguaggi per i quali le macchine di Turing ==eventualmente== si fermano, sia che l'input sia accettato o meno.

## Varianti della macchina di Turing

### Memoria nello stato

Modello esteso della macchina con un controllo finito che riporta ==lo stato e una quantità finita di dati==.

Viene implementato trasformando lo stato in una ==tupla== $[q,M_1,M_2,\ldots ]$ dove $M_i$ sono i dati.

![](../../../TCC/storage_turing_machine.png)

Un esempio è questa macchina di Turing che legge una stringa appartenente o all'insieme $\{0,1^n\}$ o a quello $\{1,0^n\}$

![](../../../TCC/turing_machine_state_example.png)

### Tracce multiple

Altro modello esteso della macchina di Turing che invece ==legge multiple tracce==. La testina si muove nello stesso verso su ogni traccia.

Ogni simbolo del nastro è una ==tupla== $[X_1,X_2, \ldots ]$ dove X indica il simbolo letto.

![](../../../TCC/multiple_tracks_TM.png)

Esempio di macchina di turing che  riconosce stringhe palindrome (?)

![](../../../TCC/multiple_tracks_TM_ex.png)