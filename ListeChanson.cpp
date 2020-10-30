#include "ListeChanson.h"

ListeChanson::ListeChanson()
{
   ptrDebut = nullptr;
   ptrFin = nullptr;
}

ListeChanson::~ListeChanson()
{   
}

void ListeChanson::ajouter(NoeudChanson* ptrChanson)
{
   NoeudChanson* ptrParcours = ptrDebut;
   NoeudChanson* ptrTemp = nullptr;

   if (!ptrDebut)
   {
      ptrDebut = ptrChanson;
   }
   else
      // La liste n'est pas vide, on insère le nouveau noeud à la fin de la liste.
   {
      // On doit se rendre sur le dernier noeud de la liste.
      while (ptrParcours->ptrSuivant)
      {
         ptrTemp = ptrParcours;
         ptrParcours = ptrParcours->ptrSuivant;
      }
      // Ici, on est rendu sur le dernier noeud. 
      ptrParcours->ptrPrecedent = ptrTemp;
      ptrParcours->ptrSuivant = ptrChanson;
      ptrParcours->ptrSuivant->ptrPrecedent = ptrParcours;
      ptrFin = ptrParcours->ptrSuivant;
   }
   return;
}

void ListeChanson::attribuerIdentifiantsGenres(int iNbChansons, ListeGenre &UneListeGenres)
{
   NoeudChanson* ptrParcoursChansons = ptrDebut;
   NoeudGenre* ptrParcoursGenre = nullptr;

   for (int i = 0; i < iNbChansons; i++)
   {
      ptrParcoursGenre = UneListeGenres.ptrDebut;
      for (int j = 0; j < UneListeGenres.iNbGenres; j++)
      {
         if (strcmp(ptrParcoursChansons->UnChanson.UnGenre.ptrNomGenre, ptrParcoursGenre->UnGenre.ptrNomGenre) == 0)
         {
            ptrParcoursChansons->UnChanson.UnGenre.iIdentifiant = ptrParcoursGenre->UnGenre.iIdentifiant;
            j = UneListeGenres.iNbGenres;
         }
         ptrParcoursGenre = ptrParcoursGenre->ptrSuivant;
      }
      ptrParcoursChansons = ptrParcoursChansons->ptrSuivant;
   }

   return;
}

void ListeChanson::attribuerIdentifiantsArtistes(int iNbChansons, ListeArtiste & UneListeArtiste)
{
   NoeudChanson* ptrParcoursChansons = ptrDebut;
   NoeudArtiste* ptrParcoursArtiste = nullptr;

   for (int i = 0; i < iNbChansons; i++)
   {
      ptrParcoursArtiste = UneListeArtiste.ptrDebut;
      for (int j = 0; j < UneListeArtiste.iNbArtistes; j++)
      {
         if (strcmp(ptrParcoursChansons->UnChanson.UnArtiste.ptrNomArtiste, ptrParcoursArtiste->UnArtiste.ptrNomArtiste) == 0)
         {
            ptrParcoursChansons->UnChanson.UnArtiste.iIdentifiant = ptrParcoursArtiste->UnArtiste.iIdentifiant;
            j = UneListeArtiste.iNbArtistes;
         }
         ptrParcoursArtiste = ptrParcoursArtiste->ptrSuivant;
      }
      ptrParcoursChansons = ptrParcoursChansons->ptrSuivant;
   }

   return;
}
