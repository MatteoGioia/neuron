Collection of papers focusing on explainability in retrieval from SIGIR 24

## Paper collection

**RAG-Ex: A Generic Framework for Explaining Retrieval Augmented Generation**  
- Author(s): _Viju Sudhi (Fraunhofer IAIS), Sinchana Ramakanth Bhat (Fraunhofer IAIS), Max Rudat (Fraunhofer IAIS), Roman Teucher (Fraunhofer IAIS)_

**Evaluating Search System Explainability with Psychometrics and Crowdsourcing**
- Author(s): _Catherine Chen (Brown University), Carsten Eickhoff (University of Tübingen)_

**Self-Explainable Next POI Recommendation**
- Author(s): _Kai Yang (University of Electronic Science and Technology of China), Yi Yang (University of Electronic Science and Technology of China), Qiang Gao (Southwestern University of Finance and Economics), Ting Zhong (University of Electronic Science and Technology of China), Yong Wang (Hong Kong University of Science and Technology), Fan Zhou (University of Electronic Science and Technology of China)_

**Explainable Uncertainty Attribution for Sequential Recommendation**
- Author(s): _Carles Balsells-Rodas (Imperial College London), Fan Yang (Amazon), Zhishen Huang (Amazon), Yan Gao (Amazon)_

**Explainability for Transparent Conversational Information-Seeking**  
- Author(s): _Weronika Łajewska (University of Stavanger), Damiano Spina (RMIT University), Johanne Trippas (RMIT University), Krisztian Balog (University of Stavanger)_


## Paper 1 

### Abstract 

[...] We introduce RAG-Ex, a model- and language-agnostic explanation framework that presents approximate explanations to the users revealing why the LLMs possibly generated a piece of text as a response, given the user input.
Our framework is compatible with both open-source and proprietary LLMs. We report the significance scores of the approximated explanations from our generic explainer in both English and German QA tasks and also study their correlation with the downstream performance of LLMs. In the extensive user studies, our explainer
yields an F1-score of 76.9% against the end user annotations and attains almost on-par performance with model-intrinsic approaches.

## Paper 2

### Abstract

[...] In this paper, we use psychometrics and crowdsourcing to identify human-centered factors of explainability in Web search systems and introduce SSE (Search System
Explainability), an evaluation metric for explainable IR (XIR) search systems. In a crowdsourced user study, we demonstrate SSE’s ability to distinguish between explainable and non-explainable systems, showing that systems with higher scores indeed indicate greater interpretability. We hope that aside from these concrete contributions to XIR, this line of work will serve as a blueprint for similar explainability evaluation efforts in other domains of machine learning and natural language processing.

## Paper 3

### Abstract

Point-of-Interest (POI) recommendation involves predicting users’ next preferred POI and is becoming increasingly significant in location-based social networks [...]
We propose a self-explainable framework with an ante-hoc view called ExNext for next POI recommendation aimed at overcoming these limitations. Specifically, we endow self-explainability to POI recommender systems through compact representation learning using a variational information bottleneck approach. The learned representation further improves accuracy by reducing redundancy behind massive spatial-temporal trajectories, which, in turn, boosts the recommendation performance. Experiments on three real-world datasets show significant improvements in both model explainability and recommendation performance.

## Paper 4

### Abstract

Sequential recommendation systems suggest products based on users’ historical behaviours. The inherent sparsity of user-item interactions in a vast product space often leads to unreliable recommendations. Recent research addresses this challenge by leveraging auxiliary product relations to mitigate recommendation uncertainty, and quantifying uncertainty in recommendation scores to modify
the candidates selection. However, such approaches may not be efficient due to the requirement of additional side information or providing suboptimal recommendations. To enhance sequential recommendation performance by leveraging uncertainty information, we introduce (Ex)plainable (U)ncertainty (A)ttribution (ExUA). We employ gradient-based saliency attribution to identify sources of uncertainty stemming from sequential interactions. Experimental findings on Amazon and MovieLens datasets demonstrate ExUA’s effectiveness in identifying interactions that induce uncertainty, resulting in a 6%+ improvement in NDCG@20 scores when the uncertainty information is integrated into a post-hoc training phase

## Paper 5

### Abstract

The increasing reliance on digital information necessitates advancements in conversational search systems, particularly in terms of information transparency. While prior research in conversational information-seeking has concentrated on improving retrieval techniques, the challenge remains in generating responses useful from a user perspective. This study explores different methods of explaining the responses, hypothesizing that transparency about the source of the information, system confidence, and limitations can enhance users’ ability to objectively assess the response. By exploring transparency across explanation type, quality, and presentation mode, this research aims to bridge the gap between system-generated responses and responses verifiable by the user. We design a user study to answer questions concerning the impact of (1) the quality of explanations enhancing the response on its usefulness and (2) ways of presenting explanations to users. The analysis of the collected data reveals lower user ratings for noisy explanations, although these scores seem insensitive to the quality of the response. Inconclusive results on the explanations presentation format suggest that it may
not be a critical factor in this setting.

