#include<iostream>
using namespace std;
const int N = 100;
int A[N];//矩阵规模
int m[N][N];//最优解
int s[N][N];
void MatrixChain(int n)
{
	int r, i, j, k;
	for (i = 0; i <= n; i++)//初始化对角线
	{
		m[i][i] = 0;
	}
	for (r = 2; r <= n; r++)//r个矩阵连乘
	{
		for (i = 1; i <= n - r + 1; i++)//r个矩阵的r-1个空隙中依次测试最优点
		{
			j = i + r - 1;
			m[i][j] = m[i][i]+m[i + 1][j] + A[i - 1] * A[i] * A[j];
			s[i][j] = i;
			for (k = i + 1; k < j; k++)//变换分隔位置，逐一测试
			{
				int t = m[i][k] + m[k + 1][j] + A[i - 1] * A[k] * A[j];
				if (t < m[i][j])//如果变换后的位置更优，则替换原来的分隔方法。
				{
					m[i][j] = t;
					s[i][j] = k;
				}
			}
		}
	}
}
void print(int i, int j, int k)
{

	if (i == j)
	{

		cout << "A" << i ;
		return;
	}
else
{ 
    if(k==1)
    {
        k=0;
         print(i, s[i][j],k);
	    print(s[i][j] + 1, j,k);//递归1到s[1][j]
    }
    else
    {
        cout << "(";
    print(i, s[i][j],k);
	print(s[i][j] + 1, j,k);//递归1到s[1][j]
    cout << ")";
    }
    
}

}
int main()
{
	int n;//n个矩阵
	cin >> n;
	int i, j;
	for (i = 0; i <= n; i++)
	{
		cin >> A[i];
	}
	MatrixChain(n);
	cout << m[1][n] << endl;
	print(1, n,1);

	return 0;
}


