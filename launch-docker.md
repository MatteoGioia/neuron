# Docker launch command

### The following command will mount docker in the notes directory and host the webserver on the 8080 port on localhost


```
cd zettelkasten

```

```

 docker run --rm -t -i -p 8080:8080 -v "$(pwd):/notes" sridca/neuron neuron gen -ws 0.0.0.0:8080
```

use sudo if on linux