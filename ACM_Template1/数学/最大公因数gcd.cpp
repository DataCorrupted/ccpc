
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;

const int maxn=300+10;
int f[maxn];

//简明版

//递归
 
int Gcd(int a, int b)
{
    if(b == 0)
        return a;
    return Gcd(b, a % b);
} 


//非递归 

int Gcd(int a, int b)
{
    while(b != 0)
    {
        int r = b;
        b = a % b;
        a = r;
    }
    return a;
}

//二元一次方程一组解 

int exGcd(int a, int b, int &x, int &y)
{
    if(b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    int r = exGcd(b, a % b, x, y);
    int t = x;
    x = y;
    y = t - a / b * y;

    return r;
}

//石头算法

int Gcd(int a, int b)
{
    if(a == 0) return b;
    if(b == 0) return a;
    if(a % 2 == 0 && b % 2 == 0) return 2 * gcd(a >> 1, b >> 1);
    else if(a % 2 == 0)  return gcd(a >> 1, b);
    else if(b % 2 == 0) return gcd(a, b >> 1);
    else return gcd(abs(a - b), Min(a, b));
} 



/*
1. 欧几里德算法和扩展欧几里德算法
欧几里德算法 
欧几里德算法又称辗转相除法，用于计算两个整数a,b的最大公约数。其计算原理依赖于下面的定理：

定理：gcd(a,b) = gcd(b,a mod b)

证明：a可以表示成a = kb + r，则r = a mod b 
假设d是a,b的一个公约数，则有 
d|a, d|b，而r = a - kb，因此d|r 
因此d是(b,a mod b)的公约数

假设d 是(b,a mod b)的公约数，则 
d | b , d |r ，但是a = kb +r 
因此d也是(a,b)的公约数

因此(a,b)和(b,a mod b)的公约数是一样的，其最大公约数也必然相等，得证

欧几里德算法就是根据这个原理来做的，其算法用C++语言描述为：

*/

int Gcd(int a, int b)
{
    if(b == 0)
        return a;
    return Gcd(b, a % b);
}

//当然你也可以写成迭代形式：

int Gcd(int a, int b)
{
    while(b != 0)
    {
        int r = b;
        b = a % b;
        a = r;
    }
    return a;
}

/*
本质上都是用的上面那个原理。

补充: 扩展欧几里德算法是用来在已知a, b求解一组p，q使得p * a+q  * b = Gcd(a, b)  (解一定存在，根据数论中的相关定理)。扩展欧几里德常用在求解模线性方程及方程组中。下面是一个使用C++的实现：

*/

int exGcd(int a, int b, int &x, int &y)
{
    if(b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    int r = exGcd(b, a % b, x, y);
    int t = x;
    x = y;
    y = t - a / b * y;

    return r;
}

/*
把这个实现和Gcd的递归实现相比，发现多了下面的x,y赋值过程，这就是扩展欧几里德算法的精髓。
可以这样思考:
对于a' = b, b' = a % b 而言，我们求得 x, y使得 a'x + b'y = Gcd(a', b')
由于b' = a % b = a - a / b * b (注：这里的/是程序设计语言中的除法)
那么可以得到:
a'x + b'y = Gcd(a', b')  ===>
bx + (a - a / b * b)y = Gcd(a', b') = Gcd(a, b)  ===>
ay +b(x - a / b*y) = Gcd(a, b)
因此对于a和b而言，他们的相对应的p，q分别是 y和(x-a/b*y)

*/

/*

2. Stein算法 
欧几里德算法是计算两个数最大公约数的传统算法，他无论从理论还是从效率上都是很好的。但是他有一个致命的缺陷，这个缺陷只有在大素数时才会显现出来。 

考虑现在的硬件平台，一般整数最多也就是64位，对于这样的整数，计算两个数之间的模是很简单的。对于字长为32位的平台，计算两个不超过32位的整数的模，只需要一个指令周期，而计算64位以下的整数模，也不过几个周期而已。但是对于更大的素数，这样的计算过程就不得不由用户来设计，为了计算两个超过 64位的整数的模，用户也许不得不采用类似于多位数除法手算过程中的试商法，这个过程不但复杂，而且消耗了很多CPU时间。对于现代密码算法，要求计算 128位以上的素数的情况比比皆是，设计这样的程序迫切希望能够抛弃除法和取模。 （注：说到抛弃除法和取模，其实辗转相除法可以写成减法的形式)

Stein算法由J. Stein 1961年提出，这个方法也是计算两个数的最大公约数。和欧几里德算法 算法不同的是，Stein算法只有整数的移位和加减法，这对于程序设计者是一个福音。 

为了说明Stein算法的正确性，首先必须注意到以下结论： 

gcd(a,a) = a，也就是一个数和他自身的公约数是其自身 
gcd(ka,kb) = k gcd(a,b)，也就是最大公约数运算和倍乘运算可以交换，特殊的，当k=2时，说明两个偶数的最大公约数必然能被2整除。

有了上述规律就可以给出Stein算法如下：

如果A=0，B是最大公约数，算法结束 
如果B=0，A是最大公约数，算法结束 
设置A1 = A、B1=B和C1 = 1 
如果An和Bn都是偶数，则An+1 =An /2，Bn+1 =Bn /2，Cn+1 =Cn *2(注意，乘2只要把整数左移一位即可，除2只要把整数右移一位即可) 
如果An是偶数，Bn不是偶数，则An+1 =An /2，Bn+1 =Bn ，Cn+1 =Cn (很显然啦，2不是奇数的约数)
如果Bn是偶数，An不是偶数，则Bn+1 =Bn /2，An+1 =An ，Cn+1 =Cn (很显然啦，2不是奇数的约数)
如果An和Bn都不是偶数，则An+1 =|An -Bn|，Bn+1 =min(An,Bn)，Cn+1 =Cn 
n++，转4 
这个算法的原理很显然，所以就不再证明了。现在考察一下该算法和欧几里德方法效率上的差别。 

给出一个C++的实现:

*/

int Gcd(int a, int b)
{
    if(a == 0) return b;
    if(b == 0) return a;
    if(a % 2 == 0 && b % 2 == 0) return 2 * gcd(a >> 1, b >> 1);
    else if(a % 2 == 0)  return gcd(a >> 1, b);
    else if(b % 2 == 0) return gcd(a, b >> 1);
    else return gcd(abs(a - b), Min(a, b));
}

/*

考虑欧几里德算法，最恶劣的情况是，每次迭代a = 2b -1,这样，迭代后，r= b-1。如果a小于2N，这样大约需要 4N次迭代。而考虑Stein算法，每次迭代后，显然AN+1BN+1≤ ANBN/2，最大迭代次数也不超过4N次。也就是说，迭代次数几乎是相等的。但是，需要注意的是，对于大素数，试商法将使每次迭代都更复杂，因此对于大素数Stein将更有优势

*/
