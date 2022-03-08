#include <bits/stdc++.h>

using namespace std;

const long long MIN_COORD = 1;
const long long MAX_COORD = 1000000000000LL/2;
const string prefix = "trees-";

default_random_engine generator;
uniform_int_distribution<long long> distribution(MIN_COORD,MAX_COORD);

string filename(int s)
{
  ostringstream oss;
  oss << prefix << setw(2) << setfill('0') << s << ".in";
  return oss.str();
}

long long random_int()
{
  long long t = distribution(generator);
  return t;
}

long long random_int(long long a, long long b)
{
  long long t = distribution(generator) % (b-a+1) + a;
  return t;
}

struct Point
{
  long long x, y;
  Point(long long xx = 0, long long yy = 0) : x{xx}, y{yy} {}

  void random() {
    x = random_int();
    y = random_int();
  }
};

ostream &operator<<(ostream &os, Point p)
{
  return os << p.x << ' ' << p.y;
}

long long gcd(long long a, long long b)
{
  if (!b) return a;
  return gcd(b, a%b);
}

bool is_inside(Point B, Point L, Point R)
{
  return L.x <= B.x && B.x <= R.x && L.y <= B.y && B.y <= R.y;
}

// random cases with relatively prime (xb,yb)
void rel_prime(int id, bool inside)
{
  ofstream out(filename(id).c_str());
  
  Point B;  B.random();
  long long g = gcd(B.x, B.y);
  B.x /= g;  B.y /= g;

  Point L, R;
  do {
    L.random(); R.random();
    if (L.x > R.x) swap(L.x, R.x);
    if (L.y > R.y) swap(L.y, R.y);
  } while ( (L.x == R.x || L.y == R.y) ||
	    (inside && !is_inside(B, L, R)) ||
	    (!inside && is_inside(B, L, R)));
  out << B << endl;
  out << L << endl;
  out << R << endl;
}

// random cases with all trees in between cut down
void all_cut(int id, bool inside)
{
  ofstream out(filename(id).c_str());

  Point B;
  B.x = B.y = random_int(100, 1000000);
  B.x *= random_int(2, MAX_COORD/B.x);
  B.y *= random_int(2, MAX_COORD/B.y);
  long long g = gcd(B.x, B.y);
  Point L, R;
  L.x = B.x/g;  L.y = B.y/g;
  if (inside) {
    R = B;
  } else {
    R.x = L.x*(g-1); R.y = L.y*(g-1);
  }
  
  out << B << endl;
  out << L << endl;
  out << R << endl;
}

// random cases with non-relatively prime B
void random_case(int id, bool inside)
{
  ofstream out(filename(id).c_str());
  
  Point B;
  B.x = B.y = random_int(100, 1000000);
  B.x *= random_int(2, MAX_COORD/B.x);
  B.y *= random_int(2, MAX_COORD/B.y);

  Point L, R;
  do {
    L.random(); R.random();
    if (L.x > R.x) swap(L.x, R.x);
    if (L.y > R.y) swap(L.y, R.y);
  } while ( (L.x == R.x || L.y == R.y) ||
	    (inside && !is_inside(B, L, R)) ||
	    (!inside && is_inside(B, L, R)));
  out << B << endl;
  out << L << endl;
  out << R << endl;
}

// random cases with some trees in between cut down
void some_cut(int id, bool first_cut)
{
  ofstream out(filename(id).c_str());

  Point B;
  B.x = B.y = random_int(100, 1000000);
  B.x *= random_int(2, MAX_COORD/B.x);
  B.y *= random_int(2, MAX_COORD/B.y);
  long long g = gcd(B.x, B.y);
  Point L, R;

  long long start_i = (first_cut) ? 1 : random_int(2,g-2);
  long long end_i = random_int(start_i+1, g-1);
  L.x = start_i*(B.x/g);  L.y = start_i*(B.y/g);
  R.x = end_i*(B.x/g);  R.y = end_i*(B.y/g);
  
  L.x -= random_int(0, L.x-1);
  L.y -= random_int(0, L.y-1);
  R.x += random_int(0, MAX_COORD-R.x);
  R.y += random_int(0, MAX_COORD-R.y);
  
  out << B << endl;
  out << L << endl;
  out << R << endl;
}

// random cases with 0-area rectangle
void area0(int id, int dir)
{
  int dx[] = {0, -1, 1, 0, 0};
  int dy[] = {0, 0, 0, -1, 1};
  
  ofstream out(filename(id).c_str());
  
  Point B;  B.random();
  long long g = gcd(B.x, B.y);
  B.x /= g;  B.y /= g;

  Point C{B};
  C.x *= 2;
  C.y *= 2;

  B.x += dx[dir];
  B.y += dy[dir];
  
  Point L, R;
  L = R = B;

  out << C << endl;
  out << L << ' ' << R << endl;
}

int main()
{
  int id = 48;

  for (int i = 0; i < 5; i++) {
    for (int d = 0; d < 5; d++) {
      area0(id++, d);
    }
  }
  
  /*
  for (int i = 0; i < 3; i++) {
    rel_prime(id++, true);
    rel_prime(id++, false);
  }
  for (int i = 0; i < 5; i++) {
    all_cut(id++, true);
    all_cut(id++, false);
  }
  for (int i = 0; i < 5; i++) {
    random_case(id++, true);
    random_case(id++, false);
  }

  for (int i = 0; i < 10; i++) {
    some_cut(id++, true);
    some_cut(id++, false);
  }
  */
  
  return 0;
}
