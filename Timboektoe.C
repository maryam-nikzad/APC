
// Project Name  : Timboektoe
// Author		 : Maryam Nikzad
// Language      : c++
// Date          : 1/24/2021

#include <bits/stdc++.h> 
using namespace std; 

//--Maxprice of fluts (cost more than 10 florins would remain unsold)
int MaxPrice=10;

//--Get index Of Cheapest (Minimum) fluts in each schuur 
int  getMin(stack<int> fluts) 
{ 
   int min = fluts.top();
   int i = 0, minIdx = 0;
	while ( !fluts.empty() ) 
	{ 
		if( fluts.top() < min )
		{
			min = fluts.top();
			minIdx = i;
		}    
		fluts.pop();
		i++;
	}  
	return minIdx;
}
	
//-- Show Main List Items
void showlist( list<list<stack<int>>> mainList ) 
{ 
	for ( list<list<stack<int> >>::iterator it = mainList.begin(); it != mainList.end(); ++it ) 
	{ 

        list<stack<int>> schuurs = *it;

     	for (list<stack<int>>::iterator it1 = schuurs.begin(); it1 != schuurs.end(); ++it1 ) 
		{ 
			stack<int> fluts = *it1; 
			
			while ( !fluts.empty() ) 
			{ 
				cout << fluts.top() << " "; 
				fluts.pop(); 
			} 
			cout << endl; 
		} 
	}
} 

//-- Show Selected List Items to gain profit
void showSelectedlist( list<list<stack<int>>> mainList ) 
{ 
	for ( list<list<stack<int>>>::iterator it = mainList.begin(); it != mainList.end(); ++it ) 
	{ 
	    cout << "\nNumber of fluts to buy : "; 
        list<stack<int>> schuurs = *it;
	    int maxProfit = 0;
     	for ( list<stack<int>>::iterator it1 = schuurs.begin(); it1 != schuurs.end(); ++it1 ) 
		{ 
			stack<int> fluts = *it1; 
			int indexMin = getMin(fluts);
			int i = 0; 
			while ( i<indexMin ) 
			{ 
				cout << fluts.top() << " "; 
				
				if(fluts.top()<MaxPrice)
					maxProfit = maxProfit +( MaxPrice -fluts.top() );
				fluts.pop();
				i++;
			} 
			//cout << endl; 
		}
		cout<<"\nschuurs ";//<<std::distance(schuurs.cbegin(), it1);		
		cout<<"\nMaximum profit is " <<maxProfit<<".";
		cout<<"\n------------------------------------";
	}
} 

//--main
int main() 
{ 
	//--declare this list for package all of entries in the list 
    list<list<stack<int>>> mainList; 
	
	//--declare schuursCount to save count of schuurs of each part
	int schuursCount = 0;
    cout<< "\nEnter schuurs Count ( when you want to terminate insert 0 ) :";
	cin >> schuursCount;
	
	bool isContine = false;
	
	if( schuursCount > 0 )
		isContine = true;
	
	while ( isContine )
	{
		//--declare this list to save schuurs of each part
		list<stack<int>> schuurs;
		
		for ( int i = 0; i <schuursCount ; ++i ) 
		{ 
			int boxesCount = 0;	
			int value = 0;
		
			cout<<"\nEnter box count of this schuur: ";
			cin>> boxesCount;
		
			//--declare stack to save fluts
			stack<int> fluts;
			
			cout<<"\nEnter fluts Prices of these boxes in schuurs : ";
			for (int i = 0; i < boxesCount  ; i++) 
			{ 
				cin>>value;
				fluts.push(value); 
			} 		
			
			schuurs.push_back(fluts); 
		}
		
		mainList.push_back(schuurs);
		
		cout<< "\nEnter Next schuurs Count ( when you want to terminate insert 0 ) :";
		cin >> schuursCount;
		
		if  (schuursCount>0)
			isContine = true;
		else
			isContine = false;
	}	

	
	showSelectedlist(mainList); 
	
	return 0; 
} 
