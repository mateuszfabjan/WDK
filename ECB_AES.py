#!/usr/bin/env python
#-*-coding: utf-8 -*-

from Crypto.Cipher import AES
from Crypto import Random
from binascii import unhexlify

plik = open('ecb.txt', 'r')
czytany = plik.read().splitlines()
key = unhexlify(czytany[0])
iv = Random.new().read(AES.block_size)
cipher = AES.new(key, AES.MODE_ECB, iv)
msg = iv + cipher.decrypt(unhexlify(czytany[1]))
print (msg.decode('latin-1'))