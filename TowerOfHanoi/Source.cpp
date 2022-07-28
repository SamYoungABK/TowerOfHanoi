#include <vector>
#include <iostream>
using std::vector;

vector<int> tower1 = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
vector<int> tower2;
vector<int> tower3;
int moveCount = 0;

void drawVector(vector<int> v);
void Solve(int disks, vector<int>& src, vector<int>& dst, vector<int>& spare);

int main()
{
	Solve(tower1.size(), tower1, tower3, tower2);
}

void drawVector(vector<int> v)
{
	std::cout << "[ ";
	for (int val : v) std::cout << val << ' ';
	std::cout << ']' << std::endl;
}

void Solve(int disks, vector<int>& src, vector<int>& dst, vector<int>& spare)
{
	if (disks < 1) return;
	Solve(disks - 1, src, spare, dst);

	dst.push_back(src.back());
	src.pop_back();

	moveCount++;
	drawVector(tower1);
	drawVector(tower2);
	drawVector(tower3);
	std::cout << "Move Number: " << moveCount << std::endl << std::endl;

	Solve(disks - 1, spare, dst, src);
}