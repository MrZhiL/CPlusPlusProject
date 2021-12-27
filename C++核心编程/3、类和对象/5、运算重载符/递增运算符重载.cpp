#include <iostream>
#include <cmath>

using namespace std;

// 递增运算符重载
// 作用：通过递增运算符，实现自己的整形数据
// 前置运算符返回引用，后置运算符返回值 

class myInteger{
	
	friend ostream & operator<< (ostream &cout, myInteger myint);
//	friend void operator++ (myInteger &myint, int );
	
	public:
		myInteger(){
			m_Num = 0; 
		}
		// 获取m_Num的值 
		int getNum(){
			return m_Num;
		}
		
		// 重载前置++ 运算符
		// 返回引用是为了一直对一个数据进行递增操作 
		myInteger& operator++ (){
			++m_Num;
			return *this;
		}
		// 重载后置++ 运算符 :::后置递增一定要返回值，前置递增要返回引用 
		// operator++ (int ):int代表占位参数，可以用于区分前置和后置递增 
		myInteger operator++ (int){
			
			// 先：记录当前的值，然后让本身的值加1，但是返回以前的值，从而实现先返回后++ 
			myInteger temp = *this; 
			// 后：递增 
			this->m_Num++;
			// 最后:将记录结果做返回 
			return temp;
		}
		
	private:
		int m_Num;
};

// 重载左运算符，加& operator是因为引用的ostream类，而不能直接创建 
ostream & operator<< (ostream &cout, myInteger myint){
	cout << "myint.m_num = " << myint.m_Num;
	return cout;
} 

/** 
// 重载后置++运算符 
void operator++ (myInteger &myint, int ){
	myint.m_Num++;
//	cout << myint.m_Num;
//	return cout;
} */ 

void test01(){
	myInteger myint;
	cout << myint << endl; 
	
	cout << "前置递增：" << ++(++myint) << endl;
	cout << myint << endl; 
	
	cout << "后置递增：" << (myint++)++ << endl; 
	cout << myint << endl; 
}

void test02(){
	myInteger myint;
	cout << myint << endl; 
	
	cout << "后置递增：" << (myint++)++ << endl; 
	cout << myint << endl; 
}

int main(){
	
	test02();

	system("pause");
	return 0;
}
