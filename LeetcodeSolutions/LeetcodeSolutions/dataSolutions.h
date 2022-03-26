#pragma once
#ifndef _DATASOLUTION_H_
#define _DATASOLUTION_H_

#include<iostream>
#include<vector>
#include <algorithm>
#include<unordered_set>
#include<unordered_map>

#include"sllts.h"

class timu1Solution {
	std::vector<int> twoSum(std::vector<int>& nums, int target) {
		/*
		@TODO:
		to find the index which can add into a certain number
		*/
	}
public:
	timu1Solution() {

	}
	void testFuncs(std::vector<int>& num) {
		/*
		* ������ָ�������:
		�����ڿ����á����ñ������ӵ�һ��Ϸ����ڴ档
		һ�����ñ���ʼ��Ϊһ�����󣬾Ͳ��ܱ�ָ����һ������ָ��������κ�ʱ��ָ����һ������
		���ñ����ڴ���ʱ����ʼ����ָ��������κ�ʱ�䱻��ʼ����
		*/

	}

private:
	std::vector<int> funcEnum(std::vector<int>& nums, int target) {
		int n = nums.size();
		for (int i = 0; i < n; ++i) {
			for (int j = i + 1; j < n; ++j) {
				if (nums[i] + nums[j] == target) {
					return { i, j };
				}
			}
		}
		return {};
	}

	std::vector<int> funcHash(std::vector<int>& nums, int target) {
		/*���ù�ϣ��ʵ��
		˼·��ʹ��unordered_map  unordered_map ���������� map ���������Դ洢�����ݽ�������
		unordered_map ������ map ����һ�����Լ�ֵ�ԣ�pair���ͣ�����ʽ�洢���ݣ��洢�ĸ�����ֵ�Եļ�������ͬ�Ҳ������޸�

		begin()				����ָ�������е�һ����ֵ�Ե������������
		end() 				����ָ�����������һ����ֵ��֮��λ�õ������������
		cbegin()			�� begin() ������ͬ��ֻ������������������� const ���ԣ����÷������صĵ��������������޸������ڴ洢�ļ�ֵ�ԡ�
		cend()				�� end() ������ͬ��ֻ������������ϣ������� const ���ԣ����÷������صĵ��������������޸������ڴ洢�ļ�ֵ�ԡ�

		empty()				������Ϊ�գ��򷵻� true������ false��
		size()				���ص�ǰ�����д��м�ֵ�Եĸ�����
		max_size()			���������������ɼ�ֵ�Ե�����������ͬ�Ĳ���ϵͳ���䷵��ֵ�಻��ͬ��

		operator[key]		��ģ������������ [] ��������书���ǿ��������������Ԫ��������ֻҪ����ĳ����ֵ�Եļ� key���Ϳ��Ի�ȡ�ü���Ӧ��ֵ��ע�⣬�����ǰ������û���� key Ϊ���ļ�ֵ�ԣ������ʹ�øü���ǰ�����в���һ���¼�ֵ�ԡ�
		at(key)				���������д洢�ļ� key ��Ӧ��ֵ����� key �����ڣ�����׳� out_of_range �쳣��
		find(key)			������ key Ϊ���ļ�ֵ�ԣ�����ҵ����򷵻�һ��ָ��ü�ֵ�Ե��������������֮���򷵻�һ��ָ�����������һ����ֵ��֮��λ�õĵ���������� end() �������صĵ���������
		count(key)			�������в����� key ���ļ�ֵ�Եĸ�����
		equal_range(key)	����һ�� pair ��������� 2 �������������ڱ�����ǰ�����м�Ϊ key �ļ�ֵ�����ڵķ�Χ��

		emplace()			������������¼�ֵ�ԣ�Ч�ʱ� insert() �����ߡ�
		emplace_hint()		������������¼�ֵ�ԣ�Ч�ʱ� insert() �����ߡ�

		insert() 			������������¼�ֵ�ԡ�
		erase()				ɾ��ָ����ֵ�ԡ�
		clear() 			�����������ɾ�������д洢�����м�ֵ�ԡ�

		swap()				���� 2 �� unordered_map �����洢�ļ�ֵ�ԣ�ǰ���Ǳ��뱣֤�� 2 ��������������ȫ��ȡ�

		bucket_count()		���ص�ǰ�����ײ�洢��ֵ��ʱ��ʹ��Ͱ��һ�������������һ��Ͱ����������
		max_bucket_count()	���ص�ǰϵͳ�У�unordered_map �����ײ�������ʹ�ö���Ͱ��
		bucket_size(n)		���ص� n ��Ͱ�д洢��ֵ�Ե�������
		bucket(key)			������ key Ϊ���ļ�ֵ������Ͱ�ı�š�

		load_factor()		���� unordered_map �����е�ǰ�ĸ������ӡ��������ӣ�ָ���ǵĵ�ǰ�����д洢��ֵ�Ե�������size()����ʹ��Ͱ����bucket_count()���ı�ֵ���� load_factor() = size() / bucket_count()��
		max_load_factor()	���ػ������õ�ǰ unordered_map �����ĸ������ӡ�

		rehash(n)			����ǰ�����ײ�ʹ��Ͱ����������Ϊ n��
		reserve()			���洢Ͱ��������Ҳ���� bucket_count() �����ķ���ֵ������Ϊ��������count��Ԫ����������������ӣ����������������������������

		hash_function()		���ص�ǰ����ʹ�õĹ�ϣ��������

		����n^2��1��ʱ����ռ临�Ӷȡ�ͨ��˼·��ʹ�ÿռ任ʱ��
		�������ǲ��ұ�����
		ͨ�������������������ϣ���ƽ�����������
		�����ڴ��ⲻ��Ҫά�����˳���ԣ�������Ŀ��ʹ�ù�ϣ��<��ֵ��>�档

		�ڸ��㷨��˼·�У���¼�Ѿ�������������ֵ�����±꣬
		ͨ�����Ե�֪��unordered_map ���Ԫ�صķ�ʽ�У�
			insert(1,2)
			emplace(1,2)
			name[1]=2;
		ͬ���������ķ�ʽ��:
			for(int size...
				cout<<name[1]
			for(int size...
				cout<<name.at(1)
		unordered_map�ı�������:
			for(auto i:name)
				cout<<i.first i.second
			��������˷�Χ ���׳�out of range ���쳣��
		��Ȼ ���׷��� ������в��ܴ洢��ͬ��ֵ��Ϊ��ֵ����������(Ȼ���ֲ���������)
		unordered_multimap ��һ���������ظ��������� map  unordered_map Ҳ�ǿ��Դ洢�ظ�Ԫ�ص�����(ֻ��map����)

		https://blog.csdn.net/zou_albert/article/details/106983268

		Java�ĵ��������������������ڽ���hash��ʱ������ͬʱָ�����������Ա�������ݶ����ܵ�Ӱ�졣
		*/
		unordered_map<int, int> hashtable;
		for (int i = 0; i < nums.size(); ++i) {
			auto it = hashtable.find(target - nums[i]);
			if (it != hashtable.end()) {
				return { it->second, i };
			}
			hashtable[nums[i]] = i;//���һ����ֵ�ԣ�����<nums[i],i>
		}
		return {};
	}

};

