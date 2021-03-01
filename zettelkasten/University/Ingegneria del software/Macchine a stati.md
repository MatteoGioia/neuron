# Macchine a stati

## Recall questions
## State machine diagram (UML 2.0)
### SMD cosa è e a cosa serve
 Serve a modellare aspetto dinamico di un sistema

 In particolare modella oggetti reattivi, ovvero che rispondono a eventi generati fuori dal loro contesto

 Mostrano una macchina a stati con enfasi sul flusso di controllo da stato a stato

### Stati
Rappresenta condizione o situazione nella quale, se certe condizioni vengono soddisfatte, vengono eseguite alcune azioni o eventi

Rappresentato con rettangolo con angoli smussati composto da 2 compartment
- Nome - se manca è detto anonimo
- Transizioni interne - non modificano lo stato, sono azioni o attività interne eseguite mentre l'elemento è in quello stato

### Transizioni interne
Coppie label-(action expression) che identificano le circostanze sotto le quali l'azione specificata dalla coppia viene invocata

Alcune label sono riservate

Ogni attività rappresenta azioni che richiedono tempo e possono essere interrotte

Alcune coppie significative
- entry/azione esegue l'azione all'entrata nello stato
- exit/azione -esegue l'azione all'uscita dello stato
- do/attività - identifica attività in esecuzione quando l'oggetto si trova nello stato
- include/azione - invoca una submachine a stati

### Transizioni 
Composta da
- Stato sorgente
- Evento scatenante o trigger
- Condizione di guardia
- Azione
- Stato destinatario


### Synch states
Usato per controllare regioni concorrenti di una macchina a stati

