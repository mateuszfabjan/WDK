#!/usr/bin/env python

#importowane biblioteki

import hashlib
import ssdeep

plik = open('C:/Users/Fabjan/Desktop/test.zip','rb')

try:
    czytaj_plik = plik.read();

finally:
    plik.close()

md = hashlib.md5(czytaj_plik).hexdigest() 
print("MD5:")
print(md)	

sha = hashlib.sha256(czytaj_plik).hexdigest() 
print("SHA-256:")
print(sha)	

ssdp = ssdeep.hash(czytaj_plik)	
print("SSDEEP:")
print(ssdp)	
blocksize = 65535

mddeep = " "

with open('C:/Users/Fabjan/Desktop/text.zip',"rb") as file: 
	for wynik in iter(lambda: file.read(1025),""): 
		md5dp=hashlib.md5(wynik)
		mddeep=mddeep+md5dp.hexdigest() 

print("MD5DEEP:")
print(mddeep)