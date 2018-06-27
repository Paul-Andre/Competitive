#include <bits/stdc++.h>

using namespace std;

int n;
int q;
int sqrtn;
int C[50001];
vector<int> G[50001];

int path_ptr;
int path[100003];
int corresp[50001];
int corresp_last[50001];

bool vis[50001];

void tour(int i) {
    vis[i] = true;

    path[path_ptr] = i;
    corresp[i] = path_ptr;
    corresp_last[i] = path_ptr;
    path_ptr ++;

    for(int j=0; j<G[i].size(); j++) {
        int u = G[i][j];
        if (!vis[u]) {
            tour(u);

            path[path_ptr] = i;
            corresp_last[i] = path_ptr;
            path_ptr++;
        }
    }
}

typedef pair<int,int> pii;
typedef pair<pii, pii> ppiipii;

vector<ppiipii> queries;

bool sq(ppiipii a, ppiipii b) {
    int al = a.first.first;
    int bl = b.first.first;
    int ar = a.first.second;
    int br = b.first.second;
    int aln = al/sqrtn;
    int bln = bl/sqrtn;
    if (aln != bln) return aln < bln;
    return ar < br;
}

int query_results[50000];

float randomFloat() {
    return (float)rand() / RAND_MAX;
}


struct bst;

void printBst(bst *b);

void validate(bst *b, bst *p);

struct bst {
    static bst *root;

    pii value;
    float weight;
    int size;
    bst *left;
    bst *right;
    bst *parent;

    static bst *reused;

    bst(){}

    static bst* mkbst(pii val, float w, bst *par);

    static void deletebst(bst *b);


    static int getSize(bst *b) ;

    int getDepth(bst *b) {
        if (b==nullptr) {
            return 0;
        }
        else return b->depth();
    }

    int depth() {
        return 1 + max(getDepth(left), getDepth(right));
    }

    bst *find(pii val) {
        if (val==value) return this;
        else if (val > value) return left->find(val);
        else return right->find(val);
    }

    void recalculateSize() {
        size = getSize(left) + getSize(right) + 1;
    }

    void assertParenthood() {
        if (this == nullptr) return;
        if (left != nullptr) {
            left->parent = this;
        }
        if (right != nullptr) {
            right->parent = this;
        }
    }

    void rotateLeft() {
        //cerr << "rotatingLeft\n";
        if (left == nullptr) return;
        bst *l = this->left;
        bst *b = l->right;
        this->left = b;
        l->right = this;
        if (this->parent != nullptr) {
            if (this->parent->left == this) {
                this->parent->left = l;
            }
            else {
                this->parent->right = l;
            }
        }
        else {
            root = l;
        }

        l->parent = this->parent;
        l->assertParenthood();
        this->assertParenthood();

        this->recalculateSize();
        l->recalculateSize();
    ////validate(bst::root, nullptr);
    }


    void rotateRight() {
        //cerr << "rotatingRight\n";
        if (right == nullptr) return;
        bst *l = this->right;
        bst *b = l->left;
        this->right = b;
        l->left = this;
        if (this->parent != nullptr) {
            if (this->parent->right == this) {
                this->parent->right = l;
            }
            else {
                this->parent->left = l;
            }
        }
        else {
            root = l;
        }

        l->parent = this->parent;
        l->assertParenthood();
        this->assertParenthood();

        this->recalculateSize();
        l->recalculateSize();
    //validate(bst::root, nullptr);
    }

    static void insert(pii val) ;

    void insert_inner(pii val) {
        size++;
        if (val > value) {
            if (left != nullptr) {
                left->insert_inner(val);
            }
            else {
                left = mkbst(val, randomFloat(), this);
                left->balanceUp();
            }
        }
        else {
            if (right != nullptr) {
                right->insert_inner(val);
            }
            else {
                right = mkbst(val, randomFloat(), this);
                right->balanceUp();
            }
        }
    }


    void balanceUp() {
        //cerr << "Balance  up\n";
        while (parent != nullptr) {
            if (parent->weight > weight) {
                if (parent->left == this) {
                    parent->rotateLeft();
                }
                else {
                    parent->rotateRight();
                }
            }
            else return;
        }
        root = this;
    }

    static void remove(pii val) ;

