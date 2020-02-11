/*
tyx今天上课实在是太累了，因此他懒得编题面，直接抱住了你的大腿请你帮他解决这个问题
给定两个数n,m，请你求出一个最小的只由组成0,1,...n-1的正整数，使得他是m的倍数*/
#include <iostream>
#include <queue>
#include <string>
#define ull unsigned long long
#define MAX 1000000000000000000
using namespace std;
struct number {
	string a;
	ull mod;
	number(string strnum = "", int mod = 0) :a(strnum), mod(mod) {};
};
queue<number> q;
ull num;
string bfs(ull n,ull m) {
	for (ull i = 1; i <= n - 1; i++) {
		string x = "";
		x = i + '0';
		number num_0(x,i);
		q.push(num_0);
		if (m == i) {
			return x;
		}
	}
	while (!q.empty()) {
		number num = q.front();
		q.pop();
		for (ull i = 0; i <= n - 1; i++) {
			ull newnum;
			newnum = num.mod * 10 + i;
			newnum = newnum % m;
			string strnum = "";
			string tmpstr;
			tmpstr = (i + '0');
			strnum = num.a + tmpstr;
			if (newnum == 0) {
				return strnum;
			}
			number next(strnum, newnum);
			q.push(next);
		}
	}
}

int main()
{
	ull n, m;
	cin >> n >> m;
	if (m == 0) cout << 0;
	else cout << bfs(n, m);
}