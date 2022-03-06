#include<iostream>
#include<cmath>
using namespace std;

void printdistance(float ED[],int size)
{
	cout<<"distances are"<<" ";
	for(int i=0;i<size;i++)
	{
		cout<<ED[i]<<" ";
	}
	cout<<endl;
}

void printorder(int order[],int size)
{
	cout<<"orders are"<<" ";
	for(int i=0;i<size;i++)
	{
		cout<<order[i]<<" ";
	}
	cout<<endl;
}

int min(float arr[], int n)
{
	int index, loc;
	float minimum = 1000;
	for (index = 0; index < n; index++)
	{
		if (arr[index] != -1 && minimum > arr[index])
		{
			minimum = arr[index];
			loc = index;
		}
	}
	arr[loc] = -1;
	return loc;
}

void selectminindex(float arr[], int brr[], int size)
{
	for (int index = 0; index < size; index++)
	{
		brr[index] = min(arr, size);
	}
}

void copyarray(float arr[], float brr[],int size)
{
	for (int index = 0; index < size; index++)
	{
		brr[index] = arr[index];
	}
}

float Euclideandistance(int x1, int y1, int x2, int y2)
{
	float a = (x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1);
	float d = sqrt(a);
	return d;
}

void announceresult(int batsmen, int bowler, int allrounder, int batsmenlabel, int bowlerlabel, int allrounderlabel, int &newuserlabel)
{
	if (batsmen>bowler&&batsmen > allrounder)
	{
		newuserlabel = batsmenlabel;
		cout << "new user selected as a batsmen and its label is " << newuserlabel << endl;
	}
	else if (bowler > batsmen && bowler > allrounder)
	{
		newuserlabel = bowlerlabel;
		cout << "new user selected as a bowler and its label is " << newuserlabel << endl;
	}
	else if (allrounder > bowler&&allrounder > batsmen)
	{
		newuserlabel = allrounderlabel;
		cout << "new user selected as a allrounder and its label is " << newuserlabel << endl;
	}
}

void selectionofplayer(int order[], int label[])
{
	int k, bowler = 0, batsmen = 0, allrounder = 0, batsmenlabel = 0, bowlerlabel = 1, allrounderlabel = 2, newuserlabel;
	for(int i=1;i<=2;i++)
	{
	cout<<"Enter odd value of k"<<endl;
	cin>>k;
	for (int index = 0; index < k; index++)
	{
		if (label[order[index]] == batsmenlabel)
		{
			batsmen++;
		}
		else if (label[order[index]] == bowlerlabel)
		{
			bowler++;
		}
		else if (label[order[index]] == allrounderlabel)
		{
			allrounder++;
		}
	}
	announceresult(batsmen, bowler, allrounder, batsmenlabel, bowlerlabel, allrounderlabel, newuserlabel);
	}
}

void enterinfo(int&x1, int&y1)
{
	cout << "enter your batting average" << endl;
	cin >> x1;
	cout << "enter your bowling average" << endl;
	cin >> y1;
}

int main()
{
	int x1, y1, index, order[15];
	int battingaverage[15] = {50, 15, 35, 45, 12, 48, 34, 12, 5, 62, 55, 26, 6, 48, 31};
	int bowlingaverage[15] = {50, 21, 29, 50, 20, 58, 26, 15, 12, 65, 29, 41, 23, 43, 28};
	int label[15] = {0, 1, 2, 0, 1, 0, 2, 1, 1, 0, 2, 2, 1, 0, 2};
	float ED[15], copyED[15];
	enterinfo(x1, y1);
	for (index = 0; index < 15; index++)
	{
		ED[index] = Euclideandistance(x1, y1, battingaverage[index], bowlingaverage[index]);
	}
	copyarray(ED, copyED,15);
	selectminindex(copyED, order, 15);
	printdistance(ED,15);
	printorder(order,15);
	selectionofplayer(order, label);
}