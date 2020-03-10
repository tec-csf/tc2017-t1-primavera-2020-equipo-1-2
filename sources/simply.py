from sympy import *
#variable opens the file polinomio.txt only for reading
g = open('polinomio.txt','r') 
#simpli saves the line
simpli = g.readline()
#fileClosing
g.close()
#function that expands the polynomial
def expPolinomio (polynom):
    n = symbols('n')
    return(expand(polynom))
#saves the function return in a string form
valor = str(polinomio(simpli))
#creates de file so, it opens in c++
arch = open ('listo.txt','w')
arch.write(valor)
arch.close()
