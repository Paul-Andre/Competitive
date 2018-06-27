#include <bits/stdc++.h>
#include <string.h>

using namespace std;
typedef long long ll;

#define PRIME 2147483647

struct Edge {
	int r;
	int l;
	int next;
	int freq;
};

ll powers[100001];

// assume substr have the same size
bool hashcmp(string &a, string &b, int al, int ar, int bl, int br, vector<ll> &aHashes, vector<ll> &bHashes) {
	/*
	cout << "Comparing strings " << a.substr(al, ar-al+1) << " " << b.substr(bl, br-bl+1) << '\n';
	cout << "al ar bl br" << al << " " << ar << " " << bl << " " << br << '\n';
	*/

	assert(ar-al == br-bl);

	if (ar-al+1<=128) {
		return memcmp(&a[al],&b[bl],ar-al+1)==0;
	}

	ll ah;
	if (al==0) ah = aHashes[ar];
	else ah = (aHashes[ar] - aHashes[al-1]) % PRIME;
	if (ah<0) {
		ah += PRIME;
	}

	ll bh;
	if (bl==0) bh = bHashes[br];
	else bh = (bHashes[br] - bHashes[bl-1]) % PRIME;
	if (bh<0) {
		bh += PRIME;
	}
	
	//cout << "ah bb before multiplying " << ah << " " << bh << '\n';

	ah*=powers[bl];
	bh*=powers[al];
	ah%=PRIME;
	bh%=PRIME;

	//cout << "ah bb after multiplying " << ah << " " << bh << '\n';

	if (ah!=bh) return false;
	return true;

	//return memcmp(&a[al],&b[bl],ar-al+1)==0;
}


