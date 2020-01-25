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
        public void solve(InputReader in,PrintWriter out){
            int q;
            q = in.nextInt();
            for(;q > 0;--q){
                int n;
                n = in.nextInt();
                int[] a = new int[n];
                int[] vis = new int[n];
                for(int i = 0;i < n;++i){
                    a[i] = in.nextInt();
                    --a[i];
                    vis[i] = 0;
                }
                int stp = 0;
                for(int i = 0;i < n;++i){
                    int pos = -1;
                    for(int j = 0;j < n;++j){
                        if(a[j] == i){
                            pos = j;
                            break;
                        }
                    }
                    while(stp != n - 1 && pos - 1 >= 0 && vis[pos - 1] == 0 && a[pos - 1] > a[pos]){
                        int t = a[pos - 1];
                        a[pos - 1] = a[pos];
                        a[pos] = t;
                        vis[pos - 1] = 1;
                        --pos;
                        ++stp;
                    }
                }
                for(int i = 0;i < n;++i){
                    out.print(++a[i] + " ");
                }
                out.println();
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
