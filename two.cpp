vector<int> printSingles(Node *root, vector<int> &v)   
{   
  if (root == NULL)   
   return v;   
    
  queue<Node *> q1; 
  q1.push(root); 
  
  int flag=0;
  while(q1.empty() == false) 
  { 
      Node * temp=q1.front(); 
      q1.pop(); 
      if(temp->left != NULL &&  
                      temp->right == NULL) 
      { 
          flag=1; 
          v.push_back(temp->left->data); 
      } 
      if(temp->left == NULL &&  
                        temp->right != NULL) 
      { 
          flag=1; 
          v.push_back(temp->right->data); 
      } 
  
      if(temp->left != NULL) 
      { 
          q1.push(temp->left); 
      } 
      
      if(temp->right != NULL) 
      { 
          q1.push(temp->right); 
      } 
  } 
  sort(v.begin(), v.end());
  
  return v;
}
vector<int> noSibling(Node* node)
{
    vector<int> a;
    a=printSingles(node, a);
    if(a.size()==0)
    a.push_back(-1);
    return a;
}