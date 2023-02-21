# I/O Operations Safety

## Sicurezza formattazione in C

### Stringhe formattate e crash dello stack

Vulnerabilità legate a ==funzioni che accettano stringhe formattate== e ==permettono di corrompere la memoria==.

Esempio:
```
printf(argv[1]); //con input %s%s%s.... crasha
```

In questo caso l'errore avviene perchè la funzione, quando mancano argomenti li cerca nello stack. Qui manca la/e stringa/e da formattare, e quindi sono restituiti gli indirizzi nello stack (che possono o non possono appartenere allo spazio di indirizzi del programma). 
Le funzioni di formattazione infatti ==inseriscono la informazioni sulla formattazione in cima allo stack== e sotto di essa gli argomenti da formattare.

### Stringhe formattate e lettura di valori nello stack

Un altro esempio classico è l'uso di stringhe formattate per leggere valori dallo stack (**correttezza da verificare**):
-  `%nx` stampa un valore `x` nello stack con `n` digits
-  `%n$x` invece salta all'`n`-esimo elemento nello stack

### Stringhe formattate e corruzione della memoria

Il format `%n` permette di ==salvare un numero di caratteri stampati in una locazione di memoria==. In caso questa locazione di memoria sia mancante, allora ==viene usato il primo valore nello stack==.

## Contromisure

### Mitigare i rischi delle stringhe formattate

Metodi comuni di mitigare i rischi sono:
- ==sanificazione input==: mai fidarsi che l'utente mandi in input quello che ci aspettiamo

### Bug Heartbleed

Un noto exploit di questa insicurezze si verificò con il bug *Heartbleed* di OpenSSL, dove un utente riusciva a stampare una larga parte dello stack usando la funzione heartbeat in modo improprio.

More on: https://heartbleed.com/

### Contromisure a memory corruption

Alcune contromisure:
- ==non eXecutable stack==: alcune aree dello stack sono marcate come non eseguibili per evitare ==code injection==, ad esempio in `gcc` esiste l'opzione `-z noexecstack`;
- ==stack canaries (randomiche)==: valori segreti, posizionati nello stack, che se vengono cambiati bloccano l'esecuzione del programma, ad esempio usando l'opzione `-fstack-protector` in `gcc`;
- ==ASLR address space layout randomization==: randomizza lo spazio di indirizzi del programma
- ==CFI control flow integrity==: viene usato un grafo che controlla il flusso di esecuzione del programma con quello che ci aspetta (calcolato staticamente), si tratta tuttavia di una ==tecnica molto costosa== da implementare.

Attenzione in quanto queste contromisure come il ==non eXecutable stack== sono vulnerabili a attacchi ==return to libc==, oppure tramite l'uso di ==fork== come nel caso delle == stack canaries==, o ancora tramite l'uso di ==ROP== nel caso di ==ASLR== (vedi sotto).

## Arbitrary Code Execution (ACE)

### Di cosa si tratta

Manipolazione del codice (e del flusso di esecuzione) tramite:
- ==code injection==
- ==code reuse==

Alcuni esempi sono:
- return to libc
- return oriented programming
- jump oriented programming

### Return to libc

Tecnica che usa un ==buffer overflow== per ==rimpiazzare un indirizzo di ritorno con quello di una funzione desiderata==.
Fa uso ad esempio di una funzione nella libreria standard di C, `system()`, per eseguire operazioni arbitrarie, i.e. aprire una shell.

### Return oriented programming

Fa uso di ==concatenazione di gadget== in assembly e controllo dello stack per alterare il funzionamento del programma. 