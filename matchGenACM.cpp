#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
//Program Only to be used by ACM
//Designed and Implemented by Harshit Vishwakarma, ACM Technical Team Memeber.
using namespace std;

bool compareInterval(vector<unsigned int> v1, vector<unsigned int> v2) { 
    return !(v1[2] < v2[2]); 
}

void generateMatch(vector<vector<unsigned int> > v,int row){
	ofstream match("matches.txt", ios::out);
	int max = 0, min = row - 1 ,iter =0;
	if(row%2 != 0){
		max = 1;
	}
	while(max <= min){
		if(v[max][0] == 0){
			++max;
			continue;
		}
		if(v[min][0] == 0){
			--min;
			continue;
		}
		++iter;
		match << v[max][1] << " vs " << v[min][1] << "\n";
		cout << iter << ". " << v[max][1] << " vs " << v[min][1] << "\n";
		++max;
		--min;
	}
	if(row%2 != 0){
		match << v[0][1] << " is automatically Promoted.\n";
		cout << v[0][1] << " is automatically Promoted.\n";
	}
	match.close();
}

void declareResults(vector<vector <unsigned int> > &v, int row){
	int input, i;
	string str = "";
	char side;
	string lroll = "", rroll = "";
	unsigned int lr, rr;
	ifstream match;
	match.open("matches.txt");
	while(1){
	cout << "Declare Result for which match? ";
	cin >> input;
	if(input != -1){
		input = input -1;
		match.seekg(24*input, ios::beg);
		getline(match, str);
		cout << str <<endl;
		cout << "Which Side WON? (L/R) ";
		cin >> side;
		if(side != 'l' && side != 'r' && side != 'L' && side != 'R'){
			continue;
		}
		i = 0;
		while(str[i] != ' '){
			lroll.push_back(str[i++]);
		}
		lr = atoi(lroll.c_str());
		i = i + 3;
		while(str[i]  != '\n'){
			rroll.push_back(str[i++]);
		}
		rr = atoi(rroll.c_str());
		i=0;
		if(side == 'l' || side == 'L'){
			for(i=0; i < row; i++){
				if(v[i][1] == lr){
					v[i][0] = 1;
				}
				if(v[i][1] == rr){
					v[i][0] = 0;
					cout << v[i][1] << " Lost." << endl;
				}
			}
			
		}
		else{
			for(i=0; i < row; i++){
				if(v[i][1] == lr){
					v[i][0] = 0;
					cout << v[i][1] << " Lost." << endl;
				}
				if(v[i][1] == rr){
					v[i][0] = 1;
				}
			}
		}
		lroll = "";
		rroll = "";
		str = "";
	}
	else{
		cout << "Do you want to Finalize the Result? (y/n) ";
		cin >> side;
		if(side == 'n'){
			continue;
		}
		else{
		ofstream ofile;
		ofile.open("results.txt", ios::app);
		ofile << "------------------------------\n";
			int temp = 0;
		while(temp < row){
			ofile << v[temp][0] << " " << v[temp][1] << " " << v[temp][2] << "\n";
			cout << v[temp][0] << " " << v[temp][1] << " " << v[temp][2] << "\n";
			++temp;
		}
		break;
		}
	}
	
}
}

int main(){
	cout << "THE ACM MATCH GENERATOR\n";
	char in;
	ifstream file;
	file.open("participants.txt");
	unsigned int row = 0;
	while(file){
		if(file.get() == '\n'){
			++row;
		}
	}
	row=row+1;
	vector<vector<unsigned int> > data(row, vector<unsigned int>(3,0));
	file.clear();
	file.seekg(0,ios::beg);
	int i =0,j=0;
	string str;
	char ch;
	const char* inp;
	while(file){
		file.get(ch);
		if(ch == '\n'){
			inp = str.c_str();
			data[i][j] = atoi(inp);
			str = "";
			++i;
			j=0;
		}
		if(ch == ' '){
			inp = str.c_str();
			data[i][j] = atoi(inp);
			str = "";
			++j;
		}
		str.push_back(ch);
	}
	data.pop_back();
	sort(data.begin(), data.end(), compareInterval);
	cout << "Do you Want to Generate Matches?(y/n) ";
	cin >> in;
	if(in == 'y'){
	generateMatch(data,row-1);
	}
	else{
		return 1;
	}
	declareResults(data, row-1);
//	ofile.close();
	file.close();
	return 0;
}
