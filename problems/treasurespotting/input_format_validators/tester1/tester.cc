#include <bits/stdc++.h>

using namespace std;

// assume simple checks like format and bounds are checked already

typedef long long ll;

struct Point {
  ll x, y;
};

bool operator==(Point p, Point q)
{
  return p.x == q.x && p.y == q.y;
}

bool operator!=(Point p, Point q)
{
  return !(p == q);
}

bool operator<(Point p, Point q)
{
  return p.x < q.x || (p.x == q.x && p.y < q.y);
}

istream &operator>>(istream &is, Point &p)
{
  return is >> p.x >> p.y;
}

int W, P;
Point treasure, wall[1000][2], person[1000][2];

set<Point> pset;

ll direction(Point p1, Point p2, Point p3)
{
  ll x1 = p3.x - p1.x;
  ll y1 = p3.y - p1.y;
  ll x2 = p2.x - p1.x;
  ll y2 = p2.y - p1.y;
  return x1*y2 - x2*y1;
}

bool on_segment(Point p1, Point p2, Point p3)
{
  return ((p1.x <= p3.x && p3.x <= p2.x) || (p2.x <= p3.x && p3.x <= p1.x)) &&
    ((p1.y <= p3.y && p3.y <= p2.y) || (p2.y <= p3.y && p3.y <= p1.y));
}

bool touchwall(int pi)
{
  Point p = person[pi][0];
  for (int i = 0; i < W; i++) {
    if (on_segment(wall[i][0], wall[i][1], p) &&
	direction(wall[i][0], wall[i][1], p) == 0)
      return true;
  }
  return false;
}

int main()
{
  cin >> W >> P;

  cin >> treasure;
  for (int i = 0; i < W; i++) {
    cin >> wall[i][0] >> wall[i][1];
    if (wall[i][0] == wall[i][1]) {
      cout << "wall endpoints " << i << endl;
      exit(1);
    }
  }
  for (int i = 0; i < P; i++) {
    cin >> person[i][0] >> person[i][1];
    if (person[i][0] == person[i][1]) {
      cout << "person endpoints " << i << endl;
      exit(2);
    }
    if (touchwall(i)) {
      cout << "person " << i << " touching wall" << endl;
      exit(3);
    }
    if (person[i][0] == treasure) {
      cout << "person " << i << " == treasure" << endl;
      exit(4);
    }
    pset.insert(person[i][0]);
    if (pset.size() != i+1) {
      cout << "person " << i << " duplicate" << endl;
      exit(5);
    }
  }

  



  return 42;
}
