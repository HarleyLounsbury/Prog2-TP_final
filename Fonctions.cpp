// But: Fonctions pour usage g�n�rale.
// Auteur: Harley Lounsbury
// Date: 16-04-2019

#include "Fonctions.h"

void ligneDeTirets(int iLargeur)
{
   // Ligne de tirets.
   cout << setw(iLargeur) << setfill('-') << "-" << setfill(' ') << endl;

   return;
}

int lireNombre()
{
   // Pour lire toutes les b�tises que pourrait taper l'utilisateur, on se cr�e une variable de type cha�ne de caract�res
   // suffisamment longue.
   const int iMAXCLAVIER = 8190;
   char cClavier[iMAXCLAVIER + 1];
   int iNb;

   cin.getline(cClavier, sizeof(cClavier), '\n');

   // On lit toute ce que l'utilisateur tape au clavier dans une cha�ne de caract�res
   // qui accepte n'importe quel caract�re.

   // atof permet de convertir la cha�ne en valeur num�rique de type double
   // MAIS: elle retourne 0 si elle ne peut pas faire la convertion.

   // il faut s'assurer que cClavier commence par un chiffre sinon on redemande � l'utilisateur

   while (!((cClavier[0] >= '0' && cClavier[0] <= '9') || (cClavier[0] == '-' && (cClavier[1] >= '0' && cClavier[1] <= '9'))))
   {
      cout << "Erreur: Vous devez entrer un nombre: ";
      cin.getline(cClavier, sizeof(cClavier), '\n');
   }

   // Convertir la cha�ne de caract�res en entier.
   iNb = atoi(cClavier);

   return iNb;
}

bool ouvrirFichierEnLecture(const char cFICHIER[], ifstream & ifCanal)
{
   // Ouvrir le fichier, c'est � dire associer au canal le fichier sur le disque dur. 
   ifCanal.open(cFICHIER, ios::in);

   // Cela ne se passe pas toujours bien. Il faut tester le succ�s de la commande open.
   if (!ifCanal)
   {
      cerr << "Erreur: le fichier " << cFICHIER << " n'a pas pu �tre ouvert correctement." << endl;
      system("pause");
      return false;
   }

   return true;
}

// AVIS:
// Cette fonction contient une allocation de m�moire dynamique. 
// L'utilisation de cette fonction n�cessite la d�sallocation. 
// � utiliser � vos risques et p�rils.
char * demanderChaine(const int iMAX_CAR, const char * ptrINVITE)
{
   const int iMAX_CLAVIER = 8190;
   char cClavier[iMAX_CLAVIER + 1];
   char* ptrChaine = nullptr;

   cout << ptrINVITE;
   cin.getline(cClavier, iMAX_CLAVIER + 1, '\n');

   while (strlen(cClavier) > iMAX_CAR)
   {
      cerr << "Erreur: Vous avez un maximum de " << iMAX_CAR << " caract�res." << endl;
      cout << ptrINVITE;
      cin.getline(cClavier, iMAX_CLAVIER + 1, '\n');
   }

   // Dans cClavier, on a la cha�ne de la bonne longeur.
   // On alloue la m�moire de la bonne taille -> strlen+1

   // IMPORTANT:
   // Quand on utilise cette fonction, n'oublie pas de lib�rer la m�moire (delete[])
   ptrChaine = new char[strlen(cClavier) + 1];
   if (ptrChaine == nullptr)
   {
      cerr << "M�moire insuffisant. Goodbye." << endl;
      system("pause");
      abort();
   }

   // On doit copier le contenu de cClavier dans ptrChaine.
   strcpy_s(ptrChaine, strlen(cClavier) + 1, cClavier);

   return ptrChaine;
}

bool validerEntier(int iEntier, int iMin, int iMax)
{
   // Valider si l'entier est entrer le bornes mises en param�tre.
   return iEntier >= iMin && iEntier <= iMax;
}

void initialiserTableauChar(char * ptrTab, const int iMAX_TAB)
{
   // Le nom de la fonction dit tout.
   for (int i = 0; i < iMAX_TAB; i++)
   {
      *(ptrTab + i) = '\0';
   }

   return;
}

void copierChar(char * ptrDest, char * ptrSource)
{
   // Fonction similaire � strcpy_s().
   int iCompteur = 0;
   for (int i = 0; i < strlen(ptrSource); i++)
   {
      *(ptrDest + i) = *(ptrSource + i);
      iCompteur++;
   }
   *(ptrDest + iCompteur) = '\0';

   return;
}

int retourneNbChar(char * ptrTab)
{
   // Fonction similaire � strlen().
   int iCompteur = 0;
   for (int i = 0; i < strlen(ptrTab); i++)
   {
      if (*(ptrTab + i) != '\0')
         iCompteur++;
   }

   return iCompteur;
}

bool siExtension(char * ptrFichier)
{
   // Fonction pour v�rifier si un nom de ficheir entr� par l'utilisateur comprend une extension.
   // Cette fonction n'est pas infaillible, car si le nom du ficheir contient un point, on va penser que c'est une s�parateur pour une extension. 
   for (int i = 0; i < strlen(ptrFichier); i++)
   {
      if (*(ptrFichier + i) == '.')
         return true;
   }
   return false;
}

void creerFichier(ofstream& ofFichier, char* ptrNomFichier)
{
   // Cr�er un fichier avec pointeur comme param�tre.
   ofFichier.open(ptrNomFichier, ios::out);
   if (!ofFichier)
   {
      cerr << "Erreur : Le fichier " << ptrNomFichier << " n'a pas pu se cr�er" << endl;
      system("pause");
      exit(2);
   }
}

void creerFichier(ofstream & ofFichier, const char cFICHIER[])
{
   // Ouvrir un fichier avec tableau de char comme param�tre.
   ofFichier.open(cFICHIER, ios::out);
   if (!ofFichier)
   {
      cerr << "Erreur : Le fichier " << cFICHIER << " n'a pas pu se cr�er" << endl;
      system("pause");
      exit(2);
   }
}

int retourneAleatoire(int iMin, int iMax)
{
   // Fonction qui retourne un nombre al�atoire entre les bornes mises en param�tre.
   return rand() % (iMax - iMin + 1) + iMin;
}

int retourneChoixMenu(const int iMIN, const int iMAX)
{
   // Fonction qui peut �tre utilis� dans n'importe quel menu qui va valider le choix le de l'utilisateur.
   int iChoix;
   cout << "Votre choix -->";
   iChoix = lireNombre();

   while (iChoix < iMIN || iChoix > iMAX)
   {
      cout << "Erreur: votre choix doit �tre compris entre " << iMIN << " et " << iMAX << ". " << endl;
      cout << "Votre choix -->";
      iChoix = lireNombre();
   }

   return iChoix;
}

