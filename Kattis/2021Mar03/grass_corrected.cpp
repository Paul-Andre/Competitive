#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

struct interval{
    int index;
    double pointA;
    double pointB;

    bool operator < (interval x) const {
        return pointA < x.pointA;   //compare intervals
    }
};

double A,B,maximum;    
int n, num, best;
vector<int> cover;
bool possible;

int main(){
	int n,length;   //n = number of sprinklers, length = length of grass
	double radius,position, width;   //radius = of sprinkler, position = of sprinkler, width = of grass
	
	while (cin >> n >> length >> width){
		interval intervals[n];
		
		for (int i=0;i<n;i++){
			cin >> position >> radius; // position radius => build intervals
			
			if (radius >= width/2){
				double p = sqrt(radius*radius -width*width/4);
				intervals[i].pointA = position - p;
				intervals[i].pointB = position + p;
				intervals[i].index = i;
			}
			else {  //doesn't matter in this case
				intervals[i].pointA = -1;
				intervals[i].pointB = -1;
				intervals[i].index = i;
			}
		}
		
		A = 0;
		B = length;

        sort(intervals,intervals+n);
        num = 0;
        cover.clear();
        possible = true;
        
        // set ncount of sprinklers
        while (intervals[num].pointB < A){
            num++;
            if (num == n){
                possible = false;
                break;
            }
        }
        
        // this codeblock never gets executed, btw
        if (A == B && possible){
            if (intervals[num].pointA <= A && intervals[num].pointB >= A){
                cover.push_back(intervals[num].index);
            }else{
                possible = false;
            }
        }
        
        //find minimum number of sprinklers needed to water the entire strip of grass
        while (A < B && possible){
            if (num == n){
                possible = false;
                break;
            }
            maximum = -1;
            best = -1;
            
            while (intervals[num].pointA <= A){
                if (intervals[num].pointB - A > maximum){
                    maximum = intervals[num].pointB - A;
                    best = num;
                }
                num++;
                if (num == n) break;
            }
            
            if (best == -1){
                possible = false;
                break;
            }
            cover.push_back(intervals[best].index);
            A = intervals[best].pointB;
        }
        
        //output
        if(possible){
            printf("%lu\n",cover.size());
        }else{
            if (!possible)
            printf("-1\n");
        }
	}

    return 0;
}
