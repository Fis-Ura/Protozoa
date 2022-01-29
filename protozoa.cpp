#include "Code_Utilities.h"
#include "asciiIntro.h"
#include "asciiIntro2.h"
#include "asciiLogo.h"
#include "asciiProtazoid.h"
#include "asciiCollectables.h"
#include "asciiMonsters.h"
#include <Windows.h>
#include <conio.h>

using namespace BdB;

//variables utilisées pour la carte
bool userQuit = false;
int hSize = 200;
int vSize = 60;
int vOffset = 0;
int hOffset = 0;
int lineSize = 800;
array<string, 200> currentMap;
bool bossIsIn = false;

//variables utilisées pour le protazoid
string protName;
int protWidth = 16;
int protHeight = 11;
int protLife;
int protLifeMax;
bool protRegen;
int protSpeed;
int protStrength;
int protSatiety = 100;
array<string, 4> protInvNames = { "Calories", "Life", "Speed", "Strength" };
array<int, 4> protInvQty = { 0, 0, 0, 0 };
bool protInvOpen = false;
char nextMove;

void moveCursor(int v, int h)
{
    cout << ESC + (to_string(v) + ";" + to_string(h) + "H");
}

string spaceString(int length)
{
    string spaces = "";
    for (int i = 0; i < length; ++i)
    {
        spaces += " ";
    }
    return spaces;
}

/**
Ajoute du spacing
@param int lines Nombre de fois que move cursor sera appele
@param int sizeY position Y
@param int sizeX position X
@param xOffset(optional) si n'est pas spécifier il reste a 1
*/
void addSpacing(int lines, int sizeY, int sizeX, int xOffset = 1)
{
    string spaces = spaceString(sizeX);

    for (int i = 1; i <= lines; i++) {
        moveCursor(vSize / 2 + sizeY / 2 + i, hSize / 2 - sizeX / 2 + xOffset);
        cout << spaces;
    }
}

void clearCin()
{
    cin.clear();
    cin.ignore(120, '\n');
}

void calibrateScreen()
{
    cout << "Assurez-vous que votre écran de terminal soit maximisé.\n";
    Sleep(2000);

    string hundred = "____________________________________________________________________________________________________";
    cout << hundred << hundred << endl;
    cout << "Est-ce que les tirets s'affichent tous sur la même ligne? o pour oui\n";
    char hValidate;
    cin >> hValidate;
    if (hValidate == 'o' || hValidate == 'O')
        hSize = 200;
    else
    {
        system("cls");
        cout << hundred << endl;
        cout << "Est-ce que les tirets s'affichent tous sur la même ligne? o pour oui\n";
        cin >> hValidate;
        if (hValidate == 'o' || hValidate == 'O')
            hSize = 100;
    }
    system("cls");
    for (int i = 0; i < 60; ++i) cout << '|' << endl;
    cout << "Est-ce que la ligne s'affiche au complet dans l'écran? o pour oui\n";
    char vValidate;
    cin >> vValidate;
    if (vValidate == 'o' || vValidate == 'O')
        vSize = 60;
    else
    {
        system("cls");
        for (int i = 0; i < 30; ++i) cout << '|' << endl;
        cout << "Est-ce que la ligne s'affiche au complet dans l'écran? o pour oui\n";
        cin >> vValidate;
        if (vValidate == 'o' || vValidate == 'O')
            vSize = 30;
    }
}

array<string, 200> buildRandomMap()
{
    int threshold = 100;
    array<string,200> newMap;
    string newLine = "";
    string lastLine = "";
    array<int, 800> cellThreshold = {};
    array<int, 800> cellThresholdLastLine = {};
    int distancer = 10;

    for (int i = 0; i < 200; ++i)
    {
        newLine = "";
        for (int i = 0; i < ((lineSize / 2) - 1); ++i)
        {
            if (i != 0)
                threshold -= cellThreshold[i - 1] * 4;
            threshold -= cellThresholdLastLine[i] * 30;
            threshold = threshold <= 0 ? 5 : threshold;
            if (rand() % threshold == threshold - 1 && distancer > 0)
            {
                cellThreshold[i] += 1;
                newLine += "1";
                distancer -= 1;
                threshold = 100;
            }
            else
            {
                cellThreshold[i] += 0;
                newLine += ".";
                threshold -= 1;
                distancer -= 1;
            }
            distancer = distancer < -30 ? 10 : distancer;
        }
        newMap[i] = newLine;
        lastLine = newLine;
        cellThresholdLastLine = cellThreshold;
    }
    return newMap;
}

//fonction pour demander a l'usager si il veut commencer une nouvelle partie
string startString = "Voulez-vous débuter un nouveau Protazoid? o pour débuter.";
int longestString = startString.size();
bool displayStartGame()
{
    string spaces = spaceString(startString.size());
    char userStart = -1;
    while (userStart != 'o' && userStart != 'O' && userStart != 'n' && userStart != 'N')
    {
        moveCursor(vSize / 2 + logo.size() / 2 + 1, hSize / 2 - longestString / 2 + 1);
        cout << spaces;
        moveCursor(vSize / 2 + logo.size() / 2 + 2, hSize / 2 - longestString / 2 + 1);
        cout << spaces;
        moveCursor(vSize / 2 + logo.size() / 2 + 3, hSize / 2 - longestString / 2 + 1);
        cout << spaces;
        if (userStart != -1)
        {
            moveCursor(vSize / 2 + logo.size() / 2 + 1, hSize / 2 - longestString / 2 + 1);
            cout << "Je n'ai pas compris, pouvez-vous répéter? ";
        }
        moveCursor(vSize / 2 + logo.size() / 2 + 2, hSize / 2 - longestString / 2 + 2);
        cout << "Voulez-vous débuter un nouveau Protazoid? o pour débuter.";
        moveCursor(vSize / 2 + logo.size() / 2 + 3, hSize / 2 - longestString / 2 + 2);
        cin >> userStart;
        clearCin();
    }
    moveCursor(vSize / 2 + logo.size() / 2 + 2, hSize / 2 - longestString / 2 + 1);
    cout << spaces;
    bool startGame = userStart == 'o' || userStart == 'O' ? true : false;
    return startGame;
}

