#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 100;

default_random_engine generator;
uniform_int_distribution<int> distribution(0,INT_MAX);

string filename(int s)
{
  ostringstream oss;
  oss << "qaly-" << setw(2) << setfill('0') << s << ".in";
  return oss.str();
}

int random_int(int lo, int hi)
{
  int t = distribution(generator) % (hi - lo + 1) + lo;
  return t;
}

void print(ofstream &out, int x)
{
  out << (x/10) << '.' << (x%10);
}

void random_case(int id)
{
  ofstream out(filename(id).c_str());

  int N = 100;
  out << N << endl;

  for (int i = 0; i < N; i++) {
    int q = random_int(1,10);
    int len = random_int(1, 500);
    print(out, q);
    out << ' ';
    print(out, len);
    out << endl;
  }
}

int main()
{
  int id = 1;

  for (int i = 0; i < 10; i++) {
    random_case(id++);
  }
  
  return 0;
}
