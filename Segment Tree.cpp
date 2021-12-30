#include <bits/stdc++.h>
using namespace std;

class Node{
  int start, mid, end; 
  Node* left, * right; 
  int sum; 
  
  public: 
    Node(int start, int end) : start(start), end(end), sum(0), left(nullptr), right(nullptr) { 
      mid = start + (end-start)/2;
    }

    // updates positions [l,r] to be val
    int update(int l, int r, int val){
      if(l > r)
        return sum; 
      if(l == start && r == end)
        return sum = val; 

      initChildren();  
      return sum = left->update(max(l, start), min(r, mid), val) + right->update(max(l, mid+1), min(r, end), val); 
    }

    int query(int l, int r){
      if(l > r)
        return 0; 
      if(l == start && r == end)
        return sum; 

      initChildren(); 
      return left->query(max(l, start), min(r, mid)) + right->query(max(l, mid+1), min(r, end)); 
    }

    void initChildren(){
      if(left == nullptr){
        left = new Node(start, mid); 
        right = new Node(mid+1, end); 
      }
    } 

    ~Node(){
      delete left; 
      delete right; 
    }
};