# Lezione II - Quality

## Recall questions
    - Perchè la quality ha diverse dimensioni? Perchè non sono "valide" prese singolarmente?
    - Conviene standardizzare il modo di misurare la quality?
    - Cosa è il project quality management? In quali steps si articola? (planning, assurance, quality control)
    - Perchè è importante (ma non basta) un processo di qualità?
    - Quanto costa la quality? (conformity+non conformity)
    - Perchè la quality è particolarmente importante nei sistemi safety critical? Perchè in questi casi è buona idea seguire uno standard? (ASIL)
    - Quali sono i tools forniti dai metodi agili per misurare la quality? 

## Che cosa è la qualità

### Qualità ha multiple dimensioni

Qualità non è un concetto semplice, ma è un concetto che ==possiede multiple dimensioni==: 
- i.e. ==cliente soddisfatto== di un prodotto 
- i.e. ==sistema funzionante a lungo== 
- i.e. prodotto ==in linea con le richieste== dei clienti (requisiti)
- i.e. prodotto ==privo di difetti==

Tutte le definizioni di sopra, per quanto corrette, non sono valide prese singolarmente, come mostrano dei banali controesempi:
- i.e. un prodotto che non fallisce mai ma è lentissimo ad operare sicuramente non è di qualità

Esistono tanti ==modi di misurare la qualità== e alcuni di essi sono ==standardizzati==.

Un esempio di standard qualitativo è definito da ==ISO 25010== detto ==SQuaRE== (Systems and software Quality Requirements and evaluation:
![](../../../Agile/quality.png)

### Project quality management

La gestione della qualità progettuale garantisce che ==il progetto soddisfi le necessità == per le quali è stato intrapreso e inlcude:
- quality ==planning==
- quality ==assurance==
- quality ==control==

### Quality planning

Processo di ==identificazione== di quali ==standard di qualità== siano ==rilevanti per il progetto== e come soddisfarli. Produce un ==quality plan==. 

Gli standard definiscono una serie di ==best practices== da seguire per evitare errori passati.

### Quality assurance 

[IEEE] ==Schemi pianificati e sistematici== che permettono di ==avere un elevato grado di confidenza su un prodotto== per quanto riguarda requisiti tecnici. Permettono inoltre di ==valutare== anche ==il processo== tramite il quale i prodotti sono sviluppati.

Sono inoltre utili per creare un ==framework di verifica della qualità== e dare ==continuità==.
- i.e. lavorare tutti con lo stesso standard diventa più semplice

### Quality control

==Controllare che le procedure e gli standard== definiti nel quality plan siano stati rispettati nel processo di sviluppo.

Il processo di quality control può essere fatto in vari modi:
- ==manuale==: quality reviews
- ==automatico==: quality measurements

### Processo di qualità

Un buon processo ==non produce necessariamente== prodotti di qualità; tuttavia questo non
giustifica fare uso di processi che siano scadenti.

In generale, processi di qualità ==diminuiscono il rischio== di creare prodotti di scarsa qualità.

### Costo della qualità

Costo della qualità = ==costo conformance== + ==costo non conformance==
- conformance: costo legato al creare prodotti in linea con i requisiti di uso
- non conformance: responsabilità legata al fallimento nel raggiungere gli standard dichiarati

## Case study: sistemi automotive

### Analisi e gestione dei rischi

In questo step si identificano ==i rischi legati al prodotto== e in seguito vengono stabiliti dei 
==goals di sicurezza== da garantire per prevenire o mitigare questi rischi.

Nel caso di del mondo ==automotive== è importante l'==ASIL== (Automotive Safety Integrity Level), uno standard che permette di identificare e valutare in modo sistematico i rischi legati al prodotto in questione.

![](../../../Agile/automotive_asil.png)

### Perchè seguire lo standard

Seguendo ad esempio tutti gli step ==specificati nello standard ISO 26262== si riescono a mostrare ==completezza==,==consistenza==,==tracciabilità== del prodotto nonchè ==produrre una documentazione esaustiva==.

In generale ci permette di mostrare che il prodotto sia safe e accettabile.

## Metodi agili e qualità

### Tools dei metodi agili

I metodi agili misurano la qualità tramite:
- ==user involvement==
- ==testing==

### Metodi agili vs quality 

Anche usando metodi agili è comunque necessario mostarare come siano stati seguiti tutti gli aspetti del quality planning - ad esempio se si sta lavorando su sistemi abbastanza safety critical.

Molto spesso infatti si è soggetti ad un bias verso il metodo di lavoro preferito che rende incapaci di vedere in modo oggettivo i dati presentati.



