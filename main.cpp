#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include <vector>
#include <time.h>
#include <fstream>

using namespace std;

int RandI()
{
    int x;
    time_t R;
    srand((unsigned) time(&R));
    x=rand()%691;
    return x;

}

int Rand(int * p, int *q ,int *r,int *s,int *a,int *b, int *c, int *d ,int *e)
{
   int x;
   int arr[9];
   time_t R;
   srand((unsigned) time(&R));
   for(int i=0;i<9;i++){
   arr[i]=rand()%1000;
   }
    x=rand()%1000;
   *p=arr[0];
   *q=arr[1];
   *r=arr[2];
   *s=arr[3];
   *a=arr[4];
   *b=arr[5];
   *c=arr[6];
   *d=arr[7];
   *e=arr[8];
   return x;
}

int main() {

    int m,n,o,p;
    int ab,bc,cd,ef,gh,ij,kl,mn,op;
    int i,j,tmp;


	
	string Chin,Phyn,Mean; 
	vector<string>Chi;
	vector<string>Phy;
	vector<string>Mn;

	//input filename
	string file;
	//cout << "Enter the filename: ";
	//cin >> file;

	//number of lines
	int l = 0;

	ifstream coeff("asdf.txt"); //opening the file.
	if (coeff.is_open()) 
	{
		//ignore first line
		string line;
		//getline(coeff, line);

		while (!coeff.eof()) //while the end of file is NOT reached
		{
			getline(coeff, Chin, '-');
			Chi.push_back(Chin);
			getline(coeff, Phyn, '-');
			Phy.push_back(Phyn);
			getline(coeff, Mean, ',');
			Mn.push_back(Mean);

			l += 1; //increment number of lines
		}
		coeff.close(); //closing the file
		int N=l-1;
		cout << "Number of entries: " << N << endl;
	}
	else cout << "Unable to open file"<<endl; //if the file is not open output
	cout << "Chinese" << "\t" << "Phyny" << "\t" << "Meaning" << endl;
	int N=l-1;

	int card[N];



	for(i=0;i<N;i++){
        card[i]=i;
        cout<<" "<<card[i];
    }
    cout<<endl;

    j=(Rand(&m,&n,&o,&p,&ab,&bc,&cd,&ef,&gh))%N;
    m=m%N;
    n=n%N;
    o=o%N;
    p=p%N;
    ab=ab%N;
    bc=bc%N;
    cd=cd%N;
    ef=ef%N;
    gh=gh%N;

    for(i=0;i<N;i++)
    {
        swap(card[ab],card[bc]);
        swap(card[ef],card[gh]);
        swap(card[i],card[j]);
        swap(card[m],card[n]);
        swap(card[o],card[p]);
    }

    for(i=0;i<N;i++)
    {
        cout<<" "<<card[i];
    }
    cout<<endl;

        int R=0,W=0;
		for(int jj=0;jj<10;jj++){
            int aa;
		    int nn;
		    tmp = card[jj];
		    cout<<" \t What is the Carrecter ? "<<endl;
		    cout<<" "<<Mn[tmp]<<endl;
          aa=RandI();

		if(aa%4==0) {
            cout<<"1."<<Chi[tmp]<< " "<<Phy[tmp]<<endl;
            cout<<"2."<<Chi[(tmp+7)%N]<<" "<<Phy[(tmp+7)%N]<<endl;
            cout<<"3."<<Chi[(tmp+14)%N]<<" "<<Phy[(tmp+14)%N]<<endl;
            cout<<"4."<<Chi[(tmp+21)%N]<< " "<<Phy[(tmp+21)%N]<<endl;
            cin>>nn;
            if(nn==1){
                cout<<"Correct"<<endl;
                R++;}
            else{
                cout<<Chi[tmp]<<" "<<Phy[tmp]<<endl;
                W++;}
		}
		else if(aa%4==1) {

            cout<<"1."<<Chi[(tmp+7)%N]<<" "<<Phy[(tmp+7)%N]<<endl;
            cout<<"2."<<Chi[tmp]<< " "<<Phy[tmp]<<endl;
            cout<<"3."<<Chi[(tmp+14)%N]<<" "<<Phy[(tmp+14)%N]<<endl;
            cout<<"4."<<Chi[(tmp+21)%N]<< " "<<Phy[(tmp+21)%N]<<endl;
            cin>>nn;
            if(nn==2){
                cout<<"Correct"<<endl;
                R++;}
            else{
                cout<<Chi[tmp]<<" "<<Phy[tmp]<<endl;
                W++;}
		}
		else if(aa%4==2) {

            cout<<"1."<<Chi[(tmp+7)%N]<<" "<<Phy[(tmp+7)%N]<<endl;
            cout<<"2."<<Chi[(tmp+14)%N]<<" "<<Phy[(tmp+14)%N]<<endl;
            cout<<"3."<<Chi[tmp]<< " "<<Phy[tmp]<<endl;
            cout<<"4."<<Chi[(tmp+21)%N]<< " "<<Phy[(tmp+21)%N]<<endl;
            cin>>nn;
            if(nn==3){
                cout<<"Correct"<<endl;
                R++;}
            else{
                cout<<Chi[tmp]<<" "<<Phy[tmp]<<endl;
                W++;}
		}
		else if(aa%4==3) {

            cout<<"1."<<Chi[(tmp+7)%N]<<" "<<Phy[(tmp+7)%N]<<endl;
            cout<<"2."<<Chi[(tmp+14)%N]<<" "<<Phy[(tmp+14)%N]<<endl;
            cout<<"3."<<Chi[(tmp+21)%N]<< " "<<Phy[(tmp+21)%N]<<endl;
            cout<<"4."<<Chi[tmp]<< " "<<Phy[tmp]<<endl;
            cin>>nn;
            if(nn==4){
                cout<<"Correct"<<endl;
                R++;}
            else{
                cout<<Chi[tmp]<<" "<<Phy[tmp]<<endl;
                W++;}
		}


    }
     cout<<" Correct : "<<R<<" Wrong : "<<W;
}


