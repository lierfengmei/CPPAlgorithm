/*找到一棵树中两个节点的最低公共祖先*/

TreeNode* FindLastCommonParent(TreeNode* pRoot,TreeNode* pNode1,TreeNode* pNode2)
{
  if(pRoot==NULL || pNode1==NULL || pNode2==NULL)
    return NULL;
  
  deque<TreeNode*> dequeNode1;
  dequeNode1.clear();
  FindRouteOfNode(pRoot,pNode1,dequeNode1);
   
  deque<TreeNode*> dequeNode2;
  dequeNode2.clear();
  FindRouteOfNode(pRoot,pNode2,dequeNode2);

  //Find Last Common Parent by two deques
  TreeNode* pParent1 = NULL;
  TreeNode* pParent2 = NULL; 

  if(dequeNode1.size()>=2 && dequeNode2.size()>=2)
  {
    pParent1 = dequeNode1.front();
    pParent2 = dequeNode2.front();
   
    if(pParent1!=pParent2) return NULL;

    dequeNode1.pop_front();
    dequeNode2.pop_front();

    if(dequeNode1.front()!=dequeNode2.front()) return pParent2;
  }
  
  if(dequeNode1.size()==1 || dequeNode2.size()==1) &&(dequeNode1.front()==dequeNode2.front())
    return dequeNode1.front();

  return NULL;
}


bool ifFind = false;
deque<TreeNode*> dequeNode1Result;
dequeNode1Result.clear();

void FindRouteOfNode(TreeNode* pRoot,TreeNode* pNode, deque<TreeNode*> dequeNode)
{
  while(pRoot==NULL || pNode==NULL) return;

  if(ifFind) return;

  TreeNode* pWalk = pRoot;
  while(pWalk!=NULL)
  {
    if(pWalk!=pNode)
    {
      dequeNode.push_back(pWalk);
      FindRouteOfNode(pWalk->p_mChildren1,pNode,dequeNode);
      FindRouteOfNode(pWalk->p_mChildren2,pNode,dequeNode);  
    }
    else 
    {
      ifFind = true;
      copy(dequeNode1Result,duqeNode);
      return;
    } 
  }

  return;

}



//在pRoot所在的树中查找包含pNode的路径。
bool GetNodePath(TreeNode* pRoot,TreeNode* pNode,list<TreeNode*>& path)
{
  if(pRoot == pNode) return true;

  path.push_back(pRoot);

  bool found = false;

  vector<TreeNode*>::iterator it = pRoot->m_vChildren.begin();
  while(it!=pRoot->m_vChildren.end() && !found)
  {
    found = GetNodePath(*it,pNode,path);
    ++it;
  }

  if(!found) path.pop_back();

  return found;
}

TreeNode* GetLastCommonNode(const list<TreeNode*>& path1,const list<TreeNode*>& path2)
{
  list<TreeNode*>::const_iterator iter1 = path1.begin();
  list<TreeNode*>::const_iterator iter2 = path2.begin();

  TreeNode* pLastNode = NULL;

  while(iter1!=path1.end() && iter2!=path2.end())
  {
    if(*iter1 == *iter2) pLastNode = *iter1;
    else return pLastNode;
    iter1++;
    iter2++;
  }
}

TreeNode* GetLastParent(TreeNode* pRoot,TreeNode* pNode1,TreeNode* pNode2)
{
  if(pRoot==NULL || pNode1==NULL || pNode2==NULL) return;

 list<TreeNode*> list1;
 list<TreeNode*> list2;
 GetNodePath(pRoot,pNode1,list1);
 GetNodePath(pRoot,pNode2,list2);

 return GetLastCommonNode(list1,list2);
}

bool GetNodePath(TreeNode* pRoot,TreeNode* pNode,list<TreeNode*>& path)
{
   if(pRoot == pNode) return true;
   path.push_back(pRoot);

   bool found = false;

  vector<TreeNode*>::iterator iter = pRoot->m_vChildren.begin();
  while(iter!=pRoot->m_vChildren.end() && !found)
  {
    found = GetNodePath(*iter,pNode,path);
    iter++;
  }

  if(!found) 
    path.pop_back();

  return found;
}



bool GetNodePath(TreeNode* pRoot,TreeNode* pNode,list<TreeNode*>& path)
{
  if(pRoot==pNode) return true;
  
  path.push_back(pRoot);
  bool found = false;

  vector<TreeNode*>::iterator iter = pRoot->m_vChildren.begin();
  while((!found)&&(iter!=pRoot->m_vChildren.end()))
  {
    found = GetNodePath(*iter,pNode,path);
    iter++;
  }
  
  if(!found) path.pop_back();

  return found;
}



bool GetNodePath(TreeNode* pRoot,TreeNode* pNode,list<TreeNode*>& path)
{
  if(pRoot==pNode) return true;

  bool found = false;
  vector<TreeNode*>::iterator iter = pRoot->m_vChildren.begin();
  path.push_back(pRoot);

  while(!found && iter!=pRoot->m_vChildren.end())
  {
    found = GetNodePath(*iter,pNode,path);
    iter++;
  }
  
  if(!found) path.pop_back();
  
  return found;
}




































