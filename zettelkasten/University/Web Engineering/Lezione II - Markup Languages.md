# Markup Languages

## Extensible Markup Language

### Origini di XML 

XML è un ==metalinguaggio==, cioè un linguaggio da cui derivano altri linguaggi.

Per questo motivo, specifica le ==regole== dei nuovi linguaggi creati.

XML deriva da ==SGML== ma è più semplice e con alcune aggiunte che lo semplificano.

### Vantaggi di XML

Completamente ==text based==, quindi senza binari. Inoltra supporta ==UNICODE==, quindi compatibile con ogni lingua.

...

### Svantaggi

Maggiore complessità nella scrittura comporta ==maggiore spazio== occupato e leggermente più complesso per il ==parsing==.

--- 

### Struttura documento XML

Composto da ==prologo== e ==corpo==.

Il corpo contiene:
- ....

### Prologo: dichiarazione XML

La dichiarazione XML è la prima riga del prologo:
- i.e. `<?xml version="1.0" encoding="ISO-8859-1"?>`

In questa espressione ci sono due coppie `nome="valore"`.

Gli attributi specificano:
- `version`: la versione di XML
- `encoding`: nome della codifica adottata
- `standalone`: opzionale, indica che il documento non fa riferimento a file esterni

### Prologo: dichiarazione DOCTYPE

### Elementi

Alcune regole importanti:
- elementi sono case sensitive
- ..

### Attributi

### Namespaces

Utili se i documenti presentano ==mix di linguaggi XML== in quanto specificano che linguaggio è usato per un attributo.

### Entità

Si usano per inserire un ==particolare sostituto==, ad esempio caratteri riservati
- i.e. le parentesi angolari

Vulnerabilità legate al non uso delle entità:
- cross site scripting (sanitizzazione!)
- sql injection (statement preparati)







