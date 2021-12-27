#include <iostream>

using namespace std;

class MyInteger{
	
	// 重载左移运算符<<
	friend ostream & operator<< (ostream &cout, MyInteger myInt);

	public:
		MyInteger(){
			m_Num = 0;
		}
		
		// 重载前置左移运算符 
		MyInteger& operator--(){
			this->m_Num--;
			return *this;
		}
		// 重载后置左移运算符 
		MyInteger operator--(int){
			
			MyInteger temp = *this; 
			this->m_Num--;
			return temp;
		}  
		
		
	private:
		int m_Num;
};

// 重载左运算符，加& operator是因为引用的ostream类，而不能直接创建 
ostream & operator<< (ostream &cout, MyInteger myInt){
	cout << myInt.m_Num; 
	return cout;
}

void test01(){
	MyInteger myInt;
	cout << "0:m_Num = " << myInt << endl;
	cout << "1(前置--):m_Num = " << --myInt << endl;
	cout << "2(后置--):m_Num = " << myInt-- << endl;
	cout << "3:m_Num = " << myInt << endl;
}


int main(){
	test01();
	
	system("pause");
	return 0;
}
