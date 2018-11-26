
//find+substr实现split
//输出至vector<string>中

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<vector>
#include<string>
using namespace std;
vector<string> spilt(const string &str, const string &delim)
{
	vector<string> spiltCollection;
	if (str.size() == 0)
		return spiltCollection;
	int start = 0;
	int idx = str.find(delim, start);
	while (idx != string::npos)
	{
		spiltCollection.push_back(str.substr(start, idx - start));
		start = idx + delim.size();
		idx = str.find(delim, start);
	}
	spiltCollection.push_back(str.substr(start));
	return spiltCollection;
}

vector<string>  split(const string& str, const string& delim) { //将分割后的子字符串存储在vector中
	vector<string> res;
	if ("" == str) return  res;

	string strs = str + delim; //*****扩展字符串以方便检索最后一个分隔出的字符串
	size_t pos;
	size_t size = strs.size();

	for (int i = 0; i < size; ++i) {
		pos = strs.find(delim, i); //pos为分隔符第一次出现的位置，从i到pos之前的字符串是分隔出来的字符串
		if (pos < size) { //如果查找到，如果没有查找到分隔符，pos为string::npos
			string s = strs.substr(i, pos - i);//*****从i开始长度为pos-i的子字符串
			res.push_back(s);//两个连续空格之间切割出的字符串为空字符串，这里没有判断s是否为空，所以最后的结果中有空字符的输出，
			i = pos + delim.size() - 1;
		}

	}
	return res;
}

int main() {
	vector<string >a = spilt(s, " ");
	int n = 0;
	for (auto i : a) {
		cout << i << endl;
	}
	return 0;
}



//strtok实现split
//函数原型：char * strtok (char *str, char * delim);

//函数功能：以delim为分隔符分割字符串str

//参数说明：str：要分隔的字符串；delim：分隔符

//返回值：从str开头开始的一个个被分割的字符串。当没有被分割时则返回null
int main() {
	char s[] = "hello world 555 444 333 222 111";
	char *p;
	const char *delim = " ";
	p = strtok(s, delim);
	while (p) {
		cout << p << endl;
		p = strtok(NULL, delim);
	}
	return 0;
}

//strtok实现split 输出至vector<string>中
vector<string> split(const string& str, const string& delim) {
	vector<string> res;
	if ("" == str) return res;
	//先将要切割的字符串从string类型转换为char*类型
	char * strs = new char[str.length() + 1]; //不要忘了
	strcpy(strs, str.c_str());

	char * d = new char[delim.length() + 1];
	strcpy(d, delim.c_str());

	char *p = strtok(strs, d);
	while (p) {
		string s = p; //分割得到的字符串转换为string类型
		res.push_back(s); //存入结果数组
		p = strtok(NULL, d);
	}

	return res;
}


int main() {
	char s[] = "hello world 555 444 333 222 111";
	const char *delim = " ";
	vector<string >a = split1(s, delim);
	for (auto i : a)
		cout << i << endl;
	return 0;
}

//正则表达式方式
std::vector<std::string> regexsplit(const std::string& input)
{ 
    std::regex re(",");

    std::sregex_token_iterator p(input.begin(), input.end(), re, -1);
    std::sregex_token_iterator end;
    std::vector<std::string> vec;
    while (p != end)
        vec.emplace_back(*p++);
 
    return vec;
}
 
//使用boost split 实现
std::vector<std::string> boostsplit(const std::string& input)
{
    std::vector <std::string> fields;
    boost::split( fields, input, boost::is_any_of( "," ) );
    return fields;
}
//sds  sdssplitlen 函数实现

void sdssplit(const std::string& input, std::vector<std::string>& v)

{

int len = 0;
sds* array = sdssplitlen(input.c_str(),input.length(),",",1,&len);
for(int i=0;i<len;i++)
　　v.emplace_back(array[i]);

}