string enterName()
{
    string startName = "En tant que Protazoid, quel sera votre nom?";
    string spaces = spaceString(longestString);
    moveCursor(vSize / 2 + logo.size() / 2 + 1, hSize / 2 - longestString / 2 + 1);
    cout << spaces;
    moveCursor(vSize / 2 + logo.size() / 2 + 2, hSize / 2 - longestString / 2 + 1);
    cout << spaces;
    moveCursor(vSize / 2 + logo.size() / 2 + 3, hSize / 2 - longestString / 2 + 1);
    cout << spaces;

    moveCursor(vSize / 2 + logo.size() / 2 + 2, hSize / 2 - startName.size() / 2 + 2);
    cout << startName;
    string testName = "";
    moveCursor(vSize / 2 + logo.size() / 2 + 3, hSize / 2 - startName.size() / 2 + 2);
    cin >> testName;
    clearCin();
    return testName;
}

//fonction pour que l'usager entre et valide le nom
void startNameValidation() {
    bool nameIsGood = false;
    while (!nameIsGood)
    {
        string testName = enterName();
        string startNameFinalValidate = "Votre Protazoid se nomme bien " + testName + "? Tappez o pour oui.";
        longestString = startNameFinalValidate.size() > longestString ? startNameFinalValidate.size() : longestString;
        string spaces = spaceString(startNameFinalValidate.size());

        moveCursor(vSize / 2 + logo.size() / 2 + 1, hSize / 2 - longestString / 2 + 1);
        cout << spaces;
        moveCursor(vSize / 2 + logo.size() / 2 + 2, hSize / 2 - longestString / 2 + 1);
        cout << spaces;
        moveCursor(vSize / 2 + logo.size() / 2 + 3, hSize / 2 - longestString / 2 + 1);
        cout << spaces;


        char validateName;
        moveCursor(vSize / 2 + logo.size() / 2 + 2, hSize / 2 - longestString / 2 + 2);
        cout << startNameFinalValidate;
        moveCursor(vSize / 2 + logo.size() / 2 + 3, hSize / 2 - longestString / 2 + 2);
        cin >> validateName;
        clearCin();
        nameIsGood = validateName == 'O' || validateName == 'o' ? true : false;
        if(nameIsGood)
            protName = testName;
    }
}

//fonction pour afficher l'intro
void displayIntro(int framesPlayed, bool skipIntro)
{
    for (int i = 0; i < framesPlayed; ++i)
    {
        if (i == 0 || (i > 0 && !skipIntro) || i == framesPlayed - 1)
        {
            cout << "\x1b[48;5;234m" << "\x1b[38;5;76m";//couleur fonctionne juste pour l'intro
            moveCursor(1, 1);
            cout << frames[i];

            int longest = 0;
            string introLine1 = "Au tout début des temps, avant la naissance des continents et des mammifères terrestres, il n'y avait qu'océan.";
            longest = introLine1.size() > longest ? introLine1.size() : longest;
            string introLine2 = "Immense, profond et périlleux il était. Un combat de tous les instants s’y passait. La loi du plus fort y régnait.";
            longest = introLine2.size() > longest ? introLine2.size() : longest;
            string introLine3 = "Dans ce jeu vous incarnez un Protazoid, un être unicellulaire microscopique tout comme nos ancêtres lointains.";
            longest = introLine3.size() > longest ? introLine3.size() : longest;
            string introLine4 = "Et tout comme eux, votre existence sera un combat de tous les instants.";
            longest = introLine4.size() > longest ? introLine4.size() : longest;
            string introLine5 = "Comme Darwin décrit si bien \"It is not the strongest of the species that survives, nor the most intelligent; it is the one most adaptable to change.";
            longest = introLine5.size() > longest ? introLine5.size() : longest;
            string introLine6 = "Donc, accumulez des calories en dévorant ce qui vous entoure et choisissez bien votre chemin évolutif, car le futur de votre espèce est entre vos mains.";
            longest = introLine6.size() > longest ? introLine6.size() : longest;
            if (i >= 1)
            {
                moveCursor(vSize / 2 - logo.size() / 2 - 12, hSize / 2 - longest / 2);
                cout << spaceString(longest);
                moveCursor(vSize / 2 - logo.size() / 2 - 12, hSize / 2 - introLine1.size() / 2 + 1);
                cout << introLine1;
            }
            if (i >= 8)
            {
                moveCursor(vSize / 2 - logo.size() / 2 - 11, hSize / 2 - longest / 2);
                cout << spaceString(longest);
                moveCursor(vSize / 2 - logo.size() / 2 - 11, hSize / 2 - introLine2.size() / 2 + 1);
                cout << introLine2;
            }
            if (i >= 15)
            {
                moveCursor(vSize / 2 - logo.size() / 2 - 10, hSize / 2 - longest / 2);
                cout << spaceString(longest);
                moveCursor(vSize / 2 - logo.size() / 2 - 10, hSize / 2 - introLine3.size() / 2 + 1);
                cout << introLine3;
            }
            if (i >= 22)
            {
                moveCursor(vSize / 2 - logo.size() / 2 - 9, hSize / 2 - longest / 2);
                cout << spaceString(longest);
                moveCursor(vSize / 2 - logo.size() / 2 - 9, hSize / 2 - introLine4.size() / 2 + 1);
                cout << introLine4;
            }
            if (i >= 29)
            {
                moveCursor(vSize / 2 - logo.size() / 2 - 8, hSize / 2 - longest / 2);
                cout << spaceString(longest);
                moveCursor(vSize / 2 - logo.size() / 2 - 8, hSize / 2 - introLine5.size() / 2 + 1);
                cout << introLine5;
            }
            if (i >= 36)
            {
                moveCursor(vSize / 2 - logo.size() / 2 - 7, hSize / 2 - longest / 2);
                cout << spaceString(longest);
                moveCursor(vSize / 2 - logo.size() / 2 - 7, hSize / 2 - introLine6.size() / 2 + 1);
                cout << introLine6;
            }

            if (i == framesPlayed - 6)
            {
                for (int i = 0; i < logo6.size(); ++i)
                {
                    moveCursor((vSize / 2 - logo6.size() / 2) + i, hSize / 2 - logo6[0].size() / 2);
                    cout << logo6[i];
                }
            }
            if (i == framesPlayed - 5)
            {
                for (int i = 0; i < logo5.size(); ++i)
                {
                    moveCursor((vSize / 2 - logo5.size() / 2) + i, hSize / 2 - logo5[0].size() / 2);
                    cout << logo5[i];
                }
            }
            if (i == framesPlayed - 4)
            {
                for (int i = 0; i < logo4.size(); ++i)
                {
                    moveCursor((vSize / 2 - logo4.size() / 2) + i, hSize / 2 - logo4[0].size() / 2);
                    cout << logo4[i];
                }
            }
            if (i == framesPlayed - 3)
            {
                for (int i = 0; i < logo3.size(); ++i)
                {
                    moveCursor((vSize / 2 - logo3.size() / 2) + i, hSize / 2 - logo3[0].size() / 2);
                    cout << logo3[i];
                }
            }
            if (i == framesPlayed - 2)
            {
                for (int i = 0; i < logo2.size(); ++i)
                {
                    moveCursor((vSize / 2 - logo2.size() / 2) + i, hSize / 2 - logo2[0].size() / 2);
                    cout << logo2[i];
                }
            }
            if (i == framesPlayed - 1)
            {
                for (int i = 0; i < logo.size(); ++i)
                {
                    moveCursor((vSize / 2 - logo.size() / 2) + i, hSize / 2 - logo[0].size() / 2);
                    cout << logo[i];
                }
            }
            Sleep(100);
            if (i != framesPlayed - 1)
                system("cls");
        }
    }
}

