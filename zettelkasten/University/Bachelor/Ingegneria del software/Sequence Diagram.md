# Sequence diagrams
## Recall questions
    - Dove è l'enfasi nei sequence diagrams? Perchè si parla di oggetti?
    - Cosa rappresentano i 2 assi?
    - Cosa sono i messaggi? Di che tipo sono? E le lifeline?
    - Cosa sono gli operatori di PAR (SEQ), OPT, LOOP, ALT e CR, REF e NEQ?
## Sequence Diagram
### Introduzione
Evoluzione a oggetti dello scenario 

Enfasi sull'aspetto temporale
- modellare sistemi Real time
- modellare flussi eventi use case 

Affronta il problema da punto di vista tecnico di design
- prima si guardava solo il sistema

### Messaggi tra oggetti
In programmazione O.O. gli oggetti interagiscono scambiandosi messaggi tra loro
  
Messaggio da A a B significa
  - A invoca metodo di B
  - B esegue l'operazione associata al metodo
  - A ottiene di nuovo il controllo e opzionalmente un valore di ritorno

### Elementi di un sequence diagram

Messaggi: linea continua 
- con freccia chiusa piena - chiamata sincrona
  - chiamata di un'operazione o di un flusso di controllo annidato 
  - in caso di flusso di controllo annidato, il controllo torna al chiamante quando l'esecuzione di tale flusso è finita
- linea continua con freccia aperta - chiamata asincrona
- linea tratteggiata con freccia aperta - ritorno da una chiamata di un'operazione
    - si può omettere

  
Oggetti - asse X
  - possono essere creati, distrutti o lasciati in vita al termine di un flusso,  distruzione indicata con X

Tempo - asse Y
  
### Combined Fragments
Permette di dividere un sequence diagram in frammenti combinabili di cui ogni parte può essere gestito tramite operatori

### Sequence diagram, operatori

Operatore ALT - permette di fare una scelta in base a delle guardie

Operatore OPT - frammento opzionale

Operatore PAR - frammenti interleavable
- i vari messaggi dei frammenti possono essere eseguiti in parallelo
- l'ordine imposto da ciascun frammento va comunque rispettato

Operatore SEQ - variazione del PAR
- vincolo su eventi in frammenti diversi ma su stessa lifeline: l'ordine va preservato
  
Operatore NEG - tracce da considerare invalide
- esempio per indicare un timeout post tentativo di login
  
Critical Region - CR
- rappresenta una regione critica che va trattata atomicamente
- nell'immagine vista prima si può vedere come i frammenti dell'operazione critical non siano interleavabili
  
Operatore LOOP - indica il numero di ripetizioni di un frammento tramite una guardia
 
Operatore REF - permette di fare riferimento ad altri sequence diagram dentro un SD
  
### Transition time
Espresso tramite constraints, permette di applicare vincoli temporali
