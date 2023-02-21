# Recall questions
    - A cosa servono i component diagrams? 
    - Cosa è un componente? È per forza un pezzo di codice? 
    - Quali sono i 4 elementi di un componente? Cosa fanno (in breve) ? 
    - Come è fatta un'interfaccia? 
    - Come è fatta una dipendenza d'uso? 
    - Come è fatta una porta? Cosa cambia se è interna o esterna? 

## Component Diagram
  ### Scopo dei component diagrams (CD)
Definire componenti del software e le loro relazioni gli uni con gli altri

Scopo - creare unità modulari riutilizzabili

Un componente può essere
- una singola classe
- un'applicazione
- un sottosistema 
- ....

### Definizione di Componente
Unità autonoma nel sistema

Alcuni stereotipi di componente
- eseguibile - gira su un processore (??)
- library - riferita da un eseguibile a runtime
- table - database a cui accede un eseguibile a runtime
- file - dati o codice sorgente
- documento 

### Struttura di un componente
Interfaccia - dichiara un set di operazioni fornite e richieste per funzionare

Dipendenza d'uso - necessità di altri componenti per funzionare

Porte - punti di interazione tra componente e ambiente

Connettori 
- connette due componenti oppure
- connette il contratto esterno di un componente con la struttura interna (??)
  
### Interfaccia
Fornita - servizi offerti dal componente all'ambiente

Richiesta - servizi che il componente si aspetta di ricevere dall'ambiente

### Dipendenza d'uso
Relazione dove un elemento richiede un altro per funzionare

Mostrata con una freccia tratteggiata e uno stereotipo sopra con la keyword uses

### Porte 
Specificano un punto di interazione preciso
- tra componente e ambiente 
- tra componente e parti interne

Tipologia di vista fornita
- black box - viene visto solo l'aspetto esterno e le componenti pubbliche
- white box - visione dei componenti interni

## Cenni sul class diagram

### Cosa è e a cosa serve

Mostra un insieme di classi e le loro relazioni

Modella la parte statica di un sistema, in particolare serve per:
- modellare il vocabolario di un sistema
- modellare semplici collaborazioni
- modellare uno schema logico di un database
