#include "Code_Utilities.h"
#include "asciiIntro.h"
#include "asciiEukaryotz.h"
#include "asciiCollectables.h"
#include "asciiMonsters.h"
#include "asciiMaps.h"
#include <Windows.h>

using namespace BdB;

//variables utilisées pour la carte
int hSize = 200;
int vSize = 60;
int vOffset = 0;
int hOffset = 0;
int lineSize = 2000;

//variables utilisées pour l'eukaryotz
int protWidth = 16;
int protHeight = 11;
int protLife;
int protSpeed;
int protStrength;
array<string, 10> protInvNames = { "Blobs" };
array<int, 10> protInvQty = { 0 };
char nextMove;

//fonction pour afficher l'intro
void displayIntro(int framesPlayed)
{
    for (int i = 0; i < framesPlayed; ++i)
    {
        cout << frames[i];
        Sleep(100);
        system("cls");
    }
}

string enterName()
{
    cout << "En tant qu'Eukaryotz, quel sera votre nom?\n";
    string testName = "";
    cin >> testName;
    //getline(cin, testName);
    return testName;
}

void moveCursor(int v, int h)
{
    cout << ESC + (to_string(v) + ";" + to_string(h) + "H");
}

bool drawEukaryotz()
{
    //draw an idle Eukaryotz in the center
    int hPos = hSize / 2 - protWidth / 2;
    int vPos = vSize / 2 - protHeight / 2;

    for (int i = 0; i < ProtagAsmall.size(); ++i)
    {
        moveCursor(vPos + i,hPos);
        cout << ProtagAsmall[i];
    }

    return true;
}

bool drawMap(char &nextMove)
{
    vOffset += nextMove == 'w' ? -(protSpeed) : (nextMove == 's' ? protSpeed : 0);
    hOffset += nextMove == 'a' ? -(protSpeed) : (nextMove == 'd' ? protSpeed : 0);
    system("cls");
    for (int imap = ((maps.size() / 2) - (vSize / 2)) + vOffset; imap < ((maps.size() / 2) + (vSize / 2)) + vOffset; ++imap)
    {
        string line = maps[imap];
        lineSize = line.size() + 1;
        string newLine;
        for (int iLine = 0; iLine < hSize; ++iLine)
        {
            newLine += line[(lineSize / 2) - (hSize / 2) + iLine + hOffset];
        }
        cout << newLine << endl;
    }
    return true;
}

array<int, 2> monstersPosition;

void positionMonsters()
{
    int monstersNumber = 1;
    for (int i = 0; i < monstersNumber; ++i)
    {
        //int h = 1 + (rand() % lineSize);
        int h = 1030;
        int v = 90;
        monstersPosition[i * 2] = h;
        monstersPosition[(i * 2) + 1] = v;
    }
}

void drawMonsters()
{
    for (int i = 0; i < 1; ++i)
    {
        int h = monstersPosition[i * 2];
        int v = monstersPosition[(i * 2) + 1];
        int monsterVOffset = (maps.size() / 2) - (vSize / 2);
        int monsterHOffset = (lineSize / 2) - (hSize / 2);
        moveCursor(1, 1);
        cout << v << " " << ((maps.size() / 2) - (vSize / 2)) << " " << h << " " << ((lineSize / 2) - (hSize / 2)) << endl;
        if (v > ((maps.size() / 2) - (vSize / 2)) && v < ((maps.size() / 2) + (vSize / 2)))
        {
            if (h > ((lineSize / 2) - (hSize / 2)) && h < ((lineSize / 2) + (hSize / 2)))
            {
                for (int i = 0; i < monsterAsmall.size(); ++i)
                {
                    moveCursor(v + i - monsterVOffset - vOffset, h - monsterHOffset - hOffset);
                    cout << monsterAsmall[i];
                }
            }
        }
    }
}

array<int, 100> blobsPosition;
void positionBlobs()
{
    int blobsNumber = 25 + (rand() % 26);
    for (int i = 0; i < blobsNumber; ++i)
    {
        int h = rand() % lineSize;
        int v = rand() % maps.size();
        blobsPosition[i * 2] = h;
        blobsPosition[(i * 2) + 1] = v;
    }
}

void drawBlobs()
{
    for (int i = 0; i < 50; ++i)
    {
        int h = blobsPosition[i * 2];
        int v = blobsPosition[(i * 2) + 1];
        int blobVOffset = (maps.size() / 2) - (vSize / 2);
        int blobHOffset = (lineSize / 2) - (hSize / 2);
        moveCursor(1, 1);
        //cout << v << " " << ((maps.size() / 2) - (vSize / 2)) << " " << h << " " << ((lineSize / 2) - (hSize / 2)) << endl;
        if (v > ((maps.size() / 2) - (vSize / 2)) && v < ((maps.size() / 2) + (vSize / 2)))
        {
            if (h > ((lineSize / 2) - (hSize / 2)) && h < ((lineSize / 2) + (hSize / 2)))
            {
                //determine if blob has been eaten by the eukaryotz
                moveCursor(3, 1);
                //cout << (v - blobVOffset - vOffset);
                if ((v - blobVOffset - vOffset) > ((vSize / 2) - (protHeight / 2)) && (v - blobVOffset - vOffset) < ((vSize / 2) + (protHeight / 2)))
                {
                    if ((h - blobHOffset - hOffset) > ((hSize / 2) - (protWidth / 2)) && (h - blobHOffset - hOffset) < ((hSize / 2) + (protWidth / 2)))
                    {
                        blobsPosition[i * 2] = 0;
                        blobsPosition[(i * 2) + 1] = 0;
                        moveCursor(vSize / 2 - protHeight / 2 - 2, hSize / 2 - protWidth / 2);
                        protInvQty[0] += 1;
                        cout << "Slurp!! +1 (" << protInvQty[0] << ")";
                    }
                }
                else
                {
                    for (int i = 0; i < 2; ++i)
                    {
                        moveCursor(v + i - blobVOffset - vOffset, h - blobHOffset - hOffset);
                        cout << BlobASmall[i];
                    }
                }
            }
        }
    }
}

