// But : Fonctions
// Auteur : Harley Lounsbury
// Date : 22/03/2019

#include "Heure.h"

Heure demanderHeure(bool bAvecSeconde, bool b24H, const char * ptrDELIMITEUR)
{

	const int iMAX_CLAVIER = 8190;
	char cClavier[iMAX_CLAVIER + 1];
	char* ptrParcours;
	char* ptrSuivant;

	Heure UneHeure;
	UneHeure = initialiserHeure();

	cout << "Veuillez entrer l'heure au format de hh:mm" << (bAvecSeconde? ":ss ":" ") << (!b24H? "AM/PM  : " : " : ");
	cin.getline(cClavier, iMAX_CLAVIER + 1, '\n');

	// On va découper cClavier en heure, minute et seconde si nécessaire
	// On utilise strtok_s qui a besoin de deux pointeurs
	// À la première utilisation de strtok, on lui indique la chaine à découper
	// Ensuite on utilise les deux pointeurs pour les autres extractions

	// On ne peut découper la chaine que si elle n'est pas vide
	if (strlen(cClavier))
	{
		ptrParcours = strtok_s(cClavier, ptrDELIMITEUR, &ptrSuivant);
		UneHeure.iHeure = atoi(ptrParcours);
		// On connait l'heure il faut la valider
		
		// On continue de découper si le reste de la chaine n'est pas vide
		if (strlen(ptrSuivant))
		{
			ptrParcours = strtok_s(NULL, ptrDELIMITEUR, &ptrSuivant);
			UneHeure.iMinute = atoi(ptrParcours);
		}
		// Il reste les secondes
		UneHeure.iSeconde = atoi(ptrSuivant);

	}

	return UneHeure;
}

Heure initialiserHeure()
{
	Heure UneHeure;

	UneHeure.iHeure = 0;
	UneHeure.iMinute = 0;
	UneHeure.iSeconde = 0;

	return UneHeure;
}

void afficherHeure(Heure UneHeure, bool bAvecEndl)
{
	// On s'assure que l'alignement est à droite et on complète avec des 0 non significatifs
	cout << setfill('0') << right;
	cout << setw(2) << UneHeure.iHeure << ":"  << setw(2) << UneHeure.iMinute << ":" << setw(2) << UneHeure.iSeconde;
	cout << setfill(' ');
	cout << (bAvecEndl ? "\n" : "");

   return;
}

Heure demanderHeureValide(bool bAvecSeconde, bool b24H, const char * ptrDELIMITEUR)
{
	Heure UneHeure;
	UneHeure = demanderHeure(bAvecSeconde, b24H, ptrDELIMITEUR);

	//while (!(estValide(UneHeure, b24H)))
	while (!(UneHeure.estValide(b24H)))

	{
		cerr << "Erreur : L'heure n'est pas valide." << endl;
		system("pause");
		UneHeure = demanderHeure(bAvecSeconde, b24H, ptrDELIMITEUR);
	}

	// L'heure est valide il faut la retourner
	return UneHeure;
}

bool estValide(Heure UneHeure, bool b24H)
{
	return validerEntier(UneHeure.iHeure, (b24H ? 0 : 1), (b24H ? 23 : 12)) && validerEntier(UneHeure.iMinute, 0, 59) && validerEntier(UneHeure.iSeconde, 0, 59);
}


// Pour indiquer qu'une fonction est membre d'une structure, on doit utiliser l'opérateur de résolution de portée  :: précédé du nom de la structure
// Du coup, on a accès à tous les champs de la structure
// Le constructeur par défaut est appelé à chaque déclaration d'une variable de type Heure
// Donc, on pourrait l'utiliser pour s'assurer que les champs de la structure soient tous initialisés
Heure::Heure()
{
	//cout << "Constructeur par défaut" << endl;
	//system("pause");
	iHeure = 0;
	iMinute = 0;
	iSeconde = 0;
}

Heure::~Heure()
{
   // cout << "Destructeur de heure" << endl;
}

Heure::Heure(const Heure & UneHeure)
{
	//cout << "Constructeur par copie" << endl;
	//system("pause");
	iHeure = UneHeure.iHeure;
	iMinute = UneHeure.iMinute;
	iSeconde = UneHeure.iSeconde;
}

void Heure::afficher(bool bAvecEndl)
{
	// On s'assure que l'alignement est à droite et on complète avec des 0 non significatifs
	cout << setfill('0') << right;
	cout << setw(2) << iHeure << ":" << setw(2) << iMinute << ":" << setw(2) << iSeconde;
	cout << setfill(' ');
	cout << (bAvecEndl ? "\n" : "");
}

bool Heure::estValide(bool b24H)
{
	return validerEntier(iHeure, (b24H ? 0 : 1), (b24H ? 23 : 12)) && validerEntier(iMinute, 0, 59) && validerEntier(iSeconde, 0, 59);
}

void Heure::demander(bool bAvecSeconde, bool b24H, const char * ptrDELIMITEUR)
{
	const int iMAX_CLAVIER = 8190;
	char cClavier[iMAX_CLAVIER + 1];
	char* ptrParcours;
	char* ptrSuivant;

	cout << "Veuillez entrer l'heure au format de hh:mm" << (bAvecSeconde ? ":ss " : " ") << (!b24H ? "AM/PM  : " : " : ");
	cin.getline(cClavier, iMAX_CLAVIER + 1, '\n');

	// On va découper cClavier en heure, minute et seconde si nécessaire
	// On utilise strtok_s qui a besoin de deux pointeurs
	// À la première utilisation de strtok, on lui indique la chaine à découper
	// Ensuite on utilise les deux pointeurs pour les autres extractions

	// On ne peut découper la chaine que si elle n'est pas vide
	if (strlen(cClavier))
	{
		ptrParcours = strtok_s(cClavier, ptrDELIMITEUR, &ptrSuivant);
		iHeure = atoi(ptrParcours);
		// On connait l'heure il faut la valider

		// On continue de découper si le reste de la chaine n'est pas vide
		if (strlen(ptrSuivant))
		{
			ptrParcours = strtok_s(NULL, ptrDELIMITEUR, &ptrSuivant);
			iMinute = atoi(ptrParcours);
		}
		// Il reste les secondes
		iSeconde = atoi(ptrSuivant);
	}
	return;
}

void Heure::demanderEtValider(bool bAvecSeconde, bool b24H, const char * ptrDELIMITEUR)
{
	demander(bAvecSeconde, b24H, ptrDELIMITEUR);

	//while (!(estValide(UneHeure, b24H)))
	while (!estValide(b24H))

	{
		cerr << "Erreur : L'heure n'est pas valide." << endl;
		system("pause");
		demander(bAvecSeconde, b24H, ptrDELIMITEUR);
	}

	// L'heure est valide il faut la retourner
	return;
}

int Heure::convertirEnMinutes()
{
	return (iHeure * 60) + iMinute;
}

int Heure::convertirEnSecondes()
{
   return (iHeure * 3600) + (iMinute * 60) + iSeconde;
}
