# Basic Knowledge

## First module (C compiling)

### Quick CLANG (and GCC) steps recap

![](./static/CYS/Clang_compiling.png)

Ricorda anche:
- linking statico: librerie esterne incluse nei binaries
- linking dinamico: librerie esterne caricate dinamicamente

### Executable and Linkable Format

ELF sta per ==Executable and Linkable Format== ed è un 
formato comunemente usato per gli ==object files==.

Le varie tipologie sono:
- ==rilocabile==: codice e dati linkabili e combinabili con altri object files per ottenere un eseguibile
- ==eseguibile==
- ==shared object file==: linkabili con altri shared per creare un object file oppure usati da un linker dinamico per creare una process image

### ELF file structure

Struttura di un file ELF: 
- ==header==: descrizione dei contenuti
- ==program header table==: info su come creare una process image
- ==sections==: contengono ciò che è necessario per il linking
- ==section header table==: con un info sulle precedenti sezioni

Sezioni importanti sono:
- .text: istruzioni eseguibili
- .bss: memoria non inizializzata del programma
- .data, .data1: memoria non inizializzata del programma
- .rodata, .rodata1: simili ai data ma read only
- .symtab: tabella dei simboli
- .dynamic: info sul linking

### Architetture x86

Processori x86 - 32 hanno 8 registri a 32 bit 

Alcuni registri storici e importanti sono:
- EAX usato come accumulatore
- ECX usato come counter nei loops
- BSP usato come ==base pointer==
- ESP usato come ==stack pointer==

Alcuni hanno delle sottosezioni

Processori x86 - 64 ha molti più registri.

### Istruzioni x86 

Istruzioni di spostamento dei dati
- `mov op2, op1` copia i dati da `op1` in `op2`
- `push op1` mette l'operando in cima allo stack
- `pop op1` rimuove il dato di 4byte dalla cima dello stack 
- `lea op1,op2` carica l'indirizzo di memoria indicato da `op2` in registro `op1` 

Istruzioni aritmetiche e logiche: classiche operazioni add, sub, and $\ldots$

Istruzioni di controllo del flusso:
- `jmp op`: salta all'istruzione specificata dall'indirizzo di memoria in op
- `cmp op1,op2`: compara gli operandi e salva il risultato nel registro `flag`
- `j <condition> op`: come `jump`, ma basa il salto su condizione o risultato in `flag`

### Memory management

Alcuni linguaggi permettono la gestione della memoria da parte del programmatore, come in C.

In C si denota un puntatore all'indirizzo in cui si trova x con `&x`

### Memory segments

La memoria è allocata per ogni processo e divisa in segmenti:
- stack: variabili locali
- heap: variabili memoria dinamica
- data segment: .bss e .data
- code segment

### Stack x86

Stack fatto di frames, creati per ogni chiamata e deallocati alla fine (return).

Lo ==stack pointer== fa riferimento all'ultimo frame dello stack, mentre il ==frame pointer== all'inizio
del frame.

In x86-64 i primi 6 argomenti vengono ora passati come registri, il resto nello stack.
Inoltre RSP e RSB sostituiscono ESP e BSP.

### C declaration: cdecl

==Calling convention== usata anche da x86:
- argomenti passati nello stack in ordine left to right
- valori di ritorno nei registri
- è il chiamante a ripulire lo stack

### Memory management C (heap)

Due funzioni principali per la gestione della memoria:
- `malloc(int)` alloca spazio per l'integer specificato e ritorna un pointer
- `free(void*)` dealloca la memoria associata ad un pointer

## Second module (Tools)

### Debugging
 
Processo di ricerca e fixing dei bug

Debugger: tool per cercare bugs nel software
- i.e. in caso di gcc con l'opzione `-g` si aggiungo info di debug nella sezione .debug del file ELF

### Binary files information

Informazioni da file binario
- verificare se il file è eseguibile 
- identificare architettura
- identificare simboli e stringhe
- identificare processi in esecuzione associati con il binario
- leggere lo SHA e verificare potenziali associazioni con software malevolo
- identificare nomi di funzioni e librerie

### Read ELF data

Tools:
- ==strings==: stampa le stringhe di un file binario di lunghezza > 4 e seguite da un carattere non stampabile
- ==objdump==: ritorna informazioni su un object file,  può inoltre disassemblare binaries
- ==readelf==

### GDB: GNU Project Debugger

Ogni ==comando== è della forma: `command parameters`

Gli ==argomenti== sono settati tramite `set args` e visibili tramite `show args`

Il debugger si ferma in presenza di:
- breakpoint: creati con `break [location] if <cond>`
- watchpoint: guarda se cambia valore di una exp
- catchpoint: guarda se accade un certo evento
- un segnale
- il completamento di uno step

Per ==vedere il contenuto dello stack== (al momento) si usa il comando:
- `frame [<selection>]` da info sul frame selezionato 

Per ==disassemblare== una funzione si usa il comando `disass`