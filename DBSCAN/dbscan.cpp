#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mod 1000000007
#define lol 1000000000005
#define ffor(i,a,b) for(int i=a;i<b;i++)
#define bfor(i,a,b) for(int i=b;i>=a;i--)
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define vp vector<pair<double,double>>
#define vpp vector<pair<int, pair<int,int>>>
#define pp pair<double,double>
#define n 2000
#define minp 5
#define eps 2.2

vector<pair<double,double>> v(n+1);
map< pp, int> visited;
map<int, vector<pp>> lis;  //Stores cluster nodes
map<pp, int> par; //Contains parent

double dist(pp a, pp b)
{
  double x1,x2,y1,y2;
  x1=a.ff;
  x2=b.ff;
  y1=a.ss;
  y2=b.ss;
  return sqrt(((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2)));  
}

bool core_point(pp x)
{
  int count=0;
  ffor(i,0,n)
  {
     if(dist(x,v[i])<=eps) count++;
  }
  if(count>=minp) return true;
  return false;
}

int main()
{
   int index;
   cout<<"Enter input number";
   cin>>index;
   ifstream input;
   string file = "input/input_" + to_string(index) + ".txt";
   input.open(file.c_str());
   ffor(i,0,n)
   { 
      input>>v[i].ff;
      input>>v[i].ss;
   }
   ffor(i,0,n) visited[v[i]]=0;
   int cluster=0;
   clock_t tim;
   tim = clock();
   ffor(i,0,n)
   {
      if(!visited[v[i]]) //Unvisited Node
      {
         visited[v[i]]=1; //Mark it visited
         if(core_point(v[i]))
         {
             cluster++;
             par[v[i]]=cluster;
             lis[cluster].pb(v[i]);  //Add in list of cluster
             
             //Adding unvisited neighbours
             vector<pair<double,double>> temp;
             ffor(j,0,n)
             { 
               if(dist(v[i],v[j]) <= eps && !visited[v[j]])
                  temp.pb(v[j]);
             }
            
             //Traversing neighbours 
             ffor(j,0,temp.size())
             {
                par[temp[j]]=cluster;
                lis[cluster].pb(temp[j]);
                
                if(!visited[temp[j]])
                {   
                  visited[temp[j]]=1;
                  //Now pushing its neighbours
                  if(core_point(temp[j]))
                  {
                     vp ptr;
                     ffor(k,0,n)
                     {
                       if(dist(temp[j],v[k]) <= eps && !visited[v[k]])
                          temp.pb(v[k]);
                     }
                  }
                }
                if(par.find(temp[j])== par.end())
                   par[temp[j]]=cluster;

             }
             ofstream output;
             string ptr = "output/ans" + to_string(index) + "_" + to_string(cluster) + ".txt"; 
             output.open(ptr.c_str());
             ffor(j,0,lis[cluster].size())
             {
                output<<lis[cluster][j].ff<<" "<<lis[cluster][j].ss<<endl;
             }
             output.close();
         }
         else 
           visited[v[i]]=2;
      }
  }
  tim = clock() - tim;
  double tt = ((double)tim)/CLOCKS_PER_SEC;
  ofstream output;
  output.open("output.txt",std::ios_base::app);
  output<<n<<" "<<tt<<endl; 
  cout<<"Total cluster "<<cluster<<endl;
  input.close();
}

