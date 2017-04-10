from Crypto.Cipher import AES
from Crypto import Random
from Crypto.Util import Counter
from binascii import unhexlify

plik = open('ctr.txt', 'r')
czytany = plik.read().splitlines()
klucz = unhexlify(czytany[0])

iv_hex =czytany[1]
ctr=Counter.new(128, initial_value=int(iv_hex,16))

ciphered = unhexlify(czytany[2])
cipher = AES.new(klucz, AES.MODE_CTR, counter=ctr)
plain = cipher.decrypt(ciphered)
print plain