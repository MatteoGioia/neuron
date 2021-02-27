# Non functional requirements
## Recall questions
    - Quali sono le 3 classificazioni principali dei NFR? 
    - Cosa sono i requisiti di performance? Come si misura?
    - Cosa è la usability? Perchè deve essere misurabile? 
    - Cosa è la dependability? In cosa si articola? 
## Non functional requirements
###  Classificazione dei requisiti non funzionali (NFR)  
Vincoli applicati al sistema intero  più che a feature che deve fornire
 - es. time costraints, specifiche tecnologie da usare e/o processo di sviluppo scelto

Requisiti del prodotto - comportamenti che il prodotto deve avere  
- e.g. velocità, reattività, sicurezza ...

Requisiti   organizzativi   - derivati da   politiche organizzative   adottate
- e.g. standard usati, metodi di sviluppo usati ...

Requisiti   esterni   - esterni al sistema
- e.g. interoperabilità, requisiti legislativi ...

###   Importanza dei requisiti non funzionali  
Possono essere   più critici dei requisiti funzionali  - la loro mancanza potrebbe rendere il sw inusabile

Un NFR può   impattare vari requisiti funzionali  

I NFR possono essere   correlati tra loro  

Diversi livelli di completezza per quanto riguarda i NFR possono rendere più o meno costoso il sistema e cambiarne il design  

### Requisiti di prodotto  
Performance   
  - focus della Software Performance Engineering
  - miglioramento del   throughput   - velocità di processing 
  - miglioramento di   latenza   - intervallo input/ risposta o simili
  - miglioramento di   accuracy   e   availability   

Usabilità  
  -   facilità di uso da parte degli attori al primo approccio e nel progressivo apprendimento delle funzionalità della piattaforma  
  -   misurabile   =  numero di step per effettuare task con alta usability
  
Dependability  
 -  abilità del siste  ma di essere affidabile nel complesso 
 -  aumentarla impatta le performance (e viceversa) e aumenta esponenzialmente i costi  
              
 Availability   
  - disponibilità o abilità del siste  ma di fornire i servizi quando richiesto   
  - misurata tramite MTBF/ (MTBF + MTTR)
      - MTBF (mean time between failures)
      - MTTF (mean time to failure)
      - MTTR (mean time to repair)
  
Reliability -  affidabilità del sistema nel fornire i servizi  
             
Safety  - abilità del sistema di   operare senza fallimenti catastrofici e danneggiare gli utenti   sebbene sia stato progettato secondo le specifiche

-   collegata alla reliability   - ma   la reliability si limita ad affidabilità entro i limiti operativi definiti  
-  importante   perchè   molti sistemi ad oggi sono software based 
-  fondamentale   per software   mission critical   /   safety critical  
          
Security   -   sicurezza del sistema   e degli utenti/dati
- pre requisito di availability, reliability e safety
-   se non vi è sicurezza, potrebbero essere modificati aspetti che garantivano le 3 proprietà di sopra  

Repairability   - riparabilità del sistema in caso di fallimento

Survivability   - capacità del sistema di   sopravvivere a situazioni eccezionali  

Mantainability   -   capacità del sistema di adattarsi a nuovi requisiti   e integrarli
    
Fault tolerance   -   capacità del sistema di tollerare i guasti   e continuare ad operare