bool drawProtazoid()
{
    if (protLife > 0)
    {
        //draw an idle Protazoid in the center
        int hPos = hSize / 2 - protWidth / 2;
        int vPos = vSize / 2 - protHeight / 2;

        if (protLifeMax >= 10)
        {
            for (int i = 0; i < ProtagAlarge.size(); ++i)
            {
                moveCursor(vPos + i, hPos);
                cout << ProtagAlarge[i];
            }
        }
        else if (protLifeMax > 6)
        {
            for (int i = 0; i < ProtagAmedium.size(); ++i)
            {
                moveCursor(vPos + i, hPos);
                cout << ProtagAmedium[i];
            }
        }
        else
        {
            for (int i = 0; i < ProtagAsmall.size(); ++i)
            {
                moveCursor(vPos + i, hPos);
                cout << ProtagAsmall[i];
            }
        }
    }
    else  //if prot has 0 hp, play die animation and gameover screen
    {
        --protLife;
        //play prot dying animation
        if (protLife == -1)
        {
            for (int i = 0; i < ProtagAdyingA.size(); ++i)
            {
                moveCursor(vSize / 2 - ProtagAdyingA.size() / 2 + i, hSize / 2 - ProtagAdyingA.size() / 2);
                cout << ProtagAdyingA[i];
            }
        }
        if (protLife == -2)
        {
            for (int i = 0; i < int(ProtagAdyingB.size()); ++i)
            {
                moveCursor(vSize / 2 - ProtagAdyingB.size() / 2 + i, hSize / 2 - ProtagAdyingB.size() / 2);
                cout << ProtagAdyingB[i];
            }
        }
        if (protLife == -3)
        {
            for (int i = 0; i < int(ProtagAdyingC.size()); ++i)
            {
                moveCursor(vSize / 2 - ProtagAdyingC.size() / 2 + i, hSize / 2 - ProtagAdyingC.size() / 2);
                cout << ProtagAdyingC[i];
            }
        }
        if (protLife == -4)
        {
            for (int i = 0; i < int(ProtagAdyingD.size()); ++i)
            {
                moveCursor(vSize / 2 - ProtagAdyingD.size() / 2 + i, hSize / 2 - ProtagAdyingD.size() / 2);
                cout << ProtagAdyingD[i];
            }
            for (int i = 0; i < int(logo6.size()); ++i)
            {
                moveCursor(vSize / 2 - logo6.size() - protHeight / 2, hSize/2 - logo6[1].size() / 2);
                cout << logo6[i];
            }
        }
        if (protLife == -5)
        {
            for (int i = 0; i < int(ProtagAdyingE.size()); ++i)
            {
                moveCursor(vSize / 2 - ProtagAdyingE.size() / 2 + i, hSize / 2 - ProtagAdyingE.size() / 2);
                cout << ProtagAdyingE[i];
            }
            for (int i = 0; i < int(logo5.size()); ++i)
            {
                moveCursor(vSize / 2 - logo5.size() - protHeight / 2 + i, hSize/2 - logo6[1].size() / 2);
                cout << logo5[i];
            }
        }
        if (protLife == -6)
        {
            for (int i = 0; i < int(logo4.size()); ++i)
            {
                moveCursor(vSize / 2 - logo4.size() - protHeight / 2 + i, hSize/2 - logo6[1].size() / 2);
                cout << logo4[i];
            }
        }
        if (protLife == -7)
        {
            for (int i = 0; i < int(logo3.size()); ++i)
            {
                moveCursor(vSize / 2 - logo3.size() - protHeight / 2 + i, hSize/2 - logo6[1].size() / 2);
                cout << logo3[i];
            }
        }
        if (protLife == -8)
        {
            for (int i = 0; i < int(logo2.size()); ++i)
            {
                moveCursor(vSize / 2 - logo2.size() - protHeight / 2 + i, hSize/2 - logo6[1].size() / 2);
                cout << logo2[i];
            }
        }
        if (protLife == -9)
        {
            for (int i = 0; i < int(logo.size()); ++i)
            {
                moveCursor(vSize / 2 - logo.size() - protHeight / 2 + i, hSize/2 - logo6[1].size() / 2);
                cout << logo[i];
            }
        }
    }
    //satiety goes down, if it's below 50, uses up calories to eat upto 100 satiety (10 satiety points each calorie)
    protSatiety -= 1;
    if (protSatiety < 50 && protInvQty[0] > 0)
    {
        int usedCal = protInvQty[0] < (100 - protSatiety) / 10 ? protInvQty[0] : (100 - protSatiety) / 10;
        protInvQty[0] -= usedCal;
        protSatiety += usedCal * 10;
        moveCursor(vSize / 2 - protHeight / 2 - 1, hSize / 2 - protWidth / 2 - 2);
        cout << spaceString(25);
        moveCursor(vSize / 2 - protHeight / 2 - 1, hSize / 2 - protWidth / 2 - 2);
        cout << "\x1b[48;5;11m\x1b[38;5;16m" << usedCal << " dépensés";
    }
    else if (protSatiety < 50 && protSatiety > 0 &&  protInvQty[0] == 0)
    {
        if (protSatiety > 40 || protSatiety < 5)
        {
            moveCursor(vSize / 2 - protHeight / 2 - 1, hSize / 2 - protWidth / 2 - 20);
            cout << "\x1b[48;5;11m\x1b[38;5;16m" << " Vous n'avez plus d'énergie, trouvez quelque chose à manger vite!!";
        }
    }
    else if (protSatiety <= -10)
    {
        protLife -= 1;
        moveCursor(vSize / 2 - protHeight / 2 - 1, hSize / 2 - protWidth / 2 - 20);
        cout << "\x1b[48;5;11m\x1b[38;5;16m" << "Chaque pas est de plus en plus lourd, il faut de l'énergie!! -1 Vie (" << protLife << ")";
        protSatiety = 0;
    }

    //if prot is evolving and has calories, he has to pay everything until evolution done or no calories left
    int evoluting;
    int evolutionETA = 0;
    if (protInvQty[1] > 0)
    {
        evoluting = 1;
        evolutionETA = protInvQty[1];
    }
    if (protInvQty[2] > 0)
    {
        evoluting = 2;
        evolutionETA = protInvQty[2];
    }
    if (protInvQty[3] > 0)
    {
        evoluting = 3;
        evolutionETA = protInvQty[3];
    }
    if (evolutionETA != 0)
    {
        int calUsed = protInvQty[0];
        evolutionETA -= protInvQty[0];
        if (evolutionETA <= 0)
        {
            calUsed += evolutionETA;
            if (evoluting == 1)
            {
                protLife += 1;
                protLifeMax += 1;
            }
            if (evoluting == 2)
            {
                protStrength += 1;
            }
            if (evoluting == 3)
            {
                protSpeed += 1;
            }
        }
        protInvQty[0] -= calUsed;
        protInvQty[evoluting] -= calUsed;
    }

    //if prot doesn't attack he can regenerate
    if (protLife < protLifeMax && protInvQty[0] > 0 && protRegen && protLife > 0)
    {
        protLife += 1;
        protInvQty[0] -= 1;
        moveCursor(vSize / 2 - protHeight / 2 - 2, hSize / 2 - protWidth / 2);
        cout << "\x1b[48;5;11m\x1b[38;5;16m" << "calories(" << protInvQty[0] << ") for life(" << protLife << ")";
    }

    return true;
}

