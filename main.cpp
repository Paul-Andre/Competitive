#include <algorithm>
#include <chrono>  // for high_resolution_clock
#include <cstring>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <cassert>

enum EntityType {
  EXPLORER = 0,
  WANDERER,
  EFFECT_PLAN,
  EFFECT_LIGHT,
  SLASHER,
  EFFECT_SHELTER,
  EFFECT_YELL,
  OTHER
};

const int MINION_SPAWNING = 0;
const int MINION_WANDERING = 1;
const int MINION_STALKING = 2;
const int MINION_RUSHING = 3;
const int MINION_STUNNED = 4;

using namespace std;

typedef pair<int, int> pii;

pii operator+(pii a, pii b) {
  return pii(a.first + b.first, a.second + b.second);
}

int width;
int height;

int playerId;

bool inBounds(pii a) {
  return (unsigned)a.first < (unsigned)width &&
         (unsigned)a.second < (unsigned)height;
}

#define IND(v, x) ((v)[(x).first][(x).second])

#define FOR_ALL_GRID(i, j)        \
  for (int i = 0; i < width; i++) \
    for (int j = 0; j < height; j++)

const int DIM = 24;

/*
uint16_t distances[DIM][DIM][DIM][DIM];
*/

pii qq[DIM * DIM];

char grid[DIM][DIM];

bool inGroup[DIM][DIM];
bool vis[DIM][DIM];
int hasPlayer[DIM][DIM];

double reward[DIM][DIM];
double utility[DIM][DIM];
double orig_spook[DIM][DIM];
double spook[DIM][DIM];

double interm[DIM][DIM];

double discouts[1000];

const double alpha = 0.8;

int turn = 0;

vector<pii> groupCells;
vector<pii> walkCells = {pii(0, 1), pii(1, 0), pii(-1, 0), pii(0, -1)};
vector<pii> walkOrCowardCells = {pii(0, 1), pii(1, 0), pii(-1, 0), pii(0, -1),
                                 pii(0, 0)};

int wocDx[] = {0, 1, 0, -1, 0};
int wocDy[] = {1, 0, -1, 0, 0};
int wDx[] = {0, 1, 0, -1};
int wDy[] = {1, 0, -1, 0};

/*
void initDistances() {
  for (int i=0; i<DIM; i++) {
    for (int j=0; j<DIM; j++) {
      int w = 0;
      int r = 0;
      qq[w] = pii(i,j);
      w++;
      distances[i][j][i][j] = 0;
      while(w != r) {
        int size = r - w;
        for (int z=0; z<size; z++) {
          int x = qq[r].first;
          int y = qq[r].second;
          r ++;
          for (int k=0; k<4; k++) {

          */

#define ZERO_OUT(x) memset(&x, 0, sizeof(x))

struct Entity {
 public:
  EntityType entityType;
  int id;
  pii position;
  int param0;
  int param1;
  int param2;

  void read_in() {
    string type;
    cin >> type >> id >> position.first >> position.second >> param0 >>
        param1 >> param2;

    if (type == "EXPLORER")
      entityType = EXPLORER;
    else if (type == "WANDERER")
      entityType = WANDERER;
    else if (type == "EFFECT_PLAN")
      entityType = EFFECT_PLAN;
    else if (type == "EFFECT_LIGHT")
      entityType = EFFECT_LIGHT;
    else if (type == "SLASHER")
      entityType = SLASHER;
    else if (type == "EFFECT_SHELTER")
      entityType = EFFECT_SHELTER;
    else if (type == "EFFECT_YELL")
      entityType = EFFECT_YELL;
    else
      entityType = OTHER;

    cin.ignore();
  }
};

struct Player {
 public:
  int id;
  pii position;
  int sanity;
  int plans;
  int lights;

  Player(Entity &e) {
    assert(e.entityType == EXPLORER);
    id = e.id;
    position = e.position;
    sanity = e.param0;
    plans = e.param1;
    lights = e.param2;
  }
};

const int sanityLossSpook = 20;

/**
 * Survive the wrath of Kutulu
 * Coded fearlessly by JohnnyYuge & nmahoude (ok we might have been a bit scared
 *by the old god...but don't say anything)
 **/
