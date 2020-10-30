// But : Cr�er une structure heure ind�pendante qui pourra �tre incluse dans n'importe quel projet
// Auteur : Harley Lounsbury
// Date : 22/03/2019


#pragma once

#include "Fonctions.h"

struct Heure
{
	// On doit d�clarer les champs de la structure : c'est la partie donn�es

	int iHeure;		// Un nombre compris entre 0 et 23
	int iMinute;	// Un nombre compris entre 0 et 59
	int iSeconde;	// Un nombre compris entre 0 et 59

	// On peut aussi d�clarer des prototypes de fonctions  : partie m�thode
	// Il existe 4 prototypes de fonctions d�finis AUTOMATIQUEMENT

	// On a d�clar� explicitement les prototypes pour coder nous m�me le fonctionnement des constructeurs et du destructeur
	Heure();	// Le protoype du constructeur par d�faut : il doit porter le nom de la structure
				// On le recode pour initialiser

	~Heure();	// Le prototype du destructeur : un destructeur commence toujours par ~ et est suivi du nom de la structure
				// Est ex�cut� quand le bloc d'instruction (dans lequel la variable est d�clar�e) se termine
				// est utilis� pour les variables dynamiques afin de lib��rer la m�moire allou�e avec un new � l'aide d'un delete

	Heure(const Heure& UneHeure);	// Le protype du constructeur par copie : contient un param�tre constant pass� en r�f�rence 
									// Est utilis� quand on passe l,objet en param�tre, ou quand on d�clare ET copie l'objet dans l'objet

	// Le quatri�me est l'op�rateur d'affectation = qui permet de faire TonHeure = MonHeure;

	void afficher(bool bAvecEndl);
	bool estValide(bool b24H);
	void demander(bool bAvecSeconde, bool b24H, const char* ptrDELIMITEUR);
	void demanderEtValider(bool bAvecSeconde, bool b24H, const char* ptrDELIMITEUR);
	int convertirEnMinutes();
   int convertirEnSecondes();

};







// Plus besoin
Heure demanderHeure(bool bAvecSeconde,bool b24H, const char* ptrDELIMITEUR);

// On n'a plus besoin de ca, l'objet est initialis� par le constructeur
Heure initialiserHeure();

// Cette fonction ne peut pas vivre sans l'objet, on va donc mettre dans la struct
void afficherHeure(Heure UneHeure, bool bAvecEndl);

// Plus besoin!
Heure demanderHeureValide(bool bAvecSeconde, bool b24H, const char* ptrDELIMITEUR);

// PLUS BESOIN
bool estValide(Heure UneHeure, bool b24H);


