# Basic Knowledge

## Recall questions

## First module

### Executable and Linkable Format

ELF sta per ==Executable and Linkable Format== ed è un 
formato comunemente usato...

Le varie tipologie sono

### ELF file structure

Struttura di un file ELF: 
- header
- program header table
- sections

Sezioni importanti sono:
- .text
- .bss
- .data, .data1
- .rodata, .rodata1: simili ai data ma read only
- .symtab
- .dynamic

### Architetture x86

Processori x86 - 32 hanno 8 registri a 32 bit 

Nomi dei registri ... importanti sono ..

Processori x86 - 64

PS. needs further explanation

### Istruzioni x86

Istruzioni di spostamento dei dati

Istruzioni aritmetiche e logiche

Istruzioni di controllo del flusso

### Memory management

Alcuni linguaggi permettono la gestione della memoria da parte del programmatore

### Memory segments

La memoria è allocata per ogni processo e divisa in segmenti:
- stack
- heap
- data segment
- code segment

### Stack x86

Stack fatto di frames, creati per ogni chiamata e deallocati alla fine (return)

### C declaration: cdecl

### Heap 

### Memory management C

*mallloc(int)*

*free(void\*)* 

### Debugging
 
Processo di ricerca e fixing dei bug

Debugger: tool per cercare bugs nel software

## Second module (Tools)

### Binary files information

Informazioni da file binario
- verificare se il file è eseguibile 
- identificare architettura
- identificare simboli e stringhe
- identificare processi in esecuzione associati con il binario
- ..
- ..

### Read ELF data

Tools:
- ==strings== 
- ==objdump==
- ==readelf==

### GDB: GNU Project Debugger

