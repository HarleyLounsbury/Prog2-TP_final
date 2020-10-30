// But: Structure principale d'un lecteur de musique.
// Auteur: Harley Lounsbury
// Date: 16-04-2019

#include "LecteurMusique.h"

LecteurMusique::LecteurMusique()
{
   // Initialiser les variables de la structure.
   iChoixMenu = NULL;
   ptrNomFichier = nullptr;
   iNbChansons = 0;
   iModeEcoute = iMODE_DEFAUT;
}

LecteurMusique::~LecteurMusique()
{
   // Si on a alloué de la mémoire, on va devoir la libérer.
   
   if (ptrNomFichier)
   {
      delete[] ptrNomFichier;
   }

   NoeudChanson* ptrParcours = UneListe.ptrDebut;

   // On doit libèrer la mémoire de chaque noeud.
   if (ptrParcours)
   {
      NoeudChanson* ptrTemp = ptrParcours->ptrSuivant;
      delete ptrParcours;
      ptrParcours = ptrTemp;
      ptrTemp = ptrTemp->ptrSuivant;

      while (ptrParcours->ptrSuivant)
      {
         delete ptrParcours;
         ptrParcours = ptrTemp;
         ptrTemp = ptrTemp->ptrSuivant;
      }
   }

}

void LecteurMusique::demarrerLecteur()
{
   // Afficher le menu du lecteur.
   afficherMenu(79);
   // Tant que l'utilisateur n'a pas choisi de quitter.
   while (iChoixMenu != iQUITTER)
   {
      // Menu principal, qui fait appel à la fonction appropriée selon le choix de l'utilisateur.
      switch (iChoixMenu)
      {
      case iCHOISIR_LISTE:
         choisirListe();
         break;
      case iCHOISIR_MODE_ECOUTE:
         if (iNbChansons == 0)
         {
            cout << "Vous n'avez aucune chanson dans votre répertoire." << endl;
            system("pause");
            break;
         }
         choisirModeEcoute();
         break;
      case iECOUTER:
         if (iNbChansons == 0)
         {
            cout << "Vous n'avez aucune chanson dans votre répertoire." << endl;
            system("pause");
            break;
         }
         ecouterListe();
         break;
      default:
         break;
      }
      afficherMenu(79);
   }
   // Condition pour vérifier qu'une liste a été importé avant d'essayer un exportation.
   if (UneListe.ptrDebut)
      sauvegarderStatsEnLec();

   return;
}

void LecteurMusique::afficherMenu(int iLargeur)
{
   // Éffacer l'écran avant d'afficher.
   system("cls");

   // Afficher le menu.
   afficherEnTete(iLargeur);
   afficherListeDeChoix();
   ligneDeTirets(iLargeur);
   iChoixMenu = retourneChoixMenu(iMIN_MENU, iMAX_MENU);

   return;
}

void LecteurMusique::afficherEnTete(int iLargeur)
{
   // Ligne de tirets.
   ligneDeTirets(iLargeur);
   // Titre du programme.
   cout << "Lecteur MP3 de Harley Lounsbury" << endl;
   // Ligne de tirets.
   ligneDeTirets(iLargeur);

   return;
}

void LecteurMusique::afficherListeDeChoix()
{
   // Afficher les choix.
   cout << "1. Choisir la liste à écouter" << endl;
   cout << "2. Choisir le mode d'écoute" << endl;
   cout << "3. Écouter la liste" << endl;
   cout << "4. Quitter" << endl;

   return;
}

void LecteurMusique::choisirListe()
{
   // Éffacer l'écran avant d'afficher.
   system("cls");
   // Ligne de tirets.
   ligneDeTirets(79);
   // Titre.
   cout << "Choix de la liste d'écoute" << endl;
   // Ligne de tirets. 
   ligneDeTirets(79);

   // Booléen pour déterminer la suite si le fichier a été ouvert corretement.
   bool bSucces;

   // Message d'intention.
   cout << "Veuillez indiquer le nom du fichier à importer dans la liste de chansons." << endl;

   cout << "Appuyez sur enter pour garder la valeur par défaut (Liste de chansons) :";
   ptrNomFichier = demanderChaine(256, "");

   // ouvrir le fichier par défaut ou le fichier saisi par l'utilisateur.
   if (strlen(ptrNomFichier) == 0)
   {
      cout << "Ouverture du fichier par défaut." << endl;
      bSucces = ouvrirFichierEnLecture(cFICHER_PAR_DEFAUT, ifCanal);
      bPointLec = false;
   }
   else
   {
      if (siExtension(ptrNomFichier))
      {
         bSucces = ouvrirFichierEnLecture(ptrNomFichier, ifCanal);
      }
      else
      {
         strcat_s(ptrNomFichier, strlen(ptrNomFichier) + 4 + 1, ".lec");
         bSucces = ouvrirFichierEnLecture(ptrNomFichier, ifCanal);
      }
      bPointLec = true;
   }

   if (bSucces)
   {
      importerListe();
      cout << "L'importation a réussi." << endl;
      system("pause");
   }

   return;
}

