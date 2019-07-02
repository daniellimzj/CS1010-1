from fractions import gcd

def make_rat(x, y):
    return (x, y)

def numer(rat):
    return rat[0]

def denom(rat):
    return rat[1]

def add_rat(x, y):
    nx, dx = numer(x), denom(x)
    ny, dy = numer(y), denom(y)
    return make_rat(nx*dy + ny*dx, dx*dy)

def sub_rat(x, y):
    nx, dx = numer(x), denom(x)
    ny, dy = numer(y), denom(y)
    return make_rat(nx*dy - ny*dx, dx*dy)

def mul_rat(x, y):
    return make_rat(numer(x)*numer(y), denom(x)*denom(y))

def div_rat(x, y):
    return make_rat(numer(x)*denom(y), denom(x)*numer(y))

def equal_rat(x, y):
    return numer(x)*denom(y) == numer(y)*denom(x)

def print_rat(rat):
    print(str(numer(rat)) + '/' + str(denom(rat)))
    
def make_rat(n, d):  # version 2
    g = gcd(n, d)
    return (n//g, d//g)
