/********************************************/

/**Tree: Preorder Traversal*******/

/********************************************/
/*Node is defined as  

struct node
{
    int data;
    node* left;
    node* right;
};

*/

void Preorder(node *root) {
    if(!root)
        return;
    cout<<root->data<<" ";
    Preorder(root->left);
    Preorder(root->right);

}


/********************************************/

/**Tree: Postorder Traversal*******/

/********************************************/

void Postorder(node *root) {

    if(!root)
        return;
    Postorder(root->left);
    Postorder(root->right);
    cout<<root->data<<" ";
    
}



/********************************************/

/**Tree: Inorder Traversal*******/

/********************************************/

void Inorder(node *root) {
    if(!root)
        return;
    Inorder(root->left);
    cout<<root->data<<" ";
    Inorder(root->right);
}

/********************************************/

/**Tree: Height of a binary tree*******/

/********************************************/
int height(node * root)
{
  if(!root)
      return 0;
  int lHeight= height(root->left);
  int rHeight= height(root->right);
  
   if(lHeight>rHeight)
       return lHeight+1;
   else
       return rHeight+1;
}





/********************************************/

/****************Tree : Top View*************/

/********************************************/

void print_left(node* rootLeft){
     if(!rootLeft)
        return;
     print_left(rootLeft->left);
     cout<<rootLeft->data<<" ";
}

void print_right(node* rootRight){
     if(!rootRight)
        return;
     cout<<rootRight->data<<" ";
     print_right(rootRight->right);
     
}
void top_view(node * root)
{
    if(!root)
        return;
    print_left(root->left);
    cout<<root->data<<" ";
    print_right(root->right);
  
}







/********************************************/

/**Tree: Level Order Traversal*******/

/********************************************/
static int height (node * root){
    
    if(!root)
        return 0;
    int lHeight =height (root->left); 
    int rHeight =height (root->right); 
    if(lHeight>rHeight)
        return lHeight+1;
    return rHeight+1;
}
static void printGivenLevel(node * root,int level){
    
    if(!root)
        return;
    if(level<=1){
        cout<<root->data<<" ";
        
    }
    else{
        printGivenLevel (root->left, level-1);
        printGivenLevel(root->right,level-1);
        
    }
}


void LevelOrder(node * root)
{
   int h = height(root);
  int i;
  for(i=1; i<=h; i++)
    printGivenLevel(root, i);
    
  
}




/********************************************/

/**Binary Search Tree : Insertion*******/

/********************************************/

node * insert(node * root, int value)
{
    node *temp = root;
    node *prev= root;
    if(!root){
        root= new node();
        root->left=NULL;
        root->right=NULL;
        root->data= value;
    }
    else{
        
        while(temp!=NULL){
            
            if(temp->data<value){                
                prev=temp;
                temp=temp->right;
            }
            else{
               prev=temp;
               temp=temp->left; 
            }
        }
        node* newNode= new node();
        newNode->left=NULL;
        newNode->right=NULL;
        newNode->data= value;
        if(prev->data<value){
            prev->right= newNode;   
        }
        else{
            prev->left= newNode;
        }
    }
   return root;
}




/********************************************/

/**Tree: Height of a binary tree*******/

/********************************************/




/********************************************/

/**Tree: Height of a binary tree*******/

/********************************************/




/********************************************/

/**Tree: Height of a binary tree*******/

/********************************************/




/********************************************/

/**Tree: Height of a binary tree*******/

/********************************************/




/********************************************/

/**Tree: Height of a binary tree*******/

/********************************************/



/********************************************/

/**Tree: Height of a binary tree*******/

/********************************************/