void LecteurMusique::importerListe()
{
   // Stocker les chansons du fichier dans la liste chaînée.
   // On va créer un nouveau Noeud. 
   NoeudChanson* ptrNouveau;
   
   ptrNouveau = new NoeudChanson;

   if (!ptrNouveau)
   {
      cerr << "Erreur: Mémoire insuffisant." << endl;
      system("pause");
      abort();
   }

   //On doit y mettre de l'information.
   ptrNouveau->UnChanson.lireChanson(ifCanal, bPointLec);
   
   // Le gateau au chocolat. 
   while (!ifCanal.eof())
   {
      iNbChansons++;
      UneListe.ajouter(ptrNouveau);
      if (!UneListeArtiste.siDoublon(ptrNouveau->UnChanson.UnArtiste))
      {
         UneListeArtiste.ajouter(ptrNouveau->UnChanson.UnArtiste);
      }
      if (!UneListeGenres.siDoublon(ptrNouveau->UnChanson.UnGenre))
      {
         UneListeGenres.ajouter(ptrNouveau->UnChanson.UnGenre);
      }
      
      ptrNouveau = new NoeudChanson;
 
      if (!ptrNouveau)
      {
         cerr << "Erreur: Mémoire insuffisant." << endl;
         system("pause");
         abort();
      }
      ptrNouveau->UnChanson.lireChanson(ifCanal, bPointLec);
   }

   // On supprime le dernier "new" qui contient rien.
   delete ptrNouveau;
   ptrNouveau = nullptr;

   return;
}

void LecteurMusique::choisirModeEcoute()
{
   system("cls");

   afficherEnTeteModeEcoute();

   afficherMenuModeEcoute();
   ligneDeTirets(79);

   // Saisir le choix de l'utilisateur et choisir la fonction appropriée.
   iChoixMenu = retourneChoixMenu(iMODE_DEFAUT, iRETOUR);
   switch (iChoixMenu)
   {
   case iMODE_DEFAUT:
      iModeEcoute = iMODE_DEFAUT;
      break;
   case iMODE_SELON_GENRE:
      iModeEcoute = iMODE_SELON_GENRE;
      choisirGenre();
      break;
   case iMODE_SELON_ARTISTE:
      iModeEcoute = iMODE_SELON_ARTISTE;
      choisirArtiste();
      break;
   case iMODE_FAVORIS:
      iModeEcoute = iMODE_FAVORIS;
      break;
   case iMODE_ALEATOIRE:
      iModeEcoute = iMODE_ALEATOIRE;
      break;
   case iRETOUR:
      break;
   }
   return;
}

void LecteurMusique::afficherEnTeteModeEcoute()
{
   // Afficher l'en-tête.
   ligneDeTirets(79);
   cout << "Choix du mode d'écoute" << endl;
   ligneDeTirets(79);
   
   return;
}

void LecteurMusique::afficherMenuModeEcoute()
{
   // Afficher le menu.
   cout << "1. Ordre de la liste (par défaut)" << endl;
   cout << "2. Selon le genre" << endl;
   cout << "3. Selon l'artiste" << endl;
   cout << "4. Les favoris" << endl;
   cout << "5. Aléatoirement" << endl;
   cout << "6. Revenir au menu principal" << endl;

   return;
}

void LecteurMusique::choisirGenre()
{
   // Fonction pour afficher et saisir le genre désiré.
   system("cls");
   afficherEnTeteGenres();
   UneListeGenres.afficherListe();
   ligneDeTirets(79);
   iGenre = retourneChoixMenu(1, UneListeGenres.iNbGenres);

   return;
}

