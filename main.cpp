#include "header.h"
#include "Slot.h"

int main()
{
  system("mode 40, 12");
  chooseFont(40);

  Slot s;

  s.startMenu();

  return 0;
}