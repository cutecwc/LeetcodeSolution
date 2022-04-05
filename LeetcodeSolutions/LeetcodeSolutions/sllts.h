#pragma once
#ifndef _SLLTS_H_
#define _SLLTS_H_
/*程序的轮子 写在此处*/
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solcpp {
public:
	void vctprt1(vector<int> nums) {
		/*访问vector<int>里面的元素，参数为vct<int>的数组 迭代iterator*/
		cout << endl;
		for (vector<int>::iterator it = nums.begin(); it != nums.end(); it++) {
			cout << "  " << *it;
		}
	}
	void vctprt2(vector<int> nums) {
		/*访问vector<int>里面的元素，参数为vct<int>的数组 直接访问*/
		cout << endl;
		for (size_t it = 0; it < nums.size(); it++) {
			cout << "  " << nums[it];
		}
	}
};

namespace forTest {
	/*测试空间
	* 将一些测试的函数写在此处
	*/
	void forHashmap() {
		unordered_map<int, int> tests;
		tests[1] = 12;
		tests[0] = 14;
		tests.emplace(2, 5);
		//tests.insert(3, 7);非法间接寻址
		tests.emplace(3, 7);
		tests.emplace(4, 9);
		tests.emplace(4, 19);


		cout << tests.at(2) << endl;


		for (auto it : tests) {
			cout << it.first << "<--遍历方式1-->" << it.second << endl;
		}


		//不能运行?
		auto it2 = tests.find(4);
		if (it2 != tests.end()) {
			cout << " <--遍历方式2-->" << it2->second << endl;
		}

		//不能运行?
		/*ToSearch: Lambda表达是什么? 仿函数是什么?
		* 一个完整的 lambda 表达式看起来像这样：
		* auto f = [](int a) -> int { return a + 1; };
		  std::cout << f(1) << std::endl;  // 输出: 2
		*
		*/
		auto its = tests.equal_range(4);
		//for_each(it.first, it.second, [](unordered_multimap<string, double>::value_type &x) {cout << x.first << "  " << x.second << endl; });
		for_each(its.first, its.second, [](unordered_map<int, int>::value_type& x) {
			cout << x.first << "<--遍历方式3-->" << x.second << endl;
			});
	}

	void forLoopFortest() {
		/*
		to practice the mind of loop locating, i created this theme.*/
		int arr[6] = { 1,4,5,12,6,24 };
		auto forloop = [&](int* arr, int size) {
			/*
			a common forloop. that loop from 0 to size,
				0 to size made by < 
				0 to i<6
				cross by 0,1,2,3,4,5 */
			for (int i = 0; i < size; i++) {
				std::cout << " " << arr[i];
			}
		};
		auto forloop2 = [&](int* arr, int size) {
			try{
				/*
				0 to i<=6;
				0,1,2,3,4,5,6 */
				for (int i = 0; i <= size; i++) {
					std::cout << " " << arr[i];
				}
			}
			catch (const std::exception&){
				std::cout << "err: An over boundary access occured." << std::endl;
			}
		};

	}
}

#endif