#pragma once

#include "Artiste.h"

struct NoeudArtiste
{
   // Donn�es.
   Artiste UnArtiste;

   // Pointeurs.
   NoeudArtiste* ptrSuivant;

   NoeudArtiste();
   ~NoeudArtiste();
};