void LecteurMusique::afficherEnTeteGenres()
{
   // Afficher l'en-tête.
   ligneDeTirets(79);
   cout << "Liste de genres" << endl;
   ligneDeTirets(79);
   cout << left << setw(6) << " ID" << "Genre" << endl;
   ligneDeTirets(79);
   
   return;
}

void LecteurMusique::choisirArtiste()
{
   // Fonction pour afficher les choix et saisir l'artiste désiré.
   system("cls");
   afficherEnTeteArtistes();
   UneListeArtiste.afficherListe();
   ligneDeTirets(79);
   iArtiste = retourneChoixMenu(1, UneListeArtiste.iNbArtistes);
   
   return;
}

void LecteurMusique::afficherEnTeteArtistes()
{
   // Afficher l'en-tête.
   ligneDeTirets(79);
   cout << "Liste des artistes" << endl;
   ligneDeTirets(79);
   cout << left << setw(6) << " ID" << "Artiste" << endl;
   ligneDeTirets(79);

   return;
}

void LecteurMusique::ecouterListe()
{
   // Déterminer le mode d'écoute désiré, ou le mode par défaut.
   switch (iModeEcoute)
   {
   case iMODE_DEFAUT:
      ecouterListeDefaut();
      break;
   case iMODE_SELON_GENRE:
      ecouterListeParGenre();
      break;
   case iMODE_SELON_ARTISTE:
      ecouterListeParArtiste();
      break;
   case iMODE_FAVORIS:
      if (contientFavoris())
         ecouterListeParFavoris();
      else
      {
         cout << "Votre liste ne contient aucune chanson favorite." << endl;
         system("pause");
      }
      break;
   case iMODE_ALEATOIRE:
      ecouterListeAleatoire();
      break;
   default:
      break;
   }
}

void LecteurMusique::ecouterListeDefaut()
{
   // Écouter toute la liste.
   NoeudChanson* ptrParcours = UneListe.ptrDebut;
   NoeudChanson* ptrParcoursEnArriere = nullptr;
   int iChoix = 0;

   while (iChoix != 113)
   {
      ecouterChanson(ptrParcours, iChoix);
      
      if (iChoix == 115)
      {
         if (ptrParcours->ptrSuivant)
            ptrParcours = ptrParcours->ptrSuivant;
         else
            ptrParcours = UneListe.ptrDebut;
      }

      if (iChoix == 98)
      {
         if (ptrParcours->ptrPrecedent)
            ptrParcours = ptrParcours->ptrPrecedent;
         else
            ptrParcours = UneListe.ptrFin;
      }
   }
   return;
}

void LecteurMusique::ecouterListeParGenre()
{
   // Écouter la liste qui vérifier si la prochaine chanson est du même genre que celui choisi par l'utilisateur.
   UneListeGenres.attribuerIdentifiants();
   UneListe.attribuerIdentifiantsGenres(iNbChansons, UneListeGenres);
   NoeudChanson* ptrParcours = UneListe.ptrDebut;
   NoeudChanson* ptrParcoursEnArriere = nullptr;
   int iChoix = 0;

   while (iChoix != 113)
   {
     while (ptrParcours->UnChanson.UnGenre.iIdentifiant != iGenre)
     {
        if (iChoix == 115 || iChoix == 0)
        {
           if (ptrParcours->ptrSuivant)
              ptrParcours = ptrParcours->ptrSuivant;
           else
              ptrParcours = UneListe.ptrDebut;
        }
        if (iChoix == 98)
        {
           if (ptrParcours->ptrPrecedent)
              ptrParcours = ptrParcours->ptrPrecedent;
           else
              ptrParcours = UneListe.ptrFin;
        }
     }
      ecouterChanson(ptrParcours, iChoix);
      
      if (iChoix == 115)
      {
         if (ptrParcours->ptrSuivant)
            ptrParcours = ptrParcours->ptrSuivant;
         else
            ptrParcours = UneListe.ptrDebut;
      }

      if (iChoix == 98)
      {
         if (ptrParcours->ptrPrecedent)
            ptrParcours = ptrParcours->ptrPrecedent;
         else
            ptrParcours = UneListe.ptrFin;
      }
   }

   return;
}

