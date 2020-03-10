import sys
import sympy

lista = sys.argv

with open('polinomio.txt', 'r') as myfile:
  data = myfile.read()

sol = sympy.expand(data)
print(sol)