#include "testlib.h"
#include <bits/stdc++.h>

#include "bounds.h"

using namespace std;

typedef long long ll;

struct Point { ll x, y; };
ll dot   (Point p, Point q) { return p.x*q.x + p.y*q.y; }
ll cross (Point p, Point q) { return p.x*q.y - p.y*q.x; }
ll len2  (Point p)          { return dot(p,p); }
Point operator -(Point p, Point q) { return {p.x-q.x, p.y-q.y}; }
bool  operator==(Point p, Point q) { return p.x == q.x && p.y == q.y; }
bool  operator!=(Point p, Point q) { return !(p == q); }

int dir(Point p, Point q, Point r) {
  ll c = cross(q-p, r-q);
  if(c == 0) return 0;
  return (c < 0 ? -1 : 1);
}

bool on_seg(Point a, Point b, Point p){
  return (min(a.x,b.x) <= p.x && p.x <= max(a.x,b.x)) &&
    (min(a.y,b.y) <= p.y && p.y <= max(a.y,b.y));
}

bool intersect(Point a1, Point a2, Point b1, Point b2){
  int d1 = dir(a1,a2,b1), d2 = dir(a1,a2,b2);
  int d3 = dir(b1,b2,a1), d4 = dir(b1,b2,a2);
  if(d1 != d2 && d1 == -d2 && d3 != d4 && d3 == -d4) return true;

  return (d1 == 0 && on_seg(a1,a2,b1)) ||
    (d2 == 0 && on_seg(a1,a2,b2)) ||
    (d3 == 0 && on_seg(b1,b2,a1)) ||
    (d4 == 0 && on_seg(b1,b2,a2));  
}

bool pointonline(Point a, Point b, Point p){
  if(a == p || b == p) return true;
  if(dir(a,b,p) != 0) return false;
  return len2(a-p) <= len2(a-b) && len2(b-p) <= len2(a-b);
}

vector<vector<Point> > wall, people;

int main(int argc, char* argv[]) {
  registerValidation(argc, argv);

  int W = inf.readInt(MIN_W, MAX_W, "w");
  inf.readSpace();
  int P = inf.readInt(MIN_P, MAX_P, "p");
  inf.readEoln();

  Point treasure;
  treasure.x = inf.readInt(MIN_X, MAX_X, "treasure x");
  inf.readSpace();
  treasure.y = inf.readInt(MIN_X, MAX_X, "treasure y");
  inf.readEoln();

  wall.assign(W, vector<Point>(2));
  for(auto& w : wall)
    for(int j=0;j<2;j++){
      w[j].x = inf.readInt(MIN_X, MAX_X,"x");
      inf.readSpace();
      w[j].y = inf.readInt(MIN_X, MAX_X,"y");
      if(j) inf.readEoln(); else inf.readSpace();
    }

  people.assign(P, vector<Point>(2));
  for(auto& p : people)
    for(int j=0;j<2;j++){
      p[j].x = inf.readInt(MIN_X, MAX_X,"x");
      inf.readSpace();
      p[j].y = inf.readInt(MIN_X, MAX_X,"y");
      if(j) inf.readEoln(); else inf.readSpace();
    }
  inf.readEof(); // Reading done... Now to verify other junk...
  
  for(auto w : wall)
    ensuref(w[0] != w[1], "Wall endpoints are not distinct");
  for(auto p : people)
    ensuref(p[0] != p[1], "People and their look must be different");
  
  for(int i=0;i<P;i++)
    for(int j=i+1;j<P;j++)
      ensuref(people[i][0] != people[j][0], "People cannot share a location");
  
  for(auto p : people)
    ensuref(p[0] != treasure, "People cannot be at the treasure");

  for(auto w : wall){
    ensuref(!pointonline(w[0], w[1], treasure), "Treasure cannot be on a wall (%d,%d) on (%d,%d)--(%d,%d)\n",treasure.x,treasure.y,w[0].x,w[0].y,w[1].x,w[1].y);
    for(auto p : people)
      ensuref(!pointonline(w[0], w[1], p[0]), "People cannot be on a wall");
  }
  
  return OK_EXIT_CODE;
}
