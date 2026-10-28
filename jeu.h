#include <vector>


class Jeu{
    private :
        std::vector<int> grille;     //Grille de jeu
        int taille;             //Taille de la grille
        int vide;               //Position dans le vector de la case vide
    public :
        Jeu(int n);             //Créer une grille de jeu mélanger
        Jeu(const char* file);  //Cr
        ~Jeu();
        std::vector<int>::iterator pos(int k);   //Renvoie l'itérateur associé a l'élément k
        int indice(int k);                  //Renvoie l'indice de l'élément k dans le vector
        bool deplacement(int k);    //Renvoie vrai si l'échange entre l'élément k et la case vide a pu avoir lieu, faux sinon
        void melange(int l = 500);                     //Deplace l fois les cases pour avoir une grille aléatoire
        void affichage_grille();        //Affiche la grille
        bool resoluble();
        int heuristique();
        void solver();
};