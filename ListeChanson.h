#pragma once

#include <iostream>
#include <fstream>
#include "NoeudChanson.h"
#include "ListeGenre.h"
#include "ListeArtiste.h"

using namespace std;

struct ListeChanson
{
   // Pointeur vers la première chanson.
   NoeudChanson* ptrDebut;
   NoeudChanson* ptrFin;

   // Constructeur par défaut.
   ListeChanson();
   ~ListeChanson();

   // Méthodes.
   void ajouter(NoeudChanson* ptrChanson);
   void attribuerIdentifiantsGenres(int iNbChansons, ListeGenre &UneListeGenres);
   void attribuerIdentifiantsArtistes(int iNbChansons, ListeArtiste &UneListeArtiste);
};