
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;


ll pow(ll base, ll power, ll mod) {
  ll acc = 1;
  while(power != 0) {
    if (power % 2 == 0) {
      power/=2;
      base = (base*base) % mod;
    } else {
      power --;
      acc = acc * base % mod;
    }
  }
  acc += mod;
  acc %= mod;
  return acc;
}

ll inverse(ll n, ll mod) {
  return pow(n, mod - 2, mod);
}


vector<string> split_string(string);

// Complete the howManyGoodSubarrays function below.
ll howManyGoodSubarrays(vector<ll> A, ll MOD, ll k) {
  if (k!= 0) {
    unordered_map<ll, ll> t;
    ll running = 1;
    t[1] ++;
    ll tot = 0;
    for (int i=0; i<A.size(); i++) {
      if (A[i] != 0) {
        running *= A[i];
        running %= MOD;
        ll inv = inverse(running, MOD);
        ll find = k * inv % MOD;
        tot += t[find];
        t[inv]++;
      } else {
        running = 1;
        t.clear();
        t[1] = 1;
      }
    }
    return tot;
  }else {
    ll p = 0;
    ll j = 0;
    ll tot = 0;
    for (int i=0; i<A.size(); i++) {
      ll a = A[i];
      if (a != 0) {
        p++;
      }else {
        j+= p;
        j++;
        p = 0;
      }
      tot += j;
    }
    return tot;

  }



}

int main()
{
  //ofstream fout(getenv("OUTPUT_PATH"));
  auto &fout  = cout;

  int t;
  cin >> t;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  for (int t_itr = 0; t_itr < t; t_itr++) {
    string nmk_temp;
    getline(cin, nmk_temp);

    vector<string> nmk = split_string(nmk_temp);

    int n = stoi(nmk[0]);

    int m = stoi(nmk[1]);

    int k = stoi(nmk[2]);

    string A_temp_temp;
    getline(cin, A_temp_temp);

    vector<string> A_temp = split_string(A_temp_temp);

    vector<ll> A(n);

    for (int i = 0; i < n; i++) {
      ll A_item = stoi(A_temp[i]);
      A_item %= m;

      A[i] = A_item;
    }

    long result = howManyGoodSubarrays(A, m, k);

    fout << result << "\n";
  }

  //fout.close();

  return 0;
}

vector<string> split_string(string input_string) {
  string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
      return x == y and x == ' ';
      });

  input_string.erase(new_end, input_string.end());

  while (input_string[input_string.length() - 1] == ' ') {
    input_string.pop_back();
  }

  vector<string> splits;
  char delimiter = ' ';

  size_t i = 0;
  size_t pos = input_string.find(delimiter);

  while (pos != string::npos) {
    splits.push_back(input_string.substr(i, pos - i));

    i = pos + 1;
    pos = input_string.find(delimiter, i);
  }

  splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

  return splits;
}
