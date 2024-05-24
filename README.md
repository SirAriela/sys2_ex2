# sys2_ex2
206862666 ariela Goncherook


##Arithmetic operators -
+, -, +=, -=
i checked if the adj matrix has the same size, if so they did the arithmetic oparations of adding/ subtracting.

+, - unaric - 
- unaric: multiplaying the edges by -1
+ unaric: mult by 1.. (idk why we need it)

*= (int) - 
multiplaying all the edges by the numeric value

<< - changing the output so it will fit to print the graphs.
https://learn.microsoft.com/en-us/cpp/standard-library/overloading-the-output-operator-for-your-own-classes?view=msvc-170

*only for edges that us different from 0.*
//increess by one postfix
Graph &operator++(int);

// increess by one prefix
 Graph &operator++();
 
comparison operators - 
checking if the graphs is containd in another graph is a np-cpmplete, i have decided to check 
it in dirrect way - https://en.wikipedia.org/wiki/Subgraph_isomorphism_problem
the same vertices has the same edges and numbered in the same order.

operator ==:
if they have the same amount of vertices, and the adj matrix is the same.
or if g1 <= g2 and g2 <= g1.

operator !=:
send the graph to == , if i recived false then i return true to that they are different.

operator "<" or ">"
if g1 is a subgraph of g2
and to check the other direction i just sent them in the oposit way.


operator <= , >=:
i checked that it or < or ==.


g = g1*g2:
i checked that the graphs has the same amount of vertices, and did multipication to matrices like in linear algebra.


