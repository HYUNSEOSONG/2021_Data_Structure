#include "List.h"
#include <assert.h>
List::List()
{
    // Initialize an empty List
    head = 0;
    tail = 0;
    current = 0;
}
List::~List() //�Ҹ���
{
    // Initialize an empty List
    while (head != 0) {
        Link delNode = head;
        head = head->next;
        delete delNode;
    }

    
}
//void List::insert(const ListElementType& elem)
//{
//    Link addedNode = new Node;
//    assert(addedNode); // check to make sure node was allocated
//    addedNode->elem = elem;
//    if (head == 0) // list was empty -- set head
//        head = addedNode;
//    else
//        tail->next = addedNode;
//    tail = addedNode;
//    addedNode->next = 0;
//}

//head�� insert�ϴ� �Լ��� ����
void List::insert(const ListElementType& elem)
{
    Link addedNode = new Node;
    assert(addedNode); // check to make sure node was allocated
    addedNode->elem = elem;
    if (head == 0) { // list was empty -- set head
       tail = addedNode; //��ó�� ����
       
      // addedNode->next = 0;//=head�� �ٲܼ� ���� =>���� if�� ������ �� �� ����
    }
    //else {
    //    addedNode->next = head;//���� ���� �տ� �ִ� �ּ�
    //    
    //}
    addedNode->next = head; //ó���϶��� head�� null�̰� �ƴϸ� ���� ����� �ּҰ�
    head = addedNode; //���ٰ� ������ �ٲ�� ����ϴ�. �ݵ�� �̼�����
}


bool List::first(ListElementType& elem)
{
    // After calling first, current points to first item in list
    if (head == 0)
        return false;
    else {
        elem = head->elem;
        current = head;
        return true;
    }
}
bool List::next(ListElementType& elem)
{
    // with proper use, current should always be nonzero
    assert(current);

    // After each call, current always points to the item
    // that next has just returned.
    if (current->next == 0)
        return false;
    else {
        current = current->next;
        elem = current->elem;
        return true;
    }
}
