# Tor

## Recall questions 
        - WIP

## The onion router

Tor is a distributed anonimity protocol (routing protocol), also known as the onion router.
The traffic is relayed over multiple nodes:

(immagine relay)

The first relay is called a guard and the last is called exit point. A minimum of 3 relays is necessary for the protocol to work.

The guard only knows the user, but not the destination website. The exit point knows the destination website but not the user. The relays don't
know anything. Furthermore, the packet is encypted with multiple keys.

(immagine con 3 nodi)
 
The name "onion" comes from the layered structure of the packet, that is encrypted in such a way that each node only knows the next relay.

### The routing protocol

Each relay has a list of the relays and can send it to the user. Using the list, the
user can pick >= 3 relays and see their public keys. 

The user can then agree with a relay (i.e. the guard) on a key using Authenticated Diffie Hellman.

(Immagine diffie helman, gruppo e public key)

The protocol is used again with other relays passing from the previous ones, so it is impossible to see how the circuit
is being built from the outside.

(Immagine circuito)

### Attacks on tor

The most common attack is traffic analysis and can be used if the owners knows both the guard and the exit point.
Through simple probalistic analysis the attacker can then de-anonimize the user. 

Another possibile attack can be done by the website, by reversing the custom settings of the user (fingerprint).
The TOR broswer is built against fingerprinting.

### Tor websites

To use a hidden service, it is first necessary to connect to a directory service through tor. The hidden service must also be connected
through tor to the directory service. The directory service then selects a rendez-vous point, used both by the user and the hidden service.

(Immagine hidden service)

To avoid attacks, the directory service is periodically changed. To compute the right directory service, a link that ends with ".onion" is used.