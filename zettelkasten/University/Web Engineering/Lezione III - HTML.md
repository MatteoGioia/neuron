# Hypetext markup language

## HTML e HTML 5

### Nascita di HTML 5

Nasce nel 2008 ma diventa una ==W3C Recommendation== il 28 ottobre 2014.
È completamente ==indipendente da SGML==.

### Modalità Standard e Quirks

I broswer supportano 2 modalità di rendering: 
- ==Standard==: segue le regole del W3C ed è quindi altamente indipendente dal broswer
- ==Quirks==: esegue regole di formattazione dello specifico broswer

Qualora sia mancante il prologo `<!DOCTYPE>`, il broswer entra in modalità quirks.
- questo può comportare situazioni imprevedibili

Nelle versioni di HTML precedenti alla 5 era presenti la modalità ==transitional==, creata per facilitare la compatibilità con codice non standard, e quella ==strict== che invece è aderente ad esso.
==In HTML5 questa differenza viene a mancare== ma è obbligatorio sempre inserire la dichiarazione `<!DOCTYPE html>` per far si che la pagina venga fornita con media type adatto.
- notare che in tal caso la dichiarazione del charset si sposta in `<meta>`
- la dichiarazione `<!DOCTYPE html>` può essere esclusa qualora venga il documento venga servito con ==media type corretto==

Esiste anche una versione detta ==Polyglot== dell'HTML5, compatibile con sintassi XML senza usare media types particolari.
È quella ==consigliata al momento==: 

````
    <!DOCTYPE html>
        <html xmlns="http://www.w3.org/1999/xhtml" lang=“...” xml:lang=“...”>
            <head>
                <title>...</title>
                <meta charset=“UTF-8”/>
            </head>
            <body> ... </body>
        </html>
````

### Struttura di un documento HTML
<small> Di seguito saranno riportate solo le informazioni più importanti</small>

Struttura di un documento HTML:
- `<html>`: attributi `lang` e `dir`
- `<head>`: intestazione, contiene `<title>` (obbligatorio), `<meta>` etc...
- `<body>`: racchiude il contenuto della pagina HTML vero e proprio

### Classificazione storica degli elementi

Originariamente HTML classificava gli elementi come ==inline== e ==blocco==, a seconda che questi potessero essere o meno ==inclusi== nel testo senza causare interruzioni. Esisteva anche il tipo ==flusso==, combinazione dei due precedenti.

Questa classificazione ==è stata poi cambiata in HTML5== in modo da rispecchiare di più il ruolo dell'elemento. 

### Attributi HTML standard e HTML5

Oltre agli attributi comunemente noti vale la pena ricordare:
- `lang`: indica codice linguistico (usato ad esempio dai traduttori)
- `dir`: indica direzione di scrittura
- `title`: usato da molti broswer come tooltip dell'elemento

HTML5 introduce nuovi attributi interessanti come:
- `contenteditable`: che rende editabile un elemento
- `spellcheck`: controlla errori ortografici
- `hidden`: marca l'elemento come ==non rilevante==
- `data-*`: usato per definire attributi ==estesi== dall'utente, è usato ad esempio nei framework per memorizzare dati addizionali
- `role`: indica il ruolo dell'elemento (che può essere diverso dal tag)
- `aria-*`: usati a supporto dei ruoli per aggiungere informazioni, i.e. elementi con `role="checkbox` possono avere `aria="checked"` per marcarne lo stato

### Flusso del testo

Alcune note utili:
- `<p>` non possono essere vuoti
- `<br>` è deprecated in HTML5

Metodo di ==sezionamento classico==:header dal primo a sesto livello, i.e. `<h4><\h4>`
- molto utili nell'indicizzazione

Vari modi per realizzare sezionamento introdotti da html5 (cfr. slide 17):
- `<main>`
- `<section>`
- `<header>`
- `<footer>`
- ...

In più, ci sono ==due elementi invisibili== presenti da sempre in HTML, sono usati per dare stile alle varie parti della pagina e molte ne fanno ancora uso:
- `<div>`: preceduto e seguito da un a capo
- `<span>`: possono essere inseriti nel testo

Oggi lo stile può essere tranquillamente applicato anche alle varie sezioni `<main>`, `<header>`, etc...
Fondamentale che abbiano `<id>` e `<class>` correttamente specificate.

### Formattazione semantica

Elementi per attribuire un significato ad alcune parti del testo, come ad esempio `<em>` che produce testo enfatizzato, oppure per aggiungere info extra, come `<address>`, usato per riportare un indirizzo.

