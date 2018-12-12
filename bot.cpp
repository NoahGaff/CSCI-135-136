#include <cstdlib>
#include <cmath>
#include <iostream>
#include "bot.h"
using namespace std;
const int MAX_ROWS = 40;
const int MAX_COLS = 40;
const int MAX_NUM = 10;
int ROWS;  // global variables
int COLS;
int NUM;
/* onStart:
An Initialization procedure called at the start of the game.
You can use it to initialize certain global variables, or do
something else before the actual simulation starts.
Parameters:
    rows: number of rows
    cols: number of columns
    num:  number of dwarfs
    log:  a cout-like log */
void onStart(int rows, int cols, int num, std::ostream &log) {
  log << "Start!" << endl; // Print a greeting message
  ROWS = rows; // Save values in global variables
  COLS = cols;
  NUM = num;
}
bool pineTreesLeft(Dwarf & dwarf)
{
  for(int i = 0; i < ROWS; i++)
  {
      for(int j = 0; j < COLS; j++)
      {
          if (dwarf.look(i,j) == PINE_TREE)
          {
              return true;
          }
      }
  }
  return false;
}
bool isNextToPineTree(Dwarf & dwarf)
{
    int r = dwarf.row();
    int c = dwarf.col();
    if  ( dwarf.look(r+1, c) == PINE_TREE ||
          dwarf.look(r-1, c) == PINE_TREE ||
          dwarf.look(r, c+1) == PINE_TREE ||
          dwarf.look(r, c-1) == PINE_TREE)
          { return true; }
    else { return false; }
}
void findPineTrees(Dwarf & dwarf, ostream &log)
{
    int r = dwarf.row();
    int c = dwarf.col();
    int distance, x, y;
    int distanceMin = 1000;
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            if (dwarf.look(i,j) == PINE_TREE)
            {
                distance = pow(r-i, 2) + pow(c-j,2);
                distance = sqrt(distance);
                if (distance < distanceMin)
                {
                    distanceMin = distance;
                    x = i;
                    y = j;
                }
            }
        }
    }
    if (dwarf.look(x, y+1) == EMPTY)
    {
        log << "Walk to tree at " << x << " " << y+1 << " " << endl;
        dwarf.start_walk(x, y+1);
    }
    else if (dwarf.look(x, y-1) == EMPTY) {
        log << "Walk to tree at " << x << " " << y-1 << " " << endl;
        dwarf.start_walk(x, y-1);
    }
    else if (dwarf.look(x-1, y) == EMPTY) {
        log << "Walk to tree at " << x-1 << " " << y << " " << endl;
        dwarf.start_walk(x-1, y);
    }
    else if (dwarf.look(x+1, y) == EMPTY) {
        log << "Walk to tree at " << x+1 << " " << y << " " << endl;
        dwarf.start_walk(x+1, y);
    }
    else {
    // Otherwise, move to a random location
    int rr = rand() % ROWS;
    int cc = rand() % COLS;
    log << "Walk to " << rr << " " << cc << endl;
    dwarf.start_walk(rr, cc);
    return;}
}
void cutPineTree(Dwarf & dwarf, ostream &log)
{
    int r = dwarf.row();
    int c = dwarf.col();
  // Look if there is a tree EAST from the dwarf
    if (dwarf.look(r, c+1) == PINE_TREE) {
        // If there is a pine tree, chop it
        log << "Found a tree -- chop!! " << endl;
        dwarf.start_chop(EAST);
    }
      // Look if there is a tree WEST from the dwarf
    else if (dwarf.look(r, c-1) == PINE_TREE) {
        // If there is a pine tree, chop it
        log << "Found a tree -- chop!! " << endl;
        dwarf.start_chop(WEST);
    }
      // Look if there is a tree NORTH from the dwarf
    else if (dwarf.look(r-1, c) == PINE_TREE) {
        // If there is a pine tree, chop it
        log << "Found a tree -- chop!! " << endl;
        dwarf.start_chop(NORTH);
    }
      // Look if there is a tree SOUTH from the dwarf
    else if (dwarf.look(r+1, c) == PINE_TREE) {
        // If there is a pine tree, chop it
        log << "Found a tree -- chop!! " << endl;
        dwarf.start_chop(SOUTH);
    }
    // Otherwise, move to a random location
    else {
      int rr = rand() % ROWS;
      int cc = rand() % COLS;
      log << "Walk to " << rr << " " << cc << endl;
      dwarf.start_walk(rr, cc);
      return;
    }
}
bool isNextToAppleTree(Dwarf & dwarf)
{
    int r = dwarf.row();
    int c = dwarf.col();
    if  ( dwarf.look(r+1, c) == APPLE_TREE ||
          dwarf.look(r-1, c) == APPLE_TREE ||
          dwarf.look(r, c+1) == APPLE_TREE ||
          dwarf.look(r, c-1) == APPLE_TREE)
          { return true; }
    else { return false; }
}
void findAppleTrees(Dwarf & dwarf, ostream &log)
{
    int r = dwarf.row();
    int c = dwarf.col();
    int distance, x, y;
    int distanceMin = 1000;
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            if (dwarf.look(i,j) == APPLE_TREE)
            {
                distance = pow(r-i, 2) + pow(c-j,2);
                distance = sqrt(distance);
                if (distance < distanceMin)
                {
                    distanceMin = distance;
                    x = i;
                    y = j;
                }
            }
        }
    }
    if (dwarf.look(x, y+1) == EMPTY)
    {
        log << "Walk to tree at " << x << " " << y+1 << " " << endl;
        dwarf.start_walk(x, y+1);
    }
    else if (dwarf.look(x, y-1) == EMPTY) {
        log << "Walk to tree at " << x << " " << y-1 << " " << endl;
        dwarf.start_walk(x, y-1);
    }
    else if (dwarf.look(x-1, y) == EMPTY) {
        log << "Walk to tree at " << x-1 << " " << y << " " << endl;
        dwarf.start_walk(x-1, y);
    }
    else if (dwarf.look(x+1, y) == EMPTY) {
        log << "Walk to tree at " << x+1 << " " << y << " " << endl;
        dwarf.start_walk(x+1, y);
    }
    else {
    // Otherwise, move to a random location
    int rr = rand() % ROWS;
    int cc = rand() % COLS;
    log << "Walk to " << rr << " " << cc << endl;
    dwarf.start_walk(rr, cc);
    return;}
}
bool isFortified(Dwarf & dwarf)
{
  int r = dwarf.row();
  int c = dwarf.col();
  if  ( dwarf.look(r+1, c) != EMPTY &&
        dwarf.look(r-1, c) != EMPTY &&
        dwarf.look(r, c+1) != EMPTY &&
        dwarf.look(r, c-1) != EMPTY )
        { return true; }
  else { return false; }
}
void fortify(Dwarf & dwarf)
{
  int r = dwarf.row();
  int c = dwarf.col();
  if (dwarf.look(r, c+1) == EMPTY) {
      // If there is a pine tree, chop it
      dwarf.start_build(EAST);
  }
    // Look if there is a tree WEST from the dwarf
  else if (dwarf.look(r, c-1) == EMPTY) {
      // If there is a pine tree, chop it
      dwarf.start_build(WEST);
  }
    // Look if there is a tree NORTH from the dwarf
  else if (dwarf.look(r-1, c) == EMPTY) {
      // If there is a pine tree, chop it
      dwarf.start_build(NORTH);
  }
    // Look if there is a tree SOUTH from the dwarf
  else if (dwarf.look(r+1, c) == EMPTY) {
      // If there is a pine tree, chop it
      dwarf.start_build(SOUTH);
  }
}
void findPickable(Dwarf & dwarf, ostream &log)
{
    int r = dwarf.row();
    int c = dwarf.col();
    int distance, x, y;
    int distanceMin = 1000;
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            if (dwarf.look(i,j) == PUMPKIN || dwarf.look(i,j) == APPLE_TREE)
            {
                distance = pow(r-i, 2) + pow(c-j,2);
                distance = sqrt(distance);
                if (distance < distanceMin)
                {
                    distanceMin = distance;
                    x = i;
                    y = j;
                }
            }
        }
    }
    if (dwarf.look(x, y+1) == EMPTY)
    {
        log << "Walk to tree at " << x << " " << y+1 << " " << endl;
        dwarf.start_walk(x, y+1);
    }
    else if (dwarf.look(x, y-1) == EMPTY) {
        log << "Walk to tree at " << x << " " << y-1 << " " << endl;
        dwarf.start_walk(x, y-1);
    }
    else if (dwarf.look(x-1, y) == EMPTY) {
        log << "Walk to tree at " << x-1 << " " << y << " " << endl;
        dwarf.start_walk(x-1, y);
    }
    else if (dwarf.look(x+1, y) == EMPTY) {
        log << "Walk to tree at " << x+1 << " " << y << " " << endl;
        dwarf.start_walk(x+1, y);
    }
}
bool isNextToPickable(Dwarf & dwarf)
{
    int r = dwarf.row();
    int c = dwarf.col();
    if  ( dwarf.look(r+1, c) == PUMPKIN ||
          dwarf.look(r-1, c) == PUMPKIN ||
          dwarf.look(r, c+1) == PUMPKIN ||
          dwarf.look(r, c-1) == PUMPKIN)
          { return true; }
    else if ( dwarf.look(r+1, c) == APPLE_TREE ||
              dwarf.look(r-1, c) == APPLE_TREE ||
              dwarf.look(r, c+1) == APPLE_TREE ||
              dwarf.look(r, c-1) == APPLE_TREE)
              { return true; }
    else { return false; }
}
void pick(Dwarf & dwarf, ostream &log)
{
    int r = dwarf.row();
    int c = dwarf.col();
  // Look if there is a tree EAST from the dwarf
    if (dwarf.look(r, c+1) == PUMPKIN || dwarf.look(r, c+1) == APPLE_TREE) {
        // If there is a pine tree, chop it
        log << "Found a tree -- chop!! " << endl;
        dwarf.start_pick(EAST);
    }
      // Look if there is a tree WEST from the dwarf
    else if (dwarf.look(r, c-1) == PUMPKIN || dwarf.look(r, c-1) == APPLE_TREE) {
        // If there is a pine tree, chop it
        log << "Found a tree -- chop!! " << endl;
        dwarf.start_pick(WEST);
    }
      // Look if there is a tree NORTH from the dwarf
    else if (dwarf.look(r-1, c) == PUMPKIN || dwarf.look(r-1, c) == APPLE_TREE) {
        // If there is a pine tree, chop it
        log << "Found a tree -- chop!! " << endl;
        dwarf.start_pick(NORTH);
    }
      // Look if there is a tree SOUTH from the dwarf
    else if (dwarf.look(r+1, c) == PUMPKIN || dwarf.look(r+1, c) == APPLE_TREE) {
        // If there is a pine tree, chop it
        log << "Found a tree -- chop!! " << endl;
        dwarf.start_pick(SOUTH);
    }
}
bool isNextToAFence(Dwarf & dwarf)
{
    int r = dwarf.row();
    int c = dwarf.col();
    if  ( dwarf.look(r+1, c) == FENCE ||
          dwarf.look(r-1, c) == FENCE ||
          dwarf.look(r, c+1) == FENCE ||
          dwarf.look(r, c-1) == FENCE)
          { return true; }
    else { return false; }
}
void cutFence(Dwarf & dwarf, ostream &log)
{
    int r = dwarf.row();
    int c = dwarf.col();
  // Look if there is a tree EAST from the dwarf
    if (dwarf.look(r, c+1) == FENCE) {
        // If there is a pine tree, chop it
        log << "Found a thing -- chop!! " << endl;
        dwarf.start_chop(EAST);
    }
      // Look if there is a tree WEST from the dwarf
    else if (dwarf.look(r, c-1) == FENCE) {
        // If there is a pine tree, chop it
        log << "Found a thing -- chop!! " << endl;
        dwarf.start_chop(WEST);
    }
      // Look if there is a tree NORTH from the dwarf
    else if (dwarf.look(r-1, c) == FENCE) {
        // If there is a pine tree, chop it
        log << "Found a thing -- chop!! " << endl;
        dwarf.start_chop(NORTH);
    }
      // Look if there is a tree SOUTH from the dwarf
    else if (dwarf.look(r+1, c) == FENCE) {
        // If there is a pine tree, chop it
        log << "Found a thing -- chop!! " << endl;
        dwarf.start_chop(SOUTH);
    }
}
bool PumpkinLeft(Dwarf & dwarf)
{
  for(int i = 0; i < ROWS; i++)
  {
      for(int j = 0; j < COLS; j++)
      {
          if (dwarf.look(i,j) == PUMPKIN)
          {
              return true;
          }
      }
  }
  return false;
}
bool isNextToPumpkin(Dwarf & dwarf)
{
    int r = dwarf.row();
    int c = dwarf.col();
    if  ( dwarf.look(r+1, c) == PUMPKIN ||
          dwarf.look(r-1, c) == PUMPKIN ||
          dwarf.look(r, c+1) == PUMPKIN ||
          dwarf.look(r, c-1) == PUMPKIN)
          { return true; }
    else { return false; }
}
void findPumpkin(Dwarf & dwarf, ostream &log)
{
    int r = dwarf.row();
    int c = dwarf.col();
    int distance, x, y;
    int distanceMin = 1000;
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            if (dwarf.look(i,j) == PUMPKIN)
            {
                distance = pow(r-i, 2) + pow(c-j,2);
                distance = sqrt(distance);
                if (distance < distanceMin)
                {
                    distanceMin = distance;
                    x = i;
                    y = j;
                }
            }
        }
    }
    if (dwarf.look(x, y+1) == EMPTY)
    {
        log << "Walk to tree at " << x << " " << y+1 << " " << endl;
        dwarf.start_walk(x, y+1);
    }
    else if (dwarf.look(x, y-1) == EMPTY) {
        log << "Walk to tree at " << x << " " << y-1 << " " << endl;
        dwarf.start_walk(x, y-1);
    }
    else if (dwarf.look(x-1, y) == EMPTY) {
        log << "Walk to tree at " << x-1 << " " << y << " " << endl;
        dwarf.start_walk(x-1, y);
    }
    else if (dwarf.look(x+1, y) == EMPTY) {
        log << "Walk to tree at " << x+1 << " " << y << " " << endl;
        dwarf.start_walk(x+1, y);
    }
    else {
    // Otherwise, move to a random location
    int rr = rand() % ROWS;
    int cc = rand() % COLS;
    log << "Walk to " << rr << " " << cc << endl;
    dwarf.start_walk(rr, cc);
    return;}
}
void cutAll(Dwarf & dwarf, ostream &log)
{
    int r = dwarf.row();
    int c = dwarf.col();
  // Look if there is a tree EAST from the dwarf
    if (dwarf.look(r, c+1) != EMPTY) {
        // If there is a pine tree, chop it
        log << "Found a thing -- chop!! " << endl;
        dwarf.start_chop(EAST);
    }
      // Look if there is a tree WEST from the dwarf
    else if (dwarf.look(r, c-1) != EMPTY) {
        // If there is a pine tree, chop it
        log << "Found a thing -- chop!! " << endl;
        dwarf.start_chop(WEST);
    }
      // Look if there is a tree NORTH from the dwarf
    else if (dwarf.look(r-1, c) != EMPTY) {
        // If there is a pine tree, chop it
        log << "Found a thing -- chop!! " << endl;
        dwarf.start_chop(NORTH);
    }
      // Look if there is a tree SOUTH from the dwarf
    else if (dwarf.look(r+1, c) != EMPTY) {
        // If there is a pine tree, chop it
        log << "Found a thing -- chop!! " << endl;
        dwarf.start_chop(SOUTH);
    }
}
bool isNextToAnyTree(Dwarf & dwarf)
{
    int r = dwarf.row();
    int c = dwarf.col();
    if  ( dwarf.look(r+1, c) == PINE_TREE ||
          dwarf.look(r-1, c) == PINE_TREE ||
          dwarf.look(r, c+1) == PINE_TREE ||
          dwarf.look(r, c-1) == PINE_TREE)
          { return true; }
    else if ( dwarf.look(r+1, c) == APPLE_TREE ||
              dwarf.look(r-1, c) == APPLE_TREE ||
              dwarf.look(r, c+1) == APPLE_TREE ||
              dwarf.look(r, c-1) == APPLE_TREE)
              { return true; }
    else { return false; }
}
/* onAction:
A procedure called each time an idle dwarf is choosing
their next action.
Parameters:
    dwarf:   dwarf choosing an action
    day:     day (1+)
    hours:   number of hours in 24-hour format (0-23)
    minutes: number of minutes (0-59)
    log:     a cout-like log  */
