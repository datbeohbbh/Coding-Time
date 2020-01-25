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

        private int n,m;
        private boolean haveCycle = false;
        private ArrayList <Vertices> direct;
        private ArrayList <Vertices> gr;
        private ArrayList <Integer> topo;
        private Dsu dsu;
        private boolean[][] canReach;
        private int[] vis;
        private int[] deg;
        private int[] col;

        public void solve(InputReader in,PrintWriter out){
            n = in.nextInt();
            m = in.nextInt();

            canReach = new boolean[n + m][n + m];
            vis = new int[n + m];
            deg = new int[n + m];
            col = new int[n + m];
            dsu = new Dsu(n + m);
            direct = new ArrayList<Vertices>();
            gr = new ArrayList<Vertices>();
            topo = new ArrayList <Integer>();

            for(int i = 0;i < n + m;++i){
                direct.add(new Vertices());
                gr.add(new Vertices());
            }
            for(int i = 0;i < n;++i){
                String s = in.nextLine();
                for(int j = 0;j < m;++j){
                    if(s.charAt(j) == '>'){
                        gr.get(n + j).adj.add(i);
                        direct.get(n + j).adj.add(i);
                        ++deg[i];
                    } else if(s.charAt(j) == '<'){
                        direct.get(i).adj.add(n + j);
                        gr.get(i).adj.add(n + j);
                        ++deg[n + j];
                    } else {
                        dsu.join(i,n + j);
                        gr.get(i).adj.add(n + j);
                        gr.get(n + j).adj.add(i);
                        ++deg[i];
                        ++deg[n + j];
                    }
                }
            }
            for(int i = 0;i < n + m;++i){
                for(int j = 0;j < n + m;++j){
                    canReach[i][j] = false;
                }
            }
            Arrays.fill(vis,0);
            for(int i = 0;i < n + m;++i){
                if(deg[i] == 0) {
                    Arrays.fill(vis, 0);
                    dfs(i);
                }
            }
            for(int i = 0;i < n + m;++i){
                if(vis[i] == 0){
                    dfs(i);
                }
            }
            if(haveCycle){
                out.print("No");
                return;
            }
            for(int i = 0;i < n + m;++i){
                for(int j = 0;j < n + m;++j){
                    if(i == j)continue;
                    if(dsu.findp(i) == dsu.findp(j)){
                        if(canReach[i][j]){
                            out.print("No");
                            return;
                        }
                    }
                }
            }
            Arrays.fill(vis,0);
            for(int i = 0;i < n + m;++i){
                if(deg[i] == 0){
                    getTopoOrder(i);
                }
            }
            for(int i = 0;i < n + m;++i){
                if(vis[i] == 0){
                    getTopoOrder(i);
                }
            }
            dp();
            out.println("Yes");
            for(int i = 0;i < n;++i){
                out.print(col[dsu.findp(i)] + " ");
            }
            out.println();
            for(int i = 0;i < m;++i){
                out.print(col[dsu.findp(i + n)] + " ");
            }
        }

        private void dp(){
            Arrays.fill(col,1);
            for(int i = topo.size() - 1;i >= 0;--i){
                int u = topo.get(i);
                for(int v : direct.get(u).adj){
                    int w = (dsu.findp(v) == dsu.findp(u) ? 0 : 1);
                    col[v] = Math.max(col[v],col[u] + w);
                }
            }
        }

        private void getTopoOrder(int u){
            vis[u] = 1;
            for(int v : direct.get(u).adj){
                if(vis[v] == 0){
                    getTopoOrder(v);
                }
            }
            topo.add(u);
        }

        private void dfs(int u){
            vis[u] = 1;
            for(int v : direct.get(u).adj){
                if(haveCycle){
                    return;
                }
                if(vis[v] == 0){
                    canReach[u][v] = true;
                    dfs(v);
                } else if(vis[v] == 1){
                    haveCycle = true;
                    return;
                }
            }
            vis[u] = 2;
        }

        private class Dsu{
            private int[] par;
            public Dsu(int size_of_array){
                par = new int[size_of_array];
                for(int i = 0;i < size_of_array;++i){
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

        private class Vertices{
            private ArrayList <Integer> adj;
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