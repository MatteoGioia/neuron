# Problemi intrattabili

## Recall questions
    - Come è definita la complessità di una TM?
    - Perchè, nonostante sostanziali differenze implementative, il discorso di complessità di un algoritmo per computer è equivalente a quello per una TM?
    - Cosa è la classe di complessità P?
    - Mostrare come viene codificato l'algoritmo di Kruskal e quale è la sua complessità.
    - Cosa è la classe di complessità NP?
    - Mostrare il problema del TSP come classico esempio di problema NP.
    - Cosa è una riduzione polinomiale? Perchè il termine polinomiale esprime un vincolo importante?
    - Cosa sono i problemi $NP$-completi? E quelli $NP$-hard?

## Classi di complessità

### Considerazioni sulla complessità

I problemi risolvibili in tempo polinomiale su un computer sono risolvibili in ==tempo polinomiale anche su una macchina di Turing==.
In generale, i primi sono computati in tempi accettabili, mentre i secondi richiedono tempi talmente lunghi da rendere i risultati incalcolabili se non per istanze molto piccole.

### Complessità di una $TM$

Definizione di ==complessità di una $TM$==:
>Una macchina di Turing $M$ ha complessità $T(n)$ qualora dato un input $w$, di lunghezza $n$, $M$ si **ferma** dopo aver fatto al massimo $T(n)$ mosse, sia che accetti che non lo faccia.

È facile intuire dunque che il nostro studio è ristretto ai problemi $\in R$,
ossia i ==linguaggi ricorsivi==.

### Classe di complessità $P$

>Diremo che un linguaggio $L$ è in $P$ se esiste un polinomio $T(n)$ tale che $L = L(M)$ per una $TM$ deterministica $M$ e questa ha ha complessità $T(n)$.

### Problema risolvibile in tempo polinomiale

Un esempio di problema risolvibile in tempo polinomiale è quello di calcolare il ==minimum spanning tree==. Per farlo, useremo ==l'algoritmo di Kruskal==.

![](./static/TM_Kruskal_P.png)

L'algoritmo è il seguente:
```
1. Per ciascun nodo, si conserva la componente connessa di cui fa parte rispetto ai lato dell'albero selezionati finora. Inizialmente nessun lato è selezionato, per cui ogni nodo forma da solo una componente connessa. 

2. Si conisidera uno dei lati di peso minimo non ancora esaminati, scegliendolo arbitrariamente. Se questo lato unisce due nodi in componenti connesse diverse (in caso contrario si va avanti in quanto aggiungendolo si formerebbe un ciclo):

    (a) si selezionata il lato che farà parte dell'albero ricoprente
    (b) si riuniscono le due componenti connesse coinvolte, associando a ogni loro nodo lo stesso numero identificativo della componente connessa.

3. Si continua a considerare nuovi lati finchè si sono esaminati tutti o fino a quando il numero di lati selezionati è pari al numero di nodi meno uno. Nel secondo caso tutti i nodi devono già trovarsi in una componente connessa, e si può evitare di esaminare altri lati.

```

![](./static/Kruskal_Solve.png)

La complessità dell'implementazione ottima di questo algoritmo è $O(m + e \log e)$. Un implementazione più semplice, invece, impiega tempo $O(e(e + m))$. Questa implementazione trova l'arco di peso minore in $O(e)$ scorrendo la lista degli archi e le componenti connesse scorrendo la lista di nodi in $O(m)$, il tutto $O(e)$ volte. Possiamo informalmente dire che ==la complessità dell'algoritmo è polinomiale nell'input $e + m$.       

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

![](./static/TM_Kruskal_Code.png)

Studiamo ora la ==complessità dell'algoritmo== in termini di macchina di Turing. Se l'input è lungo $n$, allora esso può rappresentare al massimo $O(\frac{n}{log n})$ lati.
Se i lati fossero pochi, il numero di nodi $m$ potrebbe essere esponenziale in $n$, tuttavia se $e < n - 1$ non esiste MWST e quindi il problema viene direttamente risolto con una risposta negativa.
Per prudenza, sostituiamo $e$ e $m$ nella formula della complessità originale, che diventa $O(n^2)$.

