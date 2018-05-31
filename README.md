	Program which contains BFS algorithm with slight modification.
	Solution of the following task:
	"Niewyobrazalne, ale centrala obcej wrogiej agencji sasiaduje z naszym budynkiem. Plan
	jest prosty, trzeba dotrzec do pomieszczenia dowodzenia i aresztowaæ dowódce. Niestety
	wszystkie pomieszczenia w centrali obcej wrogiej agencji maj¹ drzwi zamkniete, a my nie mamy
	dorobionych kluczy. Dlatego przebijemy siê przez œciany. Masz plany budynku w postaci grafu,
	pomieszczenia to wierzcholki, punkt D to punkt dowodzenia, zbiór S to te wierzcholki, które
	sasiaduja z naszym budynkiem (od jednego z nich zaczniemy), zas krawedzie odpowiadaja
	œcianom, przez które mozemy sie przebic. Napisz algorytm, który pozwoli ustalic trase do
	punktu dowodzenia wymagajaca przebicia jak najmniejszej liczby scian."

	HOW TO USE: 
	1. Create instance of Inputer class.
	2. Create insatance of Agency class by calling Inputer instance method - loadParameter.
		Argument is path to file from which the data will be loaded.
		Template of such a file is shown below this instruction.
	3. Call instance method findShortest.
		The printed nodes are the searched answer.

	FILE TEMPLATE:
		number of graph elements
		number of neighbour elements (quantity of S set)
		matrix of graph coincidence, elements are separeted by space
		S set, elements are also separeted by space 
		D node - element to which is path searched 

		Example:
		5 
		2
		0 1 0 0 0
		1 0 1 0 0
		0 1 0 1 1
		0 0 1 0 0
		0 0 1 0 0
		1 0
		4

	The nodes are represented by numbers, indexed from 0. 

	Author: Rosenhof Marcin, Rybicka Magdalena, Smela Damian
