# Crittografia

## Teoria dei numeri e aritmetica modulare

### Richiami su cifratura asimmetrica

Cifratura asimmetrica, requisiti:
- costo computazionale ridotto per generare chiavi e cifrare
- difficile risalire a chiave privata conoscendo la chiave pubblica e al messaggio senza conoscere le chiavi
- le 2 chiavi possono essere usate interscambiabilmente

Dipendo di funzioni chiamate ==trap-door one way functions== $y = f_k(X)$, dove
a differenza di una semplice funzione one way l'inversa diventa ==feasible== qualora sia nota la chiave, ovvero $x = f^{-1}_{k}(y)$ è facilmente risolvibile solo se $k$ e $y$ sono note, ma non è risolvibile se è nota solo $y$.

La cifratura asimmetrica è comunque ==violabile da attacchi brute-force==, ma l'utilizzo di chiavi di grandi dimesioni rende questo rischio irrisorio. 
L'uso di chiavi grandi però rende all'effettivo ==costoso computare la coppia di chiave pubblica privata== rispetto ad esempio a uno schema simmetrico.

### Teoria dei numeri

Teoria dei numeri sfruttata per creare crittografia a ==chiave doppia==. Faremo uso di ==numeri primi, aritmetica modulare e esponenziali e logaritmi==.

### Numeri Primi

Teorema della divisione:
>Per ogni $a \in Z$ e $n \in N$, esiste un $q$ unico e $r$ t.c. $a = q * n + r$ dove $0 \leq r < n$. $q$ è detto quoziente, $r = a \mod n$ è l resto.

Teorema della decomposizione:
>Ogni numero naturale è un primo oppure può essere ottenuto come prodotto di potenze di numeri primi.

Rappresentazione canonica di interi:
>Ogni inero positivo può essere rappresentato unicamente come un prodotto infinito su tutto l'insieme di numeri primi positivi: $n = 2^{n_1} * 3^{n_2} * 5^{n_3}*\ldots = \Pi_{i=1}^{\infty} \space p_{i}^{n_i}$

Il corollario implica che per effettuare una moltiplicazione tra 2 numeri ==è sufficiente== esprimere entrambi come numeri primi e pi aggiungere i corrispondenti esponenti.


### Aritmetica Modulare

Diciamo che $a \equiv b \space \mod n$ se producono lo stesso resto quando divisi per $n$.
<small>Psst...queste sono definizioni leggermente informali. Per approfondimenti vedi la sezione Aritmetica (WIP) </small> 

Alcune proprietà utili:
- ==riflessitività==, $a \equiv a \mod n$ 
- ==simmetria==, $a \equiv b \mod n \to b \equiv a \mod n$ 
- ==transitività==, se $a \equiv b \mod n$ e $b \equiv c \mod n \to a \equiv c \mod n$
- due termini congruenti rispetto a un terzo $n$ possono essere usati in modo interscambiabile in ogni operazione modulo $n$

### Gruppo Abeliani $Z_n$ e $Z^{*}_{n}$ 

$Z_n$ è il ==set di classi di equivalenza== indotte dalla congruenza $mod n$. È inoltre un ==gruppo abeliano==.
> see https://en.wikipedia.org/wiki/Modular_arithmetic

Numeri ==coprimi==:
> Due numeri sono comprimi (o primi fra di loro) se l'MCD è 1.

$Z_{n}^{*}$ è il ==set di numeri coprimi== con $n$, minori di $n$.
La ==cardinalità è espressa dal toziente di eulero== $\phi(n)$, vedi https://it.wikipedia.org/wiki/Funzione_%CF%86_di_Eulero

Importante (per RSA e anche altro):
>$phi(n) = (p-1)*(q-1)$ se $n$ è prodotto di 2 primi

### Fermat's little theorem

Teorema di Fermat (piccolo):
>$a^p \equiv a \mod p$

Inoltre vale che:
>Dato un intero $a$ e un numero primo $p$ con $a$ non divisibile per $p$, vale  $a^{p-1} \equiv 1 \mod p$

Esempio: $7^18 \equiv 1 \mod 19$, essendo 7 non divisibile per 19 che è primo.

### Teorema di Eulero Rivisitato

Un paio di formule utili:

Dati $a, n$ coprimi:
- $a^{\phi(n)} = 1 \mod n$
- $a^{\phi(n) +1 } = a \mod n$

 
## Crittografia e cifrari classici
<small> Per più info su chiavi simmetriche e pubbliche consulta wikipedia </small>

### Schemi di crittografia

Tipologie in base a ==operazione di trasformazione== e ==processo di trasformazione==.

In base a operazione:
- ==rimpiazzo==: gli elementi del plaintext sono cambiati con altri simboli
- ==trasposizione==: gli elementi del plaintext sono cambiati fra loro

In base a processo
- ==a blocco==: vengono cifrati blocchi di plaintext
- ==a flusso==: viene cifrato un simbolo alla volta

### Criptoanalisi

Insieme di tecniche per ==verificare la scelta dell'algoritmo== e delle chiavi cercando di indovinare le chiavi partendo dal solo testo cifrato.

### Cifrario di cesare

Un classico esempio di cifratura per ==rimpiazzo== fu quello inventato da Giulio Cesare. Il funzionamento può essere generalizzato:
- $M$ sono le stringhe lowercase nell'alfabeto inglese
- $Gen$: scegli un $k$ uniforme t.c. $k \in 0...25$
- $Enc_k (m_1, \ldots , m_t)$ da in output $c_1, \ldots c_t$  dove $c_i = m_i + k \mod 26$ (questo perchè arrivati alla fine dell'alfabeto si ricomincia)
- $Dec_k (c_1, \ldots c_t$ e $m_1, \ldots m_t$ dove $m_i = c_i - k \mod 26$ 

Ovviamente si tratta di un cifrario debole in quanto le sostituzioni sono limitate (WEP, rings a bell duh).

Un modo ==semplice per rinforzarlo è permutare l'alfabeto==, in modo tale da avere $26!$ possibili chiavi contro invece i 25 shifts di prima. Rimane tuttavia il problema legato al fatto che si può inferire la chiave studiando la frequenza di lettere all'interno dell'alfabeto.

### Cifrari polialfabetici (Vigenère)

L'idea è quella di sostituire le lettere con caratteri diversi in punti diversi del testo, in modo da non poter studiare la frequenza dei simboli.
Il ==cifrario di Vigenère== fa proprio questo: ==la chiave è una stringa==
mappata a dei numeri:

![](./static/CYS/vigenere.png)

Sebbene all'apparenza il cifrario sia robusto, essendo le chiavi in spazi di dimensione $26^14 \approx 2^{66}$ e quindi il bruteforce molto difficile, la debolezza sta nella chiave stessa. Una volta ==indovinata la lunghezza della chiave==, infatti, basta dividere la stringa in pezzi di uguale lunghezza a quella della chiave e trattarli come piccoli pezzi codificati con ==cifrario di Cesare==.