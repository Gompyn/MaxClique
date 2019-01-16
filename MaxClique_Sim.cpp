#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<random>
#include<map>
#include<ctime>
#include<cassert>
#include<vector>
#include"MaxCliqueFinder.h"
using namespace std;

/******************************************************************************
 * Constants to adjust
 *****************************************************************************/

const int ConstructVC_Max_Tries = 200;
constexpr int Local_Search_Iterations(int n, int m) { return n * n * 10; }
const int RemoveBMS_Max_Tries = 100;

/******************************************************************************
 * End constants to adjust
 *****************************************************************************/

int readnum(){
	int res=0;
	char c=getchar();
	for(;!isdigit(c);c=getchar());
	for(;isdigit(c);c=getchar())res=res*10+c-'0';
	return res;
}

unsigned read_u() {
	unsigned res = 0;
	char c = getchar();
	while (!isdigit(c) && c > 0) c = getchar();
	if (c < 0) return res;
	for (; isdigit(c); c = getchar()) res = res * 10 + c - '0';
	return res;
}

int n,m;

MaxCliqueFinder finder(200, 100, Local_Search_Iterations);
vector<int>max_clique;

void Initialize(){
	finder.Init();
	int i,u,v;
	for(i=1;i<=n;++i)finder.AddVertex(i);
	for(i=1;i<=m;++i){
		u=readnum(),v=readnum();
		finder.AddEdge(u,v);
	}
}
void Work(){
	max_clique=finder.FindMaxClique();
}
void PrintSolution(){
	printf("%d\n",max_clique.size());
	for(int i=0;i<max_clique.size();++i){
		printf("%d%c",max_clique[i]," \n"[i==max_clique.size()-1]);
	}
}

int main(){
	while((n = read_u()) && (m = read_u())){
		Initialize();
		Work();
		PrintSolution();
	}
	return 0;
}
