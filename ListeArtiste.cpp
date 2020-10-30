#include "ListeArtiste.h"

ListeArtiste::ListeArtiste()
{
   ptrDebut = nullptr;
   iNbArtistes = 0;
}

ListeArtiste::~ListeArtiste()
{
   NoeudArtiste* ptrParcours = ptrDebut;

   // On doit libèrer la mémoire de chaque noeud.
   if (ptrParcours)
   {
      NoeudArtiste* ptrTemp = ptrParcours->ptrSuivant;
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

void ListeArtiste::ajouter(Artiste NouvelArtiste)
{
   NoeudArtiste* ptrNouveau = new NoeudArtiste;
   ptrNouveau->UnArtiste = NouvelArtiste;
   NoeudArtiste* ptrParcours = ptrDebut;
   NoeudArtiste* ptrPrecedent = nullptr;

   // Le cas oû la liste est vide ou quand on veut insérer au début.
   if (!ptrDebut || strcmp(ptrDebut->UnArtiste.ptrNomArtiste, ptrNouveau->UnArtiste.ptrNomArtiste) > 0)
   {
      ptrNouveau->ptrSuivant = ptrDebut;
      ptrDebut = ptrNouveau;
   }
   else
   {
      while (ptrParcours && strcmp(ptrParcours->UnArtiste.ptrNomArtiste, ptrNouveau->UnArtiste.ptrNomArtiste) < 0)
      {
         ptrPrecedent = ptrParcours;
         ptrParcours = ptrParcours->ptrSuivant;
      }
      ptrNouveau->ptrSuivant = ptrParcours;
      ptrPrecedent->ptrSuivant = ptrNouveau;
      
   }
   iNbArtistes++;
   return;
}

bool ListeArtiste::siDoublon(Artiste NouvelArtiste)
{
   NoeudArtiste* ptrParcours;
   if (!ptrDebut)
   {
      return false;
   }
   else
   {
      ptrParcours = ptrDebut;
      for (int i = 1; i <= iNbArtistes; i++)
      {
         if (strcmp(ptrParcours->UnArtiste.ptrNomArtiste, NouvelArtiste.ptrNomArtiste) == 0)
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

void ListeArtiste::afficherListe()
{
   NoeudArtiste* ptrParcours;
   if (!ptrDebut)
   {
      cout << "La liste est vide." << endl;
      system("pause");
   }
   else
   {
      ptrParcours = ptrDebut;
      for (int i = 1; i <= iNbArtistes; i++)
      {
         cout << right << setw(4) << i << ". " << ptrParcours->UnArtiste.ptrNomArtiste << endl;
         if (ptrParcours->ptrSuivant)
         {
            ptrParcours = ptrParcours->ptrSuivant;
         }
      }
   }
   
   return;
}

void ListeArtiste::attribuerIdentifiants()
{
   NoeudArtiste* ptrParcours;
   if (!ptrDebut)
   {
      cout << "Erreur en attribuant les identifiants aux artistes." << endl;
      system("pause");
   }
   else
   {
      ptrParcours = ptrDebut;
      for (int i = 1; i <= iNbArtistes; i++)
      {
         ptrParcours->UnArtiste.iIdentifiant = i;
         if (ptrParcours->ptrSuivant)
         {
            ptrParcours = ptrParcours->ptrSuivant;
         }
      }
   }
   
   return;
}
