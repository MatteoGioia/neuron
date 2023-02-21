# Tor

## Recall questions 
        - What is tor and how does it work? 
        - Why the name onion?
        - How does the routing work? Why the minimum number of relays needed is 3?
        - Why is tor communication anonymous (even if the relays are malicious)?
        - How is a TOR circuit built?
        - What is a hidden service? How is connection to it achieved? Why must the directory service be changed over time? 

## The onion router

Tor is a ==distributed anonimity protocol (routing protocol), also known as the onion router.
The traffic is relayed over multiple nodes:==

![](../../../DS/tor.png)

The ==first relay is called a guard and the last is called exit point. A minimum of 3 relays is necessary for the protocol to work.==

The ==guard only knows the user, but not the destination website. The exit point knows the destination website but not the user. The relays don't
know anything. Furthermore, the packet is encypted with multiple keys.==

![](../../../DS/tor1.png)
 
The name =="onion" comes from such layered structure of the packet==, that is encrypted in such a way that each node only knows the next relay, but has not the key to decrypt the content of the subsquent layer.

### The routing protocol

==Each relay has a list of the relays and can send it to the user. Using the list, the
user can pick >= 3 relays and see their public keys.==

The ==user can then agree with a relay (i.e. the guard) on a key using Authenticated Diffie Hellman.==

![](../../../DS/tor2.png)

The ==protocol is used again with other relays passing from the previous ones, so it is impossible to see how the circuit is being built from the outside.==

### Attacks on tor

The most ==common attack is traffic analysis and can be used if the owners knows both the guard and the exit point.==
Through simple ==probalistic analysis the attacker can then de-anonimize the user.==
- although by design such attack is unlikely

Another possibile attack can be done by the website, by reversing the custom settings of the user (fingerprint).
The ==TOR broswer is built against fingerprinting.==

### Tor websites

To use a ==hidden service, it is first necessary to connect to a directory service through tor==. The hidden service must also be connected
through tor to the directory service. ==The directory service then selects a rendez-vous point, used both by the user and the hidden service.==

![](../../../DS/tor3.png)

The ==rendevouz are unique so that multiple devices can spread the traffic over multiple relays and maximise bandwith.==

To avoid attacks, the ==directory service is periodically changed. To compute the right directory service, a link that ends with ".onion" is used.==