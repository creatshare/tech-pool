import math

def quadratic(a,b,c):
	d = b*b - 4 * a *c
	if d >= 0:
		x = (-b)/2*a + math.sqrt(d)
		y = (-b)/2*a - math.sqrt(d)
		return x,y
	else:
		print('不存在')
