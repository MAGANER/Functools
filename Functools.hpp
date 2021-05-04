#pragma once
#include<functional>
#include<map>
namespace Functools
{
	template<class T,class F>
	T map(const T& seq, const std::function<F>& lambda)
	{
		//iterate over the passed sequence and apply 
		//passed lambda to each element
		//then returns new sequence

		T new_seq;
		for (auto& elem:seq)
		{
			auto result = lambda(elem);
			new_seq.push_back(result);
		}
		return new_seq;
	}
	template<class T1,class T2, class F>
	std::map<T1, T2> map(const std::map<T1, T2>& hash_table, std::function<F>& lambda)
	{
		//map function for hash tables

		std::map<T1, T2> new_map;
		for(auto beg = hash_table.begin();beg!=hash_table.end();++beg)
		{
			auto result = lambda(beg->second);
			new_map[beg->first] = result;
		}
		return new_map;
	}

	template<class T, class F>
	T filter(const T& seq, const std::function<bool(F)>& predicat)
	{
		//if sequance elements matches to predicat, then save it

		T new_seq;
		for (auto& elem : seq)
		{
			if (predicat(elem))new_seq.push_back(elem);
		}
		return new_seq;
	}
	template<class T1, class T2, class F>
	std::map<T1, T2> filter(const std::map<T1, T2>& hash_table, std::function<bool(F)>& predicat)
	{
		//filter function for hash tables

		std::map<T1, T2> new_map;
		for (auto beg = hash_table.begin(); beg != hash_table.end(); ++beg)
		{
			if (predicat(beg->second))new_map[beg->first] = beg->second;
		}
		return new_map;
	}

	template<class T, class F, class A>
	A reduce(const T& seq, const std::function<F(A,A)>& lambda)
	{
		//this function was inspired by python's standart library

		A result = A();

		for (auto& elem : seq)
		{
			result = lambda(result, elem);
		}
		return result;
	}
};