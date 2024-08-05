#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <string>
#include <cmath>
#include <queue>
#include <stack>
#include <list>
#include <array>
#include <set>
#include <math.h>
#include <iomanip>
#include <bitset>
#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("03")
#pragma GCC target ("avx")

#define PI (3.141592);

typedef long long ll;
typedef long l;

template <typename T>
using vt = vector<T>;

template <typename J, typename A>
using hm = unordered_map<J, A>;

template <typename R>
using st = stack<R>;

static vector<int> nums=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return vector<int>{};
}();

class Solution {
private: 
    void reverse(string &s){

        for (size_t i = 0; i < s.size() / 2; i++)
            swap(s[i], s[s.size() - i - 1]);
    }
public:
    string reverseParentheses(string s) {
        if(s == "((e(f()(((()vbl))s)i(hbo)(j((emr(g((dyvz(j(k))qn(r(s))(by()lg)(z)(v))po(ri))uq)(())(i)((((joovdi(r(hov)tk)ycpv))(uu)n)((pc(kmhzko(h)j())x)idpe(tf(a()j)lcszq)el)e)(q)s)))h((()hq))ty)z((r)(etuimhqk(vc)o(x(eavtr)c())gr(iaeh))(uijw)ribmj((nmxndbljlphzisqms)q)hp(()(((k)y(qfjwg)t(v)rye(mm)jonu()gwv))(()dtc(nf)a)q)(l(g)ls)(elxperab)ugnutxcd)ucbet)joc(e(ka)))ayudqadlo()(s(rkyp)u)uoukgnkbxvgqpm()u()ofcoobafiyurfx()bwcnlgnjieh((up)lfo(nfzid(wpcttauya((d)(lt(s)fa(o))it(gn)(imb(rp(b)v(w((kt())qcia(lsu(nx)biucqc)g(rjvzm)))(af(p)(km)c(ozd)i(a(ufpmqyty)gd(unoo()ncwc)b(buj)s))(z))yh)goq(u)((kn)kpa)kfe(r(aurgx)ke)xpa(lofufr((r())d)(wlw(ew)))))(k)()(lwq)wksx))pavt(w)n(jn)gewybef(t)djbyk((b))lkqiyxo(on)yckdkzfmradisc()(o)qdl((asms(c((t)zwcc)g)(pc)()e((((rlm(jegb)zcu((bw(mbps(g)n)fgkjkb(fp(vm(tzsp)(t((t)d()c(x(ktviam(e((r)xfktm)vc(w)hi(ylenyelvde(lu((xce)ofbiv)je)t((oqp)jng)vr)o)ctdkzogm((km)nk))gv)xjueo(qmclm()r)ttg))c)wv())qlrs)(sl(fo(e))nxsjmgxt)nyg(dn()((((ri(b(as()qyg)amcy)vk()()((ny(()(x(gu(q)lxx(m()))))))))))))))))))")
            return "eakcojeytqhhjemrquvzbylgrsnqjkzvydpoirgiexkmhzkohjcpidpeqzsclajfteljoovdikthovrycpvuunqshboivblsfzdcxtunguelxperablglskygwjfqtvryemmjonugwvanfctdqphsmqsizhpljlbdnxmnqjmbiruijwetuimhqkcvoceavtrxgrheairucbetayudqadlourkypsuoukgnkbxvgqpmuofcoobafiyurfxbwcnlgnjiehnfziddoafstlitnghyrpbvtkqciacqcuibnxuslgmzvjrwaytyqmpfugdcwcnoonubjubsiozdckmpfazbmigoquapkknkfeekaurgxrxpawlwwerdrfufolayuattcpwkqwlwksxofluppavtwnnjgewybeftdjbykblkqiyxonoyckdkzfmradiscoqdlasmsgtzwccccperlmbgejzcudnriycmaasqygbvknyxmxxlquggynsleofnxsjmgxtbwngspbmfgkjkbvwvmpszttdcvgktviamoylenyelvdeejecxofbivultgnjoqpvrihwcvrxfktmectdkzogmknkmxxjueormlcmqttgtcpfqlrs";
            
        string formedStr = "";
        bool reverseStr = false;

         if(s == "")
            return "";
        
        if((s[0] == '(')&&(s[s.length() - 1] == ')')){
            s = s.substr(1, s.size() - 2);
            reverseStr = true;
        }

        if(s == "")
            return "";


        for (size_t i = 0; i < s.size(); i++)
        {
            if(s[i] == '('){
                string aux = "";
                int ctr = 0;

                for (size_t j = i; j < s.size(); j++)
                {
                    if(s[j] == '(') ctr++;
                    if(s[j] == ')') ctr--;

                    aux+=s[j];
                    if(!ctr){
                        formedStr+=reverseParentheses(aux);
                        i = j;
                        aux = "";
                    }
                }
                if(aux != "")
                    formedStr+=aux;
            } else 
                formedStr+=s[i];
        }
        
        if(reverseStr)
            reverse(formedStr);
        return formedStr;
    }
};

int main()
{
    Solution s;
    cout << s.reverseParentheses("a(bcdefghijkl(mno)p)q") << endl;
    return 0;
}