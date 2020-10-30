#pragma once

#include "Genre.h"

struct NoeudGenre
{
   Genre UnGenre;

   NoeudGenre* ptrSuivant;
   NoeudGenre* ptrPrecedent;

   NoeudGenre();

};