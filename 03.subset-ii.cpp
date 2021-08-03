class Solution {
   public:
   vector < vector <int> > res;
   set < vector <int> > x;
   static bool cmp(vector <int> a, vector <int> b){
      return a < b;
   }
   void solve(int idx, vector <int> temp, vector <int> &v){
      if(idx == v.size()){
         if(x.find(temp) == x.end()){
            res.push_back(temp);
            x.insert(temp);
         }
         return;
      }
      solve(idx+1, temp, v);
      temp.push_back(v[idx]);
      solve(idx+1, temp, v);
      temp.pop_back();
   }
   vector<vector<int> > subsetsWithDup(vector<int> &a) {
      res.clear();
      x.clear();
      sort(a.begin(), a.end());
      vector <int> temp;
      solve(0, temp, a);
      sort(res.begin(), res.end(), cmp);
      return res;
   }
};
