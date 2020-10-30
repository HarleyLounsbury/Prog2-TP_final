#pragma once

#include <iostream>
#include <fstream>
#include "NoeudChanson.h"
#include "ListeGenre.h"
#include "ListeArtiste.h"

using namespace std;

struct ListeChanson
{
   // Pointeur vers la premi�re chanson.
   NoeudChanson* ptrDebut;
   NoeudChanson* ptrFin;

   // Constructeur par d�faut.
   ListeChanson();
   ~ListeChanson();

   // M�thodes.
   void ajouter(NoeudChanson* ptrChanson);
   void attribuerIdentifiantsGenres(int iNbChansons, ListeGenre &UneListeGenres);
   void attribuerIdentifiantsArtistes(int iNbChansons, ListeArtiste &UneListeArtiste);
};