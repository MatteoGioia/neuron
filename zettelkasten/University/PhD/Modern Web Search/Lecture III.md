### Lecture recap

#### Ranking

Evaluation **metrics** for ranking:
- **precision, recall**,etc
-  advanced metrics such as **DCG, RBP, ERR** (see reference material)

Pair-wise ranking algorithms, such as **RankNet**, and other approaches such as **Ranking-SVM, RankBoost**.

Modern techniques for ranking pre-BERT:
- word2vec
- FastText
- doc2vec

Bert based techniques:
- **monobert**: input both document and query, output relevance score
- **duobert**: compare pairwise queries
- **colbert**

Hard negative sampling, static and dynamic sampling

Efficient techniques for improving bert based models