#include<cstdio>
#include<algorithm>
#include<map>
using namespace std;
const int maxn = 100;
map<int, int> mmp;
int a[maxn], b[maxn], n, p[maxn];
int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i ++)
		scanf("%d", &a[i]), b[i] = a[i];
	
	sort(b+1, b+1+n);
	for(int i = 1; i < n; i ++)
		mmp[b[i]] = i+1;
	mmp[b[n]] = 1;

	for(int i = 1; i <= n; i ++)
		printf("%d ", b[mmp[a[i]]]);
	
	return 0;
}
