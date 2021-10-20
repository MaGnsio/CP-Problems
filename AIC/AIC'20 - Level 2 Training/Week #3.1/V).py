#https://vjudge.net/contest/419722#problem/V
def gcd (x, y):
 if y == 0:
  return x
 return gcd (y, x % y)
x, y, a, b = input ().split ()
n, m, l, r = int (x), int (y), int (a), int (b)
f = int (n * m / gcd (n, m))
print (int ((r // f) - ((l - 1) // f)))