array<int, 20> monstersPosition;
array<int, 10> monstersHealth;
array<int, 10> monstersStrength;

void positionMonsters()
{
    int monstersNumber = 10;
    for (int i = 0; i < monstersNumber; ++i)
    {
        int h = 1 + (rand() % lineSize);
        int v = 1 + (rand() % int(currentMap.size()));
        monstersPosition[i * 2] = h;
        monstersPosition[(i * 2) + 1] = v;
        monstersHealth[i] = 4;
        monstersStrength[i] = 3;
    }
}

void moveMonsters()
{
    int monstersNumber = 10;
    for (int i = 0; i < monstersNumber; ++i)
    {
        if (monstersHealth[i] <= 0) continue;
        int spdBoost = 1;
        if (rand() % 3 == 2) spdBoost = 5;
        if (rand() % 5 == 4)
        {
            int h = monstersPosition[i * 2];
            int v = monstersPosition[(i * 2) + 1];
            int monsterVOffset = v - int(currentMap.size())/2;
            int monsterHOffset = h - lineSize / 2;
            int moveV = monsterVOffset < vOffset ? 1 : -1;
            int moveH = monsterHOffset < hOffset ? 1 : -1;
            monstersPosition[i * 2] = h + moveH * spdBoost;
            monstersPosition[(i * 2) + 1] = v + moveV * spdBoost;
        }
        else
        {
            monstersPosition[i * 2] = monstersPosition[i * 2] + ((rand() % 3) - 1) * spdBoost;
            monstersPosition[(i * 2) + 1] = monstersPosition[(i * 2) + 1] + ((rand() % 3) - 1) * spdBoost;
        }
    }
}

void drawMonsters()
{
    for (int iMonster = 0; iMonster < 10; ++iMonster)
    {
        int h = monstersPosition[iMonster * 2];
        int v = monstersPosition[(iMonster * 2) + 1];
        int monsterVOffset = (int(currentMap.size()) / 2) - (vSize / 2);
        int monsterHOffset = (lineSize / 2) - (hSize / 2);
        int monsterStr = monstersStrength[iMonster];
        int monsterHP = monstersHealth[iMonster];
        moveCursor(1, 1);
        if (v > ((int(currentMap.size()) / 2) - (vSize / 2) + vOffset) && v < ((int(currentMap.size()) / 2) + (vSize / 2) + vOffset))
        {
            if (h > ((lineSize / 2) - (hSize / 2) + hOffset) && h < ((lineSize / 2) + (hSize / 2) + hOffset))
            {
                //determine if monster has been attacked by the protazoid
                moveCursor(3, 1);
                if (monsterHP > 0 && protLife > 0) {
                    if ((v - monsterVOffset - vOffset) > ((vSize / 2) - (protHeight / 2)) && (v - monsterVOffset - vOffset) < ((vSize / 2) + (protHeight / 2)))
                    {
                        if ((h - monsterHOffset - hOffset) > ((hSize / 2) - (protWidth / 2)) && (h - monsterHOffset - hOffset) < ((hSize / 2) + (protWidth / 2)))
                        {
                            moveCursor(vSize / 2 - protHeight / 2 - 2, hSize / 2 - protWidth / 2);
                            int protAttack = (protStrength + 1) + rand() % 6;
                            int monsterAttack = (monsterStr + 1) + rand() % 6;
                            if (protAttack >= monsterAttack)
                            {
                                monsterHP -= 1;
                                monstersHealth[iMonster] = monsterHP;
                                string hit = string("\x1b[48;5;11m\x1b[38;5;16m") + "Bang!! (" + to_string(monsterHP) + ")";
                                string win = string("\x1b[48;5;11m\x1b[38;5;16m") + "Miam!! (" + to_string(monsterHP) + ")";
                                string attackresult = monsterHP <= 0 ? win : hit;
                                cout << attackresult;
                            }
                            else
                            {
                                protLife -= 1;
                                cout << "\x1b[48;5;160m\x1b[38;5;15m" << "Ouch!! (" << protLife << ")";
                            }
                            protRegen = false;
                        }
                    }
                }

                if(monsterHP > 0)
                {
                    for (int i = 0; i < monsterAbig.size(); ++i)
                    {
                        moveCursor(v + i - monsterVOffset - vOffset, h - monsterHOffset - hOffset);
                        cout << monsterAbig[i];
                    }
                }
                else
                {
                    monstersHealth[iMonster] = monsterHP - 1;
                    if (monstersHealth[iMonster] == -1)
                    {
                        protInvQty[0] += 15;
                        moveCursor(vSize / 2 - protHeight / 2 - 3, hSize / 2 - protWidth/2 + 2);
                        cout << "\x1b[48;5;11m\x1b[38;5;16m" << "Mmmmm!! +15!!! (" << protInvQty[0] << ")";
                        for (int i = 0; i < int(monsterAsmall.size()); ++i)
                        {
                            moveCursor(v + i - monsterVOffset - vOffset, h - monsterHOffset - hOffset);
                            cout << monsterAsmall[i];
                        }
                    }
                    if (monstersHealth[iMonster] == -2)
                    {
                        moveCursor(vSize / 2 - protHeight / 2 - 3, hSize / 2 - protWidth / 2 + 2);
                        cout << "\x1b[48;5;11m\x1b[38;5;16m" << "Mmmmm!! +15!! (" << protInvQty[0] << ")";
                        for (int i = 0; i < int(monsterAdyingA.size()); ++i)
                        {
                            moveCursor(v + i - monsterVOffset - vOffset, h - monsterHOffset - hOffset);
                            cout << monsterAdyingA[i];
                        }
                    }
                    if (monstersHealth[iMonster] == -3)
                    {
                        moveCursor(vSize / 2 - protHeight / 2 - 3, hSize / 2 - protWidth / 2 + 1);
                        cout << "\x1b[48;5;11m\x1b[38;5;16m" << "Mmmmm!! +15! (" << protInvQty[0] << ")";
                        for (int i = 0; i < int(monsterAdyingB.size()); ++i)
                        {
                            moveCursor(v + i - monsterVOffset - vOffset, h - monsterHOffset - hOffset);
                            cout << monsterAdyingB[i];
                        }
                    }
                    if (monstersHealth[iMonster] == -4)
                    {
                        for (int i = 0; i < int(monsterAdyingC.size()); ++i)
                        {
                            moveCursor(v + i - monsterVOffset - vOffset, h - monsterHOffset - hOffset);
                            cout << monsterAdyingC[i];
                        }
                    }
                }
            }
        }
    }
}

