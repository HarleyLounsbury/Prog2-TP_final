// But: Fichier principale pour un émulateur d'un lecteur de musique.
// Auteur: Harley Lounsbury
// Date: 16-04-2019

#include "LecteurMusique.h"
#include "ListeChanson.h"
#include "NoeudChanson.h"

using namespace std;

int main()
{
   setlocale(LC_ALL, "");

   // Pour que le pseudo-aléatoire soit basé sur l'heure du système actuelle.
   srand(time(NULL));

   // Créer une instance de la structure.
   LecteurMusique MonLecteur;

   // Partir note lecteur.
   MonLecteur.demarrerLecteur();

   system("pause");
   return 0;
}