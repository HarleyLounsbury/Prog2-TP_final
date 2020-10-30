// But: Fonctions pour usage générale.
// Auteur: Harley Lounsbury
// Date: 16-04-2019

#pragma once

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

void ligneDeTirets(int iLargeur);
int lireNombre();
bool ouvrirFichierEnLecture(const char cFICHIER[], ifstream & ifCanal);
char * demanderChaine(const int iMAX_CAR, const char * ptrINVITE);
bool validerEntier(int iEntier, int iMin, int iMax);
void initialiserTableauChar(char* ptrTab, const int iMAX_TAB);
void copierChar(char* ptrDest, char* ptrSource);
int retourneNbChar(char* ptrTab);
bool siExtension(char* ptrFichier);
void creerFichier(ofstream& ofFichier, char* ptrNomFichier);
void creerFichier(ofstream& ofFichier, const char cFICHIER[]);
int retourneAleatoire(int iMin, int iMax);
int retourneChoixMenu(const int iMIN, const int iMAX);