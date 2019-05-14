def f(x):
  if x <= 1./2.:
    return 2. * x
  if x > 1./2.:
    return 2. * x - 1

x = (1./10.)

for i in range(80):
  print i, x
  x = f(x)

print x
# 1: x = 2/10
# 2: x = 4/10
# 3: x = 8/10
# 4: x = 6/10
# 5: x = 2/10
# 80 is a multiple of 5, so end result should be 2/10
