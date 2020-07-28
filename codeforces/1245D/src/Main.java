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
        int[] c;
        int[] k;
        int[] x;
        int[] y;

        public void solve(InputReader in,PrintWriter out){
            n = in.nextInt();
            k = new int[n + 1];
            x = new int[n + 1];
            y = new int[n + 1];
            c = new int[n + 1];
            for(int i = 0;i < n;++i){
                x[i] = in.nextInt();
                y[i] = in.nextInt();
            }
            for(int i = 0;i < n;++i){
                c[i] = in.nextInt();
            }
            for(int i = 0;i < n;++i){
                k[i] = in.nextInt();
            }
            ArrayList <Tuples> edges = new ArrayList <Tuples> ();
            for(int i = 0;i < n;++i){
                for(int j = i + 1;j < n;++j){
                    int dist = Math.abs(x[j] - x[i]) + Math.abs(y[j] - y[i]);
                    long cost = (long)(k[i] + k[j]) * (long)dist;
                    edges.add(new Tuples(i,j,cost));
                }
            }
            for(int i = 0;i < n;++i){
                edges.add(new Tuples(n,i,c[i]));
            }
            Collections.sort(edges,new WeightCompare());
            ArrayList <Tuples> mstEdges = new ArrayList<Tuples>();
            Dsu mst = new Dsu(n);
            long ans = 0;
            for(Tuples E : edges){
                if(!mst.join(E.u,E.v)){
                    ans += E.c;
                    mstEdges.add(E);
                }
            }
            out.print(ans + "\n");
            ArrayList <Integer> vertices = new ArrayList<Integer>();
            edges.clear();
            for(Tuples E : mstEdges){
                if(E.u == n){
                    vertices.add(E.v + 1);
                }
                else {
                    edges.add(new Tuples(E.u + 1,E.v + 1,-1));
                }
            }
            out.print(vertices.size() + "\n");
            for(int v : vertices){
                out.print(v + " ");
            }
            out.print("\n");
            out.print(edges.size() + "\n");
            for(Tuples E : edges){
                out.print(E.u + " " + E.v+ "\n");
            }
        }

        private class Tuples {
            int u,v;
            long c;
            Tuples(int u,int v,long c){
                this.u = u;
                this.v = v;
                this.c = c;
            }
        }

        private class WeightCompare implements Comparator <Tuples> {
            public int compare(Tuples x,Tuples y){
                if(x.c < y.c){
                    return  -1;
                } else if(x.c == y.c){
                    return 0;
                } else {
                    return 1;
                }
            }
        }

        private class Dsu {
            int[] par;
            public Dsu(int sz){
                par = new int[sz + 1];
                for(int i = 0;i <= sz;++i){
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
            boolean join(int u,int v){
                u = findp(u);
                v = findp(v);
                if(u == v){
                    return true;
                }
                par[u] = v;
                return false;
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
