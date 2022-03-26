#pragma once
#ifndef _SLLTS_H_
#define _SLLTS_H_
/*��������� д�ڴ˴�*/
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solcpp {
public:
	void vctprt1(vector<int> nums) {
		/*����vector<int>�����Ԫ�أ�����Ϊvct<int>������ ����iterator*/
		cout << endl;
		for (vector<int>::iterator it = nums.begin(); it != nums.end(); it++) {
			cout << "  " << *it;
		}
	}
	void vctprt2(vector<int> nums) {
		/*����vector<int>�����Ԫ�أ�����Ϊvct<int>������ ֱ�ӷ���*/
		cout << endl;
		for (size_t it = 0; it < nums.size(); it++) {
			cout << "  " << nums[it];
		}
	}
};

namespace forTest {
	/*���Կռ�
	* ��һЩ���Եĺ���д�ڴ˴�
	*/
	void forHashmap() {
		unordered_map<int, int> tests;
		tests[1] = 12;
		tests[0] = 14;
		tests.emplace(2, 5);
		//tests.insert(3, 7);�Ƿ����Ѱַ
		tests.emplace(3, 7);
		tests.emplace(4, 9);
		tests.emplace(4, 19);


		cout << tests.at(2) << endl;


		for (auto it : tests) {
			cout << it.first << "<--������ʽ1-->" << it.second << endl;
		}


		//��������?
		auto it2 = tests.find(4);
		if (it2 != tests.end()) {
			cout << " <--������ʽ2-->" << it2->second << endl;
		}

		//��������?
		/*ToSearch: Lambda�����ʲô? �º�����ʲô?
		* һ�������� lambda ���ʽ��������������
		* auto f = [](int a) -> int { return a + 1; };
		  std::cout << f(1) << std::endl;  // ���: 2
		*
		*/
		auto its = tests.equal_range(4);
		//for_each(it.first, it.second, [](unordered_multimap<string, double>::value_type &x) {cout << x.first << "  " << x.second << endl; });
		for_each(its.first, its.second, [](unordered_map<int, int>::value_type& x) {
			cout << x.first << "<--������ʽ3-->" << x.second << endl;
			});

	}
}

#endif