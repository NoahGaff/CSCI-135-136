/*
Author: Noah Gaffney
Course: CSCI-136
Instructor: their name
Assignment: title, e.g., Lab1A

Here, briefly, at least in one or a few sentences
describe what the program does.
Hey
Hey
*/


#include <iostream>
using namespace std;

class Profile {
private:
    string username;
    string displayname;
public:
    // Profile constructor for a user (initializing
    // private variables username=usrn, displayname=dspn)
    Profile(string usrn, string dspn);
    // Default Profile constructor (username="", displayname="")
    Profile();
    // Return username
    string getUsername();
    // Return name in the format: "displayname (@username)"
    string getFullName();
    // Change display name
    void setDisplayName(string dspn);
};

struct Post{
    string username;
    string message;
};

class Network {
private:
    static const int MAX_POSTS = 100;         // new
    static const int MAX_USERS = 20;
    Profile profiles[MAX_USERS];
    Post posts[MAX_POSTS];                    // new
    bool following[MAX_USERS][MAX_USERS];
    int numUsers;
    int numPosts;                             // new
    int findID (string usrn);
public:
    Network();
    bool addUser(string usrn, string dspn);
    bool follow(string usrn1, string usrn2);
    void printDot();
    bool writePost(string usrn, string msg);  // new
    bool printTimeline(string usrn);          // new
};

Network::Network(){
    numUsers=0;
    numPosts = 0;
    for (int i = 0; i < MAX_USERS; i++)
        for(int j = 0; j < MAX_USERS; j++)
            following[i][j] = false;
}
bool Network::follow(string usrn1, string usrn2)
{
    if (findID(usrn1) == -1)
        return false;
    else
    {
        for (int i=0; i < numUsers; i++)
            if(profiles[i].getUsername() == usrn2)
            {
                following[findID(usrn1)][i] = true;
                return true;
            }
    }
    return false;
}
void Network::printDot()
{
    cout << "digraph { "<< endl;
    for (int i=0; i < numUsers; i++)
    {
        cout << "  \"@" << profiles[i].getUsername() << "\"" << endl;
    }
        for (int i=0; i < numUsers; i++)
        {
            for(int j = 0; j < numUsers; j++)
            {
                if (following[i][j] == true)
                    cout <<  "  \"@" << profiles[i].getUsername() << "\"" " -> " << "\"@" << profiles[j].getUsername() << "\"" << endl;
            }
        }
    cout << "}" << endl;
}

int Network::findID(string usrn)
{
    for(int i=0; i<numUsers; i++)
        if(profiles[i].getUsername() == usrn)
        {
            return i;
        }
    return -1;
}

bool Network::addUser(string usrn, string dspn)
{
    if (numUsers == MAX_USERS)
            return false;

    for (int i=0; i<numUsers; i++)
    {
        if (profiles[i].getUsername() == usrn)
            return false;
    }

    for (int i=0; i<usrn.length(); i++)
    {
        if (!isalpha(usrn[i]) && !isdigit(usrn[i]))
        {
            return false;
        }
    }
    profiles[numUsers] = Profile(usrn, dspn);
    numUsers++;
    return true;
    // After checking everyhting and there is no 'false', now we can add a new user


}

bool Network::writePost(string usrn, string msg)
{
  if (numPosts == MAX_POSTS)
  {
      return false;
  }
  else
  {
    posts[numPosts].username = usrn;
    posts[numPosts].message = msg;
    numPosts++;
    return true;
  }
}

bool Network::printTimeline(string usrn)
{
  int currentID = findID(usrn);

  for (int i = MAX_POSTS; i >= 0; i--)
  {
    if (posts[i].username == usrn || following[currentID][findID(posts[i].username)] == true)
    {
      Profile currentProfile = profiles[findID(posts[i].username)];
      cout << currentProfile.getFullName() << ": "<< posts[i].message << endl;
    }
  }
  return true;
}

Profile::Profile(string usrn,string dspn)
{
    username = usrn;
    displayname = dspn;
}

Profile::Profile()
{
    username = "";
    displayname ="";
}


string Profile::getUsername()
{
    return username;
}

string Profile::getFullName()
{
    return displayname+" (@"+username+")";
}

void Profile::setDisplayName(string dspn)
{
    displayname = dspn;
}



int main() {
  Network nw;
  // add three users
  nw.addUser("mario", "Mario");
  nw.addUser("luigi", "Luigi");
  nw.addUser("yoshi", "Yoshi");

  nw.follow("mario", "luigi");
  nw.follow("luigi", "mario");
  nw.follow("luigi", "yoshi");
  nw.follow("yoshi", "mario");

  // write some posts
  nw.writePost("mario", "It's a-me, Mario!");
  nw.writePost("luigi", "Hey hey!");
  nw.writePost("mario", "Hi Luigi!");
  nw.writePost("yoshi", "Test 1");
  nw.writePost("yoshi", "Test 2");
  nw.writePost("luigi", "I just hope this crazy plan of yours works!");
  nw.writePost("mario", "My crazy plans always work!");
  nw.writePost("yoshi", "Test 3");
  nw.writePost("yoshi", "Test 4");
  nw.writePost("yoshi", "Test 5");

  cout << endl;
  cout << "======= Mario's timeline =======" << endl;
  nw.printTimeline("mario");
  cout << endl;

  cout << "======= Yoshi's timeline =======" << endl;
  nw.printTimeline("yoshi");
  cout << endl;
}
