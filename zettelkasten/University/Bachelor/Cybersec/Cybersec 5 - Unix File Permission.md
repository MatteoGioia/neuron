# Unix File Permission

## Unix access control

### Linux Principals and Subjects

==Subject==: programma eseguito per conto di un ==principal== e che opera su risorse del sistema (oggetti nella matrice degli accessi.)

==Principal==: può avere uno o più soggetti associati o trovarsi in idle.
Nel dettaglio i principals di Linux sono ==utenti== e ==gruppi==.

### User accounts (in Linux)

Gli account utenti sono salvati in `/etc/passwd` come numeri a 32 bit.
Ogni utente ha uno ==username== e uno ==UID== (user id).

Il ==superuser== è l'utente con i massimi privilegi, ha `UID = 0` e comunemente è indicato con il nome `root`. Ogni utente può diventare superuser e in tal modo disabilitare tutti (o quasi) i controlli di sicurezza.

### Gruppi (in Linux)

I gruppi sono salvati in `/etc/groups` come numeri a 32 bit.
Ogni gruppo ha un ==group name== e uno ==GID== (group id).
Per cambiare ad un nuovo gruppo è necessaria la password.

Solo i superusers possono aggiungere gruppi e membri.

### Subjects (in Linux)

I soggetti sono ==processi==, ognuno associato con:
- rUID/rGID (==reale==): ereditato dal ==processo padre==, di norma è l'UID dell'utente che lancia il programma.
- eUID/eGID (==effettivo==): ereditato dal ==processo padre== oppure ==dal file eseguito==.
- UID/GID salvato: permette di switchare tra eUID/eGID e rUID/rGID

L'eUID/eGID è utile in quanto spesso si vogliono lanciare programmi come SU e in quel caso si usa uno UID/GID che potenzialmente è diverso da quello reale dell'utente.

### Objects (in Linux)

Gli oggetti gestiti dall'ACL possono essere ==files, directories, dispositivi di memoria, I/O, $\ldots$==.
In Linux quasi tutti gli oggetti possono essere trattati come files.

Un oggetto riporta:
- 12 permission bits per owner, group e others + suid, sgid e sticky
- owner
- group 

==Solo il proprietario del file== può cambiare i permission bits e ==solo il superuser== può cambiare il proprietario.

### SUID, SGID e Sticky

I bit di SUID e SGID, se settati, permettono di switchare ==EUID/EGID== quando un file eseguibile è lanciato.

Inoltre, solo per le directories, indicano che i nuovi file ereditano il gruppo della directory corrente.

Gli sticky bits non sono più usati eccetto che per indicare che nelle directories solo il proprietario di un file lo può eliminare. 

### SUID to root

I processi con proprietario `root` e bit SUID settato ==assumono lo status di superuser== quando eseguiti.

### Access Control decisions

L'access control decide in base all'==effective UID/GID==:
- in caso questo corrisponda con il proprietario, guarda i bit dedicati ai permessi del proprietario
- alternativamente, se il gruppo possiede il file, guarda quelli dei gruppi
- se nè UID nè GID possiedono il file, guarda quelli dedicati agli altri (world)

### Managing Linux Permissions

La gestione e modifica dei permessi è fornita tramite i comandi `chown` e `chmod`