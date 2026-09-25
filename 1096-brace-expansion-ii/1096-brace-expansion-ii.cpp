class Solution {
public:
    set<string> unite(set<string> a,set<string> b){
        a.insert(b.begin(),b.end());
        return a;
    }

    set<string> product(set<string> a,set<string> b){
        set<string> res;
        for(auto &x:a)
            for(auto &y:b)
                res.insert(x+y);
        return res;
    }

    set<string> parseExpr(string &s,int &i){
        set<string> res=parseTerm(s,i);

        while(i<s.size() && s[i]==','){
            i++;
            res=unite(res,parseTerm(s,i));
        }

        return res;
    }

    set<string> parseTerm(string &s,int &i){
        set<string> res={""};

        while(i<s.size() && s[i]!=',' && s[i]!='}'){
            set<string> cur;

            if(s[i]=='{'){
                i++;
                cur=parseExpr(s,i);
                i++;
            }else{
                cur.insert(string(1,s[i]));
                i++;
            }

            res=product(res,cur);
        }

        return res;
    }

    vector<string> braceExpansionII(string expression){
        int i=0;
        set<string> ans=parseExpr(expression,i);
        return vector<string>(ans.begin(),ans.end());
    }
};