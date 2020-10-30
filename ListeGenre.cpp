#include "ListeGenre.h"

ListeGenre::ListeGenre()
{
   ptrDebut = nullptr;
   iNbGenres = 0;
}

ListeGenre::~ListeGenre()
{
   NoeudGenre* ptrParcours = ptrDebut;
   NoeudGenre* ptrTemp = nullptr;

   // On doit libèrer la mémoire de chaque noeud.
   if (ptrParcours)
   {
      if (ptrParcours->ptrSuivant)
         ptrTemp = ptrParcours->ptrSuivant;
      delete ptrParcours;
      
      ptrParcours = ptrTemp;
      ptrTemp = ptrTemp->ptrSuivant;

      while (ptrParcours->ptrSuivant)
      {
         delete ptrParcours;
         ptrParcours = ptrTemp;
         ptrTemp = ptrTemp->ptrSuivant;
      }
   }
}

void ListeGenre::ajouter(Genre NouvelGenre)
{
   NoeudGenre* ptrNouveau = new NoeudGenre;
   ptrNouveau->UnGenre = NouvelGenre;
   NoeudGenre* ptrParcours = ptrDebut;
   NoeudGenre* ptrPrecedent = nullptr;

   // Le cas oû la liste est vide ou quand on veut insérer au début.
   if (!ptrDebut || strcmp(ptrDebut->UnGenre.ptrNomGenre, ptrNouveau->UnGenre.ptrNomGenre) > 0)
   {
      ptrNouveau->ptrSuivant = ptrDebut;
      ptrDebut = ptrNouveau;
   }
   else
   {
      while (ptrParcours && strcmp(ptrParcours->UnGenre.ptrNomGenre, ptrNouveau->UnGenre.ptrNomGenre) < 0)
      {
         ptrPrecedent = ptrParcours;
         ptrParcours = ptrParcours->ptrSuivant;
      }
      ptrNouveau->ptrSuivant = ptrParcours;
      ptrPrecedent->ptrSuivant = ptrNouveau;


   }
   iNbGenres++;
   return;
}

bool ListeGenre::siDoublon(Genre NouvelGenre)
{
   NoeudGenre* ptrParcours;
   if (!ptrDebut)
   {
      return false;
   }
   else
   {
      ptrParcours = ptrDebut;
      for (int i = 1; i <= iNbGenres; i++)
      {
         if (strcmp(ptrParcours->UnGenre.ptrNomGenre, NouvelGenre.ptrNomGenre) == 0)
         {
            return true;
         }
         if (ptrParcours->ptrSuivant)
         {
            ptrParcours = ptrParcours->ptrSuivant;
         }
      }
   }
   return false;
}

void ListeGenre::afficherListe()
{
   NoeudGenre* ptrParcours;
   if (!ptrDebut)
   {
      cout << "La liste est vide." << endl;
      system("pause");
   }
   else
   {
      ptrParcours = ptrDebut;
      for (int i = 1; i <= iNbGenres; i++)
      {
         cout << right << setw(4) << i << ". " << ptrParcours->UnGenre.ptrNomGenre << endl;
         if (ptrParcours->ptrSuivant)
         {
            ptrParcours = ptrParcours->ptrSuivant;
         }
      }
   }
   
   return;
}

void ListeGenre::attribuerIdentifiants()
{
   NoeudGenre* ptrParcours;
   if (!ptrDebut)
   {
      cout << "Erreur en attribuant les identifiants aux genres." << endl;
      system("pause");
   }
   else
   {
      ptrParcours = ptrDebut;
      for (int i = 1; i <= iNbGenres; i++)
      {
         ptrParcours->UnGenre.iIdentifiant = i;
         if (ptrParcours->ptrSuivant)
         {
            ptrParcours = ptrParcours->ptrSuivant;
         }
      }
   }

   return;
}
