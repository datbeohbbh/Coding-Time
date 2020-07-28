import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args){
        InputStream  inputstream;
        OutputStream outputstream;
        inputstream = System.in;
        outputstream = System.out;
        InputReader in = new InputReader(inputstream);
        PrintWriter out = new PrintWriter(outputstream);
        Task solver = new Task();
        solver.solve(in,out);
        out.close();
    }

    static class Task{

        int n,m;
        int index_comp = -1;
        ArrayList <Vertices> gr = new ArrayList <Vertices>();
        ArrayList <Vertices> comp = new ArrayList <Vertices>();
        TreeSet <Integer> ts = new TreeSet<Integer>();
        boolean[] vis;
        int[] comp_idx;
        Dsu dsu;

        public void solve(InputReader in,PrintWriter out){
            n = in.nextInt();
            m = in.nextInt();
            for(int i = 0;i < n;++i){
                gr.add(new Vertices());
                comp.add(new Vertices());
                ts.add(i);
            }
            for(int i = 0;i < m;++i){
                int u,v;
                u = in.nextInt() - 1;
                v = in.nextInt() - 1;
                gr.get(u).adj.add(v);
                gr.get(v).adj.add(u);
            }
            vis = new boolean[n];
            comp_idx = new int[n];
            Arrays.fill(vis,false);
            for(int i = 0;i < n;++i){
                if(!vis[i]){
                    ++index_comp;
                    dfs(i);
                }
            }
            for(int i = 0;i <= index_comp;++i){
                Collections.sort(comp.get(i).adj);
            }
            dsu = new Dsu(index_comp);
            for(int i = 0;i <= index_comp;++i){
                ArrayList <Integer> ve = new ArrayList <Integer>(comp.get(i).adj);
                for(int j = 1;j < ve.size();++j){
                    int l = ve.get(j - 1);
                    int r = ve.get(j);
                    if(l + 1 < r){
                        if(chk(l) || chk(r)) {
                            connectVertices(l, r);
                        }
                    }
                }
            }
            long ans = 0;
            for(int i = 0;i <= index_comp;++i){
                if(dsu.findp(i) == i){
                    ans += (long)(dsu.child[i] - 1);
                }
            }
            out.print(ans);
        }

        boolean chk(int u){
            if(ts.ceiling(u) != null && ts.ceiling(u) == u){
                return true;
            }
            return false;
        }

        public void connectVertices(int l,int r){
            int f = l;
            while(!ts.isEmpty() && ts.ceiling(f) != null){
                f = ts.ceiling(f);
                if(f > r)return;
                dsu.join(comp_idx[l],comp_idx[f]);
                ts.remove(f);
                ++f;
            }
        }

        public void dfs(int u){
            vis[u] = true;
            comp.get(index_comp).adj.add(u);
            comp_idx[u] = index_comp;
            for(int v : gr.get(u).adj){
                if(!vis[v]){
                    dfs(v);
                }
            }
        }

        public class Dsu{
            int[] par;
            int[] child;
            public Dsu(int __size){
                par = new int[__size + 1];
                child = new int[__size + 1];
                for(int i = 0;i <= __size;++i){
                    par[i] = i;
                    child[i] = 1;
                }
            }

            int findp(int u){
                if(u == par[u]){
                    return u;
                } else {
                    return par[u] = findp(par[u]);
                }
            }

            boolean join(int u,int v){
                u = findp(u);
                v = findp(v);
                if(u == v){
                    return true;
                }
                par[u] = v;
                child[v] += child[u];
                return false;
            }
        }

        public class Vertices{
            ArrayList <Integer> adj;
            public Vertices(){
                adj = new ArrayList<Integer>();
            }
        }
    }

    static class InputReader{
        public BufferedReader reader;
        public StringTokenizer tokenizer;

        public InputReader(InputStream stream){
            reader = new BufferedReader(new InputStreamReader(stream));
            tokenizer = null;
        }

        public String next(){
            while(tokenizer == null || !tokenizer.hasMoreTokens()){
                try{
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e){
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        public int nextInt(){
            return Integer.parseInt(next());
        }

        public long nextLong(){
            return Long.parseLong(next());
        }

        public  double nextDouble(){
            return Double.parseDouble(next());
        }

        public String nextLine(){
            String ret_str = "";
            try {
                ret_str = reader.readLine();
            } catch (IOException e){
                e.printStackTrace();
            }
            return ret_str;
        }
    }
}
