#include<iostream>
#include<vector>

using namespace std;

// vector容器中 的容量和大小
// empty(); 判断容器是否为空
// capacity(); 判断容器的容量 
// size(); 判断容器的大小
// resize(int num); 重新指定容器的大小，如果num>原本的大小，则用默认值0填充；如果num小于原本的容量，则删除多余的数据
// resize(int num, elem); 重新指定容器的大小，如果num>原本的大小，则用elem填充；如果num小于原本的容量，则删除多余的数据

void printVector(vector<int> &vec){
	for(vector<int>::iterator it = vec.begin(); it != vec.end(); it++){
		cout << *it << " ";
	}
	cout << endl;
}

void IsEmptyVecotr(vector<int> &vec){
	// 判断容器是否为空,empty()返回bool类型的值，如果返回true，则表示该容器为空 
	if(vec.empty()){
		cout << "该容器为空" << endl; 
	}else{
		//cout << "该容器不为空!" << endl;
		cout << "该容器的容量为：" << vec.capacity() << "  ";
		cout << "该容器的大小为：" << vec.size() << "  ";  
		cout << "该容器中的数据为：";
		printVector(vec);//打印容器中的数据  
	}
	cout << endl;
}

void test01(){
	
	vector<int> v1;		// 无参构造，默认构造 
	IsEmptyVecotr(v1);		//判断容器是否为空以及容量大小 
	for(int i=0; i<10; i++){	// 对容器进行赋值 
		v1.push_back(i+10);
	}
	
	IsEmptyVecotr(v1);		//判断容器是否为空以及容量大小 
	
	v1.resize(14);			// 重新指定容器大小，此时用大于的部分默认填充0
	IsEmptyVecotr(v1);		//判断容器是否为空以及容量大小 
	
	v1.resize(8); 			// 重新指定容器大小，此时删除多余的数据 
	IsEmptyVecotr(v1);
	
	// resize重载函数 
	v1.resize(20,1);		// 重新指定容器大小，此时用大于的部分填充1
	IsEmptyVecotr(v1);
}

int main(){
	
	test01();
	
	system("pause");
	return 0;
}
