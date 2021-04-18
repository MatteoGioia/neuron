# Problemi intrattabili

## Recall questions
    - Come è definita la complessità di una TM?
    - Perchè, nonostante sostanziali differenze implementative, il discorso di complessità di un algoritmo per computer è equivalente a quello per una TM?
    - Mostrare come viene codificato l'algoritmo di Kruskal e quale è la sua complessità.

## Classi di complessità

### Considerazioni sulla complessità

I problemi risolvibili in tempo polinomiale su un computer sono risolvibili in ==tempo polinomiale anche su una macchina di Turing==.
In generale, i primi sono computati in tempi accettabili, mentre i secondi richiedono tempi talmente lunghi da rendere i risultati incalcolabili se non per istanze molto piccole.

### Complessità di una $TM$

Definizione di ==complessità di una $TM$==:
>Una macchina di Turing $M$ ha complessità $T(n)$ qualora dato un input $w$, di lunghezza $n$, $M$ si **ferma** dopo aver fatto al massimo $T(n)$ mosse, sia che accetti che non lo faccia.

È facile intuire dunque che il nostro studio è ristretto ai problemi $\in R$,
ossia i ==linguaggi ricorsivi==.

### Problema risolvibile in tempo polinomiale

Un esempio di problema risolvibile in tempo polinomiale è quello di calcolare il ==minimum spanning tree==. Per farlo, useremo ==l'algoritmo di Kruskal==.

*Inserire immagine*

L'algoritmo è il seguente:
```
1. Per ciascun nodo, si conserva la componente connessa di cui fa parte rispetto ai lato dell'albero selezionati finora. Inizialmente nessun lato è selezionato, per cui ogni nodo forma da solo una componente connessa. 

2. Si conisidera uno dei lati di peso minimo non ancora esaminati, scegliendolo arbitrariamente. Se questo lato unisce due nodi in componenti connesse diverse (in caso contrario si va avanti in quanto aggiungendolo si formerebbe un ciclo):

    (a) si selezionata il lato che farà parte dell'albero ricoprente
    (b) si riuniscono le due componenti connesse coinvolte, associando a ogni loro nodo lo stesso numero identificativo della componente connessa.

3. Si continua a considerare nuovi lati finchè si sono esaminati tutti o fino a quando il numero di lati selezionati è pari al numero di nodi meno uno. Nel secondo caso tutti i nodi devono già trovarsi in una componente connessa, e si può evitare di esaminare altri lati.

```

*Inserire foto esempio*

La complessità dell'implementazione ottima di questo algoritmo è $O(m + e \log e)$. Un implementazione più semplice, invece, impiega tempo $O(e(e + m)). Questa implementazione trova l'arco di peso minore in $O(e)$ scorrendo la lista degli archi e le componenti connesse scorrendo la lista di nodi in $O(m)$, il tutto $O(e)$ volte. Possiamo informalmente dire che ==la complessità dell'algoritmo è polinomiale nell'input $e + m$.       

### Macchine di Turing vs computer

L'algoritmo presentato in precedenza non può essere risolto da una macchina di Turing. Quando si affronta la questione della complessità di un problema in termini di $TM$, infatti, vanno fatte delle ==considerazioni importanti==:

1. Le $TM$ possono risolvere problemi solo sotto forma di linguaggi, ovvero dire se una stringa appartiene o meno. Tuttavia, visto che il nostro scopo è mostrare che tali problemi sono difficili, la ==complessità del problema originale non può essere più semplice di quella del problema decisionale==. Intuitivamente basta infatti solo operare una riduzione.
2. In generale la ==dimensione dell'input==, codificata in modo da essere compatibile con una $TM$, è ==maggiore di quella del problema di partenza==. Questo tuttavia ==non è un problema==, non solo perchè il rapporto fra l'input e la sua codifica differisce di solito in un fattore piccolo, come il logaritmo dell'input, ma anche perchè tale rappresentazione è spesso più accurata di quella che potremmo immaginare per un computer, che non necessariamente codifica un elemento dell'input con un byte, ad esempio.

### Codifica dell'algoritmo

Codifichiamo ora l'algoritmo in modo da essere compatibile con una macchina di Turing:
- i simboli saranno $0 \space 1 \space ( \space ) \space ,$
- ad ogni nodo viene attribuito un intero da $1 \ldots m$
- sul nastro viene posta una stringa con $m$ in binario e il peso massimo dell'albero $W$
- per ogni arco tra un nodo $i,j$, inseriamo la coppia $(i,j,W)$ sul nastro, sempre in binario

La codifica del nostro esempio è la seguente:

*Inserire immagine*

Studiamo ora la ==complessità dell'algoritmo== in termini di macchina di Turing. Se l'input è lungo $n$, allora esso può rappresentare al massimo $O(\frac{n}{log n})$ lati.
Se i lati fossero pochi, il numero di nodi $m$ potrebbe essere esponenziale in $n$, tuttavia se $e < n - 1$ non esiste MWST e quindi il problema viene direttamente risolto con una risposta negativa.
Per prudenza, sostituiamo $e$ e $m$ nella formula della complessità originale, che diventa $O(n^2)$.

Per implementare l'algoritmo usiamo una $TM$ multinastro:
1. Un nastro memorizza i nodi e i loro numeri di componenti correnti in una tabella lunga $O(n)$
2. Si percorrono i lati sul nastro di input e nel frattempo un altro nastro memorizza il lato minore tra quelli non usati. Una seconda traccia del nastro di input può essere usata per indicare i lati selezionati  come residui dai passi precedenti. Per trovare il lato di peso minimo, si impiega $O(n)$.
3. Quando un lato è selezionato, si collocano i nodi su un nastro e in $O(n)$ si cercano le componenti nella tabella
4. Un nastro infine contiene $i,j$, che devono essere riunite quando si scopre che un le lato collega, qualora fossero sconnesse. Infine in $O(n)$ si ripercorre la tabella per aggiornare $i,j$ con i nuovi numeri di componente.

Un round intero dell'algoritmo richiede $O(n)$, che in termini di $TM$ mononastro diventa $O(n^2)$. Dato che le iterazioni sono $O(n)$, allora la nostra $TM$ base impiega $O(n^4)$.