
#include "binary-tree.hpp"
#include "util.hpp"

BinaryTree::BinaryTree(){
  m_root = nullptr;
}

BinaryTree::~BinaryTree() {
  deleteTree(m_root);
}

void BinaryTree::deleteTree(Node<int>* subTree)
{

    if(subTree->getLeft() != nullptr)
    {
        deleteTree(subTree->getLeft());
    }
    if(subTree->getRight() != nullptr)
    {
        deleteTree(subTree->getRight());
    }
    delete subTree;

}

void BinaryTree::add(int value, Node<int>* subTree)
{

    if (value < subTree->getValue() )
    {
        if (subTree->getLeft()==nullptr)
        {
            Node<int>* temp = subTree->getLeft();

            temp = new Node<int>();

            temp->setValue(value);

            subTree->setRight(temp);

        }
        else
        {
            add(value, subTree->getLeft());
        }
    }
    else if (value > subTree->getValue() )
    {
        if (subTree->getRight()==nullptr)
        {
            Node<int>* temp = subTree->getRight();

            temp = new Node<int>();

            temp->setValue(value);

            subTree->setRight(temp);

        }
        else
        {
            add(value, subTree->getRight());
        }
    }
}

void BinaryTree::addElem(int elem) {
  if(m_root == nullptr)
    {
        Node<int>* temp = new Node<int>();

        temp->setValue(elem);

        m_root = temp;

    }
    else
    {
        return add(elem, m_root);

    }
}

int BinaryTree::deleteElem() {

  Node<int>* T_dawg = inorderTraverse(m_root);

  int tempin = 0;

  if (T_dawg != nullptr)
  {

    tempin = T_dawg->getValue();

    delete T_dawg;

  }

  return tempin;
}

int BinaryTree::search(int value, Node<int> *ST)
{
    if (ST!= nullptr)
    {
        if (value == ST->getValue())
        {
            return value;
        }
        else if (value < ST->getValue())
        {
            search(value, ST->getLeft());
        }
        else
        {
            search(value, ST->getRight());
        }
    }
   else
   {
        return -1;
   }

}

bool BinaryTree::exists(int elem) {
  if(search(elem,m_root) != -1)
  {
    return true;
  }
  else
  {
    return false;
  }
}

Node<int>* BinaryTree::inorderTraverse(Node<int>* ST){
  if(ST == nullptr)
  {
    return ST;
  }

  ST = inorderTraverse(ST->getLeft());

  ST = inorderTraverse(ST->getRight());

}

int BinaryTree::preorderTraverse(int identity, int (*operation)(int, int)){
  //IMPLEMENT_ME();
  return 0;
}

int BinaryTree::postorderTraverse(int identity, int (*operation)(int, int)){
  //IMPLEMENT_ME();
  return 0;
}

int BinaryTree::addAll(Node<int>* ST)
{
  if (ST == nullptr)
  {
    return 0;
  }

  return ST->getValue() + addAll(ST->getLeft()) + addAll(ST->getRight());
}

int BinaryTree::sum(){

  return addAll(m_root);
}

void BinaryTree::printHelper(Node<int>* ST,int order)
{
  if(ST != nullptr)
  {

    switch (order)
    {

      case 1: //in order

        printHelper(ST->getLeft(),order);

        std::cout << ST->getValue() << " ";

        printHelper(ST->getRight(),order);

        break;

      case 2: //pre order

        std::cout<<ST->getValue()<<" ";

        printHelper(ST->getLeft(),order);

        printHelper(ST->getRight(),order);

      case 3: //post order

        printHelper(ST->getLeft(),order);

        printHelper(ST->getRight(),order);

        std::cout<<ST->getValue()<<" ";

    }

   }
return;

}

void BinaryTree::print(int printType) {
  if(printType == 1){
    std::cout << "inorder traversal: " << std::endl;
    printHelper(m_root, printType);
  }
  else if(printType == 2){
    std::cout << "preorder traversal: " << std::endl;
    printHelper(m_root, printType);
  } else if(printType == 3){
    std::cout << "postorder traversal: " << std::endl;
    printHelper(m_root, printType);
  } else {
    std::cout << "Error invalid print type. Please choose a correct option."
              << std::endl;
  }
}
