### Calcular puntos
# Dividimos la ecuacion en varias partes
from math import sqrt
Vi = 0
k = 0.00095
vt = 1.12
r = 2150

a = -k*r/2
b = k*r*(Vi-vt)+1
c = -5

rango = int (input("rango: "))

for i in range (0,rango+1):
   Vi = float(input("\nvi: "))
   a = -1
   b = 2*Vi-3.219
   c = -4.895961
   Vo = (-b-sqrt((b**2)-4*a*c))/(2*a)   
   print (Vo)
