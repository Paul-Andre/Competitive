#include <bits/stdc++.h>

#define _USE_MATH_DEFINES
#include <cmath> 

using namespace std;


double cross (double x1, double y1, double x2, double y2) {
  return x1*y2 - x2*y1;
}

double calculateArea(vector<vector<double> > &cords) {
  return 
    fabs(cross(cords[0][0], cords[0][2], cords[1][0], cords[1][2])) +
    fabs(cross(cords[0][0], cords[0][2], cords[2][0], cords[2][2])) +
    fabs(cross(cords[1][0], cords[1][2], cords[2][0], cords[2][2]));
}

void rot(vector<vector<double> > &cords, double ang, int u, int v) {
  for (int i=0; i<cords.size(); i++) {
    double x = cords[i][u];
    double y = cords[i][v];

    double a = cos(ang);
    double b = sin(ang);

    cords[i][u] = x*a - y*b;
    cords[i][v] = x*b + y*a;
  }
}

double bound = sqrt(2.);

void solve() {

  double area;
  cin >> area;

  if (area < bound) {

    double a = 0;
    double b = M_PI/4.;

    for (int i=0; i<1000; i++) {
      vector<vector<double> > cords = {
        {1, 0, 0},
        {0, 1, 0},
        {0, 0, 1},
      };

      double c = (a + b)*0.5;

      rot(cords, c, 0, 1);
      double na = calculateArea(cords);
      /*
      cerr << na <<endl;
    */
      if (na >= area) {
        b = c;
      }
      else {
        a = c;
      }
    }

    vector<vector<double> > cords = {
      {0.5, 0, 0},
      {0, 0.5, 0},
      {0, 0, 0.5},
    };

    rot(cords, a, 0, 1);
    cout.precision(17);
    cerr.precision(17);
    //cerr << "Got " <<calculateArea(cords) * 4<< endl;

    for (int i=0; i<3; i++) {
      for (int j=0; j<3; j++) {
        cout << cords[i][j];
        if( j != 2) cout << " ";
      }
      cout <<endl;
    }
  } else {

    double a = 0;
    double b = M_PI*0.5 - atan(sqrt(2.));

    for (int i=0; i<1000; i++) {
      vector<vector<double> > cords = {
        {1, 0, 0},
        {0, 1, 0},
        {0, 0, 1},
      };

      rot(cords, M_PI/4., 2, 1);

      double c = (a + b)*0.5;

      rot(cords, c, 0, 1);
      double na = calculateArea(cords);
      /*
      cerr << na <<endl;
    */
      if (na >= area) {
        b = c;
      }
      else {
        a = c;
      }
    }

    vector<vector<double> > cords = {
      {0.5, 0, 0},
      {0, 0.5, 0},
      {0, 0, 0.5},
    };

    rot(cords, M_PI/4., 2, 1);
    rot(cords, a, 0, 1);
    cout.precision(17);
    cerr.precision(17);
    //cerr << "Got " <<calculateArea(cords) * 4<< endl;

    for (int i=0; i<3; i++) {
      for (int j=0; j<3; j++) {
        cout << cords[i][j];
        if( j != 2) cout << " ";
      }
      cout <<endl;
    }
  }


}


int t;
int main() {
  cin >> t;
  for (int tt=1; tt<=t; tt++) {
    cout << "Case #"<<tt<<":" <<endl;
    solve();
  }
}