int main() {
  discouts[0] = 1;
  for (int i = 1; i < 1000; i++) {
    discouts[i] = discouts[i - 1] * 0.8;
  }

  memset(&grid, '#', sizeof(grid));

  for (int i = -2; i <= 2; i++) {
    for (int j = -2; j <= 2; j++) {
      if (i + j <= 2) {
        groupCells.push_back(pii(i, j));
      }
    }
  }

  cin >> width;
  cin.ignore();
  cin >> height;
  cin.ignore();

  for (int j = 0; j < height; j++) {
    for (int i = 0; i < width; i++) {
      cin >> grid[i][j];
    }
  }

  int sanityLossLonely;  // how much sanity you lose every turn when alone,
                         // always 3 until wood 1
  int sanityLossGroup;  // how much sanity you lose every turn when near another
                        // player, always 1 until wood 1
  int wandererSpawnTime;  // how many turns the wanderer take to spawn, always 3
                          // until wood 1
  int wandererLifeTime;   // how many turns the wanderer is on map after
                          // spawning, always 40 until wood 1
  cin >> sanityLossLonely >> sanityLossGroup >> wandererSpawnTime >>
      wandererLifeTime;
  cin.ignore();

  // game loop
  while (1) {
    int entityCount;  // the first given entity corresponds to your explorer
    int currentEffect = 0;
    cin >> entityCount;
    auto start = std::chrono::high_resolution_clock::now();
    cin.ignore();

    bool inDanger = false;

    ZERO_OUT(inGroup);
    ZERO_OUT(reward);
    ZERO_OUT(utility);
    ZERO_OUT(orig_spook);
    ZERO_OUT(spook);
    ZERO_OUT(hasPlayer);

    vector<Entity> entities(entityCount);
    vector<Player> otherPlayers;

    for (int i = 0; i < entityCount; i++) {
      entities[i].read_in();
      if (entities[i].entityType == EXPLORER && i != 0) {
        otherPlayers.push_back(Player(entities[0]));
      }
    }

    playerId = entities[0].id;

    for (Entity &entity : entities) {
      if (entity.entityType == EXPLORER && entity.id != playerId) {

        for (pii p : groupCells) {
          pii t = entity.position + p;
          if (inBounds(t)) IND(inGroup, t) = true;
        }
        IND(hasPlayer, entity.position)++;
      } else if (entity.entityType == WANDERER) {
        if (entity.param1 == MINION_SPAWNING) {
          for (pii p : walkOrCowardCells) {
            IND(orig_spook, entity.position + p) -=
                sanityLossSpook * discouts[entity.param0];
          }
        } else {
          for (pii p : walkOrCowardCells) {
            IND(orig_spook, entity.position + p) -= sanityLossSpook;
            if (entities[0].position == entity.position + p) {
              inDanger = true;
            }
          }
        }
      } else if (entity.entityType == SLASHER) {
        if (entity.param1 == MINION_STUNNED) {
          IND(orig_spook, entity.position) -=
              sanityLossSpook * discouts[entity.param0 + 2];
        } else if (entity.param1 == MINION_WANDERING) {
          IND(orig_spook, entity.position) -= sanityLossSpook;
        } else {
          int idRushing = entity.param2;
          if (idRushing == -1) cerr << "idRushing is -1\n";

          int tillRush = 0;

          if (entity.param1 == MINION_SPAWNING ||
              entity.param1 == MINION_STALKING) {
            tillRush = entity.param0;
          }

          double value = discouts[tillRush] * sanityLossSpook;

          IND(reward, entity.position) -= value;
          if (entity.position == entities[0].position && tillRush <= 1) {
            inDanger = true;
          }

          if (idRushing == playerId) {
            for (pii dir : walkCells) {
              pii p = entity.position;
              pii pp = p + dir;
              while (IND(grid, pp) != '#') {
                if (pp == entities[0].position && tillRush <= 1) {
                  inDanger = true;
                }
                IND(reward, pp) -= value;
                pp = pp + dir;
              }
            }
          }
        }
      } else if (entity.entityType == EFFECT_SHELTER) {
        if (entity.param0 != 0) {
          IND(reward, entity.position) += 5;
        } else if (turn != 0) {
          IND(reward, entity.position) += 5 * discouts[50 - (turn % 50)];
        }
      } else if (entity.entityType == EFFECT_PLAN &&
                 entity.param1 == playerId) {
        currentEffect = EFFECT_PLAN;
      } else if (entity.entityType == EFFECT_PLAN &&
                 entity.param1 != playerId) {
        ZERO_OUT(vis);
        queue<pii> q;
        IND(vis, entity.position) = true;
        q.push(entity.position);
        IND(reward, entity.position) += 3;
        int cnt = 0;
        while (cnt < 2) {
          int size = q.size();
          for (int i = 0; i < size; i++) {
            pii v = q.front();
            q.pop();
            for (pii p : walkCells) {
              pii pp = p + v;
              if (inBounds(pp) && IND(grid, pp) != '#' && !IND(vis, pp)) {
                IND(vis, pp) = true;
                q.push(pp);
                IND(reward, pp) += 3;
              }
            }
            cnt++;
          }
        }
      }
    }

    if (currentEffect == EFFECT_PLAN) {
      for (Entity &entity : entities) {
        if (entity.entityType == EXPLORER && entity.id != playerId) {
          ZERO_OUT(vis);
          queue<pii> q;
          IND(vis, entity.position) = true;
          q.push(entity.position);
          IND(reward, entity.position) += 3;
          int cnt = 0;
          while (cnt < 2) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
              pii v = q.front();
              q.pop();
              for (pii p : walkCells) {
                pii pp = p + v;
                if (inBounds(pp) && IND(grid, pp) != '#' && !IND(vis, pp)) {
                  IND(vis, pp) = true;
                  q.push(pp);
                  IND(reward, pp) += 3;
                }
              }
              cnt++;
            }
          }
        }
      }
    }

    FOR_ALL_GRID(i, j) {
      if (inGroup[i][j])
        reward[i][j] -= sanityLossGroup;
      else
        reward[i][j] -= sanityLossLonely;
      if (grid[i][j] == 'w') reward[i][j] -= 0.001;
    }

    if (!inDanger && currentEffect == 0 && entities[0].param1 != 0) {
      int otherSeen = 0;
      ZERO_OUT(vis);
      queue<pii> q;
      IND(vis, entities[0].position) = true;
      otherSeen += IND(hasPlayer, entities[0].position);
      q.push(entities[0].position);
      int cnt = 0;
      while (cnt < 2) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
          pii v = q.front();
          q.pop();
          for (pii p : walkCells) {
            pii pp = p + v;
            if (inBounds(pp) && IND(grid, pp) != '#' && !IND(vis, pp)) {
              IND(vis, pp) = true;
              otherSeen += IND(hasPlayer, pp);
              q.push(pp);
            }
          }
          cnt++;
        }
      }
      cerr << "tried " << otherSeen << endl;
      if ((turn > 25 && otherSeen >= 1) || (turn > 50 && otherSeen >= 1)) {
        cout << "PLAN it's important" << endl;
        continue;
      }
    }

    for (int iii = 0; iii < 200; iii++) {
      FOR_ALL_GRID(i, j) {
        double tot = 0;
        int cnt = 0;
        double best = +std::numeric_limits<double>::infinity();
        for (int k = 0; k < 5; k++) {
          int x = i + wocDx[k];
          int y = j + wocDy[k];
          if ((unsigned)x < (unsigned)width && (unsigned)y < (unsigned)height &&
              grid[x][y] != '#') {
            double u = spook[x][y];
            tot += u;
            best = min(best, u);
            cnt++;
          }
        }
        interm[i][j] = orig_spook[i][j] + alpha * (tot / cnt);
      }
      FOR_ALL_GRID(i, j) { spook[i][j] = interm[i][j]; }
    }

    FOR_ALL_GRID(i, j) { reward[i][j] += spook[i][j]; }

    for (int iii = 0; iii < 200; iii++) {
      FOR_ALL_GRID(i, j) {
        double tot = 0;
        double best = -std::numeric_limits<double>::infinity();
        int cnt = 0;
        for (int k = 0; k < 5; k++) {
          int x = i + wocDx[k];
          int y = j + wocDy[k];
          if ((unsigned)x < (unsigned)width && (unsigned)y < (unsigned)height &&
              grid[x][y] != '#') {
            double u = utility[x][y];
            tot += u;
            best = max(best, u);
            cnt++;
          }
        }
        interm[i][j] = reward[i][j] + alpha * best;
      }
      FOR_ALL_GRID(i, j) { utility[i][j] = interm[i][j]; }
    }

    pii p = entities[0].position;
    pii best_go = p;
    double best_util = -std::numeric_limits<double>::infinity();

    for (pii k : walkOrCowardCells) {
      pii t = p + k;
      if (inBounds(t) && IND(grid, t) != '#') {
        if (IND(utility, t) > best_util) {
          best_util = IND(utility, t);
          best_go = t;
        }
      }
    }

    cerr << IND(inGroup, p) << endl;

    auto finish = std::chrono::high_resolution_clock::now();
    cerr << chrono::duration_cast<chrono::milliseconds>(finish - start).count()
         << endl;

    cout << "MOVE " << best_go.first << " " << best_go.second
         << " WE  W A L K I N" << endl;  // MOVE <x> <y> | WAIT
    turn++;
  }
}
