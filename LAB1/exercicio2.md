#### Exercício 2 (parcialmente explicado)s
O resultado da conta foi -1.665334536937735e-16

Isto ocorre em função da representação dos números na memória.
 - Ocorre que 2.3 e 0.3 são dízimas em binário. 
 - No entanto, a representação em notação científica implica que a mantissa de 2.3 varia em uma casa em relação à mantissa de 0.3
 - Ao subtrair 2 de 2.3, sobra um número próximo de 0.3, mas "shiftado a direita", perdendo uma informação que foi truncada;
 - Como o literal 0.3 não sofreu o mesmo truncamento, ao subtrair ele do número "próximo de 0.3" haverá a diferença observada.

Explico melhor até domingo.

    


