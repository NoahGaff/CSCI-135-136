
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
bool fortify = false;

/* onStart:
An Initialization procedure called at the start of the game.
You can use it to initialize certain global variables, or do
something else before the actual simulation starts.
Parameters:
    rows: number of rows
    cols: number of columns
    num:  number of dwarfs
    log:  a cout-like log */

void onStart(int rows, int cols, int num, std::ostream &log)
{
  log << "Start!" << endl; // Print a greeting message

  ROWS = rows; // Save values in global variables
  COLS = cols;
  NUM = num;
}

void findTrees(Dwarf & dwarf, ostream &log)
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

void cutTree(Dwarf & dwarf, ostream &log)
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

bool isNextToATree(Dwarf & dwarf)
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

bool oneAndTwoDone(Dwarf & dwarf)
{
  int x, y;
  for(int i = 0; i < ROWS; i++)
  {
      for(int j = 0; j < COLS; j++)
      {
        x = i;
        y = j;

        if (dwarf.look(x, y) != FENCE)
        {
          if (y > 3 && y < 12)
          {
            if (x == 14 || x == 5)
            {
              return false;
            }
          }
        }
      }
  }

  return true;
}

void findFence(Dwarf & dwarf, ostream &log)
{
    int r = dwarf.row();
    int c = dwarf.col();
    int distance, x, y;
    int distanceMin = 1000;

    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            if (dwarf.look(i,j) == FENCE)
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
  log << hours << endl;

  if ((hours >= 18) || (hours <= 6))
  {
    if (dwarf.name() == 2)
    {
      if (isNextToAnyTree(dwarf)) { cutAll(dwarf, log); }
      else if (dwarf.look(4, 6) != FENCE && r != 6 && c != 5) {dwarf.start_walk(6, 5);}
      else if ((dwarf.look(r, c-1) != FENCE) && c == 5 && r < 14 && r > 4) {dwarf.start_build(WEST);}
      else if ((dwarf.look(r, c-1) == FENCE) && r < 13) {dwarf.start_walk(r + 1, c);}
    }

    else if (dwarf.name() == 3)
    {
      if (isNextToAnyTree(dwarf)) { cutAll(dwarf, log); }
      else if (dwarf.look(11, 6) != FENCE && r != 6 && c != 10) {dwarf.start_walk(6, 10);}
      else if ((dwarf.look(r, c+1) != FENCE) && c == 10 && r < 14 && r > 4) {dwarf.start_build(EAST);}
      else if ((dwarf.look(r, c+1) == FENCE) && r < 13) {dwarf.start_walk(r + 1, c);}
    }
    else {dwarf.start_walk(10, 8);}
  }

  if (day == 1 || ((hours > 20) || (hours < 6)))

    if (!oneAndTwoDone(dwarf))
    {
      if (dwarf.name() == 0)
      {
        if (isNextToAnyTree(dwarf)) { cutAll(dwarf, log); }
        else if (dwarf.look(5, 5) != FENCE && r != 6 && c != 4) {dwarf.start_walk(6, 4);}
        else if ((dwarf.look(r-1, c) != FENCE) && r == 6 && c > 3 && c < 12) {dwarf.start_build(NORTH);}
        else if ((dwarf.look(r-1, c) == FENCE) && c < 11) {dwarf.start_walk(r, c + 1);}
      }

      if (dwarf.name() == 1)
      {
        if (isNextToAnyTree(dwarf)) { cutAll(dwarf, log); }
        else if (dwarf.look(14, 4) != FENCE && r != 13 && c != 4) {dwarf.start_walk(13, 4);}
        else if ((dwarf.look(r+1, c) != FENCE) && r == 13 && c > 3 && c < 12) {dwarf.start_build(SOUTH);}
        else if ((dwarf.look(r+1, c) == FENCE) && c < 11) {dwarf.start_walk(r, c + 1);}
      }
    }

/*
    if (oneAndTwoDone(dwarf) && ((hours > 19) || (hours < 6)))
    {
      if (dwarf.name() == 2)
      {
        if (isNextToAnyTree(dwarf)) { cutAll(dwarf, log); }
        else if (dwarf.look(4, 6) != FENCE && r != 6 && c != 5) {dwarf.start_walk(6, 5);}
        else if ((dwarf.look(r, c-1) != FENCE) && c == 5 && r < 14 && r > 4) {dwarf.start_build(WEST);}
        else if ((dwarf.look(r, c-1) == FENCE) && r < 13) {dwarf.start_walk(r + 1, c);}
      }

      if (dwarf.name() == 3)
      {
        if (isNextToAnyTree(dwarf)) { cutAll(dwarf, log); }
        else if (dwarf.look(11, 6) != FENCE && r != 6 && c != 10) {dwarf.start_walk(6, 10);}
        else if ((dwarf.look(r, c+1) != FENCE) && c == 10 && r < 14 && r > 4) {dwarf.start_build(EAST);}
        else if ((dwarf.look(r, c+1) == FENCE) && r < 13) {dwarf.start_walk(r + 1, c);}
      }
    }
*/
  if (day == 1)
  {
    if (isNextToATree(dwarf)) { cutTree(dwarf, log); }
    else { findTrees(dwarf, log); }
  }

  if (isNextToPickable(dwarf)) { pick(dwarf, log); }
  else { findPickable(dwarf, log); }


}