class timu53Solution {
public:
	timu53Solution() {
		/*
		TODO: to find a child, which add on a biggest number

		*/
	}
	void testApi53(std::vector<int>& nums) {
		//Solcpp solTools;
		int ccTemp = this->funcAuFVer3(nums);
		std::cout << "get max sum is: " << ccTemp << std::endl;
		return;
	}
private:
	int funcAllScan1(std::vector<int>& nums) {
		int numsSize = nums.size();
		int tempSum = 0, maxSum = INT_MIN;
		int mxSize = 0;
		for (mxSize = 1; mxSize <= numsSize; mxSize++) {
			for (int i = 0; i < numsSize; i++) {
				for (int j = 0; j < mxSize; j++) {
					tempSum += nums[j];
				}
				if (tempSum > maxSum) {
					maxSum = tempSum;
				}
				tempSum = 0;
			}
		}
		return maxSum;
	}

	int funcAllScanVer2(std::vector<int>& nums) {
		//��ʱ
		int max = INT_MIN;
		int numsSize = int(nums.size());
		for (int i = 0; i < numsSize; i++) {
			int sum = 0;
			for (int j = i; j < numsSize; j++) {
				sum += nums[j];
				if (sum > max) {
					max = sum;
				}
			}
		}
		return max;
	}

	int funcAuFVer3(std::vector<int>& nums) {
		int sum = 0, maxSum = INT_MIN;
		for (auto x : nums) {
			sum = max(sum + x, x);
			maxSum = max(sum, maxSum);
		}
		return maxSum;
	}
};