Per implementare l'algoritmo usiamo una $TM$ multinastro:
1. Un nastro memorizza i nodi e i loro numeri di componenti correnti in una tabella lunga $O(n)$
2. Si percorrono i lati sul nastro di input e nel frattempo un altro nastro memorizza il lato minore tra quelli non usati. Una seconda traccia del nastro di input può essere usata per indicare i lati selezionati  come residui dai passi precedenti. Per trovare il lato di peso minimo, si impiega $O(n)$.
3. Quando un lato è selezionato, si collocano i nodi su un nastro e in $O(n)$ si cercano le componenti nella tabella
4. Un nastro infine contiene $i,j$, che devono essere riunite quando si scopre che un le lato collega, qualora fossero sconnesse. Infine in $O(n)$ si ripercorre la tabella per aggiornare $i,j$ con i nuovi numeri di componente.

Un round intero dell'algoritmo richiede $O(n)$; dato che le iterazioni sono $O(n)$, allora la nostra $TM$ impiega $O(n^2)$ mentre la $TM$ mononastro $O(n^4)$. 

È chiaro che questo problema ==è in $P$==.

### Classe di complessità $NP$

>Diremo che un linguaggio $L$ è in $NP$ (non-deterministic polinomial) se esiste una $TM$ non deterministica $M$ e una complessità polinomiale in tempo $T(n)$ tale che $L = L(M)$ e, quando viene dato un input di lunghezza $n$, in $M$ non ci sono mosse più lunghe di $T(n)$

<small> ovvero termina in al più $T(n)$ steps </small>

Osserviamo inoltre che:
> $P \subseteq NP$

### Problema $NP$: Traveling Salesperson

Il problema del ==commesso viaggiatore== è un classico esempio di problema in $NP$. La codifica è esattamente la stessa del problema del MSWT, tuttavia qui si ==ricerca un circuito hamiltoniano di peso minimo==. Nel nostro caso stiamo codificando il problema decisionale *Esiste un circuito hamiltoniano di peso x sul grafo G?*
Per risolvere tale problema siamo obbligati a guardare tutti i cicli (meno alcuni) e calcolare quanto questi pesano. Una $NTM$* multinastro riesce a calcolare tutte le permutazioni dei nodi, su un input di lunghezza $n$, in $O(n)$; dovendo fare $n$ iterazioni impiega al più $O(n^2). Una $NTM$ mononastro quindi impiega $O(n^4)$.

Ne deriva che TSP $\in NP$.

<small>* $NTM$ = abbr. per macchina di Turing non deterministica</small>

### Riduzione polinomiale

Si tratta della tecnica principale con cui mostriamo che
> Se $P_1 \notin P$ e si può ridurre polinomialmente a $P_2$, allora anche $P_2 \notin P$. 

Idealmente anche qui sfrutteremo un algoritmo del tipo:

![](./static/poli_red.png) 

Vediamo che questo algoritmo, a differenza di quando lo usavamo per le TM, non basta a dimostrare l'enunciato, perchè ci possono essere dei casi in cui $P_1 \notin P$ ma $P_2 \in P$. Intuitivamente questo avviene perchè in quel caso non ci stavamo occupando di complessità ma più di accettazione/halting.

1. Supponiamo che $P_1 \notin P$ ma $P_2 \in P$, e che RED riceva un'istanza di $P_1$ lunga $m$ e ne produca una lunga $2^m$. Una volta prodotta l'istanza la passa all'algoritmo per $P_2$ che decide in tempo polinomiale.  Se l'algoritmo di decisione impiega un tempo $O(n^k)$, su un input di lunghezza $2^m$ impiegherebbe $O(2^{km})$, che è esponenziale in $m$. Questo significa che l'input $m$ di partenza, dato in pasto ad un algoritmo di decisione che sfrutta la riduzione da $P_1$ a $P_2$ e decide $P_1$, impiegherebbe tempo esponenziale in $m$. Pur essendoci una riduzione, questo non contraddice che $P_1 \notin P$ ma $P_2 \in P$.
2. Suppioniamo che RED produca un'istanza di $P_2$ da un'istanza di $P_1$ mantenendo invariata la lunghezza, ossia $m$, ma per farlo impieghi tempo esponenziale $O(2^m)$. Un algoritmo di decisione per $P_1$ allora può decidere in tempo esponenziale $O(2^m + m^k)$, che è il tempo pagato per la conversione (esponenziale) e per l'elaborazione tramite l'algoritmo per $P_2$ (polinomiale). Anche qui questo non contraddice che $P_1 \notin P$ ma $P_2 \in P$.

