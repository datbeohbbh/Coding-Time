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
        ArrayList <Edges> adj;
        Dsu dsu;
        TreeSet <Integer> segment = new TreeSet <Integer> ();

        public void solve(InputReader in,PrintWriter out){
            n = in.nextInt();
            m = in.nextInt();
            adj = new ArrayList <Edges> ();
            adj.add(new Edges());
            for(int i = 1;i <= n;++i){
                adj.add(new Edges());
            }
            for(int i = 1;i <= m;++i){
                int u,v;
                u = in.nextInt();
                v = in.nextInt();
                adj.get(u).link.add(v);
                adj.get(v).link.add(u);
            }
            for(int u = 1;u <= n;++u){
                segment.add(u);
            }
            dsu = new Dsu(n + 1);
            for(int i = 1;i <= n;++i){
                Collections.sort(adj.get(i).link);
                ArrayList <Integer> vertices = new ArrayList <Integer>( adj.get(i).link);
                if(!vertices.isEmpty()){
                    if(1 < vertices.get(0)){
                        joinSegment(1,vertices.get(0) - 1);
                        dsu.join(1,i);
                    }
                    if(vertices.get(vertices.size() - 1) < n){
                        joinSegment(vertices.get(vertices.size() - 1) + 1,n);
                        dsu.join(i,n);
                    }
                    for(int j = 1;j < vertices.size();++j){
                        if(vertices.get(j - 1) + 2 <= vertices.get(j)){
                            joinSegment(vertices.get(j - 1) + 1,vertices.get(j) - 1);
                            dsu.join(i,vertices.get(j - 1) + 1);
                        }
                    }
                } else {
                    out.print(0);
                    return;
                }
            }
            int ans = 0;
            for(int u = 1;u <= n;++u){
                if(dsu.findp(u) == u){
                    ++ans;
                }
            }
            out.print(ans - 1);
        }

        void joinSegment(int l,int r){
            int prev = l;
            ArrayList <Integer> cur = new ArrayList <Integer> ();
            cur.add(prev);
            while(!segment.isEmpty() && segment.ceiling(l) != null){
                int f = segment.ceiling(l);
                if(f > r)break;
                cur.add(f);
                prev = f;
                segment.remove(f);
            }
            for(int i = 0;i < cur.size();++i){
                if(cur.get(i) + 1 <= r){
                    dsu.join(cur.get(i),cur.get(i) + 1);
                    if(segment.contains(cur.get(i) + 1)){
                        segment.remove(cur.get(i) + 1);
                    }
                }
            }
        }

        private class Edges{
            ArrayList <Integer> link;
            public Edges(){
                link = new ArrayList <Integer> ();
            }
        }

        private class Dsu{
            int par[];
            public Dsu(int sz){
                par = new int[sz + 1];
                for(int i = 1;i <= sz;++i){
                    par[i] = i;
                }
            }
            int findp(int u){
                if(u == par[u]){
                    return u;
                } else {
                    return par[u] = findp(par[u]);
                }
            }
            void join(int u,int v){
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
