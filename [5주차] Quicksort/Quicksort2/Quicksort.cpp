#include "Quicksort.h"
#include <iostream>
using namespace std;


CStudent::CStudent() {
	m_ID = 0;
}


CStudent::~CStudent() {

}
CStudent::CStudent(int nParam) {
	m_ID = nParam;

}
CStudent::CStudent(const CStudent& rhs){
	m_ID = rhs.m_ID;
};
int CStudent::operator<=(const CStudent& rhs) {
	if (m_ID <= rhs.m_ID)
		return true;
	else
		return false;
}
CStudent& CStudent:: operator=(const CStudent& rhs) {
	if (this == &rhs)
		return *this;
	m_ID = rhs.m_ID;
	return *this;
}
CStudent::operator int() { return m_ID; }