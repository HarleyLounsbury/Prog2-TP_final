// But : Créer une structure heure indépendante qui pourra être incluse dans n'importe quel projet
// Auteur : Harley Lounsbury
// Date : 22/03/2019


#pragma once

#include "Fonctions.h"

struct Heure
{
	// On doit déclarer les champs de la structure : c'est la partie données

	int iHeure;		// Un nombre compris entre 0 et 23
	int iMinute;	// Un nombre compris entre 0 et 59
	int iSeconde;	// Un nombre compris entre 0 et 59

	// On peut aussi déclarer des prototypes de fonctions  : partie méthode
	// Il existe 4 prototypes de fonctions définis AUTOMATIQUEMENT

	// On a déclaré explicitement les prototypes pour coder nous même le fonctionnement des constructeurs et du destructeur
	Heure();	// Le protoype du constructeur par défaut : il doit porter le nom de la structure
				// On le recode pour initialiser

	~Heure();	// Le prototype du destructeur : un destructeur commence toujours par ~ et est suivi du nom de la structure
				// Est exécuté quand le bloc d'instruction (dans lequel la variable est déclarée) se termine
				// est utilisé pour les variables dynamiques afin de libéérer la mémoire allouée avec un new à l'aide d'un delete

	Heure(const Heure& UneHeure);	// Le protype du constructeur par copie : contient un paramètre constant passé en référence 
									// Est utilisé quand on passe l,objet en paramétre, ou quand on déclare ET copie l'objet dans l'objet

	// Le quatrième est l'opérateur d'affectation = qui permet de faire TonHeure = MonHeure;

	void afficher(bool bAvecEndl);
	bool estValide(bool b24H);
	void demander(bool bAvecSeconde, bool b24H, const char* ptrDELIMITEUR);
	void demanderEtValider(bool bAvecSeconde, bool b24H, const char* ptrDELIMITEUR);
	int convertirEnMinutes();
   int convertirEnSecondes();

};







// Plus besoin
Heure demanderHeure(bool bAvecSeconde,bool b24H, const char* ptrDELIMITEUR);

// On n'a plus besoin de ca, l'objet est initialisé par le constructeur
Heure initialiserHeure();

// Cette fonction ne peut pas vivre sans l'objet, on va donc mettre dans la struct
void afficherHeure(Heure UneHeure, bool bAvecEndl);

// Plus besoin!
Heure demanderHeureValide(bool bAvecSeconde, bool b24H, const char* ptrDELIMITEUR);

// PLUS BESOIN
bool estValide(Heure UneHeure, bool b24H);


