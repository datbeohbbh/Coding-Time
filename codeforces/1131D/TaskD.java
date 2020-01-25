import java.io.*;
import java.util.*;

public class TaskD {
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

        private ArrayList <Vertices> gr = new ArrayList <Vertices> ();
        private ArrayList <Integer> topo = new ArrayList <Integer> ();
        private ArrayList <Integer> p = new ArrayList<Integer>();
        private String[] s;
        private int[] ord;
        private int[] h;
        private int[] col;
        private boolean[] vis;
        private int n,m;

        public void solve(InputReader in,PrintWriter out){
            n = in.nextInt();
            m = in.nextInt();
            ord = new int[n + m];
            h = new int[n + m];
            vis = new boolean[n + m];
            col = new int[n + m];
            s = new String[n];
            Arrays.fill(col,1);
            Arrays.fill(h,0);
            Arrays.fill(vis,false);
            Dsu dsu = new Dsu(n + m);
            for(int i = 0;i < n;++i){
                s[i] = in.nextLine();
                for(int j = 0;j < m;++j){
                    if(s[i].charAt(j) == '='){
                        dsu.join(i,n + j);
                    }
                }
            }
            for(int i = 0;i < n + m;++i){
                gr.add(new Vertices());
            }
            for(int i = 0;i < n + m;++i){
                if(i == dsu.findp(i)){
                    ord[i] = p.size();
                    p.add(i);
                }
            }
            for(int i = 0;i < n;++i){
                for(int j = 0;j < m;++j){
                    int u = ord[dsu.findp(i)];
                    int v = ord[dsu.findp(n + j)];
                    if(u == v && s[i].charAt(j) != '='){
                        out.print("No");//contradict
                        return;
                    }
                    if(s[i].charAt(j) == '>'){
                        gr.get(u).adj.add(v);
                    } else if(s[i].charAt(j) == '<'){
                        gr.get(v).adj.add(u);
                    }
                }
            }
            for(int u : p){
                if(!vis[ord[u]]){
                    dfs(ord[u]);
                }
            }
            for(int u : p){
                for(int v : gr.get(ord[u]).adj){
                    if(h[ord[u]] < h[v]){ //cycle
                        out.print("No");
                        return;
                    }
                }
            }
            for(int u : topo){
                for(int v : gr.get(u).adj){
                    col[u] = Math.max(col[u],col[v] + 1);
                }
            }
            out.println("Yes");
            for(int i = 0;i < n;++i){
                out.print(col[ord[dsu.findp(i)]] + " ");
            }
            out.println();
            for(int i = 0;i < m;++i){
                out.print(col[ord[dsu.findp(i + n)]] + " ");
            }
        }

        private void dfs(int u){
            vis[u] = true;
            for(int v : gr.get(u).adj){
                if(!vis[v]){
                    dfs(v);
                }
            }
            h[u] = topo.size();
            topo.add(u);
        }

        private class Vertices{
            private ArrayList <Integer> adj;
            public Vertices(){
                adj = new ArrayList <Integer>();
            }
        }

        private class Dsu{
            private int[] par;
            public Dsu(int sizeArray){
                par = new int[sizeArray];
                for(int i = 0;i < sizeArray;++i){
                    par[i] = i;
                }
            }

            public int findp(int u){
                if(u == par[u]){
                    return u;
                } else {
                    return par[u] = findp(par[u]);
                }
            }

            public void join(int u,int v){
                par[findp(u)] = findp(v);
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
