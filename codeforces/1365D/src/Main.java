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
        int t = in.nextInt();
        while(t-- > 0) {
            Task solver = new Task();
            solver.solve(in, out);
        }
        out.close();
    }

    static class Task{

        private static final int tx[] = {1,-1,0,0};
        private static final int ty[] = {0,0,1,-1};
        int n,m;
        Character[][] a;

        boolean inBoard(int u,int v){
            return (0 <= u && u < n && 0 <= v && v < m);
        }

        public void solve(InputReader in,PrintWriter out){
            n = in.nextInt();
            m = in.nextInt();
            a = new Character[n][m];
            for(int i = 0;i < n;++i){
                String s = in.nextLine();
                for(int j = 0;j < s.length();++j){
                    a[i][j] = s.charAt(j);
                }
            }
            for(int i = 0;i < n;++i){
                for(int j = 0;j < m;++j){
                    for(int k = 0;k < 4;++k){
                        int u = i + tx[k];
                        int v = j + ty[k];
                        if(inBoard(u,v) && a[i][j] == 'B' && a[u][v] == '.'){
                            a[u][v] = '#';
                        }
                    }
                }
            }
            boolean chk = bfs();
            out.print(chk ? "Yes\n" : "No\n");
        }

        boolean bfs(){
            boolean[][] vis = new boolean[n][m];
            Queue < Pair > que = new LinkedList<>();
            que.offer(new Pair(n - 1,m - 1));
            vis[n - 1][m - 1] = true;
            while(!que.isEmpty()){
                Pair top = que.poll();
                int u = top.u;
                int v = top.v;
                for(int k = 0;k < 4;++k){
                    int nxt_u = u + tx[k];
                    int nxt_v = v + ty[k];
                    if(inBoard(nxt_u,nxt_v)){
                        if(a[nxt_u][nxt_v] != '#' && !vis[nxt_u][nxt_v]){
                            vis[nxt_u][nxt_v] = true;
                            que.offer(new Pair(nxt_u,nxt_v));
                        }
                    }
                }
            }
            int good = 0,bad = 0,cgood = 0;
            for(int i = 0;i < n;++i){
                for(int j = 0;j < m;++j){
                    good += (a[i][j] == 'G' && vis[i][j] ? 1 : 0);
                    cgood += (a[i][j] == 'G' ? 1 : 0);
                    bad += (a[i][j] == 'B' && vis[i][j] ? 1 : 0);
                }
            }
            if(cgood == 0){
                return true;
            }
            return (a[n - 1][m - 1] != '#' && good == cgood && bad == 0);
        }

        private class Pair {
            public int u,v;
            Pair(int u,int v){
                this.u = u;
                this.v = v;
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
