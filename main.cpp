#include <iostream>
#include <string>
#include <random>
#include <ctime>
#include <thread>

using std::cout;
using std::endl;
using std::cin;

void sleep (int timeSeconds)
{
  std::this_thread::sleep_for(std::chrono::seconds(timeSeconds));
}


int launchSettings() {
  // partie paramettre
  int tentative = 0;
   std::system("cls");
  cout << "Bienvenue sur le jeu du nombre mystère !" << endl;
  cout << "Les règles sont simples, vous devez trouver le nombre\nqui est généré au hasard tel le Juste Prix !" << endl;
  cout << "======" << endl;
  cout << "SETTINGS :" << endl;
  cout << "Nombre de tentative possible : ";
  cin >> tentative;
  std::system("cls");
  cout << "Le jeu démarre dans 5 secondes !";
  sleep(5);
  std::system("cls");


  return tentative;
}


// jeu du nombre mystère
int main()
{
  std::srand((std::time(nullptr)) / 2 * std::time(nullptr) * 10 + 5);
  int tentative = launchSettings();




  int numberMystere = std::rand() % 1000;

  int entryNumberConsole = 0;
  bool hasError = false;
  while (entryNumberConsole != numberMystere) {
    if (hasError) {
      cout << endl;
      cout << "====== ERROR =====" << endl;
      cout << "Le chiffre n'est pas celui qui à été généré !" << endl;
      cout << "Il vous reste " << tentative << " tentative(s) !" << endl;
      cout << endl;
      cout << "Nombre proposé : " << entryNumberConsole << endl;
      cout << endl;
      cout << "==================" << endl;
      cout << endl;
    }


    cout << "Veuillez entrer un nombre : ";
    cin >> entryNumberConsole;
    std::system("cls");

    if(entryNumberConsole != numberMystere) {
      hasError = true;
      if (tentative <= 1) {
        break;
      } else {
        tentative--;
        if (entryNumberConsole < numberMystere) {
          cout << "=======" << endl;
          cout << "Le chiffre est plus grand !" << endl;
          cout << "=======" << endl;;
        } else {
          cout << "=======" << endl;
          cout << "Le chiffre est plus petit !" << endl;
          cout << "=======" << endl;;
        }
      }

    } else {
      hasError = false;
      break;
    }
  }

  if (hasError)
  {
    cout << "Vous avez malheureseument perdu ! Le chiffre mystère étais : " << numberMystere << endl;
  } else {
    cout << endl;
    cout << "Bravo ! Vous avez trouvé le nombre mystère en " << tentative << " tentative(s)" << endl;
  }


  return 0;
}
