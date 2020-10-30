#pragma once

#include "Genre.h"
#include "Heure.h"
#include <fstream>
#include <iomanip>
#include "Fonctions.h"
#include "NoeudArtiste.h"
#include "NoeudGenre.h"

struct Chanson
{
   // Les donn�es d'une chanson.
   int iNumeroChanson;
   char* ptrNomChanson;
   Artiste UnArtiste;
   Genre UnGenre;
   Heure Duree;
   char* ptrNomAlbum;
   char* ptrAnnee;


   bool estFavori;
   int iNumeroPriorite;
   int iNombreEcoutes;

   // Constructeur par d�faut.
   Chanson();
   // D�structeur.
   ~Chanson();

   // M�thodes
   void afficher();
   void lireChanson(ifstream &ifCanal);
   // Surchargement de la fonction pour les fichiers .lec
   void lireChanson(ifstream &ifCanal, bool estFichierLec);
};