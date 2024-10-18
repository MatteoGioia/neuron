### Lecture recap

Web search engine components:
- crawler
- indexer
- query processor

#### Web crawlers basics

Crawlers navigate the web graph through **hyperlinks**. 
![intro_img_here]()

Crawlers have a **scheduler**, with two queues:
- **discovery** queue: download, discover
- **refreshing** queue

Performance evaluated through **coverage**, **freshness** and page **importance**.

Crawlers leverage **DNS caching** to resolve addresses and a "seen URL" table storing MD5 hashes.

![parallel_web_crawling_img_here]()

#### Indexing basics

Inverted index: data structure that links
![indexing_img_here]() 

Non naive reverse index uses additional information such as **images, HTML**, etc...

Efficient indexing through reordering and list **compression via gap encoding**, document and term based **partitioning**.

Parallel index computation with **MapReduce**.




