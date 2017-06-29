// vector에 저장, 정렬하기

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(int a, int b){
	return a > b;
}
int main(){
	int arr[] = {7, 45, 2, 12, 23, 16, 4, 88, 49, 5};

	vector<int> data;

	for(int i = 0; i < 10; i++)
		data.push_back(arr[i]);

	sort(data.begin(), data.end());

	for(int i = 0; i < data.size(); i++)
		cout << data[i] << ' ';
	cout << endl;

	sort(data.begin(), data.end(), compare);

	for(int i = 0; i < data.size(); i++)
			cout << data[i] << ' ';
	cout << endl;

	return 0;
}


