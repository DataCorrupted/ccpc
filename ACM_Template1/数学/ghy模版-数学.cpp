// 扩展欧几里德算法

void gcd(lli a, lli b, lli&d, lli&x, lli&y) {
	if(!b) d = a, x = 1, y = 0;
	else gcd(b, a%b, d, y, x), y -= x*(a/b);
}


// 逆元
// a 与 n 互质

lli inv(lli a, lli n) {
	lli d, x, y;
	gcd(a, n, d, x, y);
	return d == 1 ? (x%n+n)%n : -1;
}


// 组合数
// 预处理阶乘和逆元会更快
// 还可以用 lucas 定理优化

lli C(lli n, lli m, lli p) {
	lli s1 = 1, s2 = 1;
	for(int i = n-m+1; i <= n; i++)
		s1 = s1 * i % p;
	for(int i = 1; i <= m; i++)
		s2 = s2 * i % p;
	return s1 * inv(s2, p) % p;
}


lli pow_mod(lli a, lli n, lli p) {
	lli ret = 1;
	for(; n; n>>=1, a = a*a % p)
	    if(n & 1) ret = ret*a % p
	return ret;
}


// 防止乘法溢出

lli mul_mod(lli a, lli n, lli p) {
	lli ret = 0;
	for(; n; n>>=1, a = (a<<1) % p) 
		if(n & 1) ret = (ret+a) % p;
	return ret;
}


// BSGS
// a^x ≡ b (mod p)
// x = k*m + n, n < m
// a^(k*m+n) ≡ b (mod p) => a^(k*m) * a^n ≡ b(mod p)
// 预处理 a^n
// 主过程a^n ≡ b*inv(a^(k*m)) (mod p)
// 预处理 inv(a^m), 则 inv(a^(k*m)) = inv(a^((k-1)*m)) * inv(a^m)

// 预处理a^n : O(m*log(m)), 主过程共 p/m 轮 : O(p/m * log(m)).
// 总时间复杂度 : O(m*log(m) + p/m * log(m)) = O((m+p/m)*log(m)), 当 m = sqrt(p) 时总时间较短

lli log_mod(lli a, lli b) {
	lli m, v, e = 1;
	m = (lli)(sqrt(p) + 0.5); // notice
	v = pow_mod(pow_mod(a, m), p-2);
	map <lli,lli> x;
	x[1] = 0;
	// 预处理 a^m
	for(int i = 1; i < m; i++) {
		e = e*a % p;
		if(!x.count(e)) x[e] = i;
	}
	for(int i = 0; i < m; i++) {
		if(x.count(b)) return i*m + x[b];
		b = b*v % p;
	}
	return -1;
}


int vis[maxn];
int prime[maxp];

void sieve(int n) {
	int m = (int)(sqrt(n) + 0.5);
	memset(vis, 0, sizeof(vis));
	for(int i = 2; i <= m; i++) if(!vis[i])
		for(int j = i*i; j <= n; j+=i) vis[j] = 1;
}


int gen_primes(int n) {
	sieve(n);
	int c = 0;
	for(int i = 2; i <= n; i++) if(!vis[i])
		prime[c++] = i;
	return c;
}


struct Matrix {
	int n, m;
	int a[maxn][maxn];
	
	Matrix(int n=0, int m=0) : n(n), m(m) { memset(a, 0, sizeof(a)); }
	
	// 快速幂
	Matrix operator ^ (int p) {
		Matrix t = Matrix(n, n), A = *this;
		for(int i = 0; i < n; i++) t.a[i][i] = 1;
		for(; p; p>>=1, A=A*A) if(p & 1) t = t*A;
		return t;
	}
	
	Matrix operator * (Matrix A) {
		Matrix ret = Matrix(n, A.m);
		for(int i = 0; i < n; i++)
			for(int j = 0; j < A.m; j++) {
				ret.a[i][j] = 0;
				for(int k = 0; k < m; k++)
					ret.a[i][j] = ((lli)a[i][k]*A.a[k][j] + ret.a[i][j]) % mod;
			}
		return ret;
	}
	
	void print() {
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++)
				printf("%d ", a[i][j]);
			printf("\n");
		}
	}
};


struct XorGauss {
	bitset<maxm> maxn;
	int n;
	
	int gaussJordan() {
		int i, j, k, r = 0;
		for(j = 0; j < n; j++) {
			i = r;
			while(i < m && !A[i][j]) i++;
			if(i >= m) return -1;
			for(k = 0; k < m; k++)
				if(k != i && A[k][j]) A[k]^=A[i];
			swap(A[i], A[r++]);
		}
		return 1;
	}
};


struct Gauss {
	int n;
	double A[maxn][maxn];
	
