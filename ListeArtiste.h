#pragma once
#include "NoeudArtiste.h"
#include "Fonctions.h"


struct ListeArtiste
{
   // Pointeur vers le premier artiste.
   NoeudArtiste* ptrDebut;
   int iNbArtistes;

   // Constructeur par défaut.
   ListeArtiste();
   ~ListeArtiste();

   // Méthodes.
   void ajouter(Artiste NouvelArtiste);
   bool siDoublon(Artiste NouvelArtiste);
   void afficherListe();
   void attribuerIdentifiants();
};