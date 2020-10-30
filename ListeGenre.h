#pragma once
#include "Genre.h"
#include "NoeudGenre.h"
#include "Fonctions.h"

struct ListeGenre
{
   // Pointeur vers le premier artiste.
   NoeudGenre* ptrDebut;
   int iNbGenres;

   // Constructeur par d�faut.
   ListeGenre();
   ~ListeGenre();

   // M�thodes.
   void ajouter(Genre NouvelGenre);
   bool siDoublon(Genre NouvelGenre);
   void afficherListe();
   void attribuerIdentifiants();
};