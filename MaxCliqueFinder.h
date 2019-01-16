#pragma once
#include <map>
#include <vector>
using namespace std;
using ll = long long;
constexpr int maxn=1010;
constexpr int maxm=maxn*maxn;
class MaxCliqueFinder{
private:
	const int ConstructVC_Max_Tries;
	const int RemoveBMS_Max_Tries;
	int (*Local_Search_Iteration)(int n, int m);
	
	int on;
	bool oe[maxn][maxn];
	map<int,int>mp;
	int mp_num[maxn];
	
	int n,m;
	
	struct bEdge{
		int u,v;
	}be[maxm];
	int edge_weight[maxm];
	int deg[maxn];
	int edge_ind[maxn][maxn];
	int adj[maxn][maxn];
	
	ll step;
	ll timestamp[maxn];
	
	int dscore[maxn];
	
	int nc;
	bool in_cover[maxn];
	int nr;
	int remove_cand[maxn];
	int remove_cand_ind[maxn];
	
	int best_nc;
	bool best_in_cover[maxn];
	
	int uncover_stack[maxm];
	int uncover_stack_p;
	int uncover_stack_ind[maxm];
	
	bool conf_change[maxn];
	bool tabu[maxn];
	
	int tmp_nc;
	bool tmp_in_cover[maxn];
	int edge_ind_seq[maxm];
	
	
	void ResetRemoveCand();
	inline void Uncover(int e);
	inline void Cover(int e);
	void Add(int p);
	void Remove(int p);
	int ChooseRemove_MinLoss();
	int ChooseRemove_BMS(int times);
	int ChooseAddV(int remove_v1,int remove_v2);
	inline void UpdateBestSolution();
	void RemoveRedundant();
	void ConstructVC(int tries);
	void UpdateEdgeWeight();
	void LocalSearch(int iters);
	
	void InitComplimentGraph();
	void FindMinVertexCover();
	
public:

	MaxCliqueFinder(int ConstructVC_max_tries,
					int RemoveBMS_max_tries,
					int (*LocalSearch_iteration)(int, int)):
		ConstructVC_Max_Tries(ConstructVC_max_tries),
		RemoveBMS_Max_Tries(RemoveBMS_max_tries),
		Local_Search_Iteration(LocalSearch_iteration) { }
	void Init();
	void AddVertex(int u);
	void AddEdge(int u,int v);
	vector<int>FindMaxClique();
	
};