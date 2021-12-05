#include "modele.h"
using namespace std;

int main() {
    bool jeu = true;
    while(jeu == true) {
        initscr();
        start_color();
        init_pair(10, COLOR_YELLOW , COLOR_BLACK );
        keypad(stdscr, TRUE);
        int compteur = 0;
        int compteurfin = 0;
        Plateau t;
        t = plateauInitial();
        for (auto i: t) {
            for (auto d: i) {
                if (d == 4) {
                    compteur++;
                }
            }
        }
        Plateau t2;
        attron(COLOR_PAIR(10));
        printw("Choisissez un mode de jeu: mode simple (fleche gauche) ou mode double (fleche droite)");
        attroff(COLOR_PAIR(10));
        int m;
        m = getch();
        while( m != KEY_LEFT and m != KEY_RIGHT) {
            m = getch();
        }
        refresh();
        while (not estTermine(t)) {
            clear();
            if(estGagnant(t)){compteurfin++;}
            if(estGagnant(t) and compteurfin == 1){
                printw("2048 :) !!, voulez-vous continuer ?(y/n)");
                dessine(t);
                int d = getch();
                while( d != 'y' and d != 'n') {
                    d = getch();
                    if (d == 'y') {
                        continue;
                    }
                    if (d == 'n') {
                        clear();
                        return 0;
                    }
                }
                refresh();
            }
            clear();
            int verif = 0;
            printw("            score: ");
            printw((to_string(score(t) - 4 * compteur)).c_str(), "\n");
            dessine(t);
            int c;
            c = getch();
            if (c == 'e') {
                refresh();
                return 0;
            }
            t2 = deplacement(t, c);
            if( m == KEY_LEFT) {
                while (verif == 0 and t2 != t) {
                    int a = rand() % 4;
                    int b = rand() % 4;
                    if (t2[a][b] == 0) {
                        t2[a][b] = tireDeuxOuQuatre();
                        if (t2[a][b] == 4) {
                            compteur++;
                        }
                        verif = 1;
                    }
                }
            }if(m == KEY_RIGHT){
                while (verif == 0 and t2 != t) {
                    int a = rand() % 4;
                    int b = rand() % 4;
                    int l = rand() % 4;
                    int o = rand() % 4;
                    while (l == a and o == b) {
                        l = rand() % 4;
                        b = rand() % 4;
                    }
                    if(contientun0(t2)){
                        if (t2[a][b] == 0 ) {
                            t2[a][b] = tireDeuxOuQuatre();
                            if (t2[a][b] == 4) {
                                compteur++;
                            }
                            verif = 1;
                        }
                    }else{
                        if (t2[a][b] == 0 and t2[l][o] == 0) {
                        t2[a][b] = tireDeuxOuQuatre();
                        t2[l][o] = tireDeuxOuQuatre();
                        if (t2[a][b] == 4) {
                            compteur++;
                        }
                        if (t2[l][o] == 4) {
                            compteur++;
                        }
                        verif = 1;
                    }
                    }
                }
            }
            t = t2;
        }
        if (estTermine(t) ) {
            clear();
            printw("vous avez perdu :( , voulez-vous rejouer ?(y/n)");
            dessine(t);
            int a = getch();
            while( a != 'y' and a != 'n') {
                a = getch();
                if (a == 'y') {
                    clear();
                    continue;
                }
                if (a == 'n') {
                    clear();
                    jeu = false;
                }
            }

            refresh();
        }

    }
    return 0;
}