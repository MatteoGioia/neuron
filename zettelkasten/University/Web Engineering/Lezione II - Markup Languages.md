# Markup Languages

## Extensible Markup Language

### Origini di XML 

XML è un ==metalinguaggio==, cioè un linguaggio da cui derivano altri linguaggi ==markup==, linguaggi in cui il contenuto testuale è delimitato da tags.

Per questo motivo, specifica le ==regole== dei nuovi linguaggi creati.

XML deriva da ==SGML== ma è più semplice e con alcune aggiunte che lo semplificano.

### Vantaggi di XML

Completamente ==text based==, quindi senza binari. Inoltra supporta ==UNICODE==, quindi compatibile con ogni lingua.

Può essere trasportato tramite ==HTTP== anche attraverso firewalls, trattandosi di puro testo.

L'elaborazione automatica è semplificata grazie alla struttura rigida.

### Svantaggi

Maggiore complessità nella scrittura comporta ==maggiore spazio== occupato e leggermente più complesso per il ==parsing==.

--- 

### Struttura documento XML

Composto da ==prologo== e ==corpo==.

Il corpo contiene:
- testo
- tags ovvero i delimitatori, con i loro attibuti e/o namespaces
- annotazioni ossia i commenti
- processing instructions
- entità

### Prologo: dichiarazione XML

La dichiarazione XML è la prima riga obbligatoria del prologo:
- i.e. `<?xml version="1.0" encoding="ISO-8859-1"?>`

In questa espressione ci sono due coppie `nome="valore"`.

Gli attributi specificano:
- `version`: la versione di XML
- `encoding`: nome della codifica adottata (default UTF-8/16)
- `standalone`: opzionale, indica che il documento non fa riferimento a file esterni (default `"no"`)

### Prologo: dichiarazione DOCTYPE

La ==document type definition== stabilisce che tipo di linguaggio è usato nel documento.

Se a un documento è associata una DTD, allora questa va inserita nel prologo con una ==dichiarazione DOCTYPE== che la dichiari.

Una dichiarazione DOCTYPE è della forma: `<!DOCTYPE RootElement ExternalDTDReference [InternalDTDSubset]>`
- `RootElement` indica la radice del documento, ovvero dove questo è contenuto
- `ExternalDTDReference` è opzionale e può puntare a un file che contiene la DTD vera e propria

### Elementi

Base dei docs XML, sono delimitati dai tags.

Alcune regole importanti:
- elementi sono case sensitive
- l'elemento radice è unico

### Attributi

Permettono di specificare proprietà degli elementi. Vanno inseriti nei tag e normalmente devono essere semplici.

Per attributi complessi è meglio ==nidificare il tutto==.

### Namespaces

Utili se i documenti presentano ==mix di linguaggi XML== in quanto specificano che linguaggio è usato per un attributo.

### Entità

Si usano per inserire un ==particolare sostituto==, ad esempio caratteri riservati
- i.e. le parentesi angolari

Sono ==parsed== se vengono sostituite dal compiler con un valore testuale o ==unparsed== se invece il valore è non testuale ed è accessibile nelle annotazioni.

Vulnerabilità legate al non uso delle entità:
- cross site scripting (sanitizzazione!)
- sql injection (statement preparati)


### Sezioni CDATA

### Istruzioni di processing

### Commenti XML

### Validazione



