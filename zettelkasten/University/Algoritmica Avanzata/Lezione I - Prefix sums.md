# Prefix sums

## Problema delle somme

### Testo del problema

Data una sequenza $A = \langle a_1, a_2, \ldots, a_n \rangle$ dove $a_i \in N_{0}^{+}$ ritornare il numero di sottosequenze ==contigue== $B$ non vuote di $A$ dove la somma degli elementi è un numero pari.

![](./static/p_sum.png)

### Soluzione naive

La soluzione naive consiste in 2 cicli `for` per accumulare i risultati di volta in volta facendo scorrere i due indici $i, j$:

```
    for(unsigned int i=0; i<A.size(); i++)
        for(unsigned int j=i; j<A.size(); j++)
            if(std::accumulate(A.begin()+i, A.begin()+j+1, 0) %2 == 0)
                result++
```

Ma questa ha costo $\Theta^3$

### Soluzione con somme parziali

È possibile computare le somme parziali in tempo $O(n)$ sfruttando la funzione `std::accumulate`.
Notare che essendo calcolata per induzione la formula per la somma parte da un indice 0.

$P_0 = 0$ e $P_k = P_{k-1} + a_k$

![](./static/partial_sum.png)

Notiamo anche che $S(i,j) = \Sigma_{k=i}^{j} \space a_k = P_j - P_{i-1}$ , un'operazione che può essere eseguita in tempo costante.

Sfruttando questa soluzione, è possibile progettare un algoritmo che impiega $O(n^2)$: viene mantenuto lo stesso ciclo `for` di prima, ma ora basta controllare che $S(i,j)$ sia pari.

```
    if((P[j] - P[i-1])%2 == 0)
        result++;
```
