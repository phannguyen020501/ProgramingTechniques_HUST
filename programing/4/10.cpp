#include<bits/stdc++.h> 

using namespace std; 
int N,Q;
//N : so luong van ban
//Q: so dong truy van


vector <vector<string>> searchdoc;
vector<map<string,int>> documemt;
//document la  mang van ban
//seachdoc la mang truy van

// so lan xuat hien cua t trong van ban d
int f(string t, int d) {
    int size= documemt[d].size();
    map<string,int>::iterator test=documemt[d].find(t);
    if(test==documemt[d].end()) return 0;
    else return (int)test->second;
}
//la gia tri lon nhat cua f(t,d) voi moi t
int max_f(int d){
    int size= documemt[d].size();
    priority_queue<int> Max;
    for (map<string,int>::iterator it=documemt[d].begin(); it!=documemt[d].end(); ++it){
        Max.push(it->second);
    }
    return Max.top();
}
//so van ban chua tu t
int df(string t){
    int count=0;
    for(int d=0;d<N;++d){
        if(f(t,d)>0) count++;
    }
    return count;
}
double TF(string t,int d){
    return (double)0.5+0.5*((f(t,d)*1.0)/max_f(d));
}
double IDF(string t){
    return (double)log2f((N*1.0)/df(t));
}
//diem so cua tu t xuat hien trong van ban d
double score(string t, int d){
    if(f(t,d)!=0) return TF(t,d)*IDF(t);
    else return 0;
}
//diem so cua van ban d doi voi truy van gom cac tu (co the trung nhau) t1,t2,.....,tq
double finalScore(vector<string> doc1,int d){
     int size=doc1.size();
     double result=0;
     for(int j=0;j<size;j++){
         result+=score(doc1[j],d); 
     }
     return result;
}
//chuyen chuoi dc nhap thanh vector
vector<string> getDoc(string str){
    vector<string>doc1(0);
    int size=str.length();
    for(int i=0;i<size;i++){
        string t="";
        while(str[i]!=','&&(i)<size){
        t+=str[i];
        i++;
    }
    if(t!="") doc1.push_back(t);
    }
    return doc1;
}
//chuyen vector thanh map
map<string,int> getMap(vector<string>doc1){
    map<string,int> map;
   int size=doc1.size();
   for(int i=0;i<size;++i){
   	
       map[doc1[i]]++;
   }
   return map;
}

int main(){
	cout << "Phan Ngoc Nguyen - 201941314" << endl;
    vector<int> result;// mang ket qua
      cin>>N;
    //nhap van ban
    for(int i=0;i<N;++i){
        string str;
        cin>>str;
        vector<string> doc1=getDoc(str);
        map<string,int>map=getMap(doc1);
         documemt.push_back(map); 
    }
    //nhap truy van
    cin>>Q;
    for(int i=0;i<Q;++i){
        //queue laf luu diem cua cua dong truy van doi voi van ban j
        
        priority_queue<pair<double,int>> que;
        string str;
        cin>>str;
        vector<string> doc2=getDoc(str);
       for(int j=0;j<N;++j){
           double finalcso=finalScore(doc2,j);
          que.push({finalcso,-j});
       }
       result.push_back((-que.top().second)+1);
    } 
    for(int i=0;i<Q;i++){
        cout<<result[i]<<endl;
    }
}
