// But: Fichier principale pour un �mulateur d'un lecteur de musique.
// Auteur: Harley Lounsbury
// Date: 16-04-2019

#include "LecteurMusique.h"
#include "ListeChanson.h"
#include "NoeudChanson.h"

using namespace std;

int main()
{
   setlocale(LC_ALL, "");

   // Pour que le pseudo-al�atoire soit bas� sur l'heure du syst�me actuelle.
   srand(time(NULL));

   // Cr�er une instance de la structure.
   LecteurMusique MonLecteur;

   // Partir note lecteur.
   MonLecteur.demarrerLecteur();

   system("pause");
   return 0;
}