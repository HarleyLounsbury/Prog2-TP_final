#pragma once
#include "NoeudArtiste.h"
#include "Fonctions.h"


struct ListeArtiste
{
   // Pointeur vers le premier artiste.
   NoeudArtiste* ptrDebut;
   int iNbArtistes;

   // Constructeur par d�faut.
   ListeArtiste();
   ~ListeArtiste();

   // M�thodes.
   void ajouter(Artiste NouvelArtiste);
   bool siDoublon(Artiste NouvelArtiste);
   void afficherListe();
   void attribuerIdentifiants();
};