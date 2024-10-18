### Lecture recap

Retrieval, web mining, query processing literature

#### Sparse retrieval

**Seismic model** overview, inverted index leveraging nn representations.

Interesting property of feature vector describing ...

Key seismic model elements (**heuristics**):
- **static** pruning: shortens posting lists using aformentioned property
- **dynamic** pruning: allows to skip posting list blocks without inspecting feature vector

Since documents are now represented by features, **block pruning** is also possible. It is performed by grouping documents by similarity, to only compare relevant ones. A summary vector (consisting of the max) describes the group of elements.

#### Web mining

![structure of web mining image]()

**Web content**: extract useful information from web documents.

Query mining, concept of search **task** and search **session**.

Literature on query graphs, query flow.