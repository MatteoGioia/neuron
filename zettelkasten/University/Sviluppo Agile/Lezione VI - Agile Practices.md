# Agile Practices

## Recall questions
    - WIP

## Agile Practices

### Cosa è una pratica

Si tratta di un'attività, un modo di lavorare o una che ==può essere ripetuta nel tempo==. Senza quest'idea di ripetizione si perde infatti l'utilità stessa della pratica.

Scrum fa uso del termine ==cerimonie== come sinonimo di pratiche.

### Sprint

Componente cruciale delle metodologie agili, è ==l'unità di lavoro== con cui si indicano i cicli di sviluppo del sw. Di norma sono molto brevi.

Bisogna sempre ==stabilire la durata degli sprint==, idealmente sempre meno di un mese. Durante lo sprint, ==la task list viene congelata== e non può essere modificata da nessuno. Questo non è un problema in quanto gli sprint sono brevi e tali task possono essere aggiunte nella lista a fine ciclo senza attendere troppo.

Solo il ==product owner== può terminare in anticipo un sprint qualora valuti che una task critica non è stata inclusa e deve essere prioritizzata.

La ragione per cui gli ==sprint sono immutabili== è utile anche a ==evitare che il cliente tenti di far prioritizzare task== che reputa importanti rovinando l'auto-organizzazione del team.

Questa regola è detta ==closed window rule==.

### Schema dei meeting

Durante e prima di ogni sprint si segue il seguente schema per organizzare i meetings.

![](./static/meetings_agile.png)

### Iteration Planning

Il meeting ==è riservato a Prod. Owner e Team==, eseguito all'inizio di ogni sprint o iterazione.

In questo meeting si decide:
- cosa fare nello sprint, ossia ==l'iteration goal==
- ==l'iteration backlog==, che specifica quali feature implementare nello sprint
- ==la lista dei criteri di accettazione== per le feature da implementare

In questa fase non si definiscono ancora i membri assegnati alle task e quali task di testing fare. 

Per quanto riguarda l'==iteration backlog==, questo viene creato in 2 step:
- ==selezione delle user stories== dal backlog dell'intero prodotto
- ==decomposizione in task== di ogni user story e ==stima del costo temporale== di ognuna di esse 

Questo meeting ha di norma anche una finestra temporale prefissata per evitare di renderlo troppo lungo.

### Tecniche di supporto a Iteration Planning

Esistono alcune tecniche di supporto alla fase di iterazione, come ==Planning Game== oppure come il ==Planning Poker==. Idealmente, sapere quanto tempo richiedono le task da implementare aiuta a capire quante di queste "entrano" nello sprint. L'unità di misura usata è ==mese/persona==

Planning Game: prevede i devs da un lato, che sanno il tempo che richiede una feature per essere implementata, e i clienti dall'altro, che invece sono interessati a implementare più feature possibili in breve tempo.
I clienti dunque ordineranno le user stories (ossia le feature) in ordine di priorità e le forniranno ai devs, che verificheranno se queste rientrano temporalmente nello sprint o meno. In caso negativo, si reitera il processo fino a trovare un accordo tra le parti.

Planning Poker (SCRUM): ogni membro del ==gruppo di stimatori== ha delle carte con unità di misura precise e diverse fra loro (i.e. che non presentano differenze sottili). Tutti gli utenti assegnano alle varie task la carta che secondo loro rappresenta il costo temporale dopo che questa è stata descritta e si itera fino a trovare un accordo.
Il gruppo di stimatori è fatto da devs, Prod. Owner e qualche rappresentante dei clienti. Somigilia in questo al meotodo delfi.


### Daily meeting

Detto anche ==Daily Scrum==, si discute di:
- cosa si è fatto il giorno prima
- cosa si farà oggi
- quali sono potenziali impedimenti

Il tempo per i daily meetings è idealmente breve e non deve essere sprecato. 

I daily meeting devono inoltre essere adattati al team, come in caso di team che lavorano in fusi orari diversi (==elasticità==).

### Sprint Review Meeting

Si tratta del meeting in cui si ==analizza l'iteration planning== e si valuta ciò che effettivamente è stato fatto (feature funzionanti come misura del progresso).

### Sprint Retrospective Meeting

Nei ==retrospectives== lo SCRUM master e il team cercano di capire cosa è andato bene/male durante lo sprint ed eventualmente come possono migliorare questi vari aspetti o quali di essi possono essere mantenuti negli sprint successivi.