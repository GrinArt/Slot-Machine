#include "Slot.h"

void Slot::startMenu()
{
  bank = 0;
  int select = -1;

  system("cls");

  cout << "\n\n\t[1] Game" << endl;
  cout << "\n\t[2] Exit\n\t ";

  while (select < '1' || select > '2') select = _getch();

  if (select == '1') GameMenu();
  else exit(0);
}

void Slot::GameMenu()
{
  int select = -1;

  do
  {
    if (select == 'a' && bank < 1000) bank += 50;
    if (select == 72 && bank >= 5) { bet += 5; bank -= 5; }
    if (select == 80 && bet >= 5) { bet -= 5; bank += 5; }

    stack = bet;

    PrintSlot();

    if (select == 13 && bet > 0)
    {
      bet = 0;

      CreatingCombinations();
      PrintSlot();

      if ( (reels[0] == reels[1]) && (reels[2] == reels[3]) && (reels[1] == reels[2]) && (reels[0] == reels[3]) )
      {
        bank += stack + stack;
        stack = 0;
      }
      PrintSlot();
    }

    select = -1;
    while (select != 27 && select != 'a' && select != 72 && select != 80 && select != 13) select = _getch();

  } while (select != 27);

  startMenu();
}

int Slot::Queue()
{
  int first = symbols[0];

  for (int i = 0; i < 4; i++) symbols[i] = symbols[i + 1];
  symbols[3] = first;

  return first;
}

void Slot::CreatingCombinations()
{
  srand(time(NULL));
  int luck = rand() % (7 - 3) + 3;
  if (3 == rand() % 3 + 1) for (int i = 0; i < 4; i++) symbols[i] = luck;
  else for (int i = 0; i < 4; i++) symbols[i] = rand() % (7 - 3) + 3;
  for (int i = 0; i < 4; i++) for (int j = 0; j < rand() % 2 + 1; j++) reels[i] = Queue();
}

void Slot::PrintSlot()
{
  system("cls");

  cout << "     Bet: " << bet << "$        Bank: " << bank << "$" << endl;
  cout << "__________________________________\n\n\t    ";

  for (int i = 0; i < 4; i++)
  {
    reels[i] = symbols[i];
    cout << reels[i] << "  ";
  }

  cout << "\n\n\n\n__________________________________";
  cout << " Add $ |  + |  -   | Start | Exit" << endl;
  cout << "  [a]  | Up | Down | Enter | Esc" << endl;
  cout << "_________________________________";
}