int blobsNumber = 25 + (rand() % 26);
array<int, 100> blobsPosition;
void positionBlobs()
{
    for (int i = 0; i < blobsNumber; ++i)
    {
        int h = rand() % lineSize;
        int v = rand() % currentMap.size();
        blobsPosition[i * 2] = h;
        blobsPosition[(i * 2) + 1] = v;
    }
}

array<int, 50> blobsSizes;
void sizeBlobs()
{
    for (int i = 0; i < blobsNumber; ++i)
    {
        int randomSize = rand() % 6;
        blobsSizes[i] = randomSize;
    }
}

void addBlobs()
{
    int numberAdded = 5 + rand() % 6;
    for (int i = 0; i < 50; ++i)
    {
        int h = blobsPosition[i * 2];
        int v = blobsPosition[(i * 2) + 1];
        if (h == 0 && v == 0)
        {
            int h = rand() % lineSize;
            int v = rand() % currentMap.size();
            blobsPosition[i * 2] = h;
            blobsPosition[(i * 2) + 1] = v;
            int randomSize = rand() % 6;
            blobsSizes[i] = randomSize;
            numberAdded -= 1;
        }
        if (numberAdded <= 0) continue;
    }
}

void drawBlobs()
{
    for (int i = 0; i < 50; ++i)
    {
        int randomSize = rand() % 6;
        int h = blobsPosition[i * 2];
        int v = blobsPosition[(i * 2) + 1];
        if (h == 0 && v == 0) continue;

        int blobVOffset = (int(currentMap.size()) / 2) - (vSize / 2);
        int blobHOffset = (lineSize / 2) - (hSize / 2);
        moveCursor(2 + i, 1);
        if (v > ((int(currentMap.size()) / 2) - (vSize / 2) + vOffset) && v < ((int(currentMap.size()) / 2) + (vSize / 2) + vOffset))
        {
            if (h > ((lineSize / 2) - (hSize / 2) + hOffset) && h < ((lineSize / 2) + (hSize / 2) + hOffset))
            {
                //determine if blob has been eaten by the protazoid
                if ((v - blobVOffset - vOffset) > ((vSize / 2) - (protHeight / 2)) && (v - blobVOffset - vOffset) < ((vSize / 2) + (protHeight / 2)))
                {
                    if ((h - blobHOffset - hOffset) > ((hSize / 2) - (protWidth / 2)) && (h - blobHOffset - hOffset) < ((hSize / 2) + (protWidth / 2)))
                    {
                        blobsPosition[i * 2] = 0;
                        blobsPosition[(i * 2) + 1] = 0;
                        int blobWorth = blobsSizes[i];
                        moveCursor(vSize / 2 - protHeight / 2 - 2, hSize / 2 - protWidth / 2);
                        protInvQty[0] += blobWorth + 1;
                        cout << "\x1b[48;5;11m\x1b[38;5;16m" << "Slurp!! +" << (blobWorth + 1) << " (" << protInvQty[0] << ")";
                    }
                    else
                    {
                        for (int iLine = 0; iLine < 2; ++iLine)
                        {
                            moveCursor(v + iLine - blobVOffset - vOffset, h - blobHOffset - hOffset);
                            switch (blobsSizes[i])
                            {
                            case 0:
                            case 1:
                            case 2:
                                cout << BlobASmall[iLine];
                                break;
                            case 3:
                            case 4:
                                cout << BlobBSmall[iLine];
                                break;
                            case 5:
                                cout << BlobAmedium[iLine];
                                break;
                            }
                        }
                    }
                }
                else
                {
                    for (int iLine = 0; iLine < 2; ++iLine)
                    {
                        moveCursor(v + iLine - blobVOffset - vOffset, h - blobHOffset - hOffset);
                        switch (blobsSizes[i])
                        {
                        case 0:
                        case 1:
                        case 2:
                            cout << BlobASmall[iLine];
                            break;
                        case 3:
                        case 4:
                            cout << BlobBSmall[iLine];
                            break;
                        case 5:
                            cout << BlobAmedium[iLine];
                            break;
                        }
                    }
                }
            }
        }
    }
}

