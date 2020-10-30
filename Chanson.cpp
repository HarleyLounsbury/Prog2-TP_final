#include "Chanson.h"

Chanson::Chanson()
{
   // Initialiser les variables de la structure.
   iNumeroChanson = 0;
   ptrNomChanson = nullptr;
   ptrNomAlbum = nullptr;
   ptrAnnee = nullptr;

   estFavori = false;
   iNumeroPriorite = 0;
   iNombreEcoutes = 0;
}

Chanson::~Chanson()
{
   // Libérer de la mémoire, si il a lieu.
   if (ptrNomChanson)
      delete[] ptrNomChanson;

   if (ptrNomAlbum)
      delete[] ptrNomAlbum;

   if (ptrAnnee)
      delete[] ptrAnnee;

   if (UnArtiste.ptrNomArtiste)
      delete[] UnArtiste.ptrNomArtiste;

   if (UnGenre.ptrNomGenre)
      delete[] UnGenre.ptrNomGenre;
}

void Chanson::afficher()
{
   // Fonction pour afficher les détails de la chanson.
   cout << left;
   cout << setw(15) << "Titre:" << ptrNomChanson << endl;
   cout << setw(15) << "Artiste:" << UnArtiste.ptrNomArtiste << endl;
   cout << setw(15) << "Genre:" << UnGenre.ptrNomGenre << endl;
   cout << setw(15) << "Durée:" << (Duree.iMinute <= 9 ? "0" : "") << Duree.iMinute << ":" << Duree.iSeconde << endl;
   cout << setw(15) << "Favori:" << ((estFavori) ? "Oui" : "Non") << endl;
   cout << setw(15) << "Nb écoutes: " << iNombreEcoutes << endl;

   return;
}

void Chanson::lireChanson(ifstream & ifCanal)
{
   // Tableau de caractères temporaire.
   const int iMAX_TEMP = 100;
   char cTemp[iMAX_TEMP];

   // Lire le premier champ.
   ifCanal >> iNumeroChanson;
   ifCanal.ignore(1, ';');

   // Lire le prochain champ et stocker dans un variable temporaire avant de copier.
   ifCanal.getline(cTemp, iMAX_TEMP, ';');
   ptrNomChanson = new char[retourneNbChar(cTemp) + 1];
   copierChar(ptrNomChanson, cTemp);

   // Lire le prochain champ et stocker dans un variable temporaire avant de copier.
   ifCanal.getline(cTemp, iMAX_TEMP, ';');
   UnArtiste.ptrNomArtiste = new char[retourneNbChar(cTemp) + 1];
   copierChar(UnArtiste.ptrNomArtiste, cTemp);

   // Lire le prochain champ et stocker dans un variable temporaire avant de copier.
   ifCanal.getline(cTemp, iMAX_TEMP, ';');
   UnGenre.ptrNomGenre = new char[retourneNbChar(cTemp) + 1];
   copierChar(UnGenre.ptrNomGenre, cTemp);

   // Lire le prochain champ et stocker dans un variable temporaire avant de copier.
   ifCanal >> Duree.iMinute;
   ifCanal.ignore(1, ':');
   ifCanal >> Duree.iSeconde;
   ifCanal.ignore(1, ';');

   // Lire le prochain champ et stocker dans un variable temporaire avant de copier.
   ifCanal.getline(cTemp, iMAX_TEMP, ';');
   ptrNomAlbum = new char[retourneNbChar(cTemp) + 1];
   copierChar(ptrNomAlbum, cTemp);

   // Lire le dernier champ de la ligne et stocker dans un variable temporaire avant de copier.
   ifCanal.getline(cTemp, iMAX_TEMP, '\n');
   ptrAnnee = new char[retourneNbChar(cTemp) + 1];
   copierChar(ptrAnnee, cTemp);

   return;
}

void Chanson::lireChanson(ifstream & ifCanal, bool estFichierLec)
{
   // Tableau de caractères temporaire.
   const int iMAX_TEMP = 100;
   char cTemp[iMAX_TEMP];

   // Lire le premier champ.
   ifCanal >> iNumeroChanson;
   ifCanal.ignore(1, ';');

   // Lire le prochain champ et stocker dans un variable temporaire avant de copier.
   ifCanal.getline(cTemp, iMAX_TEMP, ';');
   ptrNomChanson = new char[retourneNbChar(cTemp) + 1];
   copierChar(ptrNomChanson, cTemp);

   // Lire le prochain champ et stocker dans un variable temporaire avant de copier.
   ifCanal.getline(cTemp, iMAX_TEMP, ';');
   UnArtiste.ptrNomArtiste = new char[retourneNbChar(cTemp) + 1];
   copierChar(UnArtiste.ptrNomArtiste, cTemp);

   // Lire le prochain champ et stocker dans un variable temporaire avant de copier.
   ifCanal.getline(cTemp, iMAX_TEMP, ';');
   UnGenre.ptrNomGenre = new char[retourneNbChar(cTemp) + 1];
   copierChar(UnGenre.ptrNomGenre, cTemp);

   // Lire le prochain champ et stocker dans un variable temporaire avant de copier.
   ifCanal >> Duree.iMinute;
   ifCanal.ignore(1, ':');
   ifCanal >> Duree.iSeconde;
   ifCanal.ignore(1, ';');

   // Lire le prochain champ et stocker dans un variable temporaire avant de copier.
   ifCanal.getline(cTemp, iMAX_TEMP, ';');
   ptrNomAlbum = new char[retourneNbChar(cTemp) + 1];
   copierChar(ptrNomAlbum, cTemp);

   // Lire le prochain champ et stocker dans un variable temporaire avant de copier.
   estFichierLec ? ifCanal.getline(cTemp, iMAX_TEMP, ';') : ifCanal.getline(cTemp, iMAX_TEMP, '\n');
   ptrAnnee = new char[retourneNbChar(cTemp) + 1];
   copierChar(ptrAnnee, cTemp);

   if (estFichierLec)
   {
   // Lire le prochain champ et stocker dans un variable temporaire avant de copier.
   ifCanal >> estFavori;
   ifCanal.ignore(1, ';');

   // Lire le prochain champ et stocker dans un variable temporaire avant de copier.
   ifCanal >> iNumeroPriorite;
   ifCanal.ignore(1, ';');

   // Lire le prochain champ et stocker dans un variable temporaire avant de copier.
   ifCanal >> iNombreEcoutes;
   ifCanal.ignore(1, '\n');
   }

   return;
}