	void gauss() {
		int i, j, k, r;
		for(i = 0; i < n; i++) {
			r = i;
			for(j = i+1; j < n; j++)
				if(fabs(A[j][i]) > fabs(A[r][i])) r = j;
			if(r != i) for(j = 0; j <= n; j++) swap(A[r][j], A[i][j]);
			for(k = i+1; k < n; k++) {
				double f = A[k][i] / A[i][i];
				for(j = i; j <= n; j++) A[k][j] -= f * A[i][j];
			}
		}
		for(i = n-1; i >= 0; i--) {
			for(j = i+1; j < n; j++)
				A[i][n] -= A[j][n] * A[i][j];
			A[i][n] /= A[i][i];
		}
	}
	
	void gaussJordan() {
		int i, j, k, r;
		for(i = 0; i < n; i++) {
			r = i;
			for(j = i+1; j < n; j++)
				if(fabs(A[j][i]) > fabs(A[r][i])) r = j;
			if(fabs(A[j][i]) < eps) continue;
			if(r != i) for(j = 0; j <= n; j++) swap(A[r][j], A[i][j]);
			for(k = 0; k < n; k++) if(k != i)
				for(j = n; j >= i; j--) A[k][j] -= A[k][i]/A[i][i] * A[i][j];
		}
	}
};


struct MU {
	int c, mu[maxn], prime[maxn];
	bool vis[maxn];
	
	void get_mu() {
		mu[1] = 1;
		for(int i = 2; i < maxn; i++) {
			if(!vis[i]) prime[++c] = i, mu[i] = -1;
			for(int j = 1; prime[j]*i < maxn; j++) {
				int k = prime[j] * i;
				vis[k] = 1;
				if(i % prime[j] == 0) { mu[k] = 0; break; }
				mu[k] = -mu[i];
			}
		}
	}
};


struct Simpson {
	double F(double x) {}
	
	double simpson(double a, double b) {
		double c = a + (b-a)/2;
		return (F(a)+4*F(c)+F(b))*(b-a)/6;
	}
	
	// 保证误差 < eps
	double asr(double a, double b, double eps, double A) {
		double c = a + (b-a)/2;
		double L = simpson(a, c), R = simpson(c, b);
		if(fabs(L+R-A) <= 15.0*eps) return L+R+(L+R-A)/15.0; // 这个 15.0 也是用来调整精度的
		return asr(a, c, eps/2, L) + asr(c, b, eps/2, R);
	}
	
	// 保证误差 < eps
	double asr(double a, double b, double eps) {
		return asr(a, b, eps, simpson(a, b));
	}
};


struct EulerPhi {
	int phi[maxn];
	
	void euler_phi(int n) {
		phi[1] = 1;
		for(int i = 2; i <= n; i++) if(!phi[i])
			for(int j = i; j <= n; j += i) {
				if(!phi[j]) phi[j] = j;
				phi[j] = phi[j] / i * (i-1);
			}
	}
	
	int get_phi(int n) {
		int ret = n;
		int m = (int)(sqrt(n) + 0.5);
		for(int i = 2; i <= m; i++) if(n % i == 0) {
			ret = ret / i * (i-1);
			while(n % i == 0) n /= i;
		}
		if(n > 1) ret = ret / n * (n-1);
		return ret;
	}
};


// Catalan
// h(0) = h(1) = 1
// h(n) = h(0)*h(n-1) + h(1)*h(n-2) + ... + h(n-1)h(0) (n>=2)

int h[maxn];

void Catalan(int n) {
	h[0] = h[1] = 1;
	for(int i = 2; i <= n; i++)
		for(int j = 0; j < i; j++)
			h[i] += h[j] * h[i-j];
	// n >= 22, beyond
}


// 斯特灵数

int s1[maxn][maxn];
int s2[maxn][maxn];

// 第一类: n个元素分成k个非空循环排列(环)的方法总数
// s(n, k) = s(n-1, k-1) + (n-1)*s(n-1, k)

// 第二类: n个元素放到k个集合内的方法总数
// s(n, k) = s(n-1, k-1) + k*s(n-1, k)

void Stirling1(int n) {
	s1[1][1] = 1;
	for(int i = 2; i <= n; i++)
		for(int j = 1; j <= i; j++)
			s1[i][j] = s1[i-1][j-1] + (i-1) * s1[i-1][j];
}

void Stirling2(int n) {
	s2[0][0] = 1;
	for(int i = 1; i <= n; i++) {
		s2[i][1] = 1;
		for(int j = 2; j <= i; j++)
			s2[i][j] = s2[i-1][j-1] + j * s2[i-1][j];
	}
}
