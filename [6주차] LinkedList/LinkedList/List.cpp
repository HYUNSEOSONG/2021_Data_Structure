#include "List.h"
#include <assert.h>
List::List()
{
    // Initialize an empty List
    head = 0;
    tail = 0;
    current = 0;
}
List::~List() //소멸자
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

//head에 insert하는 함수로 수정
void List::insert(const ListElementType& elem)
{
    Link addedNode = new Node;
    assert(addedNode); // check to make sure node was allocated
    addedNode->elem = elem;
    if (head == 0) { // list was empty -- set head
       tail = addedNode; //맨처음 설정
       
      // addedNode->next = 0;//=head로 바꿀수 있음 =>따라서 if문 밖으로 뺄 수 잇음
    }
    //else {
    //    addedNode->next = head;//현재 가장 앞에 있는 주소
    //    
    //}
    addedNode->next = head; //처음일때는 head가 null이고 아니면 다음 노드의 주소값
    head = addedNode; //앞줄과 순서가 바뀌면 곤란하다. 반드시 이순서로
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
