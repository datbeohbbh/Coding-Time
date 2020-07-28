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
        int[] idx = new int[26];

        public void solve(InputReader in,PrintWriter out){
            n = in.nextInt();
            Arrays.fill(idx,-1);
            Dsu dsu = new Dsu(n);
            for(int i = 0;i < n;++i){
                String s = in.nextLine();
                for(int j = 0;j < s.length();++j){
                    char c = s.charAt(j);
                    if(idx[c - 'a'] == -1){
                        idx[c - 'a'] = i;
                    } else {
                        dsu.join(i,idx[c - 'a']);
                    }
                }
            }
            int ans = 0;
            for(int i = 0;i < n;++i){
                ans += (i == dsu.findp(i) ? 1 : 0);
            }
            out.print(ans);
        }

        public class Dsu {
            int[] par;
            public Dsu(int _size){
                par = new int[_size];
                for(int i = 0;i < _size;++i){
                    par[i] = i;
                }
            }

            int findp(int u){
                return (par[u] == u ? par[u] : (par[u] = findp(par[u])));
            }

            void join(int u,int v){
                par[findp(u)] = par[findp(v)];
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
