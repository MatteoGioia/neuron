# Consensus in DS 

## Recall questions
    - WIP

## Consensus on transaction

### Why reaching consensus is hard

Reaching consensus is an important topic in DS.
- i.e. modern blockchains

But in real DS system, we have faults:
- crash failures
- bizantine failures: not only bizantine nodes can stop working, but they could cooperate with malicious intent

The issue is that in DS, even 1 crash failure makes reaching consensus impossible.
- this was proved in the FLP theorem
- the idea is that it is impossible to distinguish a crash from a process just being slow

Another important characteristic of DS is that they ensure:
- safety: the DS always does correct operation
- liveness

But in such a system, FLP also states that we can't reach consensus if we have both safety and liveness 

### Atomic commits

These are the important properties of the atomic commit protocols we want to design:
- AC1: all processes that reach a decision must reach the same one
- AC2: processes cannot reverse their decision
- AC3: the commit decision can only be reached if all processes voted yes
- AC4: if there are no failures, and all processes voted yes, decision must be commit

### 2-Phase commit

Components:
- coordinators
- partecipants

(Immagine)

### Recovery protocol

Because we designed the protocol in a DS...

What we can do, however, is making a recovery protocol
- this is because the crash that stops the protocol might not be a fatal crash, but a recoverable one (through the use of logs, for instance)

If you are a partecipant, you send the message and then log
- this way there is no risk of sending a message twice because you crash before logging
- this is a MUST if you are sending yes (because you can't abort after sending yes), if the answer is ABORT it is not necessary 

If you are the coordinator, you log and send the message