int main()
{
#if _WIN32 || _WIN64
    system("chcp 65001");
    system("cls");
#endif
    srand(time(0));
    positionBlobs();
    positionMonsters();
    pressToContinue("Assurez-vous que votre écran de terminal soit maximisé.\n");

    //intro
    //displayIntro(50);

    cout << "Voulez-vous débuter un nouvel eukaryotz? O pour débuter.\n";
    char userStart;
    cin >> userStart;
    bool startGame = userStart == 'o' || userStart == 'O' ? true : false;

    //variables utilisées pour l'eukaryotz
    string protName;
    array<string, 1> monsterTable = {}; //18x8
    array<string, 10> blobTable = {}; //2x2 blobs
    string envColor = ESC + Green;


    //boucle de jeu principale
    while (startGame)
    {
        //création du personnage, choix: mouvement, points de vie, force; plus tard: type d'eukaryotz
        //4 points a répartir comme on veut entre les 3 choix
        //minimum de 2 dans chacune des caractéristiques, 1 point équivaut à 1 de plus dans la caractéristique

        //boucle pour que l'usager valide le nom
        bool nameIsGood = false;
        while (!nameIsGood)
        {
            string testName = enterName();

            char validateName;
            cout << "Votre Eukaryotz se nomme bien " << testName << "? Tappez o pour oui.\n";
            cin >> validateName;
            nameIsGood = validateName == 'O' || validateName == 'o' ? true : false;
        }

        //boucle pour que l'usager valide les points de caractéristiques de son Eukaryotz
        bool pointsAreGood = false;
        int pointsLeft;
        while (!pointsAreGood)
        {
            pointsLeft = 4;
            protLife = 2;
            protSpeed = 2;
            protStrength = 2;

            system("cls");
            cout << "\bPoints de caractéristique de " << protName << "\n"
                << "Vie: " << setw(3) << protLife << endl
                << "Vitesse: " << setw(3) << protSpeed << endl
                << "Force: " << setw(3) << protStrength << endl;

            cout << "Entrez le nombre de points que vous voulez ajouter à la Vie de votre Eukaryotz: (points restants " << pointsLeft << ")\n";
            int usePoints;
            cin >> usePoints;
            cout << usePoints << endl;
            while (usePoints > pointsLeft || usePoints < 0)
            {
                cout << "Entrée invalide, utilisez vos points restants.\n";
                cout << "Entrez le nombre de points que vous voulez ajouter à la Vie de votre Eukaryotz: (points restants " << pointsLeft << ")\n";
                cin >> usePoints;
            }
            pointsLeft -= usePoints;
            protLife += usePoints;

            system("cls");
            cout << "\bPoints de caractéristique de " << protName << "\n"
                << "Vie: " << setw(3) << protLife << endl
                << "Vitesse: " << setw(3) << protSpeed << endl
                << "Force: " << setw(3) << protStrength << endl;

            cout << "Entrez le nombre de points que vous voulez ajouter à la Vitesse de votre Eukaryotz: (points restants " << pointsLeft << ")\n";
            usePoints = 0;
            cin >> usePoints;
            cout << usePoints << endl;
            while (usePoints > pointsLeft || usePoints < 0)
            {
                cout << "Entrée invalide, utilisez vos points restants.\n";
                cout << "Entrez le nombre de points que vous voulez ajouter à la Vitesse de votre Eukaryotz: (points restants " << pointsLeft << ")\n";
                cin >> usePoints;
            }
            pointsLeft -= usePoints;
            protSpeed += usePoints;


            system("cls");
            cout << "\bPoints de caractéristique de " << protName << "\n"
                << "Vie: " << setw(3) << protLife << endl
                << "Vitesse: " << setw(3) << protSpeed << endl
                << "Force: " << setw(3) << protStrength << endl;

            cout << "Entrez le nombre de points que vous voulez ajouter à la Force de votre Eukaryotz: (points restants " << pointsLeft << ")\n";
            usePoints = 0;
            cin >> usePoints;
            cout << usePoints << endl;
            while (usePoints > pointsLeft || usePoints < 0)
            {
                cout << "Entrée invalide, utilisez vos points restants.\n";
                cout << "Entrez le nombre de points que vous voulez ajouter à la Force de votre Eukaryotz: (points restants " << pointsLeft << ")\n";
                cin >> usePoints;
            }
            pointsLeft -= usePoints;
            protStrength += usePoints;

            system("cls");
            cout << "\bPoints de caractéristique de " << protName << "\n"
                << "Vie: " << setw(3) << protLife << endl
                << "Vitesse: " << setw(3) << protSpeed << endl
                << "Force: " << setw(3) << protStrength << endl;

            char validCarac;
            cout << "Est-ce que les caractéristique de votre Eukaryotz vous conviennent? o pour oui.\n";
            cin >> validCarac;
            pointsAreGood = validCarac == 'o' || validCarac == 'O' ? true : false;
        }

        bool inMap = true;
        while (inMap)
        {
            drawMap(nextMove);
            inMap = drawEukaryotz();
            drawBlobs();
            drawMonsters();
            cout << ESC + (to_string(vSize + 1) + ";1H");
            cout << "w,a,s,d suivi de la touche Entrer pour faire votre prochain mouvement.";
            cin >> nextMove;
        }

        startGame = false;
    }
    
    system("pause");
    return 0;
}