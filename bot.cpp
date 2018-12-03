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
bool building = false;

/* onStart:
An Initialization procedure called at the start of the game.
You can use it to initialize certain global variables, or do
something else before the actuabot.cpp:87:7: warning: unused variable 'c' [-Wunused-variable]
   int c = dwarf.col();
l simulation starts.
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
    NUM  = num;
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
            if (dwarf.look(i,j) == PINE_TREE || dwarf.look(i,j) == APPLE_TREE)
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

void findFences(Dwarf & dwarf, ostream &log)
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


    if (dwarf.look(x, y+2) && dwarf.look(x, y+1)== EMPTY)
    {
        log << "Walk to fence at " << x << " " << y+2 << " " << endl;
        dwarf.start_walk(x, y+2);
    }
    else if (dwarf.look(x, y-2) && dwarf.look(x, y-1) == EMPTY)
    {
        log << "Walk to fence at " << x << " " << y-2 << " " << endl;
        dwarf.start_walk(x, y-2);
    }
    else if (dwarf.look(x-2, y) && dwarf.look(x-1, y) == EMPTY)
    {
        log << "Walk to fence at " << x-2 << " " << y << " " << endl;
        dwarf.start_walk(x-2, y);
    }
    else if (dwarf.look(x+2, y) && dwarf.look(x+1, y) == EMPTY)
    {
        log << "Walk to fence at " << x+2 << " " << y << " " << endl;
        dwarf.start_walk(x+2, y);
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

    else if ( dwarf.look(r+1, c) == APPLE_TREE ||
              dwarf.look(r-1, c) == APPLE_TREE ||
              dwarf.look(r, c+1) == APPLE_TREE ||
              dwarf.look(r, c-1) == APPLE_TREE)
              { return true; }

    else { return false; }
}

bool isNextToAFence(Dwarf & dwarf)
{
    int r = dwarf.row();
    int c = dwarf.col();
    if (  (dwarf.look(r+2, c) == FENCE && dwarf.look(r+1, c) == EMPTY)  ||
          (dwarf.look(r-2, c) == FENCE && dwarf.look(r-1, c) == EMPTY) ||
          (dwarf.look(r, c+2) == FENCE && dwarf.look(r, c+1) == EMPTY) ||
          (dwarf.look(r, c-2) == FENCE && dwarf.look(r, c-1) == EMPTY) )
          { return true; }

    else { return false; }
}

void choppy(Dwarf & dwarf, ostream &log)
{
    int r = dwarf.row();
    int c = dwarf.col();

  // Look if there is a tree EAST from the dwarf
    if (dwarf.look(r, c+1) == PINE_TREE || dwarf.look(r, c+1) == APPLE_TREE) {
        // If there is a pine tree, chop it
        log << "Found a tree -- chop!! " << endl;
        dwarf.start_chop(EAST);
    }
      // Look if there is a tree WEST from the dwarf
    else if (dwarf.look(r, c-1) == PINE_TREE || dwarf.look(r, c-1) == APPLE_TREE) {
        // If there is a pine tree, chop it
        log << "Found a tree -- chop!! " << endl;
        dwarf.start_chop(WEST);
    }
      // Look if there is a tree NORTH from the dwarf
    else if (dwarf.look(r-1, c) == PINE_TREE || dwarf.look(r-1, c) == APPLE_TREE) {
        // If there is a pine tree, chop it
        log << "Found a tree -- chop!! " << endl;
        dwarf.start_chop(NORTH);
    }
      // Look if there is a tree SOUTH from the dwarf
    else if (dwarf.look(r+1, c) == PINE_TREE || dwarf.look(r+1, c) == APPLE_TREE) {
        // If there is a pine tree, chop it
        log << "Found a tree -- chop!! " << endl;
        dwarf.start_chop(SOUTH);
    }
}

bool isFence (Dwarf & dwarf)
{
  bool fenceExists = false;

  for(int i = 0; i < ROWS; i++)
  {
      for(int j = 0; j < COLS; j++)
      {
          if (dwarf.look(i,j) == FENCE) { fenceExists = true; }
      }
  }

  return fenceExists;
}

void placeFence(Dwarf & dwarf, ostream &log)
{
    int r = dwarf.row();
    int c = dwarf.col();


  // Look if there is a tree NORTH from the dwarf
    if (dwarf.look(r+2, c) == FENCE && dwarf.look(r+1, c) == EMPTY )
    {
      log << "Found Fence -- building next " << endl;
      dwarf.start_build(SOUTH);
    }
      // Look if there is a tree SOUTH from the dwarf
    else if (dwarf.look(r-2, c) == FENCE && dwarf.look(r-1, c) == EMPTY )
    {
      log << "Found Fence -- building next " << endl;
      dwarf.start_build(NORTH);
    }
      // Look if there is a tree WEST from the dwarf
    else if (dwarf.look(r, c-2) == FENCE && dwarf.look(r, c - 1) == EMPTY )
    {
      log << "Found Fence -- building next " << endl;
      dwarf.start_build(WEST);
    }
      // Look if there is a tree EAST from the dwarf
    else if (dwarf.look(r, c+2) == FENCE &&  dwarf.look(r, c + 1) == EMPTY )
    {
      log << "Found Fence -- building next " << endl;
      dwarf.start_build(EAST);
    }


}





            /* onAction:
            A procedure called each time anbot.cpp:87:7: warning: unused variable 'c' [-Wunused-variable]
            int c = dwarf.col();
            idle dwarf is choosing
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

    if (building)
    {
      if ((r >= (ROWS) * 0.25 && r <= (ROWS) * 0.75) && (c >= (COLS) * 0.25 && c <= (COLS) * 0.75) && (!isFence(dwarf)))
      {
        dwarf.start_build(NORTH);
      }
      else if (isFence(dwarf))
      {
        if (dwarf.lumber() <= 10) {building = false;}
        else if(isNextToATree(dwarf)) { choppy(dwarf,log); }
        else if (isNextToAFence(dwarf)) { placeFence(dwarf, log); }
        else { findFences(dwarf, log); }
      }
      else { dwarf.start_walk(ROWS / 2, COLS / 2); }

    }
    else if (dwarf.lumber() >= 300)
    {
      building = true;
    }
    if (!building)
    {
      if(isNextToATree(dwarf)) { choppy(dwarf,log); }
      else { findTrees(dwarf, log); }
    }
}
