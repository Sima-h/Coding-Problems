// resource: LeetCode
//Given an array of integers nums and an integer target
//return indices of the two numbers such that they add up to target.
//You may assume that each input would have exactly one solution, and you may not use the same element twice.
//You can return the answer in any order.
//***************************
//This is an O(n log n) time solution for this problem.  Storage: O(n)
//Idea: sort the elements and keep them in another vector. Then for each element nums[i], look up target-[i]
//in the sorted vector in O(log n) time. 
#include<iostream>
#include<vector>
#include<algorithm>
int main()
{
	int target;
	std::vector<int> nums;
	std::cout << "enter the list of the numbers:"<<std::endl;
	int input;
	while (true)
	{
		std::cin >> input;
		nums.push_back(input);
		if (std::cin.peek() == '\n')
			break;
	}
	std::cout << "enter the target number:" << std::endl;
	std::cin >> target;

	std::vector<int> result;
	std::vector<int> sorted;
	sorted = nums;
	sort(sorted.begin(), sorted.end());

	for (int i = 0; i < nums.size(); i++)
	{
		int temp = target - nums[i];
		auto j = std::lower_bound(sorted.begin(), sorted.end(), temp);
		
		if (j != sorted.end() && temp == *j)
		{
			int k;
			for (k = i + 1; k < nums.size(); k++)
				if (nums[k] == temp)
					break;
			if (k < nums.size())
			{
				result.push_back(i);
				result.push_back(k);

				break;
			}
		}

	}


	std::cout << "rusults:" << result[0] << "	" << result[1];

	return 0;
}