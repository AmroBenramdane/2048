#include "modele.h"

/** Des fonctions peuvent être ajoutés à ce fichier si besoin est (fonctions pour mettre à jour le score par exemple)
 * */


/** génère un Plateau de dimensions 4*4 ne contenant que des 0
 *  @return un Plateau vide
 **/

Plateau plateauVide() {
    Plateau pl;
    pl = Plateau(4);
    for (int i = 0; i < pl.size(); i++) {
        pl[i] = vector<int>(4);
    }
    return pl;
}

/** génère aléatoirement un 2 ou un 4 avec des probabilités respectives de 9/10 et 1/10
 *  @return 2 ou 4
 **/
int tireDeuxOuQuatre() {
    vector<int> proba;
    proba = vector<int>(10);
    for(int i = 0; i<proba.size()-1; i++){
        proba[i] = 2;
    }
    proba[9] = 4;
    int ind = rand() % 10;
    return proba[ind];

}
/** génère deux nombres sur des cases aléatoires d'un Plateau vide
 *  @return un Plateau en début de jeu
 **/

Plateau plateauInitial() {
    Plateau plateau = plateauVide();
    int a = rand() % 4;
    int b = rand() % 4;
    plateau[a][b] = tireDeuxOuQuatre();
    int c = rand() % 4;
    int d = rand() % 4;
    while (c == a and d == b) {
        c = rand() % 4;
        d = rand() % 4;
    }
    plateau[c][d] = tireDeuxOuQuatre();
    return plateau;
}


/** déplace les tuiles d'un Plateau vers la gauche et les combine si possible
 *  @param plateau le Plateau
 *  @return le Plateau une fois déplacé vers la gauche
 **/
Plateau deplacementGauche(Plateau plateau) {
    for (int k = 0; k < 3; k++) {
        for (int i = 0; i < plateau.size(); i++) {
            for (int v = 0; v < plateau[0].size() - 1; v++) {
                if (plateau[i][v] == 0 and plateau[i][v + 1] != 0) {
                    plateau[i][v] = plateau[i][v + 1];
                    plateau[i][v + 1] = 0;
                }
            }
        }
    }
    for (int g = 0; g < plateau.size(); g++) {
        for (int q = 0; q < plateau[0].size() - 1; q++) {
            if (plateau[g][q] == plateau[g][q + 1]) {
                plateau[g][q] = 2 * plateau[g][q];
                plateau[g][q + 1] = 0;
            }
        }
    }
    for (int i = 0; i < plateau.size(); i++) {
        for (int v = 0; v < plateau[0].size() - 1; v++) {
            if (plateau[i][v] == 0 and plateau[i][v + 1] != 0) {
                plateau[i][v] = plateau[i][v + 1];
                plateau[i][v + 1] = 0;
            }
        }
    }
    return plateau;
}

/** déplace les tuiles d'un Plateau vers la droite et les combine si possible
 *  @param plateau le Plateau
 *  @return le Plateau une fois déplacé vers la droite
 **/
Plateau deplacementDroite(Plateau plateau) {
    for (int k = 0; k < 3; k++) {
        for (int i = 0; i < plateau.size(); i++) {
            for (int v = 3; v > 0; v--) {
                if (plateau[i][v] == 0 and plateau[i][v - 1] != 0) {
                    plateau[i][v] = plateau[i][v - 1];
                    plateau[i][v - 1] = 0;
                }
            }
        }
    }
    for (int i = 0; i < plateau.size(); i++) {
        for (int v = 3; v > 0; v--) {
            if (plateau[i][v] == plateau[i][v - 1]) {
                plateau[i][v] = 2 * plateau[i][v];
                plateau[i][v - 1] = 0;
            }
        }
    }
    for (int i = 0; i < plateau.size(); i++) {
        for (int v = 3; v > 0; v--) {
            if (plateau[i][v] == 0 and plateau[i][v - 1] != 0) {
                plateau[i][v] = plateau[i][v - 1];
                plateau[i][v - 1] = 0;
            }
        }
    }
    return plateau;
}

/** déplace les tuiles d'un Plateau vers le haut et les combine si possible
 *  @param plateau le Plateau
 *  @return le Plateau une fois déplacé vers le haut
 **/
Plateau deplacementHaut(Plateau plateau) {
    for (int k = 0; k < 3; k++) {
        for (int i = 0; i < plateau.size() - 1; i++) {
            for (int v = 0; v < plateau[0].size(); v++) {
                if (plateau[i][v] == 0 and plateau[i + 1][v] != 0) {
                    plateau[i][v] = plateau[i + 1][v];
                    plateau[i + 1][v] = 0;
                }
            }
        }
    }
    for (int g = 0; g < plateau.size() - 1; g++) {
        for (int q = 0; q < plateau[0].size(); q++) {
            if (plateau[g][q] == plateau[g + 1][q]) {
                plateau[g][q] = 2 * plateau[g][q];
                plateau[g + 1][q] = 0;
            }
        }
    }
    for (int i = 0; i < plateau.size() - 1; i++) {
        for (int v = 0; v < plateau[0].size(); v++) {
            if (plateau[i][v] == 0 and plateau[i + 1][v] != 0) {
                plateau[i][v] = plateau[i + 1][v];
                plateau[i + 1][v] = 0;
            }
        }
    }
    return plateau;
}


/** déplace les tuiles d'un Plateau vers le bas et les combine si possible
 *  @param plateau le Plateau
 *  @return le Plateau une fois déplacé vers le bas
 **/
