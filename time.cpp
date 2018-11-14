/*
Author: your name
Course: CSCI-136
Instructor: their name
Assignment: title, e.g., Lab1A

Here, briefly, at least in one or a few sentences
describe what the program does.
*/


#include <iostream>
using namespace std;

enum Genre {ACTION, COMEDY, DRAMA, ROMANCE, THRILLER};

class Time
{
public:
    int h;
    int m;
};

class Movie {
public:
    string title;
    Genre genre;     // only one genre per movie
    int duration;    // in minutes
};

class TimeSlot {
public:
    Movie movie;     // what movie
    Time startTime;  // when it starts
};


int minutesSinceMidnight(Time time)
{
  int minuHour = (time.h *60) + time.m;

  return minuHour;
}


int minutesUntil(Time earlier, Time later)
{
  int timeOne, timeTwo, timeFinal;

  timeOne = minutesSinceMidnight(earlier);
  timeTwo = minutesSinceMidnight(later);

  timeFinal = timeTwo - timeOne;

  return timeFinal;
}

//this is the next part or something
//yayyyyy

Time addMinutes(Time time0, int min)
{
  time0.m += min;

  while (time0.m >= 60)
  {
    time0.m -= 60;
    time0.h ++;
  }

  return time0;
}

void printMovie(Movie mv){
    string g;
    switch (mv.genre) {
        case ACTION   : g = "ACTION"; break;
        case COMEDY   : g = "COMEDY"; break;
        case DRAMA    : g = "DRAMA";  break;
        case ROMANCE  : g = "ROMANCE"; break;
        case THRILLER : g = "THRILLER"; break;
    }
    cout << mv.title << " " << g << " (" << mv.duration << " min)";
}

void printTimeSlot(TimeSlot ts)
{
  Time endTime = addMinutes(ts.startTime, ts.movie.duration);

  printMovie(ts.movie);
  cout << " [starts at "<< ts.startTime.h << ":" << ts.startTime.m << ", ends by " << endTime.h << ":" << endTime.m << "]";
}

TimeSlot scheduleAfter(TimeSlot ts, Movie nextMovie)
{
  TimeSlot newTimeslot;
  Time nextTimeSlot = addMinutes(ts.startTime, ts.movie.duration);
  newTimeslot.startTime = nextTimeSlot;
  newTimeslot.movie = nextMovie;
  return newTimeslot;
}

//almost done!!
//yayyyyy

bool timeOverlap(TimeSlot ts1, TimeSlot ts2)
{
  int minSinMid1 = minutesSinceMidnight(ts1.startTime);
  int minSinMid2 = minutesSinceMidnight(ts2.startTime);
  Time ts1EndTime = addMinutes(ts1.startTime, ts1.movie.duration);
  Time ts2EndTime = addMinutes(ts2.startTime, ts2.movie.duration);

  if (minSinMid1 == minSinMid2) {return true;}

  else if (minSinMid1 > minSinMid2)
  {
    if (minutesUntil(ts1.startTime, ts2EndTime) > 1) {return true;}
  }
  else if (minSinMid1 < minSinMid2)
  {
    if (minutesUntil(ts2.startTime, ts1EndTime) > 1) {return true;}
  }

  return false;
}
