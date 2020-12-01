#Day 14: One-Time Pad
#http://adventofcode.com/2016/day/14
import hashlib
import re
from collections import deque

with open("input.txt", 'r') as f:
    for line in f:
        salt = line.rstrip()

def solvePart1():

  compiled3 = re.compile(r'([0-9]|[a-f])\1{2}')
  idx = 0
  keys =[]
  while True:
    key = salt + str(idx)
    md5 = hashlib.md5(key.encode("UTF-8")).hexdigest()
 
    found = re.search(compiled3, md5)
    if found is not None:
      valToBeFound = found.group(0)+ (2*found.group(1))
      for i in range(idx+1, idx+1001):
        key = salt + str(i)
        md5 = hashlib.md5(key.encode("UTF-8")).hexdigest()
        if md5.find(valToBeFound) != -1:
          keys.append(md5)
          break          
    if len(keys) == 64:
        print("Part1 answer: %d"%idx)
        break
    idx+=1

  
def solvePart2():

  def gen2016Hash(key):
    md5 = hashlib.md5(key.encode("UTF-8")).hexdigest()
    for _ in range(2016):
        md5 = hashlib.md5(md5.encode("UTF-8")).hexdigest()
    return md5
    
  compiled3 = re.compile(r'([0-9]|[a-f])\1{2}')
  idx = 0  
  keys = []
  hashes = deque()
  
  for i in range(0, 1001):
    hashes.append(gen2016Hash(salt + str(i)))
  hashIdx = 1001
  while True:    
    md5 = hashes.popleft() 
    found = compiled3.search(md5)
    if found is not None:
      valToBeFound = 5*found.group(1)
      for hash in hashes:
        if hash.find(valToBeFound) != -1:
          keys.append(md5)
          break
    if len(keys) >= 64:
        print("Part2 answer: %d"%idx) 
        break
    idx+=1
    hashes.append(gen2016Hash(salt + str(hashIdx)))
    hashIdx+=1
 
  
solvePart1()
solvePart2()



