#include <bits/stdc++.h>
void sortedInsertion(stack<int> &s,int num)
{
	if(s.empty()||(s.top()<num))
	{
		s.push(num);
		return;
	}
	int x = s.top();
	s.pop();
	sortedInsertion(s,num);
	s.push(x);
} 
void sortStack(stack<int> &stack)
{
	// Write your code here
	if(stack.empty())
	{
		return;
	}
	int num = stack.top();
	stack.pop();
	sortStack(stack);
	sortedInsertion(stack,num);
}