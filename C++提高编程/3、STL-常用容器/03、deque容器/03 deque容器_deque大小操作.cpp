#include<iostream>
#include<deque>

using namespace std;

// deque容器中的赋值操作
// deque中没有容量概念，因为deque中可以前后插入元素 
/*
	deque.empty();			//判断容器是否为空 
	deque.size();			//判断容器的大小，并返回元素的个数 
	deque.resize(num);		//重新指定容器的长度为num，若容器边长，则以默认值填充新位置
							//若容器变小，则末尾超出容器长度的元素被删除 
	deque.resize(num,elem); //重新指定容器的长度为num，若容器边长，则以elem填充新位置
					  		//若容器变小，则末尾超出容器长度的元素被删除 
*/

void printDeque(const deque<int> &deq){
	
	if(deq.empty()){
		cout << "该容器为空@" << endl;
		return;
	}
	for(deque<int>::const_iterator it = deq.begin(); it != deq.end(); it++){
		cout << *it << " ";
	}
	cout << endl;
}

void test01(){
	
	deque<int> deq;
	for(int i=0;i<10;i++){
		deq.push_back(i);
	}
	printDeque(deq);
	cout << "容器的大小为：" << deq.size() << endl; 
	
	deq.resize(15,10);
	printDeque(deq);
	cout << "容器的大小为：" << deq.size() << endl;
	
}

int main(){
	
	test01();
	
	system("pause");
	return 0;
} 