Dobbiamo dunque porre un vincolo importante:
> La riduzione da un'istanza di $P_1$ a un'istanza di $P_2$ deve avvenire in tempo polinomiale nella lunghezza dell'input

Se infatti la traduzione impiega un tempo polinomiale $O(m^j)$, l'istanza di $P_2$ non può essere più lunga di $cm^j$ dove $c$ è una qualche costante che indica il numero di passi (ricordiamo che una $TM$ scrive un simbolo alla volta!).
Possiamo ora dimostrare che l'enunciato è valido: supponiamo di poter decidere l'appartenenza a $P_2$ di una stringa in tempo $O(n^k)$. Possiamo decidere l'appartenenza di una stringa a $P_1$ in tempo $O(m^j + (cm^j)^k)$. Ne deriva che il tempo è polinomiale in $m$ essendo tutte le potenze delle costanti, e quindi $P_1 \in P$.

Faremo uso d'ora in poi solo di riduzioni di questo tipo, ossia di ==riduzioni polinomiali==. Infatti se la riduzione di un'istanza di $P_1$ impiega tempo polinomiale, allora anche l'istanza trasformata è un polinomio dell'istanza originale.

### Problemi $NP$-completi

Sia $L$ un linguaggio, diremo che:
> $L$ è $NP$-completo se 
> 1. $L \in NP$.
> 2. $\forall L' \in NP$ esiste una riduzione polinomiale da $L'$ a $L$.

Questi problemi sono noti in quanto sono i candidati migliori che mostrano ==la diseguaglianza tra $P$ e $NP$==. Mostrare che anche uno solo di questi problemi si può risolvere in tempo polinomiale dimostrerebbe invece il contrario, come vedremo più avanti!

Enunciamo ora un importante ==teorema==:
> Sia $P_1$ un problema $NP$-completo e $P_2$ un problema in $NP$. Se esiste una riduzione polinomiale da $P_1$ a $P_2$, allora $P_2$ è $NP$-completo.

Per la dimostrazione dobbiamo provare come ogni linguaggio $L$ in $NP$ si riduce in tempo polinomiale a $P_2$. Sappiamo che esiste una riduzione polinomiale di $L$ a $P_1$ che impiega tempo polinomiale $p(n)$. Una stringa $w \in L$ è convertita in una $x \in P_1$ al massimo di lunghezza $p(n)$. Sappiamo anche che esiste una riduzione polinomiale da $P_1$ a $P_2$ che avviene in tempo $q(m)$. La riduzione trasforma quindi $x \in P_1$ a $y \in P_2$ in tempo massimo $q(p(n))$. Partendo da $w$, il tempo massimo è $p(n) + q(p(n))$ che è ancora polinomiale. 
Dunque $L$ è riducibile in tempo polinomiale a $P_2$, ma essendo $L$ un linguaggio arbitrario in $NP$ questo è valido per tutti i linguaggi in $NP$, e quindi $P_2$ è $NP$-completo. 

Come suggerito precedentemente si crede che $P != NP$, e l'appartenenza agli $NP$-completi è un modo per mostrare come difficilmente un computer può risolvere un problema in modo efficiente. Come suggerito precedentemente, basterebbe dimostrare il contrario è (==teorema==):
> Se un problema $NP$-completo è in $P$, allora $P = NP$

La dimostrazione in questo caso è semplice: tramite il problema $NP$-completo che si trova in $P$ possiamo infatti operare una riduzione da ogni linguaggio generico $L$ in $NP$, mostrando quindi come $P=NP$.

### Problemi $NP$-hard

Esistono alcuni problemi per cui è possibile mostrare solo la seconda condizione dell'$NP$-completezza, ovvero che non siamo in grado di mostrare si trovino in $NP$. Questi sono detti problemi $NP$-hard.