int main(){
	powers[0]=1;

    int n;
    int m;
    int q;
    int k;
    cin >> n >> m >> q >> k;
    string s;
    cin >> s;
	//cout << s << '\n';
	for(int i=1; i<n+1 || i<q+1; i++) {
		powers[i]=powers[i-1]*128;
		powers[i]%=PRIME;
	}

	vector<unordered_map<char,Edge>> tl;

	Edge whole;
	whole.l = 0;
	whole.r = s.size();
	whole.next = -1;
	whole.freq = 1;
	tl.push_back(unordered_map<char,Edge>());
	tl[0][s[0]] = whole;

	for (int i = 1; i<s.size(); i++) {
		//cout << "i " << i << '\n';
		int ptr=0;
		for (int j = i; j<=s.size();) {
			//cout << "ptr at beginning of loop " << ptr << '\n';
			
			if (j==s.size()) {
				//cout << "End\n";
				Edge end;
				end.l = j;
				end.r = s.size();
				end.next = -1;
				end.freq = 1;
				tl[ptr]['\0']=end;
				break;
			}

			auto nextIt = tl[ptr].find(s[j]);
			if (nextIt == tl[ptr].end()) {
				//cout << "New edge beginning with " << s[j] << '\n';
				whole.l = j;
				whole.r = s.size();
				whole.next = -1;
				whole.freq = 1;
				tl[ptr][s[j]] = whole;
				break;
			}
			else {
				//cout << "There was already an edge with " << s[j] << '\n';
				//cout << "ptr " << ptr << '\n';
				//cout << "tl[ptr].size() " << tl[ptr].size() << '\n';
				Edge &next = nextIt->second;
				//cout << "next.l next.r " << next.l << " " << next.r << '\n';
				for (int k=next.l; k<=next.r;) {
					//cout << "j k " << j << " " << k << '\n';
					if (j<s.size() && s[k] == s[j]){
						k++;
						j++;
						if (k>next.r) {
							ptr = next.next;
							next.freq++;
							assert(ptr!=-1);
							// if (ptr == -1)   this never happens in this version
							break;
						}
					}
					else {
						//cout << "break edge " << next.l << " " << next.r << '\n';
						//cout << "break at position " << k << '\n';
						tl.push_back(unordered_map<char,Edge>());
						Edge end;
						end.l = j;
						end.r = s.size();
						end.next = -1;
						end.freq = 1;
						if (j==s.size()) {
							tl.back()['\0']=end;
						}
						else {
							tl.back()[s[j]]=end;
						}

						Edge cont;
						cont.l = k;
						cont.r = next.r;
						cont.next = next.next;
						cont.freq = next.freq;

						tl.back()[s[k]]=cont;

						next.r = k-1;
						//////cout << "k next.l " << k << " " << next.l << '\n';
						assert(k>next.l);
						next.next = tl.size()-1;
						next.freq++;

						goto breakOuterLoop;

					}
				}
			}
		}
breakOuterLoop:;

			   /*
			   cout << "Table of stuff after iteration: " << i << "\n" ;
			   for(int i=0; i<tl.size(); i++) {
				   cout << "Node "<<i<< ":\n";
				   for(auto it = tl[i].begin(); it!=tl[i].end(); it++) {
					   cout << "  " << it->first <<"   " << s.substr(it->second.l, it->second.r-it->second.l+1) << "   next: " << it->second.next << " freq: " << it->second.freq << '\n';
				   }
			   }
			   */
	}

	/*
	cout << "Table of stuff:\n" ;
	for(int i=0; i<tl.size(); i++) {
		cout << "Node "<<i<< ":\n";
		for(auto it = tl[i].begin(); it!=tl[i].end(); it++) {
			cout << "   " << s.substr(it->second.l, it->second.r-it->second.l+1) << "   next: " << it->second.next << " freq: " << it->second.freq << '\n';
		}
	}

	*/



	vector<ll> sHashes(s.size());
	sHashes[0] = s[0]-'\0';
	for(int i=1; i<s.size(); i++) {
		ll add = (s[i]-'\0')*powers[i];
		add%=PRIME;
		sHashes[i] = sHashes[i-1] + add;
		sHashes[i] %= PRIME;
	}

	/*
	for (int i=0; i<sHashes.size(); i++) {
		cout << sHashes[i] << " " ;
	}
	cout << '\n';
	*/


    vector< vector<int> > pairs(m,vector<int>(2));
    for(int pairs_i = 0;pairs_i < m;pairs_i++){
       for(int pairs_j = 0;pairs_j < 2;pairs_j++){
          cin >> pairs[pairs_i][pairs_j];
       }
    }

	//assert(n<1000);

	//cout << "\n\nQUERIES:\n";
	for(int a0 = 0; a0 < q; a0++){
		string w;
		int a;
		int b;
		cin >> w >> a >> b;

		vector<ll> wHashes(w.size());
		wHashes[0] = w[0]-'\0';
		for(int i=1; i<w.size(); i++) {
			ll add = (w[i]-'\0')*powers[i];
			add%=PRIME;
			wHashes[i] = wHashes[i-1] + add;
			wHashes[i] %= PRIME;
		}

		/*
		for (int i=0; i<wHashes.size(); i++) {
			cout << wHashes[i] << " " ;
		}
		cout << '\n';
		*/


		ll sum=0;
		for (int iii=a; iii<=b; iii++) {
			int l = pairs[iii][0];
			int r = pairs[iii][1];
			////cout << "Query "  << w << " " << l << " " << r << '\n';
			//cout << "Query "  << w.substr(l,r-l+1) << '\n';

			ll result = 0;
			int ptr=0;
			for (int j = l; j<=r;) {
				//cout << "j ptr " << j << " " << ptr << '\n';
				
				auto nextIt = tl[ptr].find(w[j]);
				if (nextIt == tl[ptr].end()) {
					//cout << "Character not found " << w[j] << '\n';
							goto doneSearching;
				}
				else {
					//cout << "Character found " << w[j] << '\n';
					Edge &next = nextIt->second;

					if (next.r == s.size()) {
						// end of string
						if (r-j+1 > s.size()-next.l) {
							//cout << "Word longer than end of tree.\n";

							goto doneSearching;
						}
					}

					if (r-j+1 <= next.r-next.l+1) {
						if(hashcmp(s,w, next.l, next.l+r-j, j, r, sHashes, wHashes)){
							//cout<< "Found frequency " << next.freq << '\n';
							result = next.freq;
						}
							//cout<< "continue to next query" << '\n';
						goto doneSearching;
					}

					if(hashcmp(s,w,next.l, next.r, j, j+ next.r-next.l, sHashes, wHashes)){
						ptr = next.next;
						j = j + next.r - next.l + 1;

						//cout<< "Strings are identical. Continue to next iteration"  << '\n';
						continue;
					}
					else {
						//cout<< "string mismatch"  << '\n';
						goto doneSearching;
					}
					

					/*
					for (int k=next.l; k<=next.r;) {
						//cout << "k j " << k << " " << j << '\n';
						if (k == s.size()) {
								//cout << "Got to end of tree " << '\n';
							goto doneSearching;
						}
						if (s[k] == w[j]) {
							//cout << "Match " << s[k] << '\n';

							k++;
							j++;

							if (j>r) {
								//cout << "Reached end and got frequency " << next.freq << '\n';
								result = next.freq;
								goto doneSearching;
							}
							if (k>next.r) {
								ptr = next.next;
								break;
							}

						}
						else {
							//cout << "Query doesn't match " << s[k] << " " << s[j] <<  '\n';
							goto doneSearching;
						}
					}
					*/

				}
			}
			//cout << "Reached end and nothing happened\n";
doneSearching:;
			  //cout << "resutl " << result << '\n';
			  sum += result;

		}
		cout << sum << '\n';

    }
    return 0;
}

