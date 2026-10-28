#include "jeu.h"

#include <vector>       //Conteneur vector et méthodes utiles
#include <queue>
#include <algorithm>    //Utilistaion de l'algo iter_swap

#include <random>       //Lib pour la génération de nombre aléatoire
#include <string>

#include <iostream>     //Lib d'affichage et d'écriture
#include <fstream>      //Lib pour les fichiers
#include <cassert>      //Lib pour les asserts

using namespace std;

int abs(int x){
    if(x < 0){return -x;}
    else{return x;}
}

void Jeu::affichage_grille(){
    cout << string(4 * taille + 1, '_') << endl;
    int compteur = 0;
    
    for (auto it = grille.begin(); it != grille.end(); it++) {
        if (compteur > 0 && compteur % taille == 0) {
            cout << "|" << endl;
            cout << string(4 * taille + 1, '_') << endl;
        }
        // Affichage de la valeur (si c'est -1, on peut afficher un espace pour faire plus propre)
        if (*it == -1) {
            cout << "|   ";
        } 
        else {
            cout << "| " << *it << " ";
        }
        compteur++;
    }
    cout << "|" << endl;
    cout << string(4 * taille + 1, '_') << endl;
};

Jeu::Jeu(int n) {
    taille = n;
    vide = n*n - 1; // Indice de la case vide (la dernière)
    
    // On redimensionne directement le vecteur membre 'grille'
    grille.resize(n*n);
    
    // On remplit les valeurs de 1 à n*n - 1, et -1 pour la dernière case
    for (int i = 0; i <n*n - 1; i++) {
        grille[i] = i + 1;
    }
    grille[n*n - 1] = -1; // La case vide à la fin
    this->melange();
}

//A chaque problème le code renvoie un Assert peut etre a modifier pour la communictaion avec l'interface graphique 
//Cas encore a traiter : Ligne vide au milieu, Plusieurs lignes vides pose problèmes, Exclure les grilles de plus grandes taille que 4
Jeu::Jeu(const char* file){
    //Ouverture du fichier et vérification de sa bonne ouverture
    ifstream fichier(file);
    assert(fichier.is_open());

    //Récupération de la première ligne (i.e la taille de la grille)
    string ligne;
    getline(fichier, ligne);
    taille = stoi(ligne);

    //Remplissage de la grille
    grille.resize(taille*taille);
    int i = 0;  //i correspond a la ligne et j a la colonne
    int compteur_x = 0;
    while (getline(fichier, ligne)) {
        //Suppression des lignes vides en trop
        if(ligne[0] == '\n'){
            break;
        }
        //Suppression des derniers caractères si c'est des " "
        while(ligne.back() == ' '){
            ligne.pop_back();
        }
        assert(taille*2-1==ligne.size()); //Vérifie que les lignes soit de bonne taille
        for(int j = 0;j<taille;j++){
            assert((taille*i + j) < taille*taille); //Si cette assert est déclencher alors il y a plus que n^2 -1 éléments
            if(ligne[2*j] == 'x'){      //Le fois 2 permet de sauter les espaces
                grille[taille*i + j] = -1;
                vide = i + j;
                //Gestion des plusieurs x
                compteur_x++;
                assert(compteur_x<=1);
            }
            else{
                grille[taille*i + j] = ligne[2*j] - '0';
            }
        }
        i++;
    }
    if(!resoluble()){
        cout << "Grille non résoluble" << endl;
    }
}

Jeu::~Jeu(){};

vector<int>::iterator Jeu::pos(int k){
    assert((k < taille*taille) && (k>=-1));
    for(auto it = grille.begin(); it != grille.end(); it++){
        if(*it == k){
            return it;
        }
    }
    return grille.end();
};

int Jeu::indice(int k){
    assert((k < taille*taille) && (k>=-1));
    int compteur = 0;
    for(auto it = grille.begin(); it != grille.end(); it++){
        if(*it == k){
            return compteur;
        }
        compteur++;
    }
    return -1;
}

bool Jeu::deplacement(int k){
    if((k >= taille*taille) || (k<0)){return false;}
    else{
        // Gestion des positions dans la grille et dans le vector
        int ligne_vide = indice(-1) / taille;   //Attention peut etre probleme a ce niveau la genre indice = a 0 *********A VERIF************
        int colonne_vide = indice(-1) % taille;
        int ligne_k = indice(k) / taille;
        int colonne_k = indice(k) % taille;
        //Calcul de la distance entre l'element k et l'element vide pour savoir s'il sont échangeable
        int distance = abs(ligne_vide - ligne_k) + abs(colonne_vide - colonne_k);
        if(distance == 1){
            auto it_k = pos(k);
            auto it_vide = pos(-1);
            iter_swap(it_k,it_vide);
            return true;
        }
        else{
            return false;
        }
    }
};

//Methode utiliser uniquement lors de la création d'une grille de base
//Peut etre utilie de traduire plutot en fonction (Jeu game,int l) 
void Jeu::melange(int l){
    //Initialisation d'un générateur aléatoire qui donne un nombre de la grille
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> distrib(1,taille*taille - 1);

    for(int i = 0; i < l; i++){
        int k = distrib(gen);
        while(!deplacement(k)){
            k = distrib(gen);
        }
    }
}

//Methode utiliser uniquement lors de la création d'une grille a partir d'un fichier
//Peut etre utilie de traduire plutot en fonction (vector<int> grille,int taille) 
bool Jeu::resoluble(){
    //Calcul de la taille de I, l'ensemble des inversions
    int taille_I = 0;;
    for(int i = 0;i<taille*taille - 1;i++){
        if(grille[i] != -1){    //On exclue -1
            for(int j = i + 1;j<taille*taille;j++){
                if(grille[j] == -1){continue;} //On exclue -1
                if(grille[i] > grille[j]){
                    taille_I++;
                }
            }
        }        
    }
    //Condition en fonction de la taille de la grille
    if(taille == 3){
        return ((taille_I % 2) == 0);
    }
    else if(taille == 4){
        int r = (taille - indice(-1) / taille) + 1;
        return (((r + taille_I) % 2) == 1);
    }
    else{
        return false;
    }
}

int Jeu::heuristique(){
    int sum = 0;
    for(int i = 0;i<taille*taille;i++){
        if(grille[i] != -1){
            sum += abs((indice(grille[i]) / taille) - ((grille[i] - 1) / taille)) + abs((indice(grille[i]) % taille) - ((grille[i] - 1) % taille));
        }
    }
    return sum;
}

void Jeu::solver(){
    priority_queue<int, vector<int>, greater<int>> f;
    
    
}