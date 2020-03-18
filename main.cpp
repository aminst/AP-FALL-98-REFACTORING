#include <iostream>
#include <string>
#include <vector>

using namespace std;
#define MAX_DAY_YEILD 4

typedef vector<vector<int>> map_t;

map_t read_map();
map_t read_sized_map(const int &rows_size, const int &columns_size);
int find_max_crops(const map_t &map);
vector<int> sum_row_crops(const map_t &map);
vector<int> sum_columns_crops(const map_t &map);
int calculate_max_crops(const vector<int> &rows_crops,
                        const vector<int> &columns_crops);
vector<int> sort(vector<int> v);
int sum(const vector<int> &v);
void add_to_top_yeilds(vector<int> &max_crops, vector<int> sums);

int main() {
  map_t map = read_map();
  cout << find_max_crops(map);
  return 0;
}

map_t read_map() {
  int row, column;
  cin >> row >> column;
  return read_sized_map(row, column);
}

map_t read_sized_map(const int &rows_size, const int &columns_size) {
  map_t map;
  for (int i = 0; i < rows_size; i++) {
    vector<int> new_row;
    for (int j = 0; j < columns_size; j++) {
      int new_value;
      cin >> new_value;
      new_row.push_back(new_value);
    }
    map.push_back(new_row);
  }
  return map;
}

int find_max_crops(const map_t &map) {
  vector<int> rows_crops = sum_row_crops(map);
  vector<int> columns_crops = sum_columns_crops(map);
  return calculate_max_crops(rows_crops, columns_crops);
}

vector<int> sum_row_crops(const map_t &map) {
  vector<int> sums;
  for (int i = 0; i < map.size(); i++) {
    sums.push_back(sum(map[i]));
    cerr << sum(map[i]) << endl;
  }
  cerr << "_____________" << endl;
  return sums;
}

vector<int> sum_columns_crops(const map_t &map) {
  vector<int> sums;
  for (int i = 0; i < map[0].size(); i++) {
    int sum = 0;
    for (int j = 0; j < map.size(); j++) {
      sum += map[j][i];
    }
    sums.push_back(sum);
    cerr << sum << endl;
  }
  return sums;
}

int calculate_max_crops(const vector<int> &rows_crops,
                        const vector<int> &columns_crops) {
  vector<int> max_crops(MAX_DAY_YEILD, 0);
  add_to_top_yeilds(max_crops, rows_crops);
  for (int j = 0; j < MAX_DAY_YEILD; j++) {
    cerr << max_crops[j] << " ";
  }
  cerr << endl;
  add_to_top_yeilds(max_crops, columns_crops);
  for (int j = 0; j < MAX_DAY_YEILD; j++) {
    cerr << max_crops[j] << " ";
  }
  return sum(max_crops);
}

void add_to_top_yeilds(vector<int> &max_crops, vector<int> sums) {
  for (int i = 0; i < sums.size(); i++) {
    if (max_crops[0] < sums[i]) {
      max_crops[0] = sums[i];
      max_crops = sort(max_crops);
    }
  }
}

vector<int> sort(vector<int> v) {
  bool swapp = true;
  while (swapp) {
    swapp = false;
    for (int i = 0; i < v.size() - 1; i++) {
      if (v[i] > v[i + 1]) {
        int swap_help = v[i];
        v[i] = v[i + 1];
        v[i + 1] = swap_help;
        swapp = true;
      }
    }
  }
  return v;
}

int sum(const vector<int> &v) {
  int sum = 0;
  for (auto i : v)
    sum += i;
  return sum;
}
