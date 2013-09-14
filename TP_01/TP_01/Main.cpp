#include<vector>
#include<iostream>
#include<string>

using namespace std;

class Apple {
public:
	Apple(){};
};

class Tree {
private:
	vector <Apple> apples;
public:
	Tree(){};
	~Tree(){
		this->apples.clear();
	}
	Tree(unsigned int n){
		for(int  i = 0; i < n; i++){
			this->apples.push_back(*(new Apple()));
		}
	};

		void grow(){
			unsigned int count = rand()%100;

			for(int  i = 0; i!=count; i++){
				this->apples.push_back(*(new Apple()));
			}
			cout<<"Number of the apple "<<this->apples.size()<<endl;
			cout<<count<<" apples have grown"<<endl;

		}

};

			int main(){
				unsigned int n = 0 ;
				cout<<"count of apples"<<endl;
				cin>>n;
				if(n < 0)
					cout<<"incorrect number"<<endl;

				Tree *tree = new Tree(n);

				string str = "";

				while(true)
				{
				cout<<"Inter the command (grow  \\ exit)"<<endl;
				cin>>str;

				if(str == "grow"){
					tree->grow();
				}
				else if(str == "exit"){
					return 0;
				}

				}
			}
