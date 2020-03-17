#include <iostream>
#include <string>
#include <vector>

using namespace std;
void Max_crops(vector<vector<int>> map, int &t);
int Sum(vector<int> v);
//----------------------------------------------
int main() {
  int a, b;
  cin>>a>>b;
  vector<vector<int>>map;
  for (int i=0;i<a; i++) {
    vector<int> new_row;
    for (int j =0; j<b; j++) {
      int meghdare_jadid;
      cin >> meghdare_jadid;
      new_row.push_back(meghdare_jadid);
    }
    map.push_back(new_row);
  }
  int calculate_t;
  Max_crops(map, calculate_t);
  cout<<calculate_t;
  return 0;
}
//----------------------------------------------
void Max_crops(vector<vector<int>> map, int &t) {
  vector<int> rows_crops;
  for (int i = 0; i<map.size(); i++) {
    rows_crops.push_back(Sum(map[i]));
    cerr << Sum(map[i]) << endl;
  }
  cerr << "_____________" << endl;
  vector<int> columns_crops;
  for (int i = 0; i < map[0].size(); i++) {
    int sum = 0;
    for (int j = 0; j < map.size(); j++) {
      sum+=map[j][i];
    }
    columns_crops.push_back(sum);
    cerr << sum << endl;
  }
  vector<int> max_crops(4, 0);
  for (int i=0; i<rows_crops.size(); i++) {
    if (max_crops[0]<rows_crops[i]) {
      max_crops[0] = rows_crops[i];
  bool swapp = true;
  while (swapp) {
    swapp = false;
    for (int i = 0; i<max_crops.size()-1; i++) {
      if (max_crops[i]>max_crops[i + 1]) {
        int swap_help = max_crops[i];
        max_crops[i] = max_crops[i + 1];
        max_crops[i+1] = swap_help;
        swapp = true;
      }
    }
  }
    }
  }
  for (int j=0; j <4; j++) {
    cerr << max_crops[j] <<" ";
  }
  cerr << endl;
  for (int i=0; i<columns_crops.size(); i++) {
    if (max_crops[0] < columns_crops[i]) {
      max_crops[0]=columns_crops[i];
    bool swapp = true;
  while (swapp) {
    swapp = false;
    for (int i = 0; i<max_crops.size() - 1; i++) {
      if (max_crops[i]>max_crops[i + 1]) {
        int swap_help=max_crops[i];
        max_crops[i] = max_crops[i + 1];
        max_crops[i + 1] = swap_help;
        swapp = true;
      }
    }
  }
    }
  }
  for (int j = 0; j < 4; j++) {
    cerr<<max_crops[j]<<" ";
  }
  t = Sum(max_crops);
}
//----------------------------------------------
int Sum(vector<int> v) 
{
int sum = 0;
for (auto i : v)
sum += i;
return sum;}