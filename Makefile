projet : Projet_ncurses.o projet-main.o
	g++ $^ -o $@ -I modele.h -lncurses

%.o: %.cpp
	g++ $< -c