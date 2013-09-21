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
	int bApple ;
public:
	Tree(){
		this->bApple = 0;
	};
	~Tree(){
		this->apples.clear();
	}
	Tree(unsigned int n){
		this->bApple = n;
	};

		bool grow(){
			unsigned int count = rand()%(this->bApple);
			this->bApple-=count;

			for(int  i = 0; i!=count; i++){
				this->apples.push_back(*(new Apple(rand()%20)));
			}
			cout<<"Number of the apple "<<this->apples.size()<<endl;
			cout<<count<<" apples have grown"<<endl;
			return true;
		}
		
		void shake(){
			unsigned int count = rand()%(this->apples.size());

			for(int  i = 0; i!=count; i++){
				this->apples.pop_back();
			}

			cout<<"Number of the apple "<<this->apples.size()<<endl;
			cout<<count<<" apples have shaken"<<endl;
		}

		bool bloom()
		{
			cout<<"all good"<<endl;
			this->bApple+=rand()%30;
			return true;
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
				Tree *tree = new Tree();

				string str = "";
				bool grow = false;
				bool bloom = false;


				while(true)
				{
				cout<<"Inter the command (grow \\ shake \\ exit\\ getAmountSeeds\\ bloom)"<<endl;
				cin>>str;

				if(str == "grow" && bloom){
					grow = tree->grow();
				}
				else if(str == "shake" && grow){
					 tree->shake();
				}
				else if(str == "exit"){
					return 0;
				}
				else if(str == "getAmountSeeds" && grow){
					cout<<"Amount of seeds : "<<tree->AmountSeeds()<<endl;
				}
				else if(str == "bloom"){
					bloom = tree->bloom();
				}
				}
			}