void onAction(Dwarf &dwarf, int day, int hours, int minutes, ostream &log)
{
  int r = dwarf.row();
  int c = dwarf.col();
  if (hours > 18 || hours < 6)
  {
    if (!isNextToAppleTree(dwarf)) {findAppleTrees(dwarf, log); }
    else if (!isFortified(dwarf)) {fortify(dwarf); }
    else if (isFortified(dwarf)) {pick(dwarf, log); }
  }
  if ((day == 7) && (dwarf.lumber() > 100) && (hours > 7))
  {
    if (dwarf.name() == 0)
    {
      if (isNextToAnyTree(dwarf)) { cutAll(dwarf, log); }
        else if (dwarf.look(0, 0) != FENCE && r != 1 && c != 0) {dwarf.start_walk(1, 0);}
        else if ((dwarf.look(r-1, c) != FENCE) && c == 0) {dwarf.start_build(NORTH);}
        else if ((dwarf.look(r-1, c) == FENCE)) {dwarf.start_walk(r + 1, c);}
    }
    if (dwarf.name() == 1)
    {
      if (isNextToAnyTree(dwarf)) { cutAll(dwarf, log); }
        else if (dwarf.look(1, 0) != FENCE && r != 1 && c != 1) {dwarf.start_walk(1, 1);}
        else if ((dwarf.look(r-1, c) != FENCE) && c == 1) {dwarf.start_build(NORTH);}
        else if ((dwarf.look(r-1, c) == FENCE)) {dwarf.start_walk(r + 1, c);}
    }
    if (dwarf.name() == 2)
    {
      if (isNextToAnyTree(dwarf)) { cutAll(dwarf, log); }
        else if (dwarf.look(2, 0) != FENCE && r != 1 && c != 2) {dwarf.start_walk(1, 2);}
        else if ((dwarf.look(r-1, c) != FENCE) && c == 2) {dwarf.start_build(NORTH);}
        else if ((dwarf.look(r-1, c) == FENCE)) {dwarf.start_walk(r + 1, c);}
    }
    if (dwarf.name() == 3)
    {
      if (isNextToAnyTree(dwarf)) { cutAll(dwarf, log); }
        else if (dwarf.look(3, 0) != FENCE && r != 1 && c != 3) {dwarf.start_walk(1, 3);}
        else if ((dwarf.look(r-1, c) != FENCE) && c == 3) {dwarf.start_build(NORTH);}
        else if ((dwarf.look(r-1, c) == FENCE)) {dwarf.start_walk(r + 1, c);}
    }
    if (dwarf.name() == 4)
    {
      if (isNextToAnyTree(dwarf)) { cutAll(dwarf, log); }
        else if (dwarf.look(4, 0) != FENCE && r != 1 && c != 4) {dwarf.start_walk(1, 4);}
        else if ((dwarf.look(r-1, c) != FENCE) && c == 4) {dwarf.start_build(NORTH);}
        else if ((dwarf.look(r-1, c) == FENCE)) {dwarf.start_walk(r + 1, c);}
    }
    if (dwarf.name() == 5)
    {
      if (isNextToAnyTree(dwarf)) { cutAll(dwarf, log); }
        else if (dwarf.look(5, 0) != FENCE && r != 1 && c != 5) {dwarf.start_walk(1, 5);}
        else if ((dwarf.look(r-1, c) != FENCE) && c == 5) {dwarf.start_build(NORTH);}
        else if ((dwarf.look(r-1, c) == FENCE)) {dwarf.start_walk(r + 1, c);}
    }
    else
    {
      if (isNextToAnyTree(dwarf)) { cutAll(dwarf, log); }
      else { findPickable(dwarf, log); }
    }
  }
  else
  {
    if (isNextToAFence(dwarf)) {cutFence(dwarf, log);}
    else
    {
      if (pineTreesLeft(dwarf))
      {
        if (isNextToPineTree(dwarf)) {cutPineTree(dwarf, log); }
        else {findPineTrees(dwarf, log); }
      }
      else if (PumpkinLeft(dwarf))
      {
        if (isNextToPumpkin(dwarf)) {pick(dwarf, log);}
        else {findPumpkin(dwarf, log);}
      }
      else
      {
        if (isNextToPickable(dwarf)) { pick(dwarf, log); }
        else { findPickable(dwarf, log); }
      }
    }
  }
}
