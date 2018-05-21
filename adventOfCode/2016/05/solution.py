#Day 5: How About a Nice Game of Chess?
#http://adventofcode.com/2016/day/5
import hashlib

def solveParts1and2():
  idCode = "ugkcyxxp"
  idx = 0
  counter = 0
  #results
  part1Pass=""
  part2Pass=['*' for _ in range(8)]
  while True:
      key = idCode + str(idx)
      md5 = hashlib.md5(key.encode("UTF-8")).hexdigest()
      if md5.startswith("00000"):
          if ord(md5[5]) >= ord('0') and ord(md5[5]) <= ord('7'):
            if part2Pass[int(md5[5])] == '*':
              part2Pass[int(md5[5])] = md5[6]
            if not '*' in part2Pass:
              break
            
          if counter < 8:
            part1Pass += md5[5]
            counter += 1
      idx += 1
  # results
  print("Part1 password: "+part1Pass)
  print("Part2 password: "+"".join(part2Pass))

solveParts1and2()
