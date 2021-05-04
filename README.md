# Functools
pretty simple and basic functional library for C++

## What it can do?
First of all you should know this library is pretty small.<br>
It contains 4 functions only: map, filter, slice and reduce.<br>

As you can guess, it was inspired by python.<br>

i wanted to create pure function to work with basic data structures from c++ STL: ```vector```, ```list``` and ```map```.<br>

## How to use
You need to include ```Functools.hpp``` and optionally ```use namespace Functools```.<br>


1.```map```<br>
```c++
vector<int> test = {1,2,3,4,5,6,7,8,9,10};
function<int(int)> add = [](int elem){return elem+1;};
auto result = Functools::map(test,add);
```

You will get copy of test, but add lambda is apllied to each element of test vector.

2.```filter```
```c++
vector<int> test = {1,2,3,4,5,6,7,8,9,10};
function<bool(int)> pred = [](int elem){return elem>5;};
auto result = Functools::filter(test,pred);
```

You will get vector of numbers higher then 5.

3.```reduce```
```c++
vector<int> test = {1,2,3,4,5,6,7,8,9,10};
function<int(int,int)> add = [](int a, int b){return a+b;};
auto result = Functools::reduce(test,add);
```

You will get 55. Just abstract accumulator.

4.```slice```
I don't like std::string::substr and there is no common way to get slice of linear structures.<br>
So i added this function. It returns slice: [begin, end] ⊂ S.
```c++
vector<int> test = { 1,2,3,4,5,6,7,8,9,10 };
auto new_slice = slice(test, 5, 10);
```

### Why did i write this library?
Well, mostly because i don't like ```<algorithm>``` from c++ std.
