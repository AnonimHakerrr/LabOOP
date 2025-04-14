#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;

int main() {

	setlocale(LC_CTYPE, "ukr");
	vector<vector<int>> matrix = {
		{1, 0, -3, 4},
		{0, -5, -6, 7},
		{8, 9, 10, 11},
		{12, -13, 0, -15}
	};

	int negativeCount = 0;
	int x = 0;
	int y = 0;
	int z = 0;
	//for (size_t i = 0; i < 4; i++)
	//{
	//	for (size_t j = 0; j < 4; j++)
	//	{
	//		if ((i == j) && (matrix[i][j] < 0)) {  
	//			x++;
	//		}
	//	}
	//}
	z += count_if(matrix.begin(), matrix.end(),[i = 0](auto& row) mutable {return row[i++] < 0;}); 
	for (const auto& row : matrix) {
		if (any_of(row.begin(), row.end(), [](int x) { return x == 0; })) {
			negativeCount += count_if(row.begin(), row.end(), [](int x) { return x < 0; });
		}
	
		y += count_if(row.begin(), row.end(), [](int x) { return (x < 0 && x % 2 == 0); });
	}
	cout << "Кількість від'ємних елементів у рядках з хоча б одним нулем: " << negativeCount << endl;
	cout << "Кількість від'ємних елементів на головній діагоналі: " << z << endl;
	cout << "Кількість від'ємних парних елементів у рядках : " << y << endl;
	return 0;
}