class timu217Solution {
public:
	timu217Solution() {
		/*
		funcSortVer
		funcSortVer2
		�����ڴ������ϼ���һ�£�����ʱʹ�õ�����iterator��Ҫ��ʱ��һЩ��
		����һ�� ������׼дiterator���� �ͻ�Ī������ �����������Ҫ���ó��δ���ʱ������ʹ��auto x:nums ͬ��Ч��
		����it��*it+1=(*it)+1  ������*(it+1)
		���� size_t ���ͷ���leetcode�лᱨ������������
		*/
	}
	bool containsDuplicate(std::vector<int>& nums) {
		size_t size = nums.size();

	}
	//���г�ʱver
	bool func(std::vector<int>& nums) {
		bool flagIsRepeat = false;
		for (std::vector<int>::iterator it = nums.begin(); it != nums.end(); it++) {
			for (std::vector<int>::iterator its = it + 1; its != nums.end(); its++) {
				if (*it == *its) {
					flagIsRepeat = true;
					break;
				}
			}
		}
		return flagIsRepeat;
	}
	void testFunc() {
		std::vector<int> nums = { 1,2,3,4,5,7,8,10,14,15,19,22 };
		if (this->func(nums)) {
			std::cout << "���ظ���Ԫ��" << std::endl;
		}
		else {
			std::cout << "û���ظ���Ԫ��" << std::endl;
		}
	}

	//����������ver
	bool funcSortVer(std::vector<int>& nums) {
		sort(nums.begin(), nums.end());//
		for (std::vector<int>::iterator it = nums.begin(); it + 1 != nums.end(); it++) {
			//std::cout << "  *it + 1:" << *it + 1 << " (*it)+1 :" << (*it) + 1 << " *(it+1): " << *(it + 1) << std::endl;
			//break;
			if ((*it) == (*(it + 1))) {
				return true;
			}
		}
		return false;
	}

	bool funcSortVer2(std::vector<int>& nums) {
		sort(nums.begin(), nums.end());//
		int sizeVector = nums.size();
		if (1 < sizeVector) {
			for (int i = 0; i < sizeVector - 1; i++) {
				if (nums[i] == nums[i + 1]) {
					return true;
				}
			}
		}
		return false;
	}

	void testfuncSortVer() {
		std::vector<int> nums = { 0,2,3,4,5,10,8,7,99,14,15,19,22 };
		//std::vector<int> nums = { 1 };
		Solcpp solTools;
		solTools.vctprt1(nums);

		if (this->funcSortVer2(nums)) {
			std::cout << "���ظ���Ԫ��" << std::endl;
		}
		else {
			std::cout << "û���ظ���Ԫ��" << std::endl;
		}
		solTools.vctprt2(nums);
	}

	//hash
	/*
	unordered_set ��ע�����ظ�Ԫ�صĴ洢��ʹ����hash
	insert ���δָ������λ����ֻ����һ��������
	find ���δ�ҵ�ĳ��Ԫ���򷵻�hash.end()
	count ���س��ִ��� ���ڲ����ظ� ֻ��0��1
	emplace ͬinsert ������Ч�ʸ���һЩ
	erase ɾ��ָ��Ԫ�� �ɹ�����1 ����0
	clear ���
	*/
	bool funcHashInsert(std::vector<int>& nums) {
		std::unordered_set<int> setits;
		for (int x : nums) {
			if (setits.find(x) != setits.end()) {
				return true;
			}
			setits.insert(x);
		}
		return false;
	}

	void testFuncHashInsert() {
		std::vector<int> nums = { 0,2,3,4,5,10,8,7,99,14,15,19,22 };
		//std::vector<int> nums = { 1 };
		Solcpp solTools;
		solTools.vctprt1(nums);

		if (this->funcHashInsert(nums)) {
			std::cout << "has" << std::endl;
		}
		else {
			std::cout << "has not" << std::endl;
		}
		solTools.vctprt2(nums);
	}

	//���ץȡһЩ����ƥ��(�����¼�)
	bool funcSrandToFound(std::vector<int>& nums) {
		int i = 0;
		int a = 0, b = 0;
		srand(time(0));
		int sizeNum = nums.size();
		if (1 >= sizeNum) {
			return false;
		}
		else {
			for (i = 0; i < 10000; i++) {
				a = rand() % sizeNum;
				b = rand() % sizeNum;

				if (a != b && nums[a] == nums[b]) {
					return true;
				}
			}
			return 9999 == nums[sizeNum - 1];
		}
	}

	void testFuncSrandTFound() {
		std::vector<int> nums = { 0,2,4,4,5,10,8,7,99,14,15,19,22 };
		//std::vector<int> nums = { 1 };
		Solcpp solTools;
		solTools.vctprt1(nums);

		if (this->funcSrandToFound(nums)) {
			std::cout << "has" << std::endl;
		}
		else {
			std::cout << "has not" << std::endl;
		}
		solTools.vctprt2(nums);
	}
};

#endif