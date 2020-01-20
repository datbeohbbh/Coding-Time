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
        int numTests = in.nextInt();
        for(int i = 1;i <= numTests;++i) {
            solver.solve(in, out);
        }
        out.close();
    }

    static class Task{
        public void solve(InputReader in,PrintWriter out){
            int n;
            n = in.nextInt();
            int d[] = new int[n + 1];
            ArrayList <Tuples> p = new ArrayList <Tuples> ();
            for(int i = 0;i < n;++i){
                d[i] = in.nextInt();
                int val = d[i];
                for(int j = 2;j * j <= val;++j){
                    if(val % j == 0){
                        int cnt = 0;
                        while(val % j == 0){
                            ++cnt;
                            val /= j;
                        }
                        p.add(new Tuples(j,cnt));
                    }
                }
                if(val > 1){
                    p.add(new Tuples(val,1));
                }
            }
            Collections.sort(p,new Comparator <Tuples> () {
                public int compare(Tuples x,Tuples y){
                    int cmp = Integer.compare(x.u,y.u);
                    if(cmp == 0){
                        cmp = Integer.compare(x.v,y.v);
                    }
                    return cmp;
                }
            });
            int cur = -1;
            long ans = 1;
            for(int i = p.size() - 1;i > -1;--i){
                if(p.get(i).u != cur){
                    cur = p.get(i).u;
                    ans *= fastExp((long)p.get(i).u,p.get(i).v);
                }
            }
            for(int i = 0;i < n;++i){
                if(ans == (long)d[i]){
                    if(p.isEmpty()){
                        out.print(-1);
                        return ;
                    } else {
                        ans *= (long)p.get(0).u;
                        break;
                    }
                }
            }
            out.print(ans + "\n");
        }

        private long fastExp(long x,int h){
            long ret = 1;
            for(;h > 0;x = x * x,h >>= 1){
                if(h % 2 == 1){
                    ret*=x;
                }
            }
            return ret;
        }

        private class Tuples{
            int u,v;
            Tuples(int u,int v){
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
