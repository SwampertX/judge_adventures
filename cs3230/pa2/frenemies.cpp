#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> ii;

int r, c;
vector<string> grid;
ii cstart, lstart, qstart, flag;

// 0,1,2,3 lrud
// rr, cc here are unmoved, need to make a move
ii getNextCell(int rr, int cc, int dir, bool sliding) {
  int nextr, nextc, addc, addr;
  addc = dir == 0 ? -1 : dir == 1 ? 1 : 0;
  addr = dir == 2 ? -1 : dir == 3 ? 1 : 0;
  nextc = cc + addc;
  nextr = rr + addr;
  /* printf("(%d,%d) go to (%d,%d)\n", rr, cc, nextr, nextc); */
  if (nextc < 0 || nextc >= c || nextr < 0 || nextr >= r) {
    /* cout << "overshoot" << endl; */
    return ii(-1, -1);
  }
  // try stepping into next step
  switch (grid[nextr][nextc]) {
  case ' ':   // next step is solid ground, stop here. return
  case 'c':   // next step is solid ground, stop here. return
  case 'l':   // next step is solid ground, stop here. return
  case 'q':   // next step is solid ground, stop here. return
  case '%': { // finish. acts as a solid groud {
    /* cout << "solid or finish" << endl; */
    return sliding? getNextCell(nextr, nextc, dir, true): ii(nextr, nextc);
  }
  case '.': { // slide to the next one {}
    /* cout << "slide" << endl; */
    return getNextCell(nextr, nextc, dir, true);
  }
  case '#': { // cannot move. return current
    /* cout << "rock" << endl; */
    return ii(rr, cc);
  }
  case 'O': { // it is a hole, die.
    /* cout << "hole die" << endl; */
    return ii(-1, -1);
  }
  default: { // don't by default, maybe? CLQ
    /* cout << nextr << nextc << " default die, actually '" << grid[nextr][nextc] */
         /* << "'" << endl; */
    return ii(-1, -1);
  }
  }
}

queue<ii> getVisitable(int r, int c) {
  queue<ii> visitable;
  ii nextCell;
  /* printf("getting visitable for (%d,%d)\n", r, c); */
  // 0123 lrud
  for (int i = 0; i < 4; i++) {
    nextCell = getNextCell(r, c, i, false);
    /* printf("next cell returned is (%d,%d)\n", nextCell.first, nextCell.second); */
    if (nextCell == ii(3, 2)) {
      /* printf("here visitable\n"); */
    }
    if (nextCell.first != -1 && nextCell != ii(r, c)) {
      /* cout << "can visit" << endl; */
      visitable.push(nextCell);
    }
  }
  return visitable;
}

int bfs(ii start, ii end, map<ii, ii> &pred) {
  bool visited[r][c];
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      visited[i][j] = false;
    }
  }
  queue<pair<ii, int>> toVisit;
  toVisit.push(make_pair(start, 0));
  while (!toVisit.empty()) {
    ii curr = toVisit.front().first;
    int weight = toVisit.front().second;
    /* printf("visiting (%d,%d): %d, visited:%d\n", curr.first, curr.second, */
           /* weight, visited[curr.first][curr.second]); */
    toVisit.pop();
    if (curr == end) {
      /* printf("finished, length is %d\n", weight); */
      return weight;
    }
    if (!visited[curr.first][curr.second]) {
      visited[curr.first][curr.second] = true;
      queue<ii> visitable = getVisitable(curr.first, curr.second);
      while (!visitable.empty()) {
        ii next = visitable.front();
        visitable.pop();
        /* printf("can visit (%d,%d)\n", next.first, next.second); */
        if (!visited[next.first][next.second]) {
          /* if (next == ii(3,2)) { printf("here"); } */
          pred[next] = curr;
          toVisit.push(make_pair(next, weight + 1));
        }
      }
    }
  }
  return 0;
}

string dirChar(ii curr, ii prev) {
  return curr.first > prev.first
             ? "v"
             : curr.first < prev.first ? "^"
                                       : curr.second > prev.second ? ">" : "<";
}

void printPath(string c, map<ii, ii> &pred) {
  /* printf("printing path flag:(%d,%d) prev:(%d,%d)\n", flag.first, flag.second, */
         /* pred[flag].first, pred[flag].second); */
  ii curr = flag, prev;
  stack<string> toPrint;
  string temp;
  while (pred.count(curr)) {
    prev = pred[curr];
    temp.clear();
    temp.append(c);
    temp.append(" ");
    temp.append(dirChar(curr, prev));
    toPrint.push(temp);
    curr = prev;
  }
  while (!toPrint.empty()) {
    cout << toPrint.top() << endl;
    toPrint.pop();
  }
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  cin >> r >> c;
  /* cout << r << c; */
  grid.reserve(r);
  string line;
  char cell;
  // clean up the line
  getline(cin, line);
  // ditch the first line
  getline(cin, line);
  for (int i = 0; i < r; i++) {
    getline(cin, line);
    grid.push_back(line.substr(1, c));
    for (int j = 0; j < c; j++) {
      cell = line[j + 1];
      /* cout << cell; */
      switch (cell) {
      case 'c':
        cstart = ii(i, j);
        break;
      case 'l':
        lstart = ii(i, j);
        break;
      case 'q':
        qstart = ii(i, j);
        break;
      case '%':
        flag = ii(i, j);
        break;
      default:
        break;
      }
    }
    /* cout << endl; */
  }
  /* printf("flag:%d,%d, cstart:%d,%d, lstart:%d,%d, qstart:%d,%d\n", flag.first, */
  /*        flag.second, cstart.first, cstart.second, lstart.first, lstart.second, */
  /*        qstart.first, qstart.second); */

  map<ii, ii> cpred, lpred, qpred;
  int clen, llen, qlen;
  clen = bfs(cstart, flag, cpred);
  llen = bfs(lstart, flag, lpred);
  qlen = bfs(qstart, flag, qpred);

  if (!clen || !llen || !qlen) {
      cout<<"IMPOSSIBLE\n";
      return 0;
  }
  cout << clen + llen + qlen << endl;
  printPath("c", cpred);
  printPath("l", lpred);
  printPath("q", qpred);
}