    void goDown() {
        while (left != nullptr || right != nullptr) {
            if (left == nullptr) rotateRight();
            else if (right == nullptr) rotateLeft();
            else if (left->weight < right->weight) {
                rotateLeft();
            }
            else {
                rotateRight();
            }
        }
    }

    static void snip(bst *b);

    bst *kth(int k) {
        //cerr << "kth " << k <<endl;
        //cerr << "But the size of this is " <<size << endl;
        int kk = k-getSize(left);
        if (kk < 1) return left->kth(k);
        if (kk == 1) return this;
        return (right->kth(kk-1));
    }


};

bst *bst::root = nullptr;
bst *bst::reused = nullptr;


void validate(bst *b, bst *p) {
    if (b == nullptr) return;
    if (b->parent != p) {
        printBst(bst::root);
        cerr << b->weight <<endl;
    }
    assert(b->parent == p);
    validate(b->left, b);
    validate(b->right, b);
}

void printBst(bst *b) {
    if( b == nullptr) {
        cerr << "NULL";
    }
    else {
        cerr << "( " << b->value.first << " "<<b->value.second << " " <<b->weight << " )[ ";
        printBst(b->left);
        cerr << ", ";
        printBst(b->right);
        cerr << "]\n";
    }
}

    

bst* bst::mkbst(pii val, float w, bst *par) {
    bst *b;
    if (reused == nullptr) {
        b = new bst();
    }
    else {
        b = reused;
        reused = nullptr;
    }
    b->value = val;
    b->weight =w;
    b->size = 1;
    b->left = b->right = nullptr;
    b->parent = par;
    return b;
}

void bst::deletebst(bst *b) {
    if (reused == nullptr) reused = b;
    else delete b;
}


int bst::getSize(bst *b) {
    if (b==nullptr) return 0;
    else return b->size;
}

void bst::insert(pii val) {
    if (root == nullptr) root = mkbst(val, randomFloat(), nullptr);
    else root->insert_inner(val);
}


void bst::remove(pii val) {
    //cerr << "before going down, we have ";
    //printBst(root);
    bst *b = root->find(val);
    b->goDown();

    //cerr << "before removing, we have ";
    //printBst(root);

    snip(b);
    //cerr << "after removing, we have ";
    //printBst(root);
    //nint c; cin >>c;
}


void bst::snip(bst *b) {
    //cerr << "Snipping " << b->value.first << " " <<b->value.second  <<endl;
    if (b->parent == nullptr) root = nullptr;
    else if (b->parent->left == b) b->parent->left = nullptr;
    else if (b->parent->right == b) b->parent->right = nullptr;
    bst *p = b->parent;
    deletebst(b);

    while(p!=nullptr) {
        p->recalculateSize();
        p = p->parent;
    }
}


unordered_map<int, int> occ;

void inc(int i) {
    //cerr << "Incrementing " << i <<endl;
    if (occ.find(i) == occ.end()) {
        occ[i] = 1;
        bst::insert(pii(1, i));
    }
    else {
        int j = occ[i];
        bst::remove(pii(j, i));
        bst::insert(pii(j+1, i));
        occ[i] = j+1;
    }
}

void dec(int i) {
    //cerr << "Decrementing " << i <<endl;
        int j = occ[i];
        assert(j>=1);
        
        if (j==1) {
            bst::remove(pii(j, i));
            occ.erase(i);
        }
        else {
        
            bst::remove(pii(j, i));
            bst::insert(pii(j-1, i));
            occ[i] = j-1;
        }
}

int cnt[50001];
bool hasIn[50001];
bool hasOut[50001];
bool considered[50001];

void reconsider(int i) {
    //cerr << "COnsidering "<< i <<endl;
    bool must = (!hasIn[i] || !hasOut[i] ) && cnt[i] > 0;
    //cerr << must << endl;
    if (must && !considered[i]) {
        considered[i] = true;
        inc(C[i]);
    }
    else if (!must && considered[i]) {
        considered[i] = false;
        dec(C[i]);
    }
}

