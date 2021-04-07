#pragma once
#include <iostream>

using namespace std;

class CStudent
{
public:
	CStudent();
	~CStudent();
	explicit CStudent(int nParam);
	CStudent(const CStudent& rhs);
	int operator<=(const CStudent& rhs);
	CStudent& operator=(const CStudent& rhs);
	operator int();
	
private:
	int m_ID;
	};