void drawBoss()
{
    int vBoss = 20;
    int hBoss = 360;
    int bossVOffset = (int(currentMap.size()) / 2) - (vSize / 2);
    int bossHOffset = (lineSize / 2) - (hSize / 2);
    if (vBoss > ((int(currentMap.size()) / 2) - (vSize / 2) + vOffset) && vBoss < ((int(currentMap.size()) / 2) + (vSize / 2) + vOffset))
    {
        if (hBoss > ((lineSize / 2) - (hSize / 2) + hOffset) && hBoss < ((lineSize / 2) + (hSize / 2) + hOffset))
        {
            for (int i = 0; i < boss.size(); ++i)
            {
                moveCursor(vBoss + i - bossVOffset - vOffset, hBoss - bossHOffset - hOffset);
                cout << boss[i];
            }
        }
    }
}

void bossBattle()
{

}

bool drawMap(char& nextMove)
{
    if (int(nextMove) == 27) {
        int longest = 0;
        string quitLine1 = "Quitter maintenant signifie la fin de votre espèce, j'espère que vous en êtes conscient.";
        longest = quitLine1.size() > longest ? quitLine1.size() : longest;
        string quitLine2 = "Si oui, merci d'avoir joué! Appuyer sur o suivi de Entrer pour confirmer.";
        longest = quitLine2.size() > longest ? quitLine2.size() : longest;
        moveCursor(vSize / 2 - 1, hSize / 2 - longest / 2);
        cout << spaceString(longest);
        moveCursor(vSize / 2 - 1, hSize / 2 - quitLine1.size() / 2);
        cout << "\x1b[48;5;234m\x1b[38;5;11m" << quitLine1;
        moveCursor(vSize / 2, hSize / 2 - longest / 2);
        cout << spaceString(longest);
        moveCursor(vSize / 2, hSize / 2 - quitLine2.size() / 2);
        cout << "\x1b[48;5;234m\x1b[38;5;11m" << quitLine2;
        char confirmQuit;
        cin >> confirmQuit;
        if (int(confirmQuit) == 'o')
        {
            userQuit = true;
            return 0;
        }
    }
    bool protInvWasOpen = protInvOpen;
    if (nextMove != 'i' && nextMove != 'I')
    {
        int firstLine = ((int(currentMap.size()) / 2) - int((vSize) / 2));
        vOffset += nextMove == 'w' ? -(protSpeed) : (nextMove == 's' ? protSpeed : 0);
        hOffset += nextMove == 'a' ? -(protSpeed) : (nextMove == 'd' ? protSpeed : 0);
        system("cls");
        //cout << int(nextMove);
        cout << "\x1b[48;5;234m" << "\x1b[38;5;76m";  //Ici pour mettre couleur carte et le reste du jeux.

        for (int imap = ((int(currentMap.size()) / 2) - (vSize / 2)) + vOffset; imap < ((int(currentMap.size()) / 2) + (vSize / 2)) + vOffset; ++imap)
        {
            string line;
            if (imap < 0 || imap >= int(currentMap.size()) - 1)
                line = spaceString(lineSize);
            else
                line = currentMap[imap];
            string newLine;
            for (int iLine = 0; iLine < hSize; ++iLine)
            {
                if (((int(line.size()) / 2) - (hSize / 2) + iLine + hOffset) < 0 || ((int(line.size()) / 2) - (hSize / 2) + iLine + hOffset) > int(line.size()) - 1)
                    newLine += ' ';
                else
                    newLine += line[(int(line.size()) / 2) - (hSize / 2) + iLine + hOffset];
            }
            cout << newLine << endl;
        }
    }
    if(rand() % 5 == 4) addBlobs();
    drawBlobs();
    moveMonsters();
    drawMonsters();
    drawBoss();
    if (nextMove == 'i' || nextMove == 'I' || protInvOpen)
    {
        for (int i = 0; i < Inventory.size(); ++i)
        {
            moveCursor(12 + i, 16);
            cout << Inventory[i];
        }
        moveCursor(12 + 7, 16 + 25);
        cout << protLife << " / " << protLifeMax;
        moveCursor(12 + 9, 16 + 25);
        cout << protStrength;
        moveCursor(12 + 11, 16 + 25);
        cout << protSpeed;
        moveCursor(12 + 13, 16 + 25);
        cout << protInvQty[0];
        string evoluting;
        int evolutionETA = 0;
        if (protInvQty[1] > 0)
        {
            evoluting = "Vie";
            evolutionETA = protInvQty[1];
        }
        if (protInvQty[2] > 0)
        {
            evoluting = "Force";
            evolutionETA = protInvQty[2];
        }
        if (protInvQty[3] > 0)
        {
            evoluting = "Vitesse";
            evolutionETA = protInvQty[3];
        }
        if (evolutionETA != 0)
        {
            moveCursor(12 + 7, 16 + 25 + 29 - evoluting.size());
            cout << evoluting;
            string evoCalories = to_string(evolutionETA) + " calories à trouver";
            moveCursor(12 + 8, 16 + 17 + evoCalories.size());
            cout << evoCalories;
        }
        protInvOpen = true;
    }
    if ((nextMove == '1' || nextMove == '2' || nextMove == '3') && protInvOpen && protInvQty[0] < 5)
    {
        moveCursor(12 + 18, 16 + 1);
        cout << "Vous n'avez pas assez de calories pour acheter une évolution.";
    }

    if ((nextMove == '1' || nextMove == '2' || nextMove == '3') && protInvOpen && protInvQty[0] >= 5)
    {
        moveCursor(12 + 18, 16 + 4);
        cout << "Voulez-vous achetez une évolution de ";
        if (nextMove == '1')
        {
            cout << "Vie?";
            moveCursor(12 + 19, 16 + 4);
            cout << "Appuyez sur o pour oui suivi de la touche Entrer.";
        }
        if (nextMove == '2')
        {
            cout << "Vitesse?";
            moveCursor(12 + 19, 16 + 4);
            cout << "Appuyez sur o pour oui suivi de la touche Entrer.";
        }
        if (nextMove == '3')
        {
            cout << "Force?";
            moveCursor(12 + 19, 16 + 4);
            cout << "Appuyez sur o pour oui suivi de la touche Entrer.";
        }
        char buyValidate;
        cin >> buyValidate;
        if (buyValidate == 'o' || buyValidate == 'O')
        {
            protInvQty[0] -= 5;
            if (nextMove == '1')
                protInvQty[1] += 10*protLifeMax;
            if (nextMove == '2')
                protInvQty[3] += 10*protSpeed;
            if (nextMove == '3')
                protInvQty[2] += 10*protStrength;
            protInvOpen = false;
        }
    }
    if((nextMove == '1' || nextMove == '2' || nextMove == '3') && protInvQty[0] >= 5)
    {
        protInvOpen = false;
        //add call drawmap to refresh
    }
    if ((nextMove == 'w' || nextMove == 'a' || nextMove == 's' || nextMove == 'd') && protInvOpen)
    {
        protInvOpen = false;
        //add call drawmap to refresh
    }
    if (!protInvOpen && protInvWasOpen)
    {
        char refreshMap= 'r';
        drawMap(refreshMap);
    }
    return true;
}