### Formattazione di base

Si tratta di elementi che forniscono formattazione di base molto semplice, come `<big>` e `<small>`, tuttavia il loro uso sta lentamente decadendo essendo sconsigliato.

### Liste di elementi

Utili per ==creare liste di elementi==, sono spesso utilizzate in combinazione con CSS per creare componenti come delle navbar (liste di link) e simili. 

Inoltre la semantica ben definita permette di aumentare il grado di accessibilità.

### Tabella

Molti degli attributi classici sono ora ==deprecated== a favore dell'uso dei fogli di stile.

Le tabelle mettono a disposizione raggruppamenti di righe come:
- `<thead>`: parte dedicata all'inizio della tabella
- `<tfooter>`: parte dedicata alla fine della tabella
- `<tbody>`: parte obbligatoria in ogni tabella, viene implicitamente inserita se mancante (in questo caso tutte le righe sono messe al suo interno)
 
Inserire elementi come `<thead>` o info sulle dimensioni della tabella velocizzano il processing della pagina e evitano che questa si carichi ad esempio a pezzi.

Pro tip:
>==usare tabelle solo dove effettivamente serve, ovvero useresti una tabella anche sul foglio di carta==

### Collegamenti con `a` e `link`

L'elemento `<a>` può avere due utilizzi principali:
- individuare un ==URI di destinazione==, tramite `name` o ancora meglio `id` (==modalità preferita in HTML5==) che può essere indirizzato dal fragment identifier di una URI (vedi sotto)
- indicare un ==URI di origine==, `href`

Un trick utile per quanto riguarda i ==fragment identifiers== è anche inserirli in un link per far saltare ad un punto preciso della pagina oppure come elemento per incrementare l'accessibilità (i.e. pulsanti come "salta a sezione" per schermi piccoli).

Esiste anche l'elemento `<link>`, usato invece per relazioni tra i documenti e utilizzabile solo nella `head` del documento. Presenta un attributo `rel` che permette di far riferimento a diversi tipi di contenuti, come:
- `stylesheet`: fa riferimento a fogli di stile CSS
- `index` fa riferimento ad un indice
- `alternate` per fare riferimento alla versione alternativa di un documento (es. per una lingua diversa)
- ...

È molto importante l'elemento `<base>` che indica la base per le ==URI relative== tramite `href`. Nel caso manchi, verrà usato la URI del documento corrente. Inoltre può avere un attributo `<target>` per definire il target di default in un documento con frames, ovvero se cliccando sui link bisogna aprirlo nello stesso frame o una nuova pagina.

### Immagini

Elemento `<img>`.
Attributi interessanti possono essere `<ismap>` o `<usemap>`:  il primo usa l'immagine come una ==server side map==, ovvero passa al server le coordinate di dove l'utente ha cliccato sull'immagine nel parametro ==get==, mentre il secondo in una ==client side map== che deve fare riferimento ad una ==image map==.

Pro-tip:
> Inlcudere immagini resizate comunque causa il caricamento dell'immagine regolare che viene poi ridotta per entrare nella pagina. Richiede più processing e più dati. Il primo problema viene risolto dicendo al browser le dimensioni della immagine per fare una sorta di pre allocazione di spazio, nel secondo caso linkando ad immagini di taglia appropriata.

### Mappe immagini

Rende le immagini mappe cliccabili dall'utente. Prediligere quelle ==client side== per questioni di accessibilità.

### Oggetti

Permettono di includere un oggetto generico, ma oggi hanno uso molto limitato ad ==audio, video== o aree in cui ad esempio si può disegnare tramite l'elemento `<canvas>`.

### Moduli

...

L'attributo `enctype` può aiutare a specificare quale tipo di encoding ci si aspetta dal form ed evitare problemi di compatibilità.

L'attributo `method` indica se i dati vengono mandati tramite `GET` o `POST`. Il metodo `POST` permette di inserire i dati nel payload e viene usato per grandi quantità di dati come ad esempio i file binari (per cui è presente la modalità).

Pro-tip:
>La validazione lato client è utile per ridurre il carico verso il server e gli errori ma non basta a sanificare l'input - qualche malintenzionato potrebbe scrivere il proprio client, usare la console...

### Input

Pro-tip:
>Associare gli input ai numeri protegge ulteriormente da injection (i.e. le opzioni le enumero lato server e poi lato client associo un numero e basta).