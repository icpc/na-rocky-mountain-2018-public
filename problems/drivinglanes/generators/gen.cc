#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MAX_VAL = 1000000;
const ll MAX_N = 250;
const ll MAX_M = 250;

default_random_engine generator;
uniform_int_distribution<ll> distribution(0,MAX_VAL);
const string prefix = "";

string filename(int s)
{
  ostringstream oss;
  oss << prefix << setw(2) << setfill('0') << s << ".in";
  return oss.str();
}

ll random_int()
{
  ll t = distribution(generator);
  return t;
}

ll random_int(ll a, ll b)
{
  ll t = distribution(generator) % (b-a+1) + a;
  return t;
}

ll random_c(int m, ll l, int bias = 2)
{
  ll c;
  int sign = (random_int(1,bias) == 1) ? 1 : -1;
  do {
    c = sign * random_int(0, MAX_VAL);
  } while (l + m*c <= 0);
  return c;
}

void singlelane(int id)
{
  ofstream out(filename(id).c_str());

  int n = random_int(1, MAX_N);
  int m = 1;

  out << n << ' ' << m << endl;

  ll k = random_int(1, MAX_VAL), r = random_int(1, MAX_VAL);
  out << k << ' ' << r << endl;

  for (int i = 0; i < n; i++) {
    out << random_int(1, MAX_VAL) << endl;
  }
  for (int i = 0; i < n-1; i++) {
    ll l = random_int(2*m, MAX_VAL);
    out << l << ' ' << random_c(m, l, 10) << endl;
  }
}

void singlesegment(int id)
{
  ofstream out(filename(id).c_str());

  int m = random_int(1, MAX_M);
  int n = 1;

  out << n << ' ' << m << endl;

  ll k = random_int(1, MAX_VAL), r = random_int(1, MAX_VAL);
  out << k << ' ' << r << endl;

  for (int i = 0; i < n; i++) {
    out << random_int(1, MAX_VAL) << endl;
  }
  for (int i = 0; i < n-1; i++) {
    ll l = random_int(2*m, MAX_VAL);
    out << l << ' ' << random_c(m, l, 10) << endl;
  }
}

void random_cases(int id)
{
  ofstream out(filename(id).c_str());

  int n = random_int(1, MAX_N);
  int m = random_int(1, MAX_M);


  out << n << ' ' << m << endl;

  ll k = random_int(1, MAX_VAL), r = random_int(1, 1000);
  out << k << ' ' << r << endl;

  for (int i = 0; i < n; i++) {
    out << random_int(1, MAX_VAL) << endl;
  }
  for (int i = 0; i < n-1; i++) {
    ll l = random_int(2*m, MAX_VAL);
    out << l << ' ' << random_c(m, l, 10) << endl;
  }
}

void max_cases(int id)
{
  ofstream out(filename(id).c_str());

  int n = MAX_N;
  int m = MAX_M;


  out << n << ' ' << m << endl;

  ll k = random_int(MAX_VAL-100, MAX_VAL), r = random_int(1,1000);
  out << k << ' ' << r << endl;

  for (int i = 0; i < n; i++) {
    out << random_int(MAX_VAL-100, MAX_VAL) << endl;
  }
  for (int i = 0; i < n-1; i++) {
    ll l = random_int(MAX_VAL-100, MAX_VAL);
    out << l << ' ' << random_c(m,l,10) << endl;
  }  
}

// forced to switch one lane at a time
void force(int id)
{
  ofstream out(filename(id).c_str());

  int n = MAX_N;
  int m = MAX_M;

  out << n << ' ' << m << endl;

  ll k = random_int(MAX_VAL/2, MAX_VAL), r = random_int(1,10);
  out << k << ' ' << r << endl;

  for (int i = 0; i < n; i++) {
    out << min(MAX_VAL, k+random_int(0,k-1)) << endl;
  }
  for (int i = 0; i < n-1; i++) {
    if (i == n/2) {
      ll c = -random_int((MAX_VAL-10)/m-1000, (MAX_VAL-10)/m);
      ll l = m*(-c) + 10;
      out << l << ' ' << c << endl;
    } else {
      ll l = random_int(MAX_VAL-1000, MAX_VAL);
      out << l << ' ' << random_int(1,10) << endl;
    }
  }  
}

void pos_c(int id)
{
  ofstream out(filename(id).c_str());

  int n = random_int(100, MAX_N);
  int m = random_int(100, MAX_M);

  out << n << ' ' << m << endl;

  ll k = random_int(1, MAX_VAL), r = random_int(1,1000);
  out << k << ' ' << r << endl;

  for (int i = 0; i < n; i++) {
    out << random_int(1, MAX_VAL) << endl;
  }
  for (int i = 0; i < n-1; i++) {
    ll l = random_int(MAX_VAL-1000, MAX_VAL);
    out << l << ' ' << random_int(1,10) << endl;
  }  
}

int main()
{
  int id = 1;

  for (int i = 0; i < 3; i++) {
    singlelane(id++);
    singlesegment(id++);
  }
  for (int i = 0; i < 15; i++) {
    random_cases(id++);
  }
  for (int i = 0; i < 5; i++) {
    force(id++);
  }
  pos_c(id++);
  for (int i = 0; i < 2; i++) {
    max_cases(id++);
  }
  
  return 0;
}
