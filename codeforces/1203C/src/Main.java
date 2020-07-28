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
            int n;
            n = in.nextInt();
            long[] a = new long[n + 1];
            long g = 0;
            for(int i = 0;i < n;++i){
                a[i] = in.nextLong();
                g = GCD(g,a[i]);
            }
            long ans = 1;
            for(long i = 2;i * i <= g;++i){
                if(g % i == 0){
                    int cnt = 0;
                    while(g % i == 0){
                        g /= i;
                        ++cnt;
                    }
                    ans *= (cnt + 1);
                }
            }
            if(g > 1){
                ans *= 2;
            }
            out.print(ans);
        }

        long GCD(long x,long y){
            if(y == 0){
                return x;
            } else {
                return GCD(y,x % y);
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
