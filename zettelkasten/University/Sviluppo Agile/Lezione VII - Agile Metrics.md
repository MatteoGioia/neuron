# Agile Metrics

## Recall questions
    - WIP
    - Perchè scegliere metriche poco costose ma espressive?

## Measuring Agile Teams Performance

### Metriche di progresso

Idea: ==collezionare dati in forma di metrica per analizzare l'andamento del team== che usa metodi agili, inoltre si tratta di un processo ==ciclico==.Alcune metriche possibili sono ad esempio:
- velocity: performance relativa del team nel tempo
- ==changed lines of code==

Nei metodi agili ==il software funzionante== è la metrica principale di progresso. Questo non significa però che in nome del progresso si possa scendere a compromessi su quanto funzionante sia il software, o creare software che funziona ma è di bassa qualità, i.e. *così difficile da usare che il cliente lo abbandona*.

Tutte queste metriche quindi ==vanno valutate e interpretate contestualmente==.

### Come scegliere il metro di misura

Misura ==poco costosa==: conviene scegliere metriche che non richiedano troppo tempo per essere raccolte proporzionalmente alla loro utilità, e conviene anche ==selezionare quali di queste tracciare==, ovvero che siano ==espressive==, nel senso che non richiedono troppo tempo per essere interpretate.

### Ambiti di valutazione della performance 

Esistono ==vari ambiti== entro i quali si può valutare la performance del team:
- ==project tracking==: gestire ==tasks e bugs==
- ==source control==: gestire ==codice e collaborazione sul codice==
- ==continuous integration==: generare ==build e fare test==
- ==deployment tools==:  ==muovere codice tra i vari ambienti==
- ==application monitoring==: verificare che tutto funzioni

Questo mostra che i dati ==provengono da fonti diverse==, non esiste una sola metrica per la performance "globale" che racchiuda tutte le altre in modo esaustivo. Anche le varie metriche viste precedentemente possono essere accopiate per valutare le metriche in modo diverso.

### Project Tracking

Regole per un buon project tracking: 
- assicurarsi che tutti usino lo stesso PTS
- inserire solo i dati utili nelle task
- definire chiaramente quando una task è completata in modo corretto

### Source Control

Le info del source control possono essere utili a valutare l'andamento del codice:
- i.e. situazione stagnante: molte PR ma poche code review approvate (si lavora molto su codice vecchio che non progredisce)

### Continuous Integration

Tool che permettono, ad esempio, di fare test automatici sul codice per verificare che tutte le modifiche siano state eseguite correttamente.
Un grafico ad esempio può riportare quante build fatte hanno successo e quante invece falliscono:

..inserire img...

### Application Monitoring 

Informazioni raccolte ==durante l'uso dell'applicativo==, in quanto i test, per quanto ben disegnati, potrebbero non simulare perfettamente l'uso effettivo che poi si fa di tale applicativo. 

### Altre metriche utili per il team

==Recidivism==:
> Misura di quanto spesso il team si muova nel verso sbagliato del workflow

==Comment to Commit Ratio==:
> Noto anche come PR paralysis, indica che le PR non sono distribuite in modo bilanciato nel team

Esistono inoltre metriche ==relative== agli NFR del nostro sistema che possono essere misurate meglio durante il ciclo di vita del sw.
- i.e. security: falle del codice scoperte durante l'uso