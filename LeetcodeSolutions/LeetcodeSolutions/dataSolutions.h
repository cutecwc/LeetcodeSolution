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
		* 引用与指针的区别:
		不存在空引用。引用必须连接到一块合法的内存。
		一旦引用被初始化为一个对象，就不能被指向到另一个对象。指针可以在任何时候指向到另一个对象。
		引用必须在创建时被初始化。指针可以在任何时间被初始化。
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
		/*采用哈希表实现
		思路：使用unordered_map  unordered_map 容器不会像 map 容器那样对存储的数据进行排序
		unordered_map 容器和 map 容器一样，以键值对（pair类型）的形式存储数据，存储的各个键值对的键互不相同且不允许被修改

		begin()				返回指向容器中第一个键值对的正向迭代器。
		end() 				返回指向容器中最后一个键值对之后位置的正向迭代器。
		cbegin()			和 begin() 功能相同，只不过在其基础上增加了 const 属性，即该方法返回的迭代器不能用于修改容器内存储的键值对。
		cend()				和 end() 功能相同，只不过在其基础上，增加了 const 属性，即该方法返回的迭代器不能用于修改容器内存储的键值对。

		empty()				若容器为空，则返回 true；否则 false。
		size()				返回当前容器中存有键值对的个数。
		max_size()			返回容器所能容纳键值对的最大个数，不同的操作系统，其返回值亦不相同。

		operator[key]		该模板类中重载了 [] 运算符，其功能是可以向访问数组中元素那样，只要给定某个键值对的键 key，就可以获取该键对应的值。注意，如果当前容器中没有以 key 为键的键值对，则其会使用该键向当前容器中插入一个新键值对。
		at(key)				返回容器中存储的键 key 对应的值，如果 key 不存在，则会抛出 out_of_range 异常。
		find(key)			查找以 key 为键的键值对，如果找到，则返回一个指向该键值对的正向迭代器；反之，则返回一个指向容器中最后一个键值对之后位置的迭代器（如果 end() 方法返回的迭代器）。
		count(key)			在容器中查找以 key 键的键值对的个数。
		equal_range(key)	返回一个 pair 对象，其包含 2 个迭代器，用于表明当前容器中键为 key 的键值对所在的范围。

		emplace()			向容器中添加新键值对，效率比 insert() 方法高。
		emplace_hint()		向容器中添加新键值对，效率比 insert() 方法高。

		insert() 			向容器中添加新键值对。
		erase()				删除指定键值对。
		clear() 			清空容器，即删除容器中存储的所有键值对。

		swap()				交换 2 个 unordered_map 容器存储的键值对，前提是必须保证这 2 个容器的类型完全相等。

		bucket_count()		返回当前容器底层存储键值对时，使用桶（一个线性链表代表一个桶）的数量。
		max_bucket_count()	返回当前系统中，unordered_map 容器底层最多可以使用多少桶。
		bucket_size(n)		返回第 n 个桶中存储键值对的数量。
		bucket(key)			返回以 key 为键的键值对所在桶的编号。

		load_factor()		返回 unordered_map 容器中当前的负载因子。负载因子，指的是的当前容器中存储键值对的数量（size()）和使用桶数（bucket_count()）的比值，即 load_factor() = size() / bucket_count()。
		max_load_factor()	返回或者设置当前 unordered_map 容器的负载因子。

		rehash(n)			将当前容器底层使用桶的数量设置为 n。
		reserve()			将存储桶的数量（也就是 bucket_count() 方法的返回值）设置为至少容纳count个元（不超过最大负载因子）所需的数量，并重新整理容器。

		hash_function()		返回当前容器使用的哈希函数对象。

		对于n^2与1的时间与空间复杂度。通常思路是使用空间换时间
		此问题是查找表问题
		通常有两个解决方案：哈希表和平衡二叉搜索树
		但由于此题不需要维护表的顺序性，所以题目中使用哈希表<键值对>版。

		在该算法的思路中：记录已经遍历的数的数值及其下标，
		通过测试得知，unordered_map 添加元素的方式有：
			insert(1,2)
			emplace(1,2)
			name[1]=2;
		同样，遍历的方式有:
			for(int size...
				cout<<name[1]
			for(int size...
				cout<<name.at(1)
		unordered_map的遍历还有:
			for(auto i:name)
				cout<<i.first i.second
			如果超出了范围 会抛出out of range 的异常。
		显然 容易发现 这个序列不能存储相同的值作为键值对索引！！(然后发现不是这样的)
		unordered_multimap 是一个允许有重复键的无序 map  unordered_map 也是可以存储重复元素的容器(只有map不行)

		https://blog.csdn.net/zou_albert/article/details/106983268

		Java文档中这样对容器描述：在建立hash表时，尽量同时指定其容量，以避免表扩容对性能的影响。
		*/
		unordered_map<int, int> hashtable;
		for (int i = 0; i < nums.size(); ++i) {
			auto it = hashtable.find(target - nums[i]);
			if (it != hashtable.end()) {
				return { it->second, i };
			}
			hashtable[nums[i]] = i;//添加一个键值对，包含<nums[i],i>
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
		//超时
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

class Timu88Solution {
public:
	Timu88Solution() {
		//非递减顺序 排列的数组合并到一起
		//其中 nums1长度为m+n 合并结果由m1存储
		/*
		time: 03/27/2022
		* https://www.cnblogs.com/QG-whz/p/5152963.html
		*/
	}
	void testFunc() {
		std::vector<int> nums1 = { 0,2,4,6,8,10,0,0,0,0,0 };
		std::vector<int> nums2 = { 1,3,5,7,9 };
		int m = 6;
		int n = 5;
		//this->mergerMys(nums1, m, nums2, n);
		//this->mergerVector(nums1, m, nums2, n);
		this->mergerFuncRefine(nums1, m, nums2, n);
		Solcpp crt;
		crt.vctprt1(nums1);
	}
private:
	void mergerMys(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
		/*好像这个就是双指针法..(算是未优化版吧.
		此算法有点复杂化了 时间超过44% 4ms 空间超过17% 8.9MB
		*/
		int flagNums1 = 0, flagNums2 = 0;
		std::vector<int> nums0(m);
		for (int i = 0; i < n + m; i++) {
			if (flagNums1 < m && flagNums2 < n) {
				if (nums1[flagNums1] < nums2[flagNums2]) {
					nums0[i] = nums1[flagNums1];
					flagNums1++;
				}
				else {
					nums0[i] = nums2[flagNums2];
					flagNums2++;
				}
			}
			else if (flagNums1 == m&& flagNums2 < n) {
				nums0[i] = nums2[flagNums2];
				flagNums2++;
			}
			else if (flagNums2 == n&& flagNums1 < m) {
				nums0[i] = nums1[flagNums1];
				flagNums1++;
			}
			else
				break;
		}
		int c = 0;
		for (auto i : nums0) {
			nums1[c] = i;
			c++;
		}
	}

	void mergerVector(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
		/*时间4ms 44.39% 空间8.7MB 87%*/
		int c = 0;
		for (int i = m; i < m + n; i++) {
			nums1[i] = nums2[c];
			c++;
		}
		sort(nums1.begin(), nums1.end());
	}

	void mergerFuncRefine(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
		/*
		* 未完成
		* time: 03/27/2022
		*/
		int flagNums1 = 0, flagNums2 = 0;
		int* nums = new int[m + n];
		int i = 0;
		while (flagNums1 < m || flagNums2 < n) {
			if (flagNums1 == m) {
				nums[i] = nums2[flagNums2];
				flagNums2++;
			}
			else if (flagNums2 == n) {
				nums[i] = nums1[flagNums1];
				flagNums1++;
			}
			else if (nums1[flagNums1] < nums2[flagNums2]) {
				nums[i] = nums1[flagNums1];
				flagNums1++;
			}
			else {
				nums[i] = nums2[flagNums2];
				flagNums2++;
			}
		}
		for (i = 0; i < m + n; i++) {
			nums1[i] = nums[i];
		}
		delete[]nums;
	}
};

class timu217Solution {
public:
	timu217Solution() {
		/*
		funcSortVer
		funcSortVer2
		两者内存消耗上几乎一致，但用时使用迭代器iterator的要耗时短一些。
		发现一点 不按标准写iterator遍历 就会莫名报错 另外如果不需要采用长段代码时，可以使用auto x:nums 同等效用
		迭代it有*it+1=(*it)+1  区别于*(it+1)
		另外 size_t 类型放在leetcode中会报错不能正常运行
		*/
	}
	bool containsDuplicate(std::vector<int>& nums) {
		size_t size = nums.size();

	}
	//运行超时ver
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
			std::cout << "有重复的元素" << std::endl;
		}
		else {
			std::cout << "没有重复的元素" << std::endl;
		}
	}

	//先排序后遍历ver
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
			std::cout << "有重复的元素" << std::endl;
		}
		else {
			std::cout << "没有重复的元素" << std::endl;
		}
		solTools.vctprt2(nums);
	}

	//hash
	/*
	unordered_set 关注于无重复元素的存储，使用了hash
	insert 如果未指定插入位置则只返回一个迭代器
	find 如果未找到某个元素则返回hash.end()
	count 返回出现次数 由于不可重复 只有0或1
	emplace 同insert 比它的效率更高一些
	erase 删除指定元素 成功返回1 否则0
	clear 清空
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

	//随机抓取一些点来匹配(概率事件)
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

class timu350Solution {
public:
	timu350Solution() {
		/*
		get two array, the elements in the same there will be selected and to return.*/
	}
	void testFunc(std::vector<int>& nums1, std::vector<int>& nums2) {
		Solcpp cpps;
		cpps.vctprt2(this->funcHashMap(nums1, nums2));
	}
