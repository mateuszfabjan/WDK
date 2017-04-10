#!/usr/bin/env python
#-*-coding: utf-8 -*-

from Crypto.Cipher import AES
from Crypto import Random
from binascii import unhexlify

plik = open('cbc.txt', 'r')
czytany = plik.read().splitlines()
key = unhexlify(czytany[0])
iv = unhexlify(czytany[1])
cipher = AES.new(key, AES.MODE_CBC, iv)
msg = iv + cipher.decrypt(unhexlify(czytany[2]))
print (msg.decode('latin-1'))