#include "Player.h"
//extern int rollStat();
extern int rollDie(int faces);
extern void swap(int &x, int &y);

Player::Player() {
  stats[STR] = rollStat();
  stats[INT] = rollStat();
  stats[WIS] = rollStat();
  stats[DEX] = rollStat();
  stats[CON] = rollStat();
  stats[CHA] = rollStat();
  stats[HP_MAX] = stats[CON] + rollDie(stats[CON]);
  stats[HP_CUR] = stats[HP_MAX];
}

int Player::rollStat() {
  int rolls[] = { rollDie(6), rollDie(6), rollDie(6), rollDie(6) };
  printf("%d %d %d %d\n", rolls[0], rolls[1], rolls[2], rolls[3]);

  int keep[] = { rolls[0], rolls[1], rolls[2] };
  for(int x = 0; x < 3; ++x) {
    if(rolls[3] > keep[x]) {
      swap(rolls[3], keep[x]);
    }
  }
  printf("%d %d %d\n", keep[0], keep[1], keep[2]);
  return keep[0] + keep[1] + keep[2];
}