void printStats(int i, int j) {
    cerr << "=======================================================\n";
    cerr << "Considering path between "<<path[i] <<" and " <<path[j] <<".\n";
    cerr << "Size of occ " << occ.size() <<endl;
    cerr << "Occ:\n";
    for(auto it = occ.begin(); it!=occ.end(); it++) {
        cerr << it->first <<" " <<it->second <<endl;
    }

    cerr << "Size of bst " << bst::root->size <<endl;

    for(int i=0; i<bst::root->size; i++) {
        pii v = bst::root->kth(i+1)->value;
        cerr << v.second << " " <<v.first << endl;
    }
    printBst(bst::root);
    validate(bst::root, nullptr);
    int x;
    //cin >>x;
    cerr << "=======================================================\n";
}


int main() {
    cin >> n >> q;
    sqrtn = sqrt(n);
    for(int c_i = 1; c_i <= n; c_i++){
       cin >> C[c_i];
    }
    for(int a0 = 0; a0 < n-1; a0++){
        int u;
        int v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    path_ptr = 1;
    tour(1);
    corresp[0] = -1;

    /*
    cerr << "Path: ";
    for(int i=1; i<path_ptr; i++) {
        cerr << path[i] << " ";
    }
    cerr <<endl;

    cerr << "Corresp: ";
    for (int i=1; i<=n; i++) {
        cerr << corresp[i] <<" ";
    }
    cerr <<endl;
    */



    for(int a0 = 0; a0 < q; a0++){
        int u;
        int v;
        int k;
        cin >> u >> v >> k;
        u = corresp[u];
        v = corresp[v];
        if ( u > v) {
            int tmp = u;
            u = v;
            v = tmp;
        }
        //v;
        queries.push_back(ppiipii(pii(u, v), pii(k, a0)));
    }
    sort(queries.begin(), queries.end(), sq);

    /*
    for(int q_i=0; q_i<q; q_i++) {
        ppiipii query = queries[q_i];
        cerr << query.first.first << " " << query.first.second << " | ";
        cerr << query.second.first << " " << query.second.second <<endl;
    }
    */

    int i = 1;
    int j = 1;

    inc(C[path[i]]);
    cnt[path[i]] ++;
    considered[1] = true;

    //printStats(i, j);

    for(int q_i=0; q_i<q; q_i++) {
        ppiipii query = queries[q_i];
        int l = query.first.first;
        int r = query.first.second;
        int k = query.second.first;
        //cerr << "Now doing query " << l << " "<< r <<endl;

        while(i>l) {
            //cerr << "i>l\n";
            cnt[path[i-1]] ++;

            if (corresp[path[i]] == i) {
                hasIn[path[i]] = true;
            }

            if (corresp_last[path[i-1]] == i-1) {
                hasOut[path[i-1]] = true;
            }

            reconsider(path[i]);
            reconsider(path[i-1]);
            i--;
            //printStats(i, j);
        }

        while(j<r) {
            //cerr << "j<r\n";
            cnt[path[j+1]] ++;

            if (corresp_last[path[j]] == j) {
                hasOut[path[j]] = true;
            }

            if (corresp[path[j+1]] == j+1) {
                hasIn[path[j+1]] = true;
            }

            reconsider(path[j]);
            reconsider(path[j+1]);
            j++;
            //printStats(i, j);
        }

        while( i< l) {
            //cerr << "i<l\n";
            cnt[path[i]] -- ;

            if(corresp_last[path[i]] == i) {
                hasOut[path[i]] = false;
            }
            if(corresp[path[i+1]] == i+1) {
                hasIn[path[i+1]] = false;
            }

            reconsider(path[i]);
            reconsider(path[i+1]);
            i++;
            //printStats(i, j);
        }

        while( j> r) {
            //cerr << "j>r\n";
            cnt[path[j]] -- ;

            if(corresp[path[j]] == j) {
                hasIn[path[j]] = false;
            }
            if(corresp_last[path[j-1]] == j-1) {
                hasOut[path[j-1]] = false;
            }

            reconsider(path[j]);
            reconsider(path[j-1]);
            j--;
            //printStats(i, j);
        }


        cerr << "Size: " << bst::root->size << "Depth: " << bst::root->depth() << endl;
        query_results[query.second.second] = bst::root->kth(k)->value.second;
    }
    for(int i=0; i<q; i++) {
        cout <<query_results[i] <<endl;
    }

        
    return 0;
}
