#include<vector>
#include<iostream>
#include<string>

using namespace std;

class Apple {
public:	int countSeeds;
public:
	Apple(){};
	Apple(int n){
		countSeeds= n;
	};
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
			this->apples.push_back(*(new Apple(rand()%20)));
		}
	};

		void grow(){
			unsigned int count = rand()%100;

			for(int  i = 0; i!=count; i++){
				this->apples.push_back(*(new Apple(rand()%20)));
			}
			cout<<"Number of the apple "<<this->apples.size()<<endl;
			cout<<count<<" apples have grown"<<endl;

		}
		
		void shake(){
			unsigned int count = rand()%100;

			for(int  i = 0; i!=count; i++){
				this->apples.pop_back();
			}

			cout<<"Number of the apple "<<this->apples.size()<<endl;
			cout<<count<<" apples have shaken"<<endl;
		}

	int AmountSeeds()
	{
		int amount = 0;
		for(int i = 0; i < this->apples.size();i++)
		{
			amount +=this->apples[i].countSeeds;
		}
		return amount;
	}

};


			int main(){
				unsigned int n = 0 ;
				cout<<"count of apples : ";
				cin>>n;
				if(n < 0)
					cout<<"incorrect number"<<endl;

				Tree *tree = new Tree(n);

				string str = "";

				while(true)
				{
				cout<<"Inter the command (grow \\ shake \\ exit\\getAmountSeeds)"<<endl;
				cin>>str;

				if(str == "grow"){
					tree->grow();
				}
				else if(str == "shake"){
					tree->shake();
				}
				else if(str == "exit"){
					return 0;
				}
				else if(str == "getAmountSeeds")
					cout<<"Amount of seeds : "<<tree->AmountSeeds()<<endl;
				}
			}



