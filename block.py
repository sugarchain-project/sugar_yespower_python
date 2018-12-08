import sugarPersonality_yespower, binascii, os, sys, time

#blockheader for bitzeny's genesis block
# header = "010000000000000000000000000000000000000000000000000000000000000000000000d6583f75558751197a8e8a2760d4f9b08ba0a40e6e49d456c69f8046c3b85447f0ae0a5bf0ff071f68020000"
header = "02000000cef5b89f4ebf38a73cd440439edaca4afa7c7ad82be281473b9e5ee5f70900005df17cda32f206b3f27d9c3a262f3709a08164b05846532f0afd3a456bd550c59f5d5d54ffff3f1ef5190000"
print header

#pow hash
hashbin = binascii.unhexlify(header)
posthash = sugarPersonality_yespower.getPoWHash(hashbin)[::-1]
# target = "0007fff000000000000000000000000000000000000000000000000000000000"
target = "000002ab465b554b820b7ebe96c6c3447e8b1f7460889cf0e103a32bf36ee2eb"
targetbin = binascii.unhexlify(target)

print ' '
print binascii.hexlify(targetbin)
print binascii.hexlify(posthash)
print ' '

if posthash < target:
   print 'hash is lower than target (good)'
else:
   print 'hash above target (error)'
