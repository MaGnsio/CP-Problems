//https://vjudge.net/contest/416230#problem/X
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
typedef long long ll;
typedef long double ld;
ll mod = 1e9 + 7;

const int MAX = 700;
typedef int BigInt[MAX]; //BigInt ≡ int[MAX]
void big_zero (BigInt N); //N = 0
void big_copy (BigInt X, BigInt Y); //X = Y
int big_len (BigInt N); //N.size () = i
void big_print (BigInt N); //cout << N
void big_from_str (BigInt N, string S); //N = stoi (S)
int big_cmp (BigInt A, BigInt B); //(A > B, 1) || (A < B, -1) || (A == B, 0)
void big_product (BigInt R, int F); //R *= F
void big_add (BigInt R, int N); //R += N
char big_sub (BigInt A, BigInt B, BigInt R, char sign = '+'); //R = sign (A - B)
void big_divide (BigInt A, BigInt B, BigInt R); //R = A % B, A /= B

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    ll t;
    cin >> t;
    while (t--)
    {
        string A, B;
        BigInt X, Y, Z;
        cin >> A >> B;
        big_from_str (X, A);
        big_from_str (Y, B);
        big_divide (X, Y, Z);
        big_print (X);
        cout << " ";
        big_print (Z);
        cout << "\n";
    }
}

void big_zero (BigInt N) {for (int i = 0; i < MAX; ++i) N[i] = 0;}
void big_copy (BigInt X, BigInt Y) {for (int i = 0; i < MAX; ++i) X[i] = Y[i];}
int big_len (BigInt N)
{
  int i;
  for (i = MAX - 1; i && !N[i]; --i);
  return i;
}
void big_print (BigInt N) {for (int i = big_len (N); i >= 0; --i) cout << N[i];}
void big_from_str (BigInt N, string S)
{
  big_zero(N);
  for (int i = S.size() - 1; i >= 0; --i) {N[S.size () - 1 - i] = S[i] - '0';}
}
int big_cmp (BigInt A, BigInt B)
{
  for (int i = MAX - 1 ; i >= 0 ; --i)
  {
    if (A[i] > B[i]) return 1;
    else if (A[i] < B[i]) return -1;
  }
  return 0;
}
void big_product (BigInt R, int F)
{
  int carry = 0;
  for (int i = 0; i < MAX; ++i)
  {
    carry += R[i] * F;
    R[i] = carry % 10;
    carry /= 10;
  }
}
void big_add (BigInt R, int N)
{
  int carry = N;
  for (int i = 0; i < MAX && carry; ++i)
  {
    int n = R[i] + carry;
    R[i] = n % 10;
    carry = n / 10;
  }
}
char big_sub (BigInt A, BigInt B, BigInt R, char sign)
{
  if (big_cmp (A, B) < 0) return big_sub (B, A, R, '-');
  big_zero (R);
  int len_a = big_len (A), len_b = big_len (B);
  int max = len_a > len_b ? len_a : len_b;
  for (int i = 0; i <= max; i++) R[i] = A[i] - B[i];
  for (int i = 0; i <= max; i++)
  {
    while (R[i] < 0) R[i] += 10, R[i + 1] -= 1;
  }
  return sign;
}
void big_divide (BigInt A, BigInt B, BigInt R)
{
  BigInt cpy;
  big_zero (R);
  int i = big_len (A);
  while (i >= 0)
  {
    big_product (R, 10);
    big_add (R, A[i]);
    A[i] = 0;
    while (big_cmp (R, B) >= 0 )
    {
      big_sub (R, B, cpy);
      big_copy(R, cpy);
      A[i]++;
    }
    i--;
  }
}
