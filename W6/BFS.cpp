#include<iostream>
using namespace std;

int main(){
	int node_count = 8;
	int adjacency[8][8] = {
		{0,1,1,0,0,0,0,0},
		{1,0,1,1,1,0,0,0},
		{1,1,0,0,1,0,1,1},
		{0,1,0,0,1,0,0,0},
		{0,1,1,1,0,1,0,0},
		{0,0,0,0,1,0,0,0},
		{0,0,1,0,0,0,0,1},
		{0,0,1,0,0,0,1,0}
	};
	bool discovered[node_count];
	for(int i = 0; i < node_count; i++){
		discovered[i] = false;
	}
	int output[node_count];

	discovered[0] = true;
	output[0] = 1;

	int counter = 1;
	for(int i = 0; i < node_count; i++){
		for(int j = 0; j < node_count; j++){
			if((adjacency[i][j] == 1)&&(discovered[j] == false)){
				output[counter] = j+1;
				discovered[j] = true;
				counter++;
			}
		}
	}
	cout<<"BFS : "<<endl;
	for(int i = 0; i < node_count; i++){
		cout<<output[i]<<" ";
	}
}