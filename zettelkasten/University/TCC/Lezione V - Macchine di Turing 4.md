# Ulteriori costrutti per le Macchine di Turing

## Recall questions 
    - WIP

## Macchine di Turing

### Macchine di Turing ristrette

Esamineremo ora delle versioni ristrette della classica macchina di Turing che, sebbene abbiano limitazioni, sono comunque modelli di calcolo equivalenti a quella originale (ossia accettano gli stessi linguaggi).

### Macchina di Turing con nastri semi infiniti

Assumiamo che i nastri della $TM$ in questione ==non abbiano celle a sx dell'input==. Per simulare una $TM$ regolare $M$, possiamo costruire la $TM \space M_1$ come segue:
- $M_1$ possiede due tracce: una dove sono contenuti i simboli a SX del nastro di $M$ e nell'altra quelli a DX 
- è presente un simbolo speciale che evita che la testina strabordi a SX
- $M_1$ non scrive mai blanks, ovvero il nastro, in ogni istante, è un prefisso di simboli non vuoti (non blank) seguiti da una sequenza infinita di blank e questa sequenza di simboli non vuoti inizia sempre all'inizio della posizione iniziale del nastro.

....

La dimostrazione che questa macchina è possibile si fa in modo ==costruttivo==

### Macchina multi stack

### Macchine a contatori

<small> Vedi anche #[[Lezione II - Macchine di Turing]] </small>

