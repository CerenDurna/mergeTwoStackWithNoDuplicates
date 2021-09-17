#include <iostream>
#include <stack>
#include <string>  
#include <vector> 
#include <set> 
#include <algorithm>
#include <unordered_set>

using namespace std;

stack<int> merged(stack<int>& stack1, stack<int>& stack2)
{
	// Push contents of both stacks in result
	stack<int> res;
	while (!stack2.empty()) {
		res.push(stack2.top());
		stack2.pop();
	}
	while (!stack1.empty()) {
		res.push(stack1.top());
		stack1.pop();
	}

	return res;
}


void destructiveReverseCopy(vector<int>& v, std::stack<int>& stack3)
{
	while (stack3.size())
	{
		v.push_back(stack3.top());
		stack3.pop();
	}
}

void reverseCopy(stack<int>& stack3, const vector<int>& v)
{
	for (auto it = v.rbegin(); it < v.rend(); ++it)
	{
		stack3.push(*it);

	}

}

int main()
{

	stack<int> stack1;
	int int1 = 1;
	int int2 = 2;
	int int3 = 3;
	int int4 = 4;
	int int5 = 5;
	int int6 = 6;
	int int7 = 7;
	int int8 = 8;
	int int9 = 9;
	int int10 = 10;

	stack1.push(int1);
	stack1.push(int2);
	stack1.push(int3);
	stack1.push(int4);
	stack1.push(int5);
	stack1.push(int6);
	stack1.push(int7);
	stack1.push(int8);
	stack1.push(int9);
	stack1.push(int10);


	stack<int> stack2;
	int int11 = 1;
	int int12 = 2;
	int int13 = 7;
	int int14 = 13;
	int int15 = 14;
	int int16 = 15;
	int int17 = 16;
	int int18 = 17;
	int int19 = 18;
	int int20 = 10;


	stack2.push(int11);
	stack2.push(int12);
	stack2.push(int13);
	stack2.push(int14);
	stack2.push(int15);
	stack2.push(int16);
	stack2.push(int17);
	stack2.push(int18);
	stack2.push(int19);
	stack2.push(int20);



	stack<int> stack3 = merged(stack1, stack2);

	vector<int> v;

	destructiveReverseCopy(v, stack3);

	unordered_multiset<int> unique(v.begin(), v.end());
	v.erase(std::remove_if(v.begin(), v.end(), [&](const auto& e) {return unique.count(e) > 1; }), v.end());

	reverseCopy(stack3, v);

	cout << "Merged stack with no duplicates:\n";
	while (!stack3.empty())
	{
		cout << stack3.top() << " ";
		stack3.pop();
	}


}

