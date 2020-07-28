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

        private static final int lg = 18;
        int n,m;
        Vertex[] tree;
        int[][] dp;
        int[] h;

        public void solve(InputReader in,PrintWriter out){
            n = in.nextInt();
            tree = new Vertex[n];
            h = new int[n];
            dp = new int[lg + 2][n];
            Arrays.fill(h,0);
            for(int i = 0;i < n;++i){
                tree[i] = new Vertex();
            }
            for(int i = 0;i < n - 1;++i){
                int u,v;
                u = in.nextInt() - 1;
                v = in.nextInt() - 1;
                tree[u].adj.add(v);
                tree[v].adj.add(u);
            }
            dfs(0,0);
            for(int j = 1;j <= lg;++j){
                for(int i = 0;i < n;++i){
                    dp[j][i] = dp[j - 1][dp[j - 1][i]];
                }
            }
            m = in.nextInt();
            while(m-- > 0){
                int x,y,a,b,k;
                x = in.nextInt() - 1;
                y = in.nextInt() - 1;
                a = in.nextInt() - 1;
                b = in.nextInt() - 1;
                k = in.nextInt();
                boolean ok = false;
                int dist_0 = dist(a,b);
                int dist_1 = dist(a,x) + 1 + dist(y,b);
                int dist_2 = dist(a,y) + 1 + dist(x,b);
                if(((dist_0 & 1) ^ (k & 1)) == 0){
                    ok |= (dist_0 <= k);
                }
                if(((dist_1 & 1) ^ (k & 1)) == 0){
                    ok |= (dist_1 <= k);
                }
                if(((dist_2 & 1) ^ (k & 1)) == 0){
                    ok |= (dist_2 <= k);
                }
                out.print(ok ? "YES\n" : "NO\n");
            }
        }

        void dfs(int u,int par){
            dp[0][u] = par;
            for(int v : tree[u].adj){
                if(v == par){
                    continue;
                }
                h[v] = h[u] + 1;
                dfs(v,u);
            }
        }

        int lca(int u,int v){
            if(h[u] < h[v]){
                int tmp = u;
                u = v;
                v = tmp;
            }
            for(int j = lg;j >= 0;--j){
                if(h[dp[j][u]] >= h[v]){
                    u = dp[j][u];
                }
            }
            if(u == v){
                return u;
            }
            for(int j = lg;j >= 0;--j){
                if(dp[j][u] != dp[j][v]){
                    u = dp[j][u];
                    v = dp[j][v];
                }
            }
            return dp[0][u];
        }

        int dist(int u,int v){
            return h[u] + h[v] - (h[lca(u,v)] << 1);
        }

        public class Vertex{
            ArrayList < Integer > adj;
            Vertex(){
                adj = new ArrayList<>();
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
