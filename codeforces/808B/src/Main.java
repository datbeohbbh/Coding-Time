import java.io.*;
import java.util.*;
import java.text.DecimalFormat;

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
            int n,k;
            n = in.nextInt();
            k = in.nextInt();
            int[] a = new int[n + 1];
            for(int i = 0;i < n;++i){
                a[i] = in.nextInt();
            }
            double sum = 0;
            double ans = 0;
            for(int i = 0;i < n;++i){
                if(i >= k){
                    ans += sum;
                    sum -= (double)a[i - k];
                }
                sum += (double)a[i];
            }
            ans += sum;
            DecimalFormat df = new DecimalFormat("#.###########");
            out.print(df.format(ans / (double)(n - k + 1)));
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