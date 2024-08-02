/*
    Devoir 3
    St Cyr Lee J Vandersar
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <cctype>

using namespace std;


vector<string> trouverMotsDebutPhrase(const string& nomFichier) {

    ifstream fichier(nomFichier);
    vector<string> premiersMots;

    if (!fichier) {
        cout << "Erreur lors de l'ouverture du fichier." << endl;
        return premiersMots;
    }
    string ligne;
    while (getline(fichier, ligne)) {
        istringstream iss(ligne);
        string mot;
        bool estNouvellePhrase = true;

        while (iss >> mot) {
            if (estNouvellePhrase && isupper(mot[0]) ) {
                premiersMots.push_back(mot);
                estNouvellePhrase = false;
            }

            if (mot.find('.') != string::npos || mot.find('?') != string::npos || mot.find('!') != string::npos ) {
                estNouvellePhrase = true;
            }
        }
    }

    fichier.close();
    return premiersMots;

}

void afficherMot(const vector<string>& listeMots){

    for (const auto& mot : listeMots) {
       cout << mot << endl;
    }

}

int main() {

    string nomFichier = "ephesiens1.txt";

    afficherMot( trouverMotsDebutPhrase(nomFichier) );

    return 0;

}
