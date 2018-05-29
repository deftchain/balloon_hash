## balloon_hash
_python module for pow verification_

### further reading / credits
balloon hashing is a memory-hard pow algorithm rivaling argon2 (secure hash at 1/8th memory cost).
the original password hashing algorithm was developed by Dan Boneh, Henry Corrigan-Gibbs and Stuart Schechter.
ported for PoW use by barrystyle (deft developer); this being the first coin ever to put it to use.

### installation:
1. python setup.py install
2. copy the resulting .so module to /usr/lib or /usr/local/lib

### testing:
python block.py

_note: libssl1.0 required (libssl1.1 wont work)_
