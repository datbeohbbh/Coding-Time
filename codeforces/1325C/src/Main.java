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

        int n;

        public void solve(InputReader in,PrintWriter out){
            n = in.nextInt();
            int[] ans = new int[n + 2];
            Arrays.fill(ans,-1);
            Graph[] adj = new Graph[n + 2];
            for(int i = 1;i <= n;++i){
                adj[i] = new Graph();
            }
            for(int i = 1;i < n;++i){
                int u,v;
                u = in.nextInt();
                v = in.nextInt();
                adj[u].edges.add(new Pairs(v,i));
                adj[v].edges.add(new Pairs(u,i));
            }
            int flag = -1;
            for(int i = 1;i <= n;++i){
                if(adj[i].edges.size() >= 3){
                    flag = i;
                }
            }
            if(flag == -1){
                for(int i = 1;i < n;++i){
                    out.println(i - 1);
                }
            } else {
                int cur = -1;
                for(int i = 0;i < adj[flag].edges.size();++i){
                    Pairs <Integer> p = adj[flag].edges.get(i);
                    ans[p.idx] = ++cur;
                }
                for(int i = 1;i < n;++i){
                    if(ans[i] == -1){
                        ans[i] = ++cur;
                    }
                }
                for(int i = 1;i < n;++i){
                    out.println(ans[i]);
                }
            }
        }

        public class Graph{
            ArrayList <Pairs> edges;
            Graph(){
                edges = new ArrayList<Pairs>();
            }
        }

        public class Pairs <T> {
            public T u,idx;
            public Pairs(T u,T idx){
                this.u = u;
                this.idx = idx;
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
