# Prefix sums

## Problema delle somme

### Testo del problema

Data una sequenza $A = \langle a_1, a_2, \ldots, a_n \rangle$ dove $a_i \in N_{0}^{+}$ ritornare il numero di sottosequenze ==contigue== $B$ non vuote di $A$ dove la somma degli elementi è un numero pari.

![](./static/p_sum.png)

### Soluzione naive

La soluzione naive consiste in 2 cicli `for` per accumulare i risultati di volta in volta facendo scorrere i due indici $i, j$:

```
    unsigned int result = 0;

    for(unsigned int i=0; i<A.size(); i++)
        for(unsigned int j=i; j<A.size(); j++)
            if(std::accumulate(A.begin()+i, A.begin()+j+1, 0) %2 == 0)
                result++

    return result;
```

Ma questa ha costo $\Theta^3$

### Soluzione con somme parziali

È possibile computare le somme parziali in tempo $O(n)$ sfruttando la funzione `std::partial_sum`.
Notare che essendo calcolata per induzione la formula per la somma parte da un indice 0.

$P_0 = 0$ e $P_k = P_{k-1} + a_k$

![](./static/partial_sum.png)

Notiamo anche che è possibile computare la sommatoria degli elementi tra due posizioni nel vettore A come $S(i,j) = \Sigma_{k=i}^{j} \space a_k = P_j - P_{i-1}$ , un'operazione che può essere eseguita in tempo costante:
- i.e. ad esempio nell'immagine $S(3,4) = P(4) - P(2) = 18 - 7 = 11$ 

Questo accade perchè semplicemente escludiamo dalla somma la parte del vettore già incontrata, come mostrato nell'immagine:

![](./static/psum_trick.png)

Sfruttando questa soluzione, è possibile progettare un algoritmo che impiega $O(n^2)$: viene mantenuto lo stesso ciclo `for` di prima, ma ora basta controllare che $S(i,j)$ sia pari per ogni coppia dove $i \leq j$.

```
    std::vector<int> P(A.size()+1);
    std::partial_sum(A.begin(), A.end(), P.begin()+1);
    unsigned int result = 0;

    for(unsigned int i=1; i<=A.size(); i++)
        for(unsigned int j=i; j<=A.size(); j++)
            if((P[j] - P[i-1])%2 == 0)
                result++;

    return result;
```

### Soluzione in tempo lineare

Notiamo che ogni paio $l,j$ dove $l < j$ e $P_j - P_l$ è pari indica la presenza di un vettore con elementi contigui la cui somma è pari, ovvero contribuisce di 1 al risultato. In altre parole, non dobbiamo scorrere il vettore spendendo $O(n^2)$!

Notiamo anche che in una differenza, il risultato è pari solo se entrambi i membri sono pari oppure dispari.

Sfruttando queste due considerazioni è facile calcolare il numero di vettori contigui che rispettino la proprietà: siano $E$ e $F$ il numero di valori pari e dispari nel vettore delle somme parziali
- vettori con somma pari: $\binom{E}{2} = \frac{E(E-1)}{2}$
- vettori con somma dispari: $\binom{F}{2} = \frac{F(F-1)}{2}$

In questo modo ci basta calcolare il vettore delle somme parziali $P$ in $O(n)$ e calcolare poi $F$ da $P$ sempre in $O(n)$: il risultato è dato da $F \frac{F-1}{2} + \frac{(n+1-F)(n-F)}{2}$ calcolato in $O(1)$
- attz: $n$ è la lunghezza di $A$, perciò compare con un +1, che scompare nel secondo termine del binomiale!

Il codice semplificato diventa:
```
    std::partial_sum(A.begin(), A.end(), A.begin());
    int odd = std::count_if(A.begin(), A.end(),
                [](int x) {return x%2;});
    
    return odd*(odd-1)/2 + (A.size()-odd)*(A.size()+1-odd)/2;
```

E anche la complessità si riduce e diventa $O(n)$.

### Soluzioni in tempo lineare e spazio costante

Se osserviamo che ogni somma parziale è usata una volta sola, possiamo ulteriormente semplificare l'algoritmo:
- tenere traccia dell'input e la somma corrente $O(n)$
- calcolare $F$ ci costa $O(n)$
- il risultato è dato da $F \frac{F-1}{2} + \frac{(n+1-F)(n-F)}{2}$ calcolato in $O(1)$

```
    unsigned int n;
    std::cin >> n;
    int x, odd=0, prefix_sum=0;

    for(unsigned int i=0; i<n; i++){
        std::cin >> x;
        prefix_sum += x;
        odd += (prefix_sum%2)?1:0;
    }

    std::cout << odd*(odd-1)/2 + (n-odd)*(n+1-odd)/2 << "\n"
```

In questo modo lo spazio diventa $O(1)$!