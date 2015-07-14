#include "header.h"

class Slot
{
private:
  char reels[4];
  char symbols[4];
  int bank;
  int bet;
  int stack;
  int counter;

public:
  Slot() : bet(0), stack(0), bank(0), counter(0) { for (int i = 0; i < 4; i++) symbols[i] = 3; };

  void startMenu();
  void GameMenu();
  int Queue();
  void CreatingCombinations();
  void PrintSlot();

  ~Slot(){};
};
