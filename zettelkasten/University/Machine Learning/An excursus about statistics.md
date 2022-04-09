# An excursus on statistics

Performance evaluation is about estimating errors. Errors are governed by probability.

In the following we'll refer to:
- test set as sample taken from a population
- value of an instance, or a feature, as an observation
- error of a ML model on a test set as a random variable, which we want to estimate 

## Estimators and error

Function of a sample of the data used to estimate some useful quality:

>$\hat{\theta}_S = g(S), S = (x_1, \ldots, x_m)$ where $x_i$ is a rv drawn from a distribution $D$

In the following, we'll focus on 2 main questions:

>**Q1**: Given a hypothesis $h$ and a data sample containing $n$ instances drawn at random according to distribution $D$, what is the best estimate of the accuracy of $h$ over future instances drawn from the same distribution? 

>**Q2**: Given that one hypothesis $h_1$ outperforms another hypotesis $h_2$over some sample data $S$, how probable is it that this hypothesis is more accurate in general?

### Hyp. accuracy and confidence intervals

To answer the first question, we are going to comput the ==confidence interval==. In  fact, the true error rate of our hypotesis $h(x)$ can't be computed, but we can get an idea of the interval in which it lies. 

![](../../..//ML/confint.png)

### Using sample error as a building block for the estimator for true error

As stated before, we want to find a good estimator for the error of our hypotesis. One possibile candidate is the ==sample error==.

Sample error of hpyotesis $h(x)$ for the target function $c(x)$ on a data sample $S$:
>$error(h(x)) = \sum_{i=1}^{n} \delta(c(x_i), h(x_i)) = \frac{r}{n} = 1 - accuracy_s (h)$ where $r$ is the number of misclassifications

This sample error usually differs from the ==true error==, the target rv that it tries to estimate. The true error of hyp. $h$ for the target classification function $c(x)$ and distribution $D$ of instances is the probability that $h$ will misclassify any instance $x$ drawn at random according to $D$:
>$error_D (h) = Pr_{x \in D}[c(x) \neq h(x)]$

An import thing about the sample error or $\frac{r}{v}$, is that it follows a binomial distribution:
>$P(X = r) = \binom{n}{r} p^r (1-p)^{n-r} = \frac{n!}{r!(n-r)!} p^r (1-p)^{n-r}$

In fact, we can see the sample rate as the probability of our hyp. misclassifying $r$ times the instances out of $n$ samples. We can then consider the following properties:
- expected value $E(\frac{r}{n}) = np$
- variance $Var(X) = np(1-p)$
- standard deviation $\sigma(X) = \sqrt{np(1-p)}$

Out of these values we can't compute the mean only. ==But, given a big enough sample size, the expected value of the sample error and the exp. value of the true error align.==

### Central limit theorem ... and why the previous claims work!

In the following we are going to explain why the sample error can be actually a good estimator for the probability of an error.

>CLT: the arithmetic mean of a sufficiently large number of experiments of independent random variables, each with a well-defined expected value and well-defined variance, will be approximately normally distributed.

This is important because the mean of the sample errors, which are binomial rv and are statistically indipendent, will tend to be the same as the real population mean errror! This means the distribution will be something like:

![](../../..//ML/gaussPE.png)

For a gaussian rv $f(x | \mu, \sigma^2) = \frac{1}{\sigma \sqrt{2 \pi}} e^{-\frac{(x - \mu)^2}{2 \sigma^2}}$, we know the following properties:
- 99.7% of the probability mass lies in the area below the mean value $\mu \pm 3 \sigma$
- 95.4% of the probability mass lies in the area below $\mu \pm 2 \sigma$
- 68.3% of the probability mass lies  in the area below $\mu \pm \sigma$

This is good for 2 main reasons:
- the sample error is an unbiased estimator for a large enough number of experiments, since the bias is 0
- we can approximate the std. deviation of the true error $\sigma_S = \frac{\sigma_r}{n} = \frac{1}{n} \sqrt{np \cdot (1-p)} = \sqrt{\frac{p \cdot (1-p)}{n}} \simeq \sqrt{\frac{\frac{r}{n} \cdot (1 - \frac{r}{n})}{n}} = \sqrt{\frac{error_S (h) \cdot (1 - error_S (h))}{n}}$

It is important to remember that this secondo property holds true for a large enough $n$ and that while approximating the std. deviation is ok, approximating $p$ with $\frac{r}{n}$ is not a good idea as the difference could be significant.

### Computing a confidence interval for an error estimate

We are now ready to compute a confidence interval. A confidence interval represents the statistical significane, said Margin of Error ME, of the expected distance $\Delta$ between the real value (in our case, $p$) and the observed estimate (in our case $\frac{r}{n}$).

>An $N\%$ confidence interval for some parameter $p$ is an interval $[LB, UB]$ that is expected with probability $N\%$ to contain $p$. 

>$\Delta = | error_D(h) - error_S (h)| \leq ME \implies |p - \frac{r}{n}| \leq E \implies |p - \frac{r}{n}| \leq z \sigma_S$
>$\implies LB = \frac{r}{n} - z \sigma_S \leq p \leq z \sigma_S + \frac{r}{n} = UB$

The ME is computed as the product of critical value times the std. deviation, which in simpler terms is the size of the area of the gaussian we are considering (how many $z$ std. devs from the mean?). The critical values are also called $z$-values. $\Delta$ is the abs. error of the estimate. 
- the good thing is that, for fixed $N\%$, we have tables that specify the $z$ in gaussian distribution!

>$[LB, UB] = [\frac{r}{n} - z \sqrt{\frac{\frac{r}{n} (1 - \frac{r}{n})}{n}}, \frac{r}{n} + z \sqrt{\frac{\frac{r}{n} (1 - \frac{r}{n})}{n}}]$

We can exploit the fact that the gaussian is symmetric to compute the probability that the error of our ML system is at most a given value.

![](../../..//ML/onetaild.png)