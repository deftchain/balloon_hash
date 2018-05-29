import balloon_hash, binascii, os, sys, time

#blockheader for deft's genesis block
header = "010000000000000000000000000000000000000000000000000000000000000000000000d6583f75558751197a8e8a2760d4f9b08ba0a40e6e49d456c69f8046c3b85447f0ae0a5bf0ff071f68020000"
print header

#pow hash
hashbin = binascii.unhexlify(header)
posthash = balloon_hash.getPoWHash(hashbin)[::-1]
target = "0007fff000000000000000000000000000000000000000000000000000000000"
targetbin = binascii.unhexlify(target)

print ' '
print binascii.hexlify(targetbin)
print binascii.hexlify(posthash)
print ' '

if posthash < target:
   print 'hash is lower than target (good)'
else:
   print 'hash above target (error)'
