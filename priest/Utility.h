#include <random>
#include <string>
#include <sstream>

void swap(int &x, int &y) {
  x ^= y;
  y ^= x;
  x ^= y;
}

int rollDie(int faces) {
  return (rand() % (faces)+1);
}

std::string itos(int input) {
  std::stringstream ss;
  ss << input;
  return ss.str();
}

std::string statString(int* stats) {
  return  itos(stats[STR]) + "\n" + itos(stats[INT]) + "\n" + itos(stats[WIS]) + "\n" + itos(stats[DEX]) + "\n" +
    itos(stats[CON]) + "\n" + itos(stats[CHA]) + "\n\n" + itos(stats[HP_CUR]) + "\\" + itos(stats[HP_MAX]);
}