private:
	std::vector<int> funcAllin(std::vector<int>& nums1, std::vector<int>& nums2) {
		/* not completed
		just find and no square and time impair will be considered
		
		error got, why?
		the order of array related, if the order of array which you put in have a exchangement. the result of the returnning will be changed,
		that's a damage
		So, the question is no Solution which based on my idea?*/
		std::vector<int> arrToReturn;
		
		/*
		for (std::vector<int>::iterator ic = nums1.begin(); ic != nums2.end(); ic++) {
			for (std::vector<int>::iterator it = nums2.begin(); it != nums2.end(); it++) {
				if (*it == *ic) {
					arrToReturn.insert(arrToReturn.begin(), *it);
					nums2.erase(it);
					break;
				}
			}
		}
		*/
		int numLenOfnums1 = nums1.size();
		int numLenOfnums2 = nums2.size();
		for (int i = 0; i < numLenOfnums1; i++) {
			std::vector<int>::iterator icc = nums2.begin();
			for (int j = 0; j < numLenOfnums2; j++) {
				if (nums1[i] == nums2[j]) {
					arrToReturn.insert(arrToReturn.begin(), nums1[i]);
					//nums2.swap(icc);
					numLenOfnums2--;
				}
				icc++;
			}
		}

		return arrToReturn;
	}

	std::vector<int> funcSort(std::vector<int>& nums1, std::vector<int>& nums2) {

	}

	std::vector<int> funcHashMap(std::vector<int>& nums1, std::vector<int>& nums2) {
		/*
		with hashmap named unordered_map, we can conservation two members of them:
			numbers in the nums1 which had found
			then the other one is: the count of them
		
		then how to use them?:
		to list them by a for loop, the value and their count will be recorded
		
		then list vector2 named nums2, to compare the value (find the count over zero) with the recorders. 
			if you can find one, a count in them will be reduce one
				if the count has been zero, the number will be delete from the vector
		hash_map just a middle value, no more role will find
		*/
		if (nums1.size() > nums2.size()) {
			return funcHashMap(nums2, nums1);
		}
		else {
			std::unordered_map<int, int> cntmap;
			for (auto it : nums1) {
				++cntmap[it];
			}

			std::vector<int> arrToRtn;
			for (auto ic : nums2) {
				if (cntmap.count(ic)) {
					arrToRtn.push_back(ic);
					--cntmap[ic];

					if (cntmap[ic] == 0) {
						cntmap.erase(ic);
					}
				}
			}

			return arrToRtn;
		}
	}
};

#endif