Plateau deplacementBas(Plateau plateau) {
    for (int k = 0; k < 3; k++) {
        for (int i = 3; i > 0; i--) {
            for (int v = 0; v < plateau[0].size(); v++) {
                if (plateau[i][v] == 0 and plateau[i - 1][v] != 0) {
                    plateau[i][v] = plateau[i - 1][v];
                    plateau[i - 1][v] = 0;
                }
            }
        }
    }
    for (int g = 3; g > 0; g--) {
        for (int q = 0; q < plateau[0].size(); q++) {
            if (plateau[g][q] == plateau[g - 1][q]) {
                plateau[g][q] = 2 * plateau[g][q];
                plateau[g - 1][q] = 0;
            }
        }
    }
    for (int i = 3; i > 0; i--) {
        for (int v = 0; v < plateau[0].size(); v++) {
            if (plateau[i][v] == 0 and plateau[i - 1][v] != 0) {
                plateau[i][v] = plateau[i - 1][v];
                plateau[i - 1][v] = 0;
            }
        }
    }
    return plateau;
}

/** déplace les tuiles d'un Plateau dans la direction donnée et génère une nouvelle tuile si le déplacement est valide
 *  @param plateau le Plateau
 *  @param direction la direction
 *  @return le Plateau déplacé dans la direction
 **/


Plateau deplacement(Plateau plateau, int direction) {
    if (direction == KEY_UP) {
        return deplacementHaut(plateau);
    }
    if (direction == KEY_LEFT) {
        return deplacementGauche(plateau);
    }
    if (direction == KEY_DOWN) {
        return deplacementBas(plateau);
    }
    if (direction == KEY_RIGHT) {
        return deplacementDroite(plateau);
    }
    return plateau;
}

/** affiche un Plateau
 * @param p le Plateau
 **/
void dessine(Plateau p) {
    start_color();
    init_pair(2, 0 ,255 );
    init_pair(4, 0, 223);
    init_pair(8, 255, 216);
    init_pair(16, 255,215);
    init_pair(32, 255, 210);
    init_pair(64, 255, 52);
    init_pair(5, 251, 226);
    init_pair(3, 251, 220);
    init_pair(1, COLOR_WHITE, COLOR_GREEN);
    printw("\n.................................\n");
    for (auto i: p) {
        printw("|");
        for (int d: i) {
            string nb = to_string(d);
            if (d < 10) {
                if( d == 0){
                    printw("       ");
                    printw("|");
                }else{
                    attron(COLOR_PAIR(d));
                    printw("   ");
                    printw(nb.c_str());
                    printw("   ");
                    attroff(COLOR_PAIR(d));
                    printw("|");
                }
            }
            if (d >= 10 and d < 100) {
                attron(COLOR_PAIR(d));
                printw("  ");
                printw(nb.c_str());
                printw("   ");
                attroff(COLOR_PAIR(d));
                printw("|");
            }
            if (d >= 100 and d < 1000) {
                attron(COLOR_PAIR(5));
                printw("  ");
                printw(nb.c_str());
                printw("  ");
                attroff(COLOR_PAIR(5));
                printw("|");
            }
            if (d >= 1000 and d < 10000) {
                attron(COLOR_PAIR(3));
                printw(" ");
                printw(nb.c_str());
                printw("  ");
                attroff(COLOR_PAIR(3));
                printw("|");
            }
            if (d >= 10000) {
                attron(COLOR_PAIR(1));
                printw(" ");
                printw(nb.c_str());
                printw(" ");
                attroff(COLOR_PAIR(1));
                printw("|");
            }
        }
        printw("\n.................................\n");

    }

}

/**string dessine(Plateau p){
    ostringstream flux;
    int plusgrand = 0;
    for(auto i:p){
        for(auto d:i){
            if(d >= plusgrand){
                plusgrand = d;
            }
        }
    }
    string nb = to_string(plusgrand);
    int longueur = nb.size();
    string chaine;
    for(int i = 0; i< 17+4*(longueur-1);i++){
        flux<<"*";
    }
    flux<<endl;
    chaine = flux.str();
    for(auto i:p){
        flux<<"* ";
        for(auto d:i){
            flux<< setw(longueur) << d<< " * ";
        }
        flux<<endl<<chaine;
    }
    string s = flux.str();
    return s;


}**/

/** permet de savoir si une partie est terminée
 *  @param plateau un Plateau
 *  @return true si le plateau est vide, false sinon
 **/
bool estTermine(Plateau plateau) {
    for (int k = 0; k < 4; k++) {
        for (int i = 0; i < 4; i++) {
            if (plateau[k][i] == 0) {
                return false;
            }
        }
    }
    if (plateau == deplacementBas(plateau) and plateau == deplacementGauche(plateau)
        and plateau == deplacementDroite(plateau) and plateau == deplacementHaut(plateau)) {
        return true;
    }
    return false;
}

/** permet de savoir si une partie est gagnée
 * @param plateau un Plateau
 * @return true si le plateau contient un 2048, false sinon
 **/
bool estGagnant(Plateau plateau) {
    for (int k = 0; k < 4; k++) {
        for (int i = 0; i < 4; i++) {
            if (plateau[i][k] == 2048) {
                return true;
            }
        }
    }
    return false;
}


int score(Plateau plateauV) {
    int score = 0;
    int k = 0;
    for( auto i : plateauV){
        for( auto d : i){
            if(d > 2){
                k = log(d)/log(2);
                score += d*(k-1);

            }
        }
    }

    return score;
}

bool contientun0( Plateau plateau){
    int compteur = 0;
    for(auto i : plateau){
        for(auto d : i){
            if (d == 0){
                compteur++;
            }
        }
    }
    if(compteur == 1){
        return true;
    }else{
        return false;
    }
}