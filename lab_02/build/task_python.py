import time

def Calculate(x):
  return x * x - x * x + x * 4 - x * 5 + x + x

def isint(s):
    try:
        int(s)
        return True
    except ValueError:
        return False

while True:
  x = 2
  n = input()
  if  not isint(n):
    break
  n = int(n)
  start = time.time()
  for _ in range(n):
    x = Calculate(x)
  finish = time.time()
  t = finish - start
  print(t)