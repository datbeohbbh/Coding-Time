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
        int[] a;
        long[] sum;
        long[] tot;
        long[] ans;

        public void solve(InputReader in,PrintWriter out){
            n = in.nextInt();
            m = in.nextInt();
            sum = new long[n + 1];
            tot = new long[n + 1];
            ans = new long[n + 1];
            a = new int[n + 1];
            sum[0] = 0;
            Arrays.fill(ans,0);
            for(int i = 1;i <= n;++i){
                a[i] = in.nextInt();
            }
            Arrays.sort(a);
            for(int i = 1;i <= n;++i){
                sum[i] = sum[i - 1] + a[i];
            }
            for(int k = 1;k <= n;++k){
                int d = (k % m);
                if(k == 0){
                    d = m;
                }
                tot[d] += sum[k];
                ans[k] += tot[d];
            }
            for(int k = 1;k <= n;++k){
                out.print(ans[k] + " ");
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
