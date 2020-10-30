// But: Structure principale d'un lecteur de musique.
// Auteur: Harley Lounsbury
// Date: 16-04-2019

#pragma once

// Inclure les librairies nécessaires.
#include "Fonctions.h"
#include "ListeChanson.h"
#include "ListeArtiste.h"
#include "NoeudChanson.h"
#include <iostream>
#include <iomanip>
#include "windows.h"
#include <conio.h>
#include <Windows.h>
#include "ListeGenre.h"

using namespace std;

// Déclaration de constantes.
const int iMIN_MENU = 1;
const int iMAX_MENU = 4;

const int iCHOISIR_LISTE = 1;
const int iCHOISIR_MODE_ECOUTE = 2;
const int iECOUTER = 3;

// Même si iQUITTER et iMAX_MENU ont la même valeur, le fait d'avoir des noms distincts améliorera la lisibilité du code.
const int iQUITTER = 4;

const int iMODE_DEFAUT = 1;
const int iMODE_SELON_GENRE = 2;
const int iMODE_SELON_ARTISTE = 3;
const int iMODE_FAVORIS = 4;
const int iMODE_ALEATOIRE = 5;
const int iRETOUR = 6;

const char cFICHER_PAR_DEFAUT[] = "Liste de chansons.txt";
const char cFICHIER_DE_SORTIE[] = "Liste de chansons.lec";

#define KEY_LEFT  75
#define KEY_RIGHT 77

struct LecteurMusique
{
   // Variables de la structure.
   int iChoixMenu;
   char* ptrNomFichier;
   ifstream ifCanal;
   ofstream ofCanal;
   bool bPointLec;
   ListeChanson UneListe;
   ListeArtiste UneListeArtiste;
   ListeGenre UneListeGenres;
   NoeudChanson UnNoeud;
   int iNbChansons;
   int iModeEcoute;
   int iGenre;
   int iArtiste;

   // Constructeur par défaut.
   LecteurMusique();
   // Déstructeur.
   ~LecteurMusique();

   // Méthodes.
   void demarrerLecteur();

   void afficherMenu(int iLargeur);
   void afficherEnTete(int iLargeur);
   void afficherListeDeChoix();  
   void choisirListe();
   void importerListe();
   void choisirModeEcoute();
   void afficherEnTeteModeEcoute();
   void afficherMenuModeEcoute();
   void choisirGenre();
   void afficherEnTeteGenres();
   void choisirArtiste();
   void afficherEnTeteArtistes();
   void ecouterListe();
   void ecouterListeDefaut();
   void ecouterListeParGenre();
   void ecouterListeParArtiste();
   void ecouterListeParFavoris();
   void ecouterListeAleatoire();
   bool contientFavoris();
   void ecouterProchainFavori(NoeudChanson* &ptrParcours, int &iChoix);
   NoeudChanson* determinerProchainMoinsEcoute();
   void ecouterUneChansonAleatoire(int &iChoix);
   NoeudChanson* determinerPlusHautePriorite();
   void afficherNavigation();
   void ecouterChanson(NoeudChanson* ptrChanson, int & iChoix);
   void sauvegarderStatsEnLec();
   void ecrireDansFichier(ofstream& ofCanal);
   void afficherDetailsChanson(NoeudChanson* ptrChanson, int iTempsEcouleSecondes, int iTempsEcouleMinutes);
   
};