int main()
{
    
#if _WIN32 || _WIN64
    system("chcp 65001");
    system("cls");
#endif
    srand(time(0));
    //calibration de l'écran d'affichage
    calibrateScreen();

    //positionnement et initialisation des acteurs
    positionBlobs();
    sizeBlobs();
    positionMonsters();
    currentMap = buildRandomMap();

    cout << "Appuyez sur S pour skipper l'intro ou une autre touche pour le voir et appuyez sur Entrée.\n";
    bool skipIntro = false;
    char userSkip;
    cin >> userSkip;
    clearCin();
    if (userSkip == 'S' || userSkip == 's')
        skipIntro = true;

    //intro
    displayIntro(50, skipIntro);

    bool startGame = displayStartGame();

    //variables utilisées pour le protazoid
    array<string, 1> monsterTable = {}; //18x8
    array<string, 10> blobTable = {}; //2x2 blobs
    string envColor = ESC + Green;


    //boucle de jeu principale
    while (startGame)
    {
        //création du personnage, choix: mouvement, points de vie, force; plus tard: type du protazoid
        //4 points a répartir comme on veut entre les 3 choix
        //minimum de 2 dans chacune des caractéristiques, 1 point équivaut à 1 de plus dans la caractéristique

        startNameValidation();

        //boucle pour que l'usager valide les points de caractéristiques de son protazoid
        bool pointsAreGood = false;
        int pointsLeft;
        while (!pointsAreGood)
        {
            pointsLeft = 4;
            protLife = 2;
            protSpeed = 2;
            protStrength = 2;

            string longestString = "Entrez le nombre de points que vous voulez ajouter à la Vitesse de votre Protazoid: (points restants  )";
            string spaces = spaceString(longestString.size());

            addSpacing(9, logo.size(), longestString.size());

            moveCursor(vSize / 2 + logo.size() / 2 + 2, hSize / 2 - longestString.size() / 2 + 2);
            cout << "Points de caractéristique de " << protName;
            moveCursor(vSize / 2 + logo.size() / 2 + 3, hSize / 2 - longestString.size() / 2 + 2);
            cout << ">Vie: " << setw(3) << protLife;
            moveCursor(vSize / 2 + logo.size() / 2 + 4, hSize / 2 - longestString.size() / 2 + 3);
            cout << "Vitesse: " << setw(3) << protSpeed;
            moveCursor(vSize / 2 + logo.size() / 2 + 5, hSize / 2 - longestString.size() / 2 + 3);
            cout << "Force: " << setw(3) << protStrength;

            char usePoints = '|';
            while (int(usePoints) < int('0') || int(usePoints) > int('0'+pointsLeft))
            {
                moveCursor(vSize / 2 + logo.size() / 2 + 7, hSize / 2 - longestString.size() / 2 + 1);
                cout << spaces;
                moveCursor(vSize / 2 + logo.size() / 2 + 7, hSize / 2 - longestString.size() / 2 + 2);
                cout << "Entrez le nombre de points que vous voulez ajouter à la Vie de votre Protazoid: (points restants " << pointsLeft << ")";
                moveCursor(vSize / 2 + logo.size() / 2 + 8, hSize / 2 - longestString.size() / 2 + 2);
                if (int(usePoints) != char('|'))
                {
                    moveCursor(vSize / 2 + logo.size() / 2 + 8, hSize / 2 - longestString.size() / 2 + 2);
                    cout << spaces;
                    moveCursor(vSize / 2 + logo.size() / 2 + 8, hSize / 2 - longestString.size() / 2 + 1);
                    cout << "Entrée invalide, utilisez vos points restants.";
                }
                cin >> usePoints;
                clearCin();
            }
            int pointsUsed;
            switch (int(usePoints))
            {
                case int('0') :
                    pointsUsed = 0;
                    break;
                case int('1') :
                    pointsUsed = 1;
                    break;
                case int('2') :
                    pointsUsed = 2;
                    break;
                case int('3') :
                    pointsUsed = 3;
                    break;
                case int('4') :
                    pointsUsed = 4;
                    break;
            }
            pointsLeft -= pointsUsed;
            protLife += pointsUsed;

            addSpacing(9, logo.size(), longestString.size());

            moveCursor(vSize / 2 + logo.size() / 2 + 2, hSize / 2 - longestString.size() / 2 + 2);
            cout << "Points de caractéristique de " << protName;
            moveCursor(vSize / 2 + logo.size() / 2 + 3, hSize / 2 - longestString.size() / 2 + 3);
            cout << "Vie: " << setw(3) << protLife;
            moveCursor(vSize / 2 + logo.size() / 2 + 4, hSize / 2 - longestString.size() / 2 + 2);
            cout << ">Vitesse: " << setw(3) << protSpeed;
            moveCursor(vSize / 2 + logo.size() / 2 + 5, hSize / 2 - longestString.size() / 2 + 3);
            cout << "Force: " << setw(3) << protStrength;
            
            usePoints = '|';
            while (int(usePoints) < int('0') || int(usePoints) > int('0'+pointsLeft))
            {
                moveCursor(vSize / 2 + logo.size() / 2 + 7, hSize / 2 - longestString.size() / 2 + 1);
                cout << spaces;
                moveCursor(vSize / 2 + logo.size() / 2 + 7, hSize / 2 - longestString.size() / 2 + 2);
                cout << "Entrez le nombre de points que vous voulez ajouter à la Vitesse de votre Protazoid: (points restants " << pointsLeft << ")";
                moveCursor(vSize / 2 + logo.size() / 2 + 8, hSize / 2 - longestString.size() / 2 + 2);
                if (int(usePoints) != char('|'))
                {
                    moveCursor(vSize / 2 + logo.size() / 2 + 8, hSize / 2 - longestString.size() / 2 + 2);
                    cout << spaces;
                    moveCursor(vSize / 2 + logo.size() / 2 + 8, hSize / 2 - longestString.size() / 2 + 1);
                    cout << "Entrée invalide, utilisez vos points restants.";
                }
                cin >> usePoints;
                clearCin();
            }
            pointsUsed = NULL;
            switch (int(usePoints))
            {
                case int('0') :
                    pointsUsed = 0;
                    break;
                case int('1') :
                    pointsUsed = 1;
                    break;
                case int('2') :
                    pointsUsed = 2;
                    break;
                case int('3') :
                    pointsUsed = 3;
                    break;
                case int('4') :
                    pointsUsed = 4;
                    break;
            }
            pointsLeft -= pointsUsed;
            protSpeed += pointsUsed;

            //Strength
            addSpacing(9, logo.size(), longestString.size());

            moveCursor(vSize / 2 + logo.size() / 2 + 2, hSize / 2 - longestString.size() / 2 + 2);
            cout << "Points de caractéristique de " << protName;
            moveCursor(vSize / 2 + logo.size() / 2 + 3, hSize / 2 - longestString.size() / 2 + 3);
            cout << "Vie: " << setw(3) << protLife;
            moveCursor(vSize / 2 + logo.size() / 2 + 4, hSize / 2 - longestString.size() / 2 + 3);
            cout << "Vitesse: " << setw(3) << protSpeed;
            moveCursor(vSize / 2 + logo.size() / 2 + 5, hSize / 2 - longestString.size() / 2 + 2);
            cout << ">Force: " << setw(3) << protStrength;
            
            usePoints = '|';
            while (int(usePoints) < int('0') || int(usePoints) > int('0'+pointsLeft))
            {
                moveCursor(vSize / 2 + logo.size() / 2 + 7, hSize / 2 - longestString.size() / 2 + 1);
                cout << spaces;
                moveCursor(vSize / 2 + logo.size() / 2 + 7, hSize / 2 - longestString.size() / 2 + 2);
                cout << "Entrez le nombre de points que vous voulez ajouter à la Force de votre Protazoid: (points restants " << pointsLeft << ")";
                moveCursor(vSize / 2 + logo.size() / 2 + 8, hSize / 2 - longestString.size() / 2 + 2);
                if (int(usePoints) != char('|'))
                {
                    moveCursor(vSize / 2 + logo.size() / 2 + 8, hSize / 2 - longestString.size() / 2 + 2);
                    cout << spaces;
                    moveCursor(vSize / 2 + logo.size() / 2 + 8, hSize / 2 - longestString.size() / 2 + 1);
                    cout << "Entrée invalide, utilisez vos points restants.";
                }
                cin >> usePoints;
                clearCin();
            }
            pointsUsed = NULL;
            switch (int(usePoints))
            {
                case int('0') :
                    pointsUsed = 0;
                    break;
                case int('1') :
                    pointsUsed = 1;
                    break;
                case int('2') :
                    pointsUsed = 2;
                    break;
                case int('3') :
                    pointsUsed = 3;
                    break;
                case int('4') :
                    pointsUsed = 4;
                    break;
            }
            pointsLeft -= pointsUsed;
            protStrength += pointsUsed;
            
            addSpacing(9, logo.size(), longestString.size());

            moveCursor(vSize / 2 + logo.size() / 2 + 2, hSize / 2 - longestString.size() / 2 + 2);
            cout << "Points de caractéristique de " << protName;
            moveCursor(vSize / 2 + logo.size() / 2 + 3, hSize / 2 - longestString.size() / 2 + 3);
            cout << "Vie: " << setw(3) << protLife;
            moveCursor(vSize / 2 + logo.size() / 2 + 4, hSize / 2 - longestString.size() / 2 + 3);
            cout << "Vitesse: " << setw(3) << protSpeed;
            moveCursor(vSize / 2 + logo.size() / 2 + 5, hSize / 2 - longestString.size() / 2 + 3);
            cout << "Force: " << setw(3) << protStrength;

            char validCarac;
            moveCursor(vSize / 2 + logo.size() / 2 + 7, hSize / 2 - longestString.size() / 2 + 2);
            cout << "Est-ce que les caractéristique de votre Protazoid vous conviennent? o pour oui.";
            moveCursor(vSize / 2 + logo.size() / 2 + 8, hSize / 2 - longestString.size() / 2 + 2);
            cin >> validCarac;
            clearCin();
            pointsAreGood = validCarac == 'o' || validCarac == 'O' ? true : false;
        }
        protLifeMax = protLife;

        bool inMap = true;
        while (inMap)
        {
            protRegen = true;
            drawMap(nextMove);
            if (userQuit) break;
            inMap = drawProtazoid();
            if (protLife > 0)
            {
                cout << ESC + (to_string(vSize + 1) + ";1H");
                cout << "\x1b[48;5;234m\x1b[38;5;11m" << "w,a,s,d pour faire vous déplacer, i pour ouvrir l'inventaire. Pour quitter, appuyez sur la touche ESCAPE." << "\x1b[0m\x1b[48;5;234m";
                nextMove = _getch();
            }
            else if(protLife <= 0 && protLife > -9)
            {
                nextMove = 'r';
                Sleep(250);
            }
            else
            {
                char restart;
                string gameOverLine1 = "Vous êtes mort.";
                string gameOverLine2 = "L'histoire de votre espèce se termine ici, meilleure chance à la prochaine incarnation.";
                string gameOverLine3 = "Appuyez sur q pour quitter Protozoa ou r pour renaître.";
                moveCursor(vSize / 2 - 2, hSize / 2 - gameOverLine1.size() / 2);
                cout << "\x1b[48;5;234m\x1b[38;5;11m" << gameOverLine1;
                Sleep(1000);
                moveCursor(vSize / 2 - 2 + 1, hSize / 2 - gameOverLine2.size() / 2);
                cout << "\x1b[48;5;234m\x1b[38;5;11m" << gameOverLine2;
                Sleep(1000);
                moveCursor(vSize / 2 - 2 + 2, hSize / 2 - gameOverLine3.size() / 2);
                cout << "\x1b[48;5;234m\x1b[38;5;11m" << gameOverLine3;
                Sleep(1000);
                restart = _getch();
                if (restart == 'q' || restart == 'Q')
                    inMap = false;
            }
        }

        startGame = false;
    }
    
    return 0;
}