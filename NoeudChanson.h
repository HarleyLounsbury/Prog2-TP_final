#pragma once

#include "Chanson.h"

struct NoeudChanson
{
   // Donn�es.
   Chanson UnChanson;

   // Pointeurs.
   NoeudChanson* ptrPrecedent;
   NoeudChanson* ptrSuivant;

   // M�thodes
   NoeudChanson();
   ~NoeudChanson();
};