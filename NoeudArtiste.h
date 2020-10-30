#pragma once

#include "Artiste.h"

struct NoeudArtiste
{
   // Données.
   Artiste UnArtiste;

   // Pointeurs.
   NoeudArtiste* ptrSuivant;

   NoeudArtiste();
   ~NoeudArtiste();
};