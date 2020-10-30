#pragma once

#include "Chanson.h"

struct NoeudChanson
{
   // Données.
   Chanson UnChanson;

   // Pointeurs.
   NoeudChanson* ptrPrecedent;
   NoeudChanson* ptrSuivant;

   // Méthodes
   NoeudChanson();
   ~NoeudChanson();
};