void LecteurMusique::ecouterListeParArtiste()
{
   UneListeArtiste.attribuerIdentifiants();
   UneListe.attribuerIdentifiantsArtistes(iNbChansons, UneListeArtiste);
   NoeudChanson* ptrParcours = UneListe.ptrDebut;
   NoeudChanson* ptrParcoursEnArriere = nullptr;
   int iChoix = 0;

   while (iChoix != 113)
   {
      while (ptrParcours->UnChanson.UnArtiste.iIdentifiant != iArtiste)
      {
         if (iChoix == 115 || iChoix == 0)
         {
            if (ptrParcours->ptrSuivant)
               ptrParcours = ptrParcours->ptrSuivant;
            else
               ptrParcours = UneListe.ptrDebut;
         }
         if (iChoix == 98)
         {
            if (ptrParcours->ptrPrecedent)
               ptrParcours = ptrParcours->ptrPrecedent;
            else
               ptrParcours = UneListe.ptrFin;
         }
      }
      ecouterChanson(ptrParcours, iChoix);
      
      if (iChoix == 115)
         if (ptrParcours->ptrSuivant)
            ptrParcours = ptrParcours->ptrSuivant;
         else
            ptrParcours = UneListe.ptrDebut;

      if (iChoix == 98)
         if (ptrParcours->ptrPrecedent)
            ptrParcours = ptrParcours->ptrPrecedent;
         else
            ptrParcours = UneListe.ptrFin;
   }
   return;
}

void LecteurMusique::ecouterListeParFavoris()
{
   NoeudChanson* ptrParcours = UneListe.ptrDebut;
   NoeudChanson* ptrParcoursEnArriere = nullptr;
   int iChoix = 0;

   while (iChoix != 113)
   {
      while (ptrParcours->UnChanson.estFavori != true)
      {
         if (iChoix == 115 || iChoix == 0)
         {
            if (ptrParcours->ptrSuivant)
               ptrParcours = ptrParcours->ptrSuivant;
            else
               ptrParcours = UneListe.ptrDebut;
         }
         if (iChoix == 98)
         {
            if (ptrParcours->ptrPrecedent)
               ptrParcours = ptrParcours->ptrPrecedent;
            else
               ptrParcours = UneListe.ptrFin;
         }
      }
      ecouterChanson(ptrParcours, iChoix);

      if (iChoix == 115)
         if (ptrParcours->ptrSuivant)
            ptrParcours = ptrParcours->ptrSuivant;
         else
            ptrParcours = UneListe.ptrDebut;

      if (iChoix == 98)
         if (ptrParcours->ptrPrecedent)
            ptrParcours = ptrParcours->ptrPrecedent;
         else
            ptrParcours = UneListe.ptrFin;
   }
   return;
}

void LecteurMusique::ecouterListeAleatoire()
{
   NoeudChanson* ptrParcours = UneListe.ptrDebut;
   int iChoix = 0;
   int iDeterminerChanson;

   ecouterUneChansonAleatoire(iChoix);

   while (iChoix != 113)
   {
      iDeterminerChanson = retourneAleatoire(1, 3);
      switch (iDeterminerChanson)
      {
         case 1:
            ecouterProchainFavori(ptrParcours, iChoix);
            break;
         case 2:
            ecouterChanson(determinerProchainMoinsEcoute(), iChoix);
            break;
         case 3:
            ecouterChanson(determinerPlusHautePriorite(), iChoix);
            break;
      }
   }
}

bool LecteurMusique::contientFavoris()
{
   NoeudChanson* ptrParcours = UneListe.ptrDebut;
   for (int i = 0; i < iNbChansons; i++)
   {
      if (ptrParcours->UnChanson.estFavori)
         return true;
      ptrParcours = ptrParcours->ptrSuivant;
   }

   return false;
}

void LecteurMusique::ecouterProchainFavori(NoeudChanson* &ptrParcours, int &iChoix)
{
   if (contientFavoris())
   {
      while (ptrParcours->UnChanson.estFavori != true)
      {
         if (ptrParcours->ptrSuivant)
            ptrParcours = ptrParcours->ptrSuivant;
         else
            ptrParcours = UneListe.ptrDebut;
      }
      ecouterChanson(ptrParcours, iChoix);
   }
   return;
}

NoeudChanson* LecteurMusique::determinerProchainMoinsEcoute()
{
   NoeudChanson* ptrParcoursBase = UneListe.ptrDebut;
   NoeudChanson* ptrParcoursComp = nullptr;
   NoeudChanson* ptrAEcouter = ptrParcoursBase;

   for (int i = 0; i < iNbChansons - 1; i++)
   {
      ptrParcoursComp = ptrParcoursBase->ptrSuivant;
      for (int j = i + 1; j < iNbChansons; j++)
      {
         if (ptrParcoursBase->UnChanson.iNombreEcoutes <= ptrParcoursComp->UnChanson.iNombreEcoutes)
         {
            ptrAEcouter = ptrParcoursComp;
            return ptrAEcouter;
         }
         ptrParcoursComp = ptrParcoursComp->ptrSuivant;
      }
      ptrParcoursBase = ptrParcoursBase->ptrSuivant;
   }
   return ptrAEcouter;
}

void LecteurMusique::ecouterUneChansonAleatoire(int &iChoix)
{
   NoeudChanson* ptrParcours = UneListe.ptrDebut;
   int iIdChanson;

   iIdChanson = retourneAleatoire(1, iNbChansons);

   while (ptrParcours->UnChanson.iNumeroChanson != iIdChanson)
   {
      if (ptrParcours->ptrSuivant)
         ptrParcours = ptrParcours->ptrSuivant;
   }
   ecouterChanson(ptrParcours, iChoix);

   return;

}

NoeudChanson * LecteurMusique::determinerPlusHautePriorite()
{
   NoeudChanson* ptrParcours = UneListe.ptrDebut;
   NoeudChanson* ptrAEcouter = ptrParcours;

   for (int i = 0; i < iNbChansons - 1; i++)
   {
      if (ptrParcours->UnChanson.iNumeroPriorite < ptrParcours->ptrSuivant->UnChanson.iNumeroPriorite)
      {
         ptrAEcouter = ptrParcours->ptrSuivant;
         return ptrAEcouter;
      }
      ptrParcours = ptrParcours->ptrSuivant;
   }
   return ptrAEcouter;
}

void LecteurMusique::afficherNavigation()
{
   // Pour afficher les options de navigation pendant l'écoute.
   cout << endl << endl;
   cout << "<- ou b permet d'aller à la chanson précédente" << endl;
   cout << "-> ou s permet d'aller à la chanson suivante" << endl;
   cout << "espace permet de mettre sur pause" << endl;
   cout << "r permet de répéter la chanson" << endl;
   cout << "f permet d'ajouter aux favoris" << endl;
   cout << "q permet de quitter l'écoute de la liste" << endl;

   return;
}

void LecteurMusique::ecouterChanson(NoeudChanson * ptrChanson, int & iChoix)
{
   int iTempsEcouleSecondes = 0;
   int iTempsEcouleMinutes = 0;
   int iSecondesTotal;

   // Boucle pour la chanson. 
   for (iSecondesTotal = 0; iSecondesTotal < ptrChanson->UnChanson.Duree.convertirEnSecondes(); iSecondesTotal++)
   {
      // Pour la raisons de tester le programme, l'augmentation du nombre d'écoutes est mieux placer ici, pour pas faire en sorte qu'il faut écouter la chanson au complet pour la voir arriver. 
      // Peut-être c'est mieux à la fin d'une écoute, ou bien aprés qu'il passe un nombre de secondes d'écoute arbitraire et déterminer d'avance. 
      if (iSecondesTotal == 0)
      {
         ptrChanson->UnChanson.iNombreEcoutes++;
      }
      // Pause invisible pour 1 seconde.
      Sleep(1000);
         
      afficherDetailsChanson(ptrChanson, iTempsEcouleSecondes, iTempsEcouleMinutes);

      iTempsEcouleSecondes++;

      // À chaque minute, il faut augmenter les minutes et remettre les secondes à 0.
      if (iTempsEcouleSecondes == 60)
      {
         iTempsEcouleMinutes++;
         iTempsEcouleSecondes = 0;
      }

      // Opération pour gérer les contrôles.
      // Ce mécanisme ne peut pas être intégré dans une fonction en raison des instructions de retour requises pour quitter la fonction de chanson.
      while (_kbhit())
      {
         iChoix = _getch();
         switch (iChoix)
         {
         // 'b'
         case 98:
         // 'B'
         case 66:
         // 's'
         case 115:
         // 'S'
         case 83:
         // 'q'
         case 113:
         // 'Q'
         case 81:
            return;
         // <-
         case 75:
            iChoix = 98;
            return;
         // ->
         case 77:
            iChoix = 115;
            return;
         // 'r'   
         case 114:
         // 'R'
         case 82:
            iTempsEcouleMinutes = 0;
            iTempsEcouleSecondes = 0;
            iSecondesTotal = 0;
            ptrChanson->UnChanson.iNumeroPriorite++;
            break;
         // 'f'
         case 102:
         // 'F'
         case 70:
            if (ptrChanson->UnChanson.estFavori)
               ptrChanson->UnChanson.estFavori = false;
            else
               ptrChanson->UnChanson.estFavori = true;
            break;
         // ' '
         case 32:
            // Fonctionalité pour pouvoir effectuer des commandes pendant qu'une chanson est sur 'pause'.
            iChoix = _getch();
            switch (iChoix)
            {
            case 98:
            case 66:
            case 115:
            case 83:
            case 113:
            case 81:
               return;
            case 75:
               iChoix = 98;
               return;
            case 77:
               iChoix = 115;
               return;
            case 114:
            case 82:
               iTempsEcouleMinutes = 0;
               iTempsEcouleSecondes = 0;
               iSecondesTotal = 0;
               ptrChanson->UnChanson.iNumeroPriorite++;
               break;
            case 102:
            case 70:
               if (ptrChanson->UnChanson.estFavori)
                  ptrChanson->UnChanson.estFavori = false;
               else
                  ptrChanson->UnChanson.estFavori = true;
               _getch();
               break;
            }

            break;
         }
      }
   }
   // Si on a écouté la chanson au complet, on augmente son numéro de priorité.
   ptrChanson->UnChanson.iNumeroPriorite++;
}

void LecteurMusique::sauvegarderStatsEnLec()
{
   // Condition pour vérifier si le fichier par défaut a été choisi. 
   strlen(ptrNomFichier) == 0 ? creerFichier(ofCanal, cFICHIER_DE_SORTIE) : creerFichier(ofCanal, ptrNomFichier);
   ecrireDansFichier(ofCanal);
   
   return;
}

void LecteurMusique::ecrireDansFichier(ofstream & ofCanal)
{
   NoeudChanson* ptrParcours = UneListe.ptrDebut;

   // On doit vérifier si la liste contient au moins un noeud, sinon, elle est vide.
   if (!UneListe.ptrDebut)
   {
      cout << "La liste est vide." << endl;
   }
   else
   {
      while (ptrParcours)
      {
         ofCanal << ptrParcours->UnChanson.iNumeroChanson << ";"
            << ptrParcours->UnChanson.ptrNomChanson << ";"
            << ptrParcours->UnChanson.UnArtiste.ptrNomArtiste << ";"
            << ptrParcours->UnChanson.UnGenre.ptrNomGenre << ";"
            << ptrParcours->UnChanson.Duree.iMinute << ":" << ptrParcours->UnChanson.Duree.iSeconde << ";"
            << ptrParcours->UnChanson.ptrNomAlbum << ";"
            << ptrParcours->UnChanson.ptrAnnee << ";"
            << (ptrParcours->UnChanson.estFavori == true ? 1 : 0) << ";"
            << ptrParcours->UnChanson.iNumeroPriorite << ";"
            << ptrParcours->UnChanson.iNombreEcoutes << endl;
         // On doit passer au noeud suivant.
         ptrParcours = ptrParcours->ptrSuivant;
      }
      cout << endl;
   }
 
   return;
}

void LecteurMusique::afficherDetailsChanson(NoeudChanson * ptrChanson, int iTempsEcouleSecondes, int iTempsEcouleMinutes)
{
   system("cls");
   // Afficher le numéro de chanson sur le total.
   cout << ptrChanson->UnChanson.iNumeroChanson << " sur " << iNbChansons << endl;

   // Afficher les détails de la chanson.
   ptrChanson->UnChanson.afficher();

   // Afficher le temps écoulé sur le total.
   cout << (iTempsEcouleMinutes < 9 ? "0" : "") << iTempsEcouleMinutes << ":" << (iTempsEcouleSecondes <= 9 ? "0" : "") << iTempsEcouleSecondes;
   cout << " sur " << (ptrChanson->UnChanson.Duree.iMinute <= 9 ? "0" : "") << ptrChanson->UnChanson.Duree.iMinute << ":" << ptrChanson->UnChanson.Duree.iSeconde << endl;

   afficherNavigation();

   return;
}
