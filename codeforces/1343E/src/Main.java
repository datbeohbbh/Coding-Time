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
        int T = in.nextInt();
        for(int test = 1;test <= T;++test) {
            Task solver = new Task();
            solver.solve(in, out);
        }
        out.close();
    }

    static class Task{

        private static final long inf = (long)1e18;
        int n,m,a,b,c;
        long[] pref;
        int[] dista,distb,distc;
        Vertex[] gr;

        public void solve(InputReader in,PrintWriter out){
            n = in.nextInt();
            m = in.nextInt();
            a = in.nextInt();
            b = in.nextInt();
            c = in.nextInt();
            pref = new long[m + 1];
            for(int i = 1;i <= m;++i){
                pref[i] = in.nextLong();
            }
            Arrays.sort(pref,1,m + 1);
            pref[0] = 0;
            for(int i = 1;i <= m;++i){
                pref[i] += pref[i - 1];
            }
            gr = new Vertex[n + 1];
            for(int u = 1;u <= n;++u){
                gr[u] = new Vertex();
            }
            for(int i = 1;i <= m;++i){
                int u,v;
                u = in.nextInt();
                v = in.nextInt();
                gr[u].adj.add(v);
                gr[v].adj.add(u);
            }
            dista = bfs(a);
            distb = bfs(b);
            distc = bfs(c);
            long ans = inf;
            for(int x = 1;x <= n;++x){
                if(dista[x] + distb[x] + distc[x] <= m){
                    ans = Math.min(ans,pref[distb[x]] + pref[dista[x] + distb[x] + distc[x]]);
                }
            }
            System.out.println(ans);
        }

        int[] bfs(int src){
            Queue <Integer> que = new LinkedList<>();
            que.offer(src);
            int[] d = new int[n + 1];
            Arrays.fill(d,-1);
            d[src] = 0;
            while(que.size() > 0){
                int top = que.poll();
                for(int v : gr[top].adj){
                    if(d[v] == -1){
                        d[v] = d[top] + 1;
                        que.offer(v);
                    }
                }
            }
            return d;
        }

        class Vertex{
            public ArrayList <Integer> adj;
            